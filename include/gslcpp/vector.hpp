/// @file       include/gslcpp/vector.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vector.

// Use old-style include-guards instead of '#pragma once' here because we have
// to include at bottom implementation-headers, each of which includes this
// file; old-style guards here make neovim happy.
#ifndef GSL_VECTOR_HPP
#  define GSL_VECTOR_HPP

#  include "vec-iface.hpp" // vec_iface
#  include <algorithm> // swap
#  include <type_traits> // is_same_v, enable_if_t

/// Namespace for C++-interface to small subset of GSL's functionality,
/// initially just minimization, which requires using gsl_vector.
namespace gsl {


using std::enable_if_t;
using std::is_const_v;
using std::is_same_v;


/// Generic template for CRTP-descendant from vec_iface.
/// - `S` indicates number of elements in instance of generic template.
/// - Each specialization has non-positive `S`; see gsl::size_code.
/// - `T` must be `double` or (only if `S == VIEW`) possibly `double const`.
/// @tparam S  Positive size or code for allocation and ownership.
/// @tparam T  For internal use, type of each element.
template<int S, typename T= double> class vector {
  static_assert(S > 0);

  using view= typename view_helper<T>::view;

  T d_[S]; ///< Storage for data.
  view view_; ///< GSL's view of data within instance of vector.

public:
  /// Initialize GSL's view of static storage, but do not initialize elements.
  vector(): view_(gsl_vector_view_array(d_, S)) {}

  using element_t= T;

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return view_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto const &v() const { return view_.vector; }
};


/// Specialization for vector as dynamic container on construction.
template<typename T> class vector<DCON, T> {
public:
  /// Identifier for each of two possible allocation-methods.
  enum class alloc_type {
    ALLOC, ///< Just allocate without initialization.
    CALLOC ///< Initialize each element to zero after allocation.
  };

  using element_t= T;

private:
  /// Identifier for one of two possible allocation-methods.
  /// - By default, allocate without initialization.
  alloc_type alloc_type_= alloc_type::ALLOC;

  /// Pointer to allocated descriptor for vector.
  typename view_helper<T>::vect *v_= nullptr;

  /// Deallocate vector and its descriptor.
  void free() {
    if(v_) gsl_vector_free(v_);
    v_= nullptr;
  }

  /// Allocate vector and its descriptor.
  /// @param n  Number of elements in vector.
  /// @return  Pointer to vector's descriptor.
  gsl_vector *allocate(size_t n) {
    free();
    if(alloc_type_ == alloc_type::ALLOC) return gsl_vector_alloc(n);
    return gsl_vector_calloc(n);
  }

public:
  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return *v_; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto const &v() const { return *v_; }

  /// Allocate vector and its descriptor.
  /// @param n  Number of elements in vector.
  /// @param a  Method to use for allocation.
  vector(size_t n, alloc_type a= alloc_type::ALLOC): alloc_type_(a) {
    v_= allocate(n);
  }

  /// Allocate vector and its descriptor, and perform deep copy on
  /// construction.
  /// @tparam S  Size-parameter indicating type of source.
  /// @tparam V  Type of view.
  /// @param src  Vector to copy.
  template<int S, typename V>
  vector(vector<S, V> const &src): alloc_type_(alloc_type::ALLOC) {
    v_= allocate(src.pv()->size);
    memcpy(*this, src);
  }

  /// Move on construction.
  /// - Note that this is not a templated constructor because moving works only
  ///   from other vector<DCON>.
  /// @param src  Vector to move.
  vector(vector &&src): alloc_type_(src.alloc_type_), v_(src.v_) {
    src.alloc_type_= alloc_type::ALLOC;
    src.v_= nullptr;
  }

  /// Deallocate existing vector and its descriptor; allocate new vector and
  /// its descriptor; and perform deep copy on assignment.
  /// @tparam S  Size-parameter indicating type of source.
  /// @tparam V  Type of view.
  /// @param src  Vector to copy.
  /// @return  Reference to instance after modification.
  template<int S, typename V> vector &operator=(vector<S, V> const &src) {
    alloc_type_= alloc_type::ALLOC;
    v_= allocate(src.pv()->size);
    memcpy(*this, src);
    return *this;
  }

  /// Move on assignment.
  /// - This instance's original descriptor and data should be deallocated
  ///   after move, when src's destructor is called.
  /// - Note that this is not a templated function because moving works only
  ///   from other vector<DCON>.
  /// @param src  Vector to exchange state with.
  /// @return  Reference to instance after modification.
  vector &operator=(vector &&src) {
    std::swap(alloc_type_, src.alloc_type_);
    std::swap(v_, src.v_);
    return *this;
  }

  /// Deallocate vector and its descriptor.
  virtual ~vector() { free(); }
};


/// Specialization for vector that refers to mutable, external data.
template<typename T> class vector<VIEW, T> {
  using view= typename view_helper<T>::view;
  view view_; ///< GSL's view of data outside instance.

public:
  using element_t= T;

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return view_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto const &v() const { return view_.vector; }

  /// Constructor called by TBS.
  /// @param v  View to copy.
  vector(view const &v): view_(v) {}
};


/// Short-hand for vector with ownership of dynamically allocated storage.


template<unsigned S, typename T= double>
struct vector_s: public vec_iface<vector<S, T>> {
  using P= vec_iface<vector<S, T>>;
  using P::P;

  /// Construct by copying from dynamic vector or view of same size.
  /// - Mismatch in size produces run-time abort.
  /// - `OV` must be `gsl_vector_view` or (only if `OS == VIEW`) possibly
  ///   `gsl_vector_const_view`.
  /// @tparam OS  Size-code (DCON=0 or VIEW=-1) of source-vector.
  /// @tparam OV  Type of view used internally by source-vector.
  /// @param ov  Reference to source-vector.
  template<int OS, typename OV, typename= enable_if_t<(OS < 1)>>
  vector_s(vec_iface<vector<OS, OV>> const &ov) {
    memcpy(*this, ov);
  }

  /// Initialize GSL's view, and initialize elements by copying from array.
  /// - Size-parameter `S` can be *deduced* from the argument!
  /// - So, for example, one can do this:
  ///   ```c++
  ///   double d[]= {2.0, 3.0, 4.0};
  ///   vector v(d); // No template-parameter required!
  ///   ```
  /// @param d  Data to copy for initialization.
  vector_s(T const (&d)[S]);

  /// Initialize GSL's view, and initialize vector by copying from array.
  /// - Mismatch in size produces run-time abort.
  /// - For example:
  ///   ```c++
  ///   double d[]= {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  ///   vector<3> v(d, 1, 2); // Start at offset 1 (not 0) and use stride 2.
  ///   // So v == [2.0, 4.0, 6.0].
  ///   ```
  /// @tparam N  Number of elements in non-decayed C-style array.
  /// @param d  Non-decayed C-style array.
  /// @param i  Offset of initial element to be copied.
  /// @param s  Stride of elements to be copied.
  template<unsigned N, typename= enable_if_t<N != S>>
  vector_s(T const (&d)[N], size_t i= 0, size_t s= 1);

  /// Initialize GSL's view, and initialize elements by copying from array.
  /// - Stride is required as first argument in order to disambiguate this
  ///   constructor from the one that takes a non-decayed array.
  /// @param s  Stride.
  /// @param d  Decayed C-style array.
  vector_s(size_t s, T const *d): vector_s() { memcpy(*this, view(S, d, s)); }

  /// Initialize GSL's view, and initialize vector by deep copy.
  /// @param v  Data to copy for initialization.
  vector_s(vector_s const &v) { memcpy(*this, v); }

  /// Assign vector by deep copy.
  /// @param v  Data to copy for initialization.
  /// @return  Reference to modified vector.
  vector_s &operator=(vector_s const &v) {
    memcpy(*this, v);
    return *this;
  }

  /// Assign vector by copying from array.
  /// @param v  Data to copy for initialization.
  /// @return  Reference to modified vector.
  vector_s &operator=(T const (&d)[S]) {
    memcpy(*this, view(d));
    return *this;
  }
};


template<typename T= double>
struct vector_d: public vec_iface<vector<DCON, T>> {
  using P= vec_iface<vector<DCON, T>>;
  using P::P;
};


template<typename T= double>
struct vector_v: public vec_iface<vector<VIEW, T>> {
  using P= vec_iface<vector<VIEW, T>>;
  using P::P;

  /// Initialize view of standard (decayed) C-array.
  /// - Arguments are reordered relative to those given to
  ///   gsl_vector_view_array_with_stride().
  /// - Putting number of element at *beginning* disambiguates from constructor
  ///   from non-decayed array.
  /// - Putting stride at *end* allows it to have default value of 1.
  /// @param b  Pointer to first element of array and of view.
  /// @param n  Number of elements in view.
  /// @param s  Stride of view relative to array.
  vector_v(size_t n, T *b, size_t s= 1):
      P(view_helper<T>::make_view(n, b, s)) {}

  /// Initialize view of non-decayed C-array.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows every argument to have
  ///   good default (N for number of elements in view, 0 for initial offset,
  ///   and 1 for stride).
  /// @tparam N  Number of elements in array.
  /// @param b  Reference to non-decayed C-array.
  /// @param n  Number of elements in view.
  /// @param i  Offset in array of first element in view.
  /// @param s  Stride of view relative to array.
  template<int N>
  vector_v(T (&b)[N], size_t n= N, size_t i= 0, size_t s= 1):
      P(view_helper<T>::make_view(b, n, i, s)) {}
};


template<typename T= double>
struct vector_cv: public vec_iface<vector<VIEW, T const>> {
  using P= vec_iface<vector<VIEW, T const>>;
  using P::P;

  /// Initialize view of standard (decayed) C-array.
  /// - Arguments are reordered relative to those given to
  ///   gsl_vector_view_array_with_stride().
  /// - Putting number of element at *beginning* disambiguates from constructor
  ///   from non-decayed array.
  /// - Putting stride at *end* allows it to have default value of 1.
  /// @param b  Pointer to first element of array and of view.
  /// @param n  Number of elements in view.
  /// @param s  Stride of view relative to array.
  vector_cv(size_t n, T const *b, size_t s= 1):
      P(view_helper<T const>::make_view(n, b, s)) {}

  /// Initialize view of non-decayed C-array.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows every argument to have
  ///   good default (N for number of elements in view, 0 for initial offset,
  ///   and 1 for stride).
  /// @tparam N  Number of elements in array.
  /// @param b  Reference to non-decayed C-array.
  /// @param n  Number of elements in view.
  /// @param i  Offset in array of first element in view.
  /// @param s  Stride of view relative to array.
  template<int N>
  vector_cv(T const (&b)[N], size_t n= N, size_t i= 0, size_t s= 1):
      P(view_helper<T const>::make_view(b, n, i, s)) {}
};


template<unsigned S, typename T> vector_s<S, T>::vector_s(T const (&d)[S]) {
  memcpy(*this, vector_cv(d));
}


template<unsigned S, typename T>
template<unsigned N, typename>
vector_s<S, T>::vector_s(T const (&d)[N], size_t i, size_t s) {
  if(i + s * (S - 1) > N - 1) {
    throw std::runtime_error("source-array not big enough");
  }
  memcpy(*this, vector_cv(d, S, i, s));
}


} // namespace gsl

#endif // ndef GSL_VECTOR_HPP

// Implementation relying on definition of vector defined above.
#include "impl/vec-iface-impl.hpp"

// EOF
