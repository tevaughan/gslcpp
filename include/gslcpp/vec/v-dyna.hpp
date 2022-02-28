/// \file       include/gslcpp/vec/v-dyna.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::v_dyna.

#pragma once
#include "../wrap/free.hpp" // w_free
#include "../wrap/type-map.hpp" // w_vector
#include "../wrap/vector-alloc.hpp" // w_vector_alloc
#include "../wrap/vector-calloc.hpp" // w_vector_calloc
#include <algorithm> // swap

namespace gsl {


/// Interface to vector-storage with two key properties: (1) that its size is
/// determined dynamically, at run-time, and (2) that it is owned by instance
/// of interface.
///
/// %v_dyna implements concept gsl::vew_stor and can serve as template-type
/// parameter for (and thus base of) gsl::iface.
///
/// @tparam T  Type of each element in vector.
template<typename T> class v_dyna {
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
  w_vector<E> *v_= nullptr;

  /// Deallocate vector and its descriptor.
  void free() {
    if(v_) w_free(v_);
    v_= nullptr;
  }

  /// Allocate vector and its descriptor.
  /// @param n  Number of elements in vector.
  /// @return  Pointer to vector's descriptor.
  w_vector<E> *allocate(size_t n) {
    free();
    if(alloc_type_ == alloc_type::ALLOC) return w_vector_alloc<E>(n);
    return w_vector_calloc<E>(n);
  }

  /// Swap values held by two variables.
  /// @tparam U  Common type of items.
  /// @param a  Reference to first item.
  /// @param b  Reference to second item.
  template<typename U> static void swap_(U &a, U &b) {
    U const tmp= a;
    a= b;
    b= tmp;
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
  v_dyna(size_t n, alloc_type a= alloc_type::ALLOC): alloc_type_(a) {
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
  v_dyna(vector<S, V> const &src): alloc_type_(alloc_type::ALLOC) {
    v_= allocate(src.pv()->size);
    memcpy(*this, src);
  }
#endif

  /// Move on construction.
  /// - Note that this is not a templated constructor because moving works only
  ///   from other vector<DCON>.
  /// @param src  Vector to move.
  v_dyna(v_dyna &&src): alloc_type_(src.alloc_type_), v_(src.v_) {
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
  template<int S, typename V> v_dyna &operator=(vector<S, V> const &src) {
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
  v_dyna &operator=(v_dyna &&src) {
    swap_(alloc_type_, src.alloc_type_);
    swap_(v_, src.v_);
    return *this;
  }

  /// Deallocate vector and its descriptor.
  virtual ~v_dyna() { free(); }
};


} // namespace gsl

// EOF
