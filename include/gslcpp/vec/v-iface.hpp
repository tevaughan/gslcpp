/// \dir        include/gslcpp/vec
/// \brief      Types and functions specific to interface to GSL's vectors.

/// \file       include/gslcpp/vec/v-iface.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::v_iface.

#pragma once

#include "../wrap/add-constant.hpp" // add_constant
#include "../wrap/add.hpp" // add
#include "../wrap/axpby.hpp" // axpby
#include "../wrap/div.hpp" // div
#include "../wrap/equal.hpp" // equal
#include "../wrap/fprintf.hpp" // fprintf
#include "../wrap/fread.hpp" // fread
#include "../wrap/fscanf.hpp" // fscanf
#include "../wrap/fwrite.hpp" // fwrite
#include "../wrap/get.hpp" // get
#include "../wrap/isneg.hpp" // isneg
#include "../wrap/isnonneg.hpp" // isnonneg
#include "../wrap/isnull.hpp" // isnull
#include "../wrap/ispos.hpp" // ispos
#include "../wrap/max-index.hpp" // max_index
#include "../wrap/max.hpp" // max
#include "../wrap/memcpy.hpp" // memcpy
#include "../wrap/min-index.hpp" // min_index
#include "../wrap/min.hpp" // min
#include "../wrap/minmax-index.hpp" // minmax_index
#include "../wrap/minmax.hpp" // minmax
#include "../wrap/mul.hpp" // mul
#include "../wrap/ptr.hpp" // ptr
#include "../wrap/reverse.hpp" // reverse
#include "../wrap/scale.hpp" // scale
#include "../wrap/set-all.hpp" // set_all
#include "../wrap/set-basis.hpp" // set_basis
#include "../wrap/set-zero.hpp" // set_zero
#include "../wrap/set.hpp" // set
#include "../wrap/sub.hpp" // sub
#include "../wrap/subvector.hpp" // subvector
#include "../wrap/sum.hpp" // sum
#include "../wrap/swap-elements.hpp" // swap_elements
#include "../wrap/swap.hpp" // swap
#include "v-iterator.hpp" // iterator
#include "v-stor.hpp" // stor
#include "v-view.hpp" // view
#include <iostream> // ostream

namespace gsl {


using std::is_const_v;


// Forward declaration.
template<typename T> class vector_v;


/// Interface for every kind of vector.
/// @tparam S  Type referring to storage of elements.
template<v_stor S> struct v_iface: public S {
  /// Inherit constructors.
  using S::S;

  /// Inherit assigment.
  using S::operator=;

  /// Reference to instance of w_vector<S::E>, which is either gsl_vector,
  /// gsl_vector_float, etc.
  using S::v;

  /// Type of each element.
  using E= typename S::E;

  /// Type of iterator that points to mutable element.
  using iterator= v_iterator<v_iface>;

  /// Type of iterator that points to immutable element.
  using const_iterator= v_iterator<v_iface const>;

  /// Iterator that points to first element.
  /// @return  Iterator that points to first element.
  iterator begin() { return iterator(*this, 0); }

  /// Iterator that points to element just past last element.
  /// @return  Iterator that points to element just past last element.
  iterator end() { return iterator(*this, size()); }

  /// Iterator that points to first element.
  /// @return  Iterator that points to first element.
  const_iterator begin() const { return const_iterator(*this, 0); }

  /// Iterator that points to element just past last element.
  /// @return  Iterator that points to element just past last element.
  const_iterator end() const { return const_iterator(*this, size()); }

  /// Size of vector.
  /// @return  Size of vector.
  size_t size() const { return v().size; }

  /// Pointer to first element in vector.
  /// - Be careful to check `v().stride` in case data be not contiguous.
  /// @return  Pointer to first element.
  E *data() { return (E *)v().data; /* Cast for complex. */ }

  /// Pointer to first element in immutable vector.
  /// - Be careful to check `v().stride` in case data be not contiguous.
  /// @return  Pointer to first immutable element.
  E const *data() const { return (E const *)v().data; /* Cast for complex. */ }

  /// Read element with bounds-checking.
  /// @param i  Offset of element.
  /// @return  Value of element.
  E get(size_t i) const { return w_get(&v(), i); }

  /// Write element with bounds-checking.
  /// @param i  Offset of element.
  /// @param x  New value for element.
  void set(size_t i, E const &x) { w_set(&v(), i, x); }

  /// Read element without bounds-checking.
  /// @param i  Offset of element.
  /// @return  Reference to immutable element.
  E const &operator[](size_t i) const { return data()[i * v().stride]; }

  /// Write element without bounds-checking.
  /// @param i  Offset of element.
  /// @return  Reference to mutable element.
  E &operator[](size_t i) { return data()[i * v().stride]; }

  /// Retrieve pointer to `i`th element with bounds-checking.
  /// This could be useful if stride unknown.
  /// @param i  Offset of element.
  /// @return  Pointer to mutable element.
  E *ptr(size_t i) { return w_ptr(&v(), i); }

  /// Retrieve pointer to `i`th element with bounds-checking.
  /// This could be useful if stride unknown.
  /// @param i  Offset of element.
  /// @return  Pointer to immutable element.
  E const *ptr(size_t i) const { return w_ptr(&v(), i); }

  /// Set every element.
  /// @param x  Value to which each element should be set.
  void set_all(E const &x) { w_set_all(&v(), x); }

  /// Set every element to zero.
  void set_zero() { w_set_zero(&v()); }

  /// Set element at offset `i` to unity and every other element to zero.
  /// @param i  Offset of element set to unity.
  /// @return  TBD: GSL's documentation does not specify.
  int set_basis(size_t i) { return w_set_basis(&v(), i); }

  /// Write non-portable binary-image of vector to file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fwrite(FILE *f) const { return w_fwrite(f, &v()); }

  /// Read non-portable binary-image of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fread(FILE *f) { return w_fread(f, &v()); };

  /// Write ASCII-formatted representation of vector to file.
  /// @param flp  Pointer to structure for buffered interface.
  /// @param fmt  printf()-style format-string.
  /// @return  Zero only on success.
  int fprintf(FILE *flp, char const *fmt) const {
    return w_fprintf(flp, &v(), fmt);
  }

  /// Read ASCII-formatted representation of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fscanf(FILE *f) { return w_fscanf(f, &v()); }

  /// View of subvector of vector.  Arguments are reordered from those given to
  /// gsl_vector_subvector_with_stride().  Putting initial offset and stride at
  /// end allows each to have good default (0 for initial offset and 1 for
  /// stride).
  /// @param n  Number of elements in view.
  /// @param i  Offset in vector of first element in view.
  /// @param s  Stride of view relative to vector.
  /// @return  View of subvector.
  v_iface<v_view<E>> subvector(size_t n, size_t i= 0, size_t s= 1) {
    return w_subvector(&v(), i, s, n);
  }

  /// View of subvector of vector.  Arguments are reordered from those given to
  /// gsl_vector_subvector_with_stride().  Putting initial offset and stride at
  /// end allows each to have good default (0 for initial offset and 1 for
  /// stride).
  /// @param n  Number of elements in view.
  /// @param i  Offset in vector of first element in view.
  /// @param s  Stride of view relative to vector.
  /// @return  View of subvector.
  v_iface<v_view<E const>>
  subvector(size_t n, size_t i= 0, size_t s= 1) const {
    return w_subvector(&v(), i, s, n);
  }

  /// View of vector.
  /// @return  View of vector.
  v_iface<v_view<E>> view() { return w_subvector(&v(), 0, 1, size()); }

  /// View of vector.
  /// @return  View of vector.
  v_iface<v_view<E const>> view() const {
    return w_subvector(&v(), 0, 1, size());
  }

  /// Swap elements within this vector.
  /// @param i  Offset of one element.
  /// @param j  Offset of other element.
  /// @return  TBD: GSL's documentation does not specify.
  int swap_elements(size_t i, size_t j) { return w_swap_elements(&v(), i, j); }

  /// Reverse order of elements.
  /// @return  TBD: GSL's documentation does not specify.
  int reverse() { return w_reverse(&v()); }

  /// Add contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be added into this.
  /// @param b  Vector whose contents should be added into this.
  /// @return  TBD: GSL's documentation does not specify.
  template<typename T> int add(v_iface<T> const &b) {
    return w_add(&v(), &b.v());
  }

  /// Subtract contents of `b` from this vector in place.
  /// @tparam T  Type of vector to be subtracted from this.
  /// @param b  Vector whose contents should be subtracted from this.
  /// @return  TBD: GSL's documentation does not specify.
  template<typename T> int sub(v_iface<T> const &b) {
    return w_sub(&v(), &b.v());
  }

  /// Multiply contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be multiplied into this.
  /// @param b  Vector whose contents should be multiplied into this.
  /// @return  TBD: GSL's documentation does not specify.
  template<typename T> int mul(v_iface<T> const &b) {
    return w_mul(&v(), &b.v());
  }

  /// Divide contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be divided into this.
  /// @param b  Vector whose contents should be divided into this.
  /// @return  TBD: GSL's documentation does not specify.
  template<typename T> int div(v_iface<T> const &b) {
    return w_div(&v(), &b.v());
  }

  /// Add contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be added into this.
  /// @param b  Vector whose contents should be added into this.
  /// @return  Reference to this vector after modification.
  template<typename T> v_iface &operator+=(v_iface<T> const &b) {
    add(b);
    return *this;
  }

  /// Subtract contents of `b` from this vector in place.
  /// @tparam T  Type of vector to be subtracted from this.
  /// @param b  Vector whose contents should be subtracted from this.
  /// @return  Reference to this vector after modification.
  template<typename T> v_iface &operator-=(v_iface<T> const &b) {
    sub(b);
    return *this;
  }

  /// Multiply contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be multiplied into this.
  /// @param b  Vector whose contents should be multiplied into this.
  /// @return  Reference to this vector after modification.
  template<typename T> v_iface &operator*=(v_iface<T> const &b) {
    mul(b);
    return *this;
  }

  /// Divide contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be divided into this.
  /// @param b  Vector whose contents should be divided into this.
  /// @return  Reference to this vector after modification.
  template<typename T> v_iface &operator/=(v_iface<T> const &b) {
    div(b);
    return *this;
  }

  /// Multiply scalar into this vector in place.
  /// @param x  Scalar to multiply into this.
  /// @return  TBD: GSL's documentation does not specify.
  int scale(E const &x) { return w_scale(&v(), x); }

  /// Multiply scalar into this vector in place.
  /// @param x  Scalar to multiply into this.
  /// @return  Reference to this vector after modification.
  v_iface &operator*=(E const &x) {
    scale(x);
    return *this;
  }

  /// Add constant into each element of this vector in place.
  /// @param x  Constant to add into this vector.
  /// @return  TBD: GSL's documentation does not specify.
  int add_constant(E const &x) { return w_add_constant(&v(), x); }

  /// Add constant into each element of this vector in place.
  /// @param x  Constant to add into this vector.
  /// @return  Reference to this vector after modification.
  v_iface &operator+=(E const &x) {
    add_constant(x);
    return *this;
  }

  /// Sum of elements.
  /// @return  Sum of elements.
  E sum() const { return w_sum(&v()); }

  /// Greatest value of any element.
  /// @return  Greatest value of any element.
  E max() const { return w_max(&v()); }

  /// Least value of any element.
  /// @return  Least value of any element.
  E min() const { return w_min(&v()); }

  /// Greatest value and least value of any element.
  /// @param min  On return, least value.
  /// @param max  On return, greatest value.
  void minmax(E &min, E &max) const { w_minmax(&v(), &min, &max); }

  /// Offset of greatest value.
  /// @return  Offset of greatest value.
  size_t max_index() const { return w_max_index(&v()); }

  /// Offset of least value.
  /// @return  Offset of least value.
  size_t min_index() const { return w_min_index(&v()); }

  /// Offset of least value and offset of greatest value.
  /// @param imin  On return, offset of least value.
  /// @param imax  On return, offset of greatest value.
  void minmax_index(size_t &imin, size_t &imax) const {
    w_minmax_index(&v(), &imin, &imax);
  }

  /// True only if every element have zero value.
  /// @return  True only if every element be zero.
  bool isnull() const { return w_isnull(&v()); }

  /// True only if every element be positive.
  /// @return  True only if every element be positive.
  bool ispos() const { return w_ispos(&v()); }

  /// True only if every element be negative.
  /// @return  True only if every element be negative.
  bool isneg() const { return w_isneg(&v()); }

  /// True only if every element be non-negative.
  /// @return  True only if every element be non-negative.
  bool isnonneg() const { return w_isnonneg(&v()); }
};


/// Test equality of two vectors.
/// @tparam U  Type of one descendant of v_iface.
/// @tparam V  Type of other descendant of v_iface.
/// @param u  Reference to one vector.
/// @param v  Reference to other vector.
/// @return  True only if vectors be equal.
template<typename U, typename V>
bool operator==(v_iface<U> const &u, v_iface<V> const &v) {
  return equal(u, v);
}


/// Test inequality of two vectors.
/// @tparam U  Type of one descendant of v_iface.
/// @tparam V  Type of other descendant of v_iface.
/// @param u  Reference to one vector.
/// @param v  Reference to other vector.
/// @return  True only if vectors be unequal.
template<typename U, typename V>
bool operator!=(v_iface<U> const &u, v_iface<V> const &v) {
  return !equal(u, v);
}


/// Print vector to output-stream.
/// @tparam U  Type of descendant of v_iface.
/// @param os  Reference to output-stream.
/// @param u  Reference to vector.
/// @return  Reference to modified output-stream.
template<typename U>
std::ostream &operator<<(std::ostream &os, v_iface<U> const &u) {
  os << "[";
  int const last= int(u.size()) - 1;
  for(int i= 0; i < last; ++i) os << u[i] << ",";
  if(last >= 0) os << u[last];
  os << "]";
  return os;
}


/// Linearly combine vector `x` into vector `y` in place.
/// @tparam T  Type of storage for first vector.
/// @tparam U  Type of storage for second vector.
/// @param alpha  Coeffient of `x`.
/// @param x  First vector (source).
/// @param beta  Coefficient of `y`.
/// @param y  Second vector and (source and destination).
/// @return  TBD: GSL's documentation does not specify.
template<typename T, typename U>
int axpby(
      typename T::E const &alpha,
      v_iface<T> const &x,
      typename U::E const &beta,
      v_iface<U> &y) {
  return w_axpby(alpha, &x.v(), beta, &y.v());
}


/// Test equality of two vectors.
/// @tparam S1  Type of storage for one vector.
/// @tparam S2  Type of storage for other vector.
/// @param v1  Reference to one vector.
/// @param v2  Reference to other vector.
/// @return  True only if vectors be equal.
template<typename S1, typename S2>
bool equal(v_iface<S1> const &v1, v_iface<S2> const &v2) {
  return w_equal(&v1.v(), &v2.v());
}


/// Copy data from source, whose length must be same as that of destination.
/// @tparam T  Type of descendant of v_iface for destination.
/// @tparam U  Type of descendant of v_iface for source.
/// @param dst  Destination.
/// @param src  Source.
/// @return  TBD: GSL's documentation does not specify.
template<typename T, typename U>
int memcpy(v_iface<T> &dst, v_iface<U> const &src) {
  return w_memcpy(&dst.v(), &src.v());
}


/// Swap contents of one and other vector, each with same length.
/// @tparam S1  Type of storage for one vector.
/// @tparam S2  Type of storage for other vector.
/// @param v1  One vector.
/// @param v2  Other vector.
/// @return  TBD: GSL's documentation does not specify.
template<typename S1, typename S2> int swap(v_iface<S1> &v1, v_iface<S2> &v2) {
  return w_swap(&v1.v(), &v2.v());
}


} // namespace gsl

// EOF