/// @file       include/gslcpp/vec-iface.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vec_iface.

#pragma once

// Use inline-definition of each accessor-function.
// - Define this before including `gsl_vector.h`.
#ifndef HAVE_INLINE
#  define HAVE_INLINE
#endif

#include "size-code.hpp" // VIEW
#include "vec-iterator.hpp" // vec_iterator
#include <gsl/gsl_vector.h> // gsl_vector_view, gsl_vector_const_view
#include <iostream> // ostream

namespace gsl {


template<int S, typename T> class vector; // Forward declaration.


/// Interface for every kind of vector.
/// @tparam D  Type of descendant of `vec_iface<D>` (according to CRTP).
template<typename D> struct vec_iface {
  /// Type of iterator that points to mutable element.
  using iterator= vec_iterator<vec_iface>;

  /// Type of iterator that points to immutable element.
  using const_iterator= vec_iterator<vec_iface const>;

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
  size_t size() const { return v_().size; }

  /// Pointer to first element in vector.
  /// - Be careful to check `v().stride` in case data be not contiguous.
  /// @return  Pointer to first element.
  double *data() { return v_().data; }

  /// Pointer to first element in immutable vector.
  /// - Be careful to check `v().stride` in case data be not contiguous.
  /// @return  Pointer to first immutable element.
  double const *data() const { return v_().data; }

  /// Read element with bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Value of element.
  double get(size_t i) const { return gsl_vector_get(&v_(), i); }

  /// Write element with bounds-checking.
  /// @parameter i  Offset of element.
  /// @parameter x  New value for element.
  void set(size_t i, double x) { gsl_vector_set(&v_(), i, x); }

  /// Read element without bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Reference to immutable element.
  double const &operator[](size_t i) const { return data()[i * v_().stride]; }

  /// Write element without bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Reference to mutable element.
  double &operator[](size_t i) { return data()[i * v_().stride]; }

  /// Retrieve pointer to `i`th element with bounds-checking.
  /// - This could be useful if stride unknown.
  /// @parameter i  Offset of element.
  /// @return  Pointer to mutable element.
  double *ptr(size_t i) { return gsl_vector_ptr(&v_(), i); }

  /// Retrieve pointer to `i`th element with bounds-checking.
  /// - This could be useful if stride unknown.
  /// @parameter i  Offset of element.
  /// @return  Pointer to immutable element.
  double const *ptr(size_t i) const { return gsl_vector_const_ptr(&v_(), i); }

  /// Set every element.
  /// @param x  Value to which each element should be set.
  void set_all(double x) { gsl_vector_set_all(&v_(), x); }

  /// Set every element to zero.
  void set_zero() { gsl_vector_set_zero(&v_()); }

  /// Set element at offset `i` to unity and every other element to zero.
  /// @param i  Offset of element set to unity.
  /// @return  TBD.
  int set_basis(size_t i) { return gsl_vector_set_basis(&v_(), i); }

  /// Write non-portable binary image of vector to file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fwrite(FILE *f) const { return gsl_vector_fwrite(f, &v_()); }

  /// Read non-portable binary image of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fread(FILE *f) { return gsl_vector_fread(f, &v_()); };

  /// Write ASCII-formatted representation of vector to file.
  /// @param flp  Pointer to structure for buffered interface.
  /// @param fmt  printf()-style format-string.
  /// @return  Zero only on success.
  int fprintf(FILE *flp, char const *fmt) const {
    return gsl_vector_fprintf(flp, &v_(), fmt);
  }

  /// Read ASCII-formatted representation of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fscanf(FILE *f) { return gsl_vector_fscanf(f, &v_()); }

  /// View of subvector of vector.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows each to have good
  ///   default (0 for initial offset and 1 for stride).
  /// @param n  Number of elements in view.
  /// @param i  Offset in vector of first element in view.
  /// @param s  Stride of view relative to vector.
  vector<VIEW, double> subvector(size_t n, size_t i= 0, size_t s= 1);

  /// View of immutable subvector of vector.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_const_subvector_with_stride().
  /// - Putting initial offset and stride at end allows each to have good
  ///   default (0 for initial offset and 1 for stride).
  /// @param n  Number of elements in view.
  /// @param i  Offset in vector of first element in view.
  /// @param s  Stride of view relative to current vector.
  vector<VIEW, double const>
  subvector(size_t n, size_t i= 0, size_t s= 1) const;

  /// Swap elements within this vector.
  /// @param i  Offset of one element.
  /// @param j  Offset of other element.
  /// @return  TBD.
  int swap_elements(size_t i, size_t j) {
    return gsl_vector_swap_elements(&v_(), i, j);
  }

  /// Reverse order of elements.
  /// @return  TBD.
  int reverse() { return gsl_vector_reverse(&v_()); }

  /// Add contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be added into this.
  /// @param b  Vector whose contents should be added into this.
  /// @return  TBD.
  template<typename T> int add(vec_iface<T> const &b) {
    return gsl_vector_add(&v_(), &b.v_());
  }

  /// Subtract contents of `b` from this vector in place.
  /// @tparam T  Type of vector to be subtracted from this.
  /// @param b  Vector whose contents should be subtracted from this.
  /// @return  TBD.
  template<typename T> int sub(vec_iface<T> const &b) {
    return gsl_vector_sub(&v_(), &b.v_());
  }

  /// Multiply contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be multiplied into this.
  /// @param b  Vector whose contents should be multiplied into this.
  /// @return  TBD.
  template<typename T> int mul(vec_iface<T> const &b) {
    return gsl_vector_mul(&v_(), &b.v_());
  }

  /// Divide contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be divided into this.
  /// @param b  Vector whose contents should be divided into this.
  /// @return  TBD.
  template<typename T> int div(vec_iface<T> const &b) {
    return gsl_vector_div(&v_(), &b.v_());
  }

  /// Add contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be added into this.
  /// @param b  Vector whose contents should be added into this.
  /// @return  Reference to this vector after modification.
  template<typename T> vec_iface &operator+=(vec_iface<T> const &b) {
    add(b);
    return *this;
  }

  /// Subtract contents of `b` from this vector in place.
  /// @tparam T  Type of vector to be subtracted from this.
  /// @param b  Vector whose contents should be subtracted from this.
  /// @return  Reference to this vector after modification.
  template<typename T> vec_iface &operator-=(vec_iface<T> const &b) {
    sub(b);
    return *this;
  }

  /// Multiply contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be multiplied into this.
  /// @param b  Vector whose contents should be multiplied into this.
  /// @return  Reference to this vector after modification.
  template<typename T> vec_iface &operator*=(vec_iface<T> const &b) {
    mul(b);
    return *this;
  }

  /// Divide contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be divided into this.
  /// @param b  Vector whose contents should be divided into this.
  /// @return  Reference to this vector after modification.
  template<typename T> vec_iface &operator/=(vec_iface<T> const &b) {
    div(b);
    return *this;
  }

  /// Multiply scalar into this vector in place.
  /// @param x  Scalar to multiply into this.
  /// @return  TBD.
  int scale(double x) { return gsl_vector_scale(&v_(), x); }

  /// Multiply scalar into this vector in place.
  /// @param x  Scalar to multiply into this.
  /// @return  Reference to this vector after modification.
  vec_iface &operator*=(double x) {
    scale(x);
    return *this;
  }

  /// Add constant into each element of this vector in place.
  /// @param x  Constant to add into this vector.
  /// @return  TBD.
  int add_constant(double x) { return gsl_vector_add_constant(&v_(), x); }

  /// Add constant into each element of this vector in place.
  /// @param x  Constant to add into this vector.
  /// @return  Reference to this vector after modification.
  vec_iface &operator+=(double x) {
    add_constant(x);
    return *this;
  }

#if defined(GSL_VER) && GSL_VER > 26
  /// Sum of elements.
  /// @return  Sum of elements.
  double sum() const { return gsl_vector_sum(&v_()); }
#endif

  /// Greatest value of any element.
  /// @return  Greatest value of any element.
  double max() const { return gsl_vector_max(&v_()); }

  /// Least value of any element.
  /// @return  Least value of any element.
  double min() const { return gsl_vector_min(&v_()); }

  /// Greatest value and least value of any element.
  /// @param min_out  On return, least value.
  /// @param max_out  On return, greatest value.
  void minmax(double &min_out, double &max_out) const {
    gsl_vector_minmax(&v_(), &min_out, &max_out);
  }

  /// Offset of greatest value.
  /// @return  Offset of greatest value.
  size_t max_index() const { return gsl_vector_max_index(&v_()); }

  /// Offset of least value.
  /// @return  Offset of least value.
  size_t min_index() const { return gsl_vector_min_index(&v_()); }

  /// Offset of least value and offset of greatest value.
  /// @param imin  On return, offset of least value.
  /// @param imax  On return, offset of greatest value.
  void minmax_index(size_t &imin, size_t &imax) const {
    gsl_vector_minmax_index(&v_(), &imin, &imax);
  }

  /// True only if every element have zero value.
  /// @return  True only if every element be zero.
  bool isnull() const { return gsl_vector_isnull(&v_()); }

  /// True only if every element be positive.
  /// @return  True only if every element be positive.
  bool ispos() const { return gsl_vector_ispos(&v_()); }

  /// True only if every element be negative.
  /// @return  True only if every element be negative.
  bool isneg() const { return gsl_vector_isneg(&v_()); }

  /// True only if every element be non-negative.
  /// @return  True only if every element be non-negative.
  bool isnonneg() const { return gsl_vector_isnonneg(&v_()); }

#if defined(GSL_VER) && GSL_VER > 26
  template<typename T, typename U>
  friend int
  axpby(double alpha, vec_iface<T> const &x, double beta, vec_iface<U> &y);
#endif

  template<typename T, typename U>
  friend bool equal(vec_iface<T> const &u, vec_iface<U> const &v);

  template<typename T, typename U>
  friend int memcpy(vec_iface<T> &dst, vec_iface<U> const &src);

  template<typename T, typename U>
  friend int swap(vec_iface<T> &v, vec_iface<U> &w);

private:
  /// Pointer to descendant's C-interface gsl_vector.
  auto &v_() { return static_cast<D *>(this)->v(); }

  /// Pointer to descendant's immutable C-interface gsl_vector.
  auto const &v_() const { return static_cast<D const *>(this)->v(); }
};


/// Test equality of two vectors.
/// @tparam U  Type of one descendant of vec_iface.
/// @tparam V  Type of other descendant of vec_iface.
/// @param u  Reference to one vector.
/// @param v  Reference to other vector.
/// @return  True only if vectors be equal.
template<typename U, typename V>
bool operator==(vec_iface<U> const &u, vec_iface<V> const &v) {
  return equal(u, v);
}


/// Test inequality of two vectors.
/// @tparam U  Type of one descendant of vec_iface.
/// @tparam V  Type of other descendant of vec_iface.
/// @param u  Reference to one vector.
/// @param v  Reference to other vector.
/// @return  True only if vectors be unequal.
template<typename U, typename V>
bool operator!=(vec_iface<U> const &u, vec_iface<V> const &v) {
  return !equal(u, v);
}


/// Print vector to output-stream.
/// @tparam U  Type of descendant of vec_iface.
/// @param os  Reference to output-stream.
/// @param u  Reference to vector.
/// @return  Reference to modified output-stream.
template<typename U>
std::ostream &operator<<(std::ostream &os, vec_iface<U> const &u) {
  os << "[";
  int const last= int(u.size()) - 1;
  for(int i= 0; i < last; ++i) os << u[i] << ",";
  if(last >= 0) os << u[last];
  os << "]";
  return os;
}


#if defined(GSL_VER) && GSL_VER > 26
/// Linearly combine vector `x` into vector `y` in place.
/// @tparam T  Type of descendant of vec_iface for first vector.
/// @tparam U  Type of descendant of vec_iface for second vector.
/// @param a  Coeffient of `x`.
/// @param x  First vector (source).
/// @param b  Coefficient of `y`.
/// @param y  Second vector and (source and destination).
/// @return  TBD.
template<typename T, typename U>
int axpby(double alpha, vec_iface<T> const &x, double beta, vec_iface<U> &y) {
  return gsl_vector_axpby(alpha, &x.v_(), beta, &y.v_());
}
#endif


/// Test equality of two vectors.
/// @tparam T  Type of one descendant of vec_iface.
/// @tparam U  Type of other descendant of vec_iface.
/// @param u  Reference to one vector.
/// @param v  Reference to other vector.
/// @return  True only if vectors be equal.
template<typename T, typename U>
bool equal(vec_iface<T> const &t, vec_iface<U> const &u) {
  return gsl_vector_equal(&t.v_(), &u.v_());
}


/// Copy data from source, whose length must be same as that of destination.
/// @tparam T  Type of descendant of vec_iface for destination.
/// @tparam U  Type of descendant of vec_iface for source.
/// @param dst  Destination.
/// @param src  Source.
/// @return  TBD.
template<typename T, typename U>
int memcpy(vec_iface<T> &dst, vec_iface<U> const &src) {
  return gsl_vector_memcpy(&dst.v_(), &src.v_());
}


/// Swap contents of one and other vector, each with same length.
/// @tparam T  Type of one descendant of vec_iface.
/// @tparam U  Type of other descendant of vec_iface.
/// @param t  One vector.
/// @param u  Other vector.
/// @return  TBD.
template<typename T, typename U> int swap(vec_iface<T> &t, vec_iface<U> &u) {
  return gsl_vector_swap(&t.v_(), &u.v_());
}


} // namespace gsl

// EOF
