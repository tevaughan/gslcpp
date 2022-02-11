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
/// - `V` must be `gsl_vector_view` or (but only if `S == VIEW`) possibly
///   `gsl_vector_const_view`.
/// @tparam S  Positive size or code for allocation and ownership.
/// @tparam V  Type of view used internally to point at internal C-array.
template<int S, typename V= gsl_vector_view>
class vector: public vec_iface<vector<S, V>> {
  static_assert(S > 0);
  static_assert(is_same_v<V, gsl_vector_view>);

  double d_[S]; ///< Storage for data.
  V view_; ///< GSL's view of data within instance of vector.

  using vec::view; ///< Explicitly inherit static template-functions.

public:
  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return view_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto const &v() const { return view_.vector; }

  /// Initialize GSL's view of static storage, but do not initialize elements.
  vector(): view_(gsl_vector_view_array(d_, S)) {}

  /// Construct by copying from dynamic vector or view of same size.
  /// - Mismatch in size produces run-time abort.
  /// - `OV` must be `gsl_vector_view` or (only if `OS == VIEW`) possibly
  ///   `gsl_vector_const_view`.
  /// @tparam OS  Size-code (DCON=0 or VIEW=-1) of source-vector.
  /// @tparam OV  Type of view used internally by source-vector.
  /// @param ov  Reference to source-vector.
  template<int OS, typename OV, typename= enable_if_t<(OS < 1)>>
  vector(vector<OS, OV> const &ov): vector() {
    memcpy(*this, ov);
  }

  /// Initialize GSL's view, and initialize elements by copying from array.
  /// - Size-parameter `S` can be *deduced* from the argument!
  /// - So, for example, one can do this:
  ///   ```c++
  ///   double d[]= {2.0, 3.0, 4.0};
  ///   vector v(d); // No template-parameter required!
  ///   ```
  /// - This constructor completely initializes new vector with data from
  ///   C-style array (that has *not* decayed).
  /// @param d  Data to copy for initialization.
  vector(double const (&d)[S]): vector() { memcpy(*this, view(d)); }

  /// Initialize GSL's view, and initialize vector by copying from array.
  /// - Mismatch in size produces run-time abort.
  /// - Size-parameter `S` can *not* be deduced from the argument.
  /// - For example:
  ///   ```c++
  ///   double d[]= {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  ///   vector<3> v(d, 1, 2); // Start at offset 1 (not 0) and use stride 2.
  ///   // So v == [2.0, 4.0, 6.0].
  ///   ```
  /// - This constructor completely initializes new vector with data from
  ///   C-style array (that has *not* decayed).
  /// @tparam N  Number of elements in non-decayed C-style array.
  /// @param d  Non-decayed C-style array.
  /// @param i  Offset of initial element to be copied.
  /// @param s  Stride of elements to be copied.
  template<unsigned N>
  vector(double const (&d)[N], size_t i, size_t s= 1): vector() {
    if(i + s * (S - 1) >= N) {
      throw std::runtime_error("source-array not big enough");
    }
    memcpy(*this, view(d, S, i, s));
  }

  /// Initialize GSL's view, and initialize vector by deep copy.
  /// @param v  Data to copy for initialization.
  vector(vector const &v): vector() { memcpy(*this, v); }

  /// Assign vector by deep copy.
  /// @param v  Data to copy for initialization.
  /// @return  Reference to modified vector.
  vector &operator=(vector const &v) {
    memcpy(*this, v);
    return *this;
  }

  /// Assign vector by copying from array.
  /// @param v  Data to copy for initialization.
  /// @return  Reference to modified vector.
  vector &operator=(double const (&d)[S]) {
    memcpy(*this, view(d));
    return *this;
  }
};


/// Specialization for vector as dynamic container on construction.
template<> class vector<DCON>: public vec_iface<vector<DCON>> {
public:
  /// Identifier for each of two possible allocation-methods.
  enum class alloc_type {
    ALLOC, ///< Just allocate without initialization.
    CALLOC ///< Initialize each element to zero after allocation.
  };

private:
  /// Identifier for one of two possible allocation-methods.
  /// - By default, allocate without initialization.
  alloc_type alloc_type_= alloc_type::ALLOC;

  gsl_vector *v_= nullptr; ///< Pointer to allocated descriptor for vector.

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
template<typename V> class vector<VIEW, V>: public vec_iface<vector<VIEW, V>> {
  static_assert(
    is_same_v<V, gsl_vector_view> || is_same_v<V, gsl_vector_const_view>);

  V view_; ///< GSL's view of data outside instance.

  enum {
    /// Symbol used to select appropriate constructor from other vector.
    IS_CONST_VEC= is_same_v<V, gsl_vector_const_view>
  };

public:
  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return view_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto const &v() const { return view_.vector; }

  /// Constructor called by view().
  /// @param v  View to copy.
  vector(gsl_vector_view v): view_(v) {}

  /// Constructor called by view().
  /// @param v  View to copy.
  vector(gsl_vector_const_view v): view_(v) {}

  /// Initialize view of standard (decayed) C-array.
  /// - Arguments are reordered relative to those given to
  ///   gsl_vector_view_array_with_stride().
  /// - Putting stride at *end* allows it to have default value of 1.
  /// @tparam T  Type of each element.
  /// @param b  Pointer to first element of array and of view.
  /// @param n  Number of elements in view.
  /// @param s  Stride of view relative to array.
  template<typename T>
  vector(T *b, size_t n, size_t s= 1): view_(view_array(b, n, s).view_) {}

  /// Initialize view of non-decayed C-array.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows every argument to have
  ///   good default (N for number of elements in view, 0 for initial offset,
  ///   and 1 for stride).
  /// @tparam T  Type of each element.
  /// @tparam N  Number of elements in array.
  /// @param b  Reference to non-decayed C-array.
  /// @param n  Number of elements in view.
  /// @param i  Offset in array of first element in view.
  /// @param s  Stride of view relative to array.
  template<typename T, int N>
  vector(T (&b)[N], size_t n= N, size_t i= 0, size_t s= 1):
      view_(vec::view(b, n, i, s).view_) {}

  /// View of subvector of vector.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows each to have good
  ///   default:
  ///   - 0 for number of elements in view as code for v.size(),
  ///   - 0 for initial offset, and
  ///   - 1 for stride).
  /// @param n  Number of elements in view.
  /// @param i  Offset in vector of first element in view.
  /// @param s  Stride of view relative to vector.
  template<int S, typename T, typename= enable_if_t<is_same_v<V, T>>>
  vector(vector<S, T> &v, size_t n= 0, size_t i= 0, size_t s= 1):
      view_(v.subvector(n ? n : v.size(), i, s).view_) {}

  /// View of subvector of vector.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows each to have good
  ///   default:
  ///   - 0 for number of elements in view as code for v.size(),
  ///   - 0 for initial offset, and
  ///   - 1 for stride).
  /// @param n  Number of elements in view.
  /// @param i  Offset in vector of first element in view.
  /// @param s  Stride of view relative to vector.
  template<
    int S,
    typename T,
    typename= enable_if_t<!is_const_v<decltype(T::vector)> && IS_CONST_VEC>>
  vector(vector<S, T> const &v, size_t n= 0, size_t i= 0, size_t s= 1):
      view_(v.subvector(n ? n : v.size(), i, s).view_) {}
};


/// Short-hand for vector with ownership of dynamically allocated storage.
using vectord= vector<DCON>;


} // namespace gsl

#endif // ndef GSL_VECTOR_HPP

// Implementations, each relying on definition of vector defined above.
#include "impl/vec-iface-impl.hpp"
#include "impl/vec-impl.hpp"

// EOF
