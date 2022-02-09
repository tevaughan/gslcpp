/// @file       include/gslcpp/vec-iface.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vec_iface.

#pragma once

#include "vec-base.hpp"
#include "vec-iterator.hpp"
#include <type_traits> // enable_if_t, is_const_v

namespace gsl {


using std::enable_if_t;
using std::is_const_v;
using std::is_same_v;


/// Interface for every kind of vector.
/// @tparam D  Type of descendant of `vec_iface<D>`.
template<typename D> struct vec_iface: public vec_base {
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

  /// Pointer to descendant's C-interface gsl_vector.
  auto &vec() { return static_cast<D *>(this)->v(); }

  /// Pointer to descendant's immutable C-interface gsl_vector.
  auto const &vec() const { return static_cast<D const *>(this)->v(); }

  /// Size of vector.
  /// @return  Size of vector.
  size_t size() const { return vec().size; }

  /// Stride of vector in memory.
  /// @return  Stride of vector.
  size_t stride() const { return vec().stride; }

  /// Pointer to first element in vector.
  /// @return  Pointer to first element.
  double *data() { return vec().data; }

  /// Pointer to first element in immutable vector.
  /// @return  Pointer to first immutable element.
  double const *data() const { return vec().data; }

  /// Read element with bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Value of element.
  double get(size_t i) const { return gsl_vector_get(&vec(), i); }

  /// Write element with bounds-checking.
  /// @parameter i  Offset of element.
  /// @parameter x  New value for element.
  void set(size_t i, double x) { gsl_vector_set(&vec(), i, x); }

  /// Read element without bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Reference to immutable element.
  double const &operator[](size_t i) const { return data()[i * stride()]; }

  /// Write element without bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Reference to mutable element.
  double &operator[](size_t i) { return data()[i * stride()]; }

  /// Retrieve pointer to `i`th element with bounds-checking.
  /// - This could be useful if stride unknown.
  /// @parameter i  Offset of element.
  /// @return  Pointer to mutable element.
  double *ptr(size_t i) { return gsl_vector_ptr(&vec(), i); }

  /// Retrieve pointer with bounds-checking.
  /// - This could be useful if stride unknown.
  /// @parameter i  Offset of element.
  /// @return  Pointer to immutable element.
  double const *ptr(size_t i) const { return gsl_vector_const_ptr(&vec(), i); }

  /// Set every element.
  /// @param x  Value to which each element should be set.
  void set_all(double x) { gsl_vector_set_all(&vec(), x); }

  /// Set every element to zero.
  void set_zero() { gsl_vector_set_zero(&vec()); }

  /// Set element at offset `i` to unity and every other element to zero.
  /// @param i  Offset of element set to unity.
  /// @return  TBD.
  int set_basis(size_t i) { return gsl_vector_set_basis(&vec(), i); }

  /// Write non-portable binary image of vector to file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fwrite(FILE *f) const { return gsl_vector_fwrite(f, &vec()); }

  /// Read non-portable binary image of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fread(FILE *f) { return gsl_vector_fread(f, &vec()); };

  /// Write ASCII-formatted representation of vector to file.
  /// @param flp  Pointer to structure for buffered interface.
  /// @param fmt  printf()-style format-string.
  /// @return  Zero only on success.
  int fprintf(FILE *flp, char const *fmt) const {
    return gsl_vector_fprintf(flp, &vec(), fmt);
  }

  /// Read ASCII-formatted representation of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fscanf(FILE *f) { return gsl_vector_fscanf(f, &vec()); }

  /// View of subvector of vector.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_subvector_with_stride().
  /// - Putting initial offset and stride at end allows each to have good
  ///   default (0 for initial offset and 1 for stride).
  /// @param n  Number of elements in view.
  /// @param i  Offset in vector of first element in view.
  /// @param s  Stride of view relative to vector.
  view<double> subvector(size_t n, size_t i= 0, size_t s= 1);

  /// View of immutable subvector of vector.
  /// - Arguments are reordered from those given to
  ///   gsl_vector_const_subvector_with_stride().
  /// - Putting initial offset and stride at end allows each to have good
  ///   default (0 for initial offset and 1 for stride).
  /// @param n  Number of elements in view.
  /// @param i  Offset in vector of first element in view.
  /// @param s  Stride of view relative to current vector.
  view<double const> subvector(size_t n, size_t i= 0, size_t s= 1) const;

  /// Swap elements within this vector.
  /// @param i  Offset of one element.
  /// @param j  Offset of other element.
  /// @return  TBD.
  int swap_elements(size_t i, size_t j) {
    return gsl_vector_swap_elements(&vec(), i, j);
  }

  /// Reverse order of elements.
  /// @return  TBD.
  int reverse() { return gsl_vector_reverse(&vec()); }

  /// Add contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be added into this.
  /// @param b  Vector whose contents should be added into this.
  /// @return  TBD.
  template<typename T> int add(vec_iface<T> const &b) {
    return gsl_vector_add(&vec(), &b.vec());
  }

  /// Subtract contents of `b` from this vector in place.
  /// @tparam T  Type of vector to be subtracted from this.
  /// @param b  Vector whose contents should be subtracted from this.
  /// @return  TBD.
  template<typename T> int sub(vec_iface<T> const &b) {
    return gsl_vector_sub(&vec(), &b.vec());
  }

  /// Multiply contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be multiplied into this.
  /// @param b  Vector whose contents should be multiplied into this.
  /// @return  TBD.
  template<typename T> int mul(vec_iface<T> const &b) {
    return gsl_vector_mul(&vec(), &b.vec());
  }

  /// Divide contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be divided into this.
  /// @param b  Vector whose contents should be divided into this.
  /// @return  TBD.
  template<typename T> int div(vec_iface<T> const &b) {
    return gsl_vector_div(&vec(), &b.vec());
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
  int scale(double x) { return gsl_vector_scale(&vec(), x); }

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
  int add_constant(double x) { return gsl_vector_add_constant(&vec(), x); }

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
  double sum() const { return gsl_vector_sum(&vec()); }
#endif

  /// Greatest value of any element.
  /// @return  Greatest value of any element.
  double max() const { return gsl_vector_max(&vec()); }

  /// Least value of any element.
  /// @return  Least value of any element.
  double min() const { return gsl_vector_min(&vec()); }

  /// Greatest value and least value of any element.
  /// @param min_out  On return, least value.
  /// @param max_out  On return, greatest value.
  void minmax(double &min_out, double &max_out) const {
    gsl_vector_minmax(&vec(), &min_out, &max_out);
  }

  /// Offset of greatest value.
  /// @return  Offset of greatest value.
  size_t max_index() const { return gsl_vector_max_index(&vec()); }

  /// Offset of least value.
  /// @return  Offset of least value.
  size_t min_index() const { return gsl_vector_min_index(&vec()); }

  /// Offset of least value and offset of greatest value.
  /// @param imin  On return, offset of least value.
  /// @param imax  On return, offset of greatest value.
  void minmax_index(size_t &imin, size_t &imax) const {
    gsl_vector_minmax_index(&vec(), &imin, &imax);
  }

  /// True only if every element have zero value.
  /// @return  True only if every element be zero.
  bool isnull() const { return gsl_vector_isnull(&vec()); }

  /// True only if every element be positive.
  /// @return  True only if every element be positive.
  bool ispos() const { return gsl_vector_ispos(&vec()); }

  /// True only if every element be negative.
  /// @return  True only if every element be negative.
  bool isneg() const { return gsl_vector_isneg(&vec()); }

  /// True only if every element be non-negative.
  /// @return  True only if every element be non-negative.
  bool isnonneg() const { return gsl_vector_isnonneg(&vec()); }
};


} // namespace gsl

// EOF
