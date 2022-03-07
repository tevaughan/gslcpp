/// \file       include/gslcpp/vec/v-stor.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::v_stor.

#pragma once
#include "../wrap/free.hpp" // w_free
#include "../wrap/vector-alloc.hpp" // w_vector_alloc
#include "../wrap/vector-calloc.hpp" // w_vector_calloc
#include "../wrap/vector-view-array.hpp" // vector_view_array

namespace gsl {


/// Generic %v_stor is interface to storage with two key properties: (1) that
/// size of storage is known statically, at compile-time, and (2) that it is
/// owned by instance of %v_stor.
///
/// Specialization is for storage-size determined at run-time.
///
/// %v_stor implements concept gsl::v_stor and can serve as template-type
/// parameter for (and thus base of) gsl::v_iface.
///
/// @tparam T  Type of each element in vector.
/// @tparam S  Compile-time size of vector (0 for size specified at run-time).
template<typename T, size_t S= 0> class v_stor {
  static_assert(S > 0);

  T d_[S]; ///< Storage for data.
  w_vector_view<T> cview_; ///< GSL's view of data.

  v_stor(v_stor const &)= delete; ///< Disable copy-construction.
  v_stor &operator=(v_stor const &)= delete; ///< Disable copy-assignment.

public:
  /// Initialize GSL's view of static storage, but do not initialize elements.
  /// If number `n` of elements intended for vector be not `S`, then throw.
  /// \param n  Number of elements intended for vector.
  v_stor(size_t n= S): cview_(w_vector_view_array(d_, 1, S)) {
    if(n != S) throw "mismatch in size";
  }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return cview_.vector; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto &v() const { return cview_.vector; }
};


/// Specialization, which is interface to storage with two key properties: (1)
/// that size of storage is determined dynamically, at run-time, and (2) that
/// it is owned by instance of interface.
///
/// Generic %v_stor is for storage-size determined at compile-time.
///
/// %v_dyna implements concept gsl::v_stor and can serve as template-type
/// parameter for (and thus base of) gsl::v_iface.
///
/// @tparam T  Type of each element in vector.
template<typename T> class v_stor<T> {
  v_stor(v_stor const &)= delete; ///< Disable copy-construction.
  v_stor &operator=(v_stor const &)= delete; ///< Disable copy-assignment.

public:
  /// Identifier for each of two possible allocation-methods.
  enum alloc_type {
    ALLOC, ///< Just allocate without initialization.
    CALLOC ///< Initialize each element to zero after allocation.
  };

protected:
  /// Pointer to allocated descriptor for vector.
  w_vector<T> *v_= nullptr;

  /// Deallocate vector and its descriptor.
  void free() {
    if(v_) w_free(v_);
    v_= nullptr;
  }

  /// Allocate vector and its descriptor.
  /// \param n  Number of elements in vector.
  /// \param a  Type of allocation (simple or initialized to zero).
  /// \return  Pointer to vector's descriptor.
  w_vector<T> *allocate(size_t n, alloc_type a) {
    free();
    if(a == ALLOC) return w_vector_alloc<T>(n);
    return w_vector_calloc<T>(n);
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
  /// Allocate vector and its descriptor.
  /// @param n  Number of elements in vector.
  /// @param a  Method to use for allocation.
  v_stor(size_t n, alloc_type a= ALLOC) { v_= allocate(n, a); }

  /// True if object's data have been validly allocated.
  /// \return  True if object's data have been validly allocated.
  bool valid() const { return v_!= nullptr; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to vector.
  auto &v() { return *v_; }

  /// Reference to GSL's interface to vector.
  /// @return  Reference to GSL's interface to immutable vector.
  auto &v() const { return *v_; }

  /// Move on construction.
  /// - Note that this is not a templated constructor because moving works only
  ///   from other vector<DCON>.
  /// @param src  Vector to move.
  v_stor(v_stor &&src): v_(src.v_) { src.v_= nullptr; }

  /// Move on assignment.  This instance's original descriptor and data should
  /// be deallocated after move, when src's destructor is called.  Note that
  /// this is not a templated function because moving works only from other
  /// vector<DCON>.
  /// @param src  Vector to exchange state with.
  /// @return  Reference to instance after modification.
  v_stor &operator=(v_stor &&src) {
    swap_(v_, src.v_);
    return *this;
  }

  /// Deallocate vector and its descriptor.
  virtual ~v_stor() { free(); }
};


} // namespace gsl

// EOF
