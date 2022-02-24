/// @file       include/gslcpp/vec/stor.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
///
/// @brief      Definition for
///             gsl::vec::stor,
///             gsl::vec::stat,
///             gsl::vec::dyna, and
///             gsl::vec::view.

#pragma once

#include "../c/iface.hpp" // c_iface

namespace gsl::vec {


using std::same_as;


/// Interface required for template referring to storage for vector.
/// @tparam T  Candidate type of storage for vector.
template<typename T> concept stor= requires(T &x, T const &y) {
  typename T::E;
  { x.v() } -> same_as<typename c::iface<typename T::E>::vector &>;
  { y.v() } -> same_as<typename c::iface<typename T::E>::vector const &>;
};


/// Interface to vector-storage allocated on stack, statically, at
/// compile-time, and owned by instance of interface.
///
/// `S` indicates number of elements in instance of generic template.
///
/// @tparam S  Positive size.
/// @tparam T  Type of each element in vector.
template<unsigned S, typename T= double> class stat {
  static_assert(S > 0);

public:
  using E= T; ///< Type of each element.

private:
  T d_[S]; ///< Storage for data.
  c::vector_view<E> view_; ///< GSL's view of data within instance of vector.

public:
  /// Initialize GSL's view of static storage, but do not initialize elements.
  stat(): view_(gsl_vector_view_array(d_, S)) {}

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return view_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto &v() const { return view_.vector; }
};


/// Interface to vector-storage allocated dynamically, at run-time, and owned
/// by instance of interface.
/// @tparam T  Type of each element in vector.
template<typename T> class dyna {
public:
  /// Identifier for each of two possible allocation-methods.
  enum class alloc_type {
    ALLOC, ///< Just allocate without initialization.
    CALLOC ///< Initialize each element to zero after allocation.
  };

  using E= T; ///< Type of each element.

private:
  /// Identifier for one of two possible allocation-methods.
  /// - By default, allocate without initialization.
  alloc_type alloc_type_= alloc_type::ALLOC;

  /// Pointer to allocated descriptor for vector.
  c::vector<E> *v_= nullptr;

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
  auto &v() const { return *v_; }

  /// Allocate vector and its descriptor.
  /// @param n  Number of elements in vector.
  /// @param a  Method to use for allocation.
  dyna(size_t n, alloc_type a= alloc_type::ALLOC): alloc_type_(a) {
    v_= allocate(n);
  }

  // Move to descendant.
#if 0
  /// Allocate vector and its descriptor, and perform deep copy on
  /// construction.
  /// @tparam S  Size-parameter indicating type of source.
  /// @tparam V  Type of view.
  /// @param src  Vector to copy.
  template<int S, typename V>
  dyna(vector<S, V> const &src): alloc_type_(alloc_type::ALLOC) {
    v_= allocate(src.pv()->size);
    memcpy(*this, src);
  }
#endif

  /// Move on construction.
  /// - Note that this is not a templated constructor because moving works only
  ///   from other vector<DCON>.
  /// @param src  Vector to move.
  dyna(dyna &&src): alloc_type_(src.alloc_type_), v_(src.v_) {
    src.alloc_type_= alloc_type::ALLOC;
    src.v_= nullptr;
  }

  // Move to descendant.
#if 0
  /// Deallocate existing vector and its descriptor; allocate new vector and
  /// its descriptor; and perform deep copy on assignment.
  /// @tparam S  Size-parameter indicating type of source.
  /// @tparam V  Type of view.
  /// @param src  Vector to copy.
  /// @return  Reference to instance after modification.
  template<int S, typename V> dyna &operator=(vector<S, V> const &src) {
    alloc_type_= alloc_type::ALLOC;
    v_= allocate(src.pv()->size);
    memcpy(*this, src);
    return *this;
  }
#endif

  /// Move on assignment.  This instance's original descriptor and data should
  /// be deallocated after move, when src's destructor is called.  Note that
  /// this is not a templated function because moving works only from other
  /// vector<DCON>.
  /// @param src  Vector to exchange state with.
  /// @return  Reference to instance after modification.
  dyna &operator=(dyna &&src) {
    std::swap(alloc_type_, src.alloc_type_);
    std::swap(v_, src.v_);
    return *this;
  }

  /// Deallocate vector and its descriptor.
  virtual ~dyna() { free(); }
};


/// Interface to vector-storage not owned by interface.
/// @tparam T  Type of each element in vector.
template<typename T> class view {
public:
  using E= T; ///< Type of each element.

private:
  c::vector_view<E> view_; ///< GSL's view of data outside instance.

public:
  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return view_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto &v() const { return view_.vector; }

  /// Constructor called by TBS.
  /// @param v  View to copy.
  view(c::vector_view<E> const &v): view_(v) {}

  /// GSL's native, C-language interface to vector-view.
  /// @return  GSL's native, C-language interface to vector-view.
  auto &cview() const { return view_; }
};


} // namespace gsl::vec

// EOF
