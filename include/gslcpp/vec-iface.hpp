/// @file       include/gslcpp/vec-iface.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vec_iface.

#pragma once

#include "c-iface.hpp" // c_iface
#include "vec-iterator.hpp" // vec_iterator
#include "vec-view.hpp" // vec_view
#include <gsl/gsl_vector.h> // gsl_vector_view, gsl_vector_const_view
#include <iostream> // ostream

namespace gsl {


using std::same_as;


// Forward declaration.
template<typename T> class vector_v;


template<typename T> concept vec= requires(T &x, T const &y) {
  typename T::elem;
  { x.v() } -> same_as<typename c_iface<typename T::elem>::vec &>;
  { y.v() } -> same_as<typename c_iface<typename T::elem>::vec const &>;
};


/// Interface for every kind of vector.
/// @tparam D  Type referring to storage of elements.
template<vec D> struct vec_iface: public D {
  /// Inherit constructors.
  using D::D;

  /// Inherit assigment.
  using D::operator=;

  /// Type of each element.
  using typename D::elem;

  /// Reference to gsl_vector.
  using D::v;

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
  size_t size() const { return v().size; }

  /// Pointer to first element in vector.
  /// - Be careful to check `v().stride` in case data be not contiguous.
  /// @return  Pointer to first element.
  elem *data() { return v().data; }

  /// Pointer to first element in immutable vector.
  /// - Be careful to check `v().stride` in case data be not contiguous.
  /// @return  Pointer to first immutable element.
  elem const *data() const { return v().data; }

  /// Read element with bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Value of element.
  elem get(size_t i) const { return gsl_vector_get(&v(), i); }

  /// Write element with bounds-checking.
  /// @parameter i  Offset of element.
  /// @parameter x  New value for element.
  void set(size_t i, elem const &x) { gsl_vector_set(&v(), i, x); }

  /// Read element without bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Reference to immutable element.
  elem const &operator[](size_t i) const { return data()[i * v().stride]; }

  /// Write element without bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Reference to mutable element.
  elem &operator[](size_t i) { return data()[i * v().stride]; }

  /// Retrieve pointer to `i`th element with bounds-checking.
  /// - This could be useful if stride unknown.
  /// @parameter i  Offset of element.
  /// @return  Pointer to mutable element.
  elem *ptr(size_t i) {
    if constexpr(std::is_const_v<elem>) {
      return gsl_vector_const_ptr(&v(), i);
    } else {
      return gsl_vector_ptr(&v(), i);
    }
  }

  /// Retrieve pointer to `i`th element with bounds-checking.
  /// - This could be useful if stride unknown.
  /// @parameter i  Offset of element.
  /// @return  Pointer to immutable element.
  elem const *ptr(size_t i) const { return gsl_vector_const_ptr(&v(), i); }

  /// Set every element.
  /// @param x  Value to which each element should be set.
  void set_all(elem const &x) { gsl_vector_set_all(&v(), x); }

  /// Set every element to zero.
  void set_zero() { gsl_vector_set_zero(&v()); }

  /// Set element at offset `i` to unity and every other element to zero.
  /// @param i  Offset of element set to unity.
  /// @return  TBD.
  int set_basis(size_t i) { return gsl_vector_set_basis(&v(), i); }

  /// Write non-portable binary image of vector to file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fwrite(FILE *f) const { return gsl_vector_fwrite(f, &v()); }

  /// Read non-portable binary image of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fread(FILE *f) { return gsl_vector_fread(f, &v()); };

  /// Write ASCII-formatted representation of vector to file.
  /// @param flp  Pointer to structure for buffered interface.
  /// @param fmt  printf()-style format-string.
  /// @return  Zero only on success.
  int fprintf(FILE *flp, char const *fmt) const {
    return gsl_vector_fprintf(flp, &v(), fmt);
  }

  /// Read ASCII-formatted representation of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fscanf(FILE *f) { return gsl_vector_fscanf(f, &v()); }

  /// View of subvector of vector.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows each to have good
  ///   default (0 for initial offset and 1 for stride).
  /// @param n  Number of elements in view.
  /// @param i  Offset in vector of first element in view.
  /// @param s  Stride of view relative to vector.
  /// @return  View of subvector.
  vec_iface<vec_view<elem>> subvector(size_t n, size_t i= 0, size_t s= 1) {
    return c_iface<elem>::subvector(&v(), i, s, n);
  }

  /// View of subvector of vector.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows each to have good
  ///   default (0 for initial offset and 1 for stride).
  /// @param n  Number of elements in view.
  /// @param i  Offset in vector of first element in view.
  /// @param s  Stride of view relative to vector.
  /// @return  View of subvector.
  vec_iface<vec_view<elem const>>
  subvector(size_t n, size_t i= 0, size_t s= 1) const {
    return c_iface<elem const>::subvector(&v(), i, s, n);
  }

  /// View of vector.
  /// @return  View of vector.
  vec_iface<vec_view<elem>> view() {
    return c_iface<elem>::subvector(&v(), 0, 1, size());
  }

  /// View of vector.
  /// @return  View of vector.
  vec_iface<vec_view<elem const>> view() const {
    return c_iface<elem const>::subvector(&v(), 0, 1, size());
  }

  /// Swap elements within this vector.
  /// @param i  Offset of one element.
  /// @param j  Offset of other element.
  /// @return  TBD.
  int swap_elements(size_t i, size_t j) {
    return gsl_vector_swap_elements(&v(), i, j);
  }

  /// Reverse order of elements.
  /// @return  TBD.
  int reverse() { return gsl_vector_reverse(&v()); }

  /// Add contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be added into this.
  /// @param b  Vector whose contents should be added into this.
  /// @return  TBD.
  template<typename T> int add(vec_iface<T> const &b) {
    return gsl_vector_add(&v(), &b.v());
  }

  /// Subtract contents of `b` from this vector in place.
  /// @tparam T  Type of vector to be subtracted from this.
  /// @param b  Vector whose contents should be subtracted from this.
  /// @return  TBD.
  template<typename T> int sub(vec_iface<T> const &b) {
    return gsl_vector_sub(&v(), &b.v());
  }

  /// Multiply contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be multiplied into this.
  /// @param b  Vector whose contents should be multiplied into this.
  /// @return  TBD.
  template<typename T> int mul(vec_iface<T> const &b) {
    return gsl_vector_mul(&v(), &b.v());
  }

  /// Divide contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be divided into this.
  /// @param b  Vector whose contents should be divided into this.
  /// @return  TBD.
  template<typename T> int div(vec_iface<T> const &b) {
    return gsl_vector_div(&v(), &b.v());
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
  int scale(elem const &x) { return gsl_vector_scale(&v(), x); }

  /// Multiply scalar into this vector in place.
  /// @param x  Scalar to multiply into this.
  /// @return  Reference to this vector after modification.
  vec_iface &operator*=(elem const &x) {
    scale(x);
    return *this;
  }

  /// Add constant into each element of this vector in place.
  /// @param x  Constant to add into this vector.
  /// @return  TBD.
  int add_constant(elem const &x) { return gsl_vector_add_constant(&v(), x); }

  /// Add constant into each element of this vector in place.
  /// @param x  Constant to add into this vector.
  /// @return  Reference to this vector after modification.
  vec_iface &operator+=(elem const &x) {
    add_constant(x);
    return *this;
  }

#if defined(GSL_VER) && GSL_VER > 26
  /// Sum of elements.
  /// @return  Sum of elements.
  elem sum() const { return gsl_vector_sum(&v()); }
#endif

  /// Greatest value of any element.
  /// @return  Greatest value of any element.
  elem max() const { return gsl_vector_max(&v()); }

  /// Least value of any element.
  /// @return  Least value of any element.
  elem min() const { return gsl_vector_min(&v()); }

  /// Greatest value and least value of any element.
  /// @param min_out  On return, least value.
  /// @param max_out  On return, greatest value.
  void minmax(elem &min_out, elem &max_out) const {
    gsl_vector_minmax(&v(), &min_out, &max_out);
  }

  /// Offset of greatest value.
  /// @return  Offset of greatest value.
  size_t max_index() const { return gsl_vector_max_index(&v()); }

  /// Offset of least value.
  /// @return  Offset of least value.
  size_t min_index() const { return gsl_vector_min_index(&v()); }

  /// Offset of least value and offset of greatest value.
  /// @param imin  On return, offset of least value.
  /// @param imax  On return, offset of greatest value.
  void minmax_index(size_t &imin, size_t &imax) const {
    gsl_vector_minmax_index(&v(), &imin, &imax);
  }

  /// True only if every element have zero value.
  /// @return  True only if every element be zero.
  bool isnull() const { return gsl_vector_isnull(&v()); }

  /// True only if every element be positive.
  /// @return  True only if every element be positive.
  bool ispos() const { return gsl_vector_ispos(&v()); }

  /// True only if every element be negative.
  /// @return  True only if every element be negative.
  bool isneg() const { return gsl_vector_isneg(&v()); }

  /// True only if every element be non-negative.
  /// @return  True only if every element be non-negative.
  bool isnonneg() const { return gsl_vector_isnonneg(&v()); }

#if defined(GSL_VER) && GSL_VER > 26
  template<typename T, typename U>
  friend int axpby(
    element_t const &alpha,
    vec_iface<T> const &x,
    element_t const &beta,
    vec_iface<U> &y);
#endif

  template<typename T, typename U>
  friend bool equal(vec_iface<T> const &u, vec_iface<U> const &v);

  template<typename T, typename U>
  friend int memcpy(vec_iface<T> &dst, vec_iface<U> const &src);

  template<typename T, typename U>
  friend int swap(vec_iface<T> &v, vec_iface<U> &w);
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
int axpby(
  typename T::element_t const &alpha,
  vec_iface<T> const &x,
  typename U::element_t const &beta,
  vec_iface<U> &y) {
  return gsl_vector_axpby(alpha, &x.v(), beta, &y.v());
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
  return gsl_vector_equal(&t.v(), &u.v());
}


/// Copy data from source, whose length must be same as that of destination.
/// @tparam T  Type of descendant of vec_iface for destination.
/// @tparam U  Type of descendant of vec_iface for source.
/// @param dst  Destination.
/// @param src  Source.
/// @return  TBD.
template<typename T, typename U>
int memcpy(vec_iface<T> &dst, vec_iface<U> const &src) {
  return gsl_vector_memcpy(&dst.v(), &src.v());
}


/// Swap contents of one and other vector, each with same length.
/// @tparam T  Type of one descendant of vec_iface.
/// @tparam U  Type of other descendant of vec_iface.
/// @param t  One vector.
/// @param u  Other vector.
/// @return  TBD.
template<typename T, typename U> int swap(vec_iface<T> &t, vec_iface<U> &u) {
  return gsl_vector_swap(&t.v(), &u.v());
}


} // namespace gsl

// EOF
