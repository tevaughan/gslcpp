/// @file       gsl/vec-iface.hpp
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
  using iterator= vec_iterator<vec_iface, double>;
  using const_iterator= vec_iterator<vec_iface const, double const>;

  iterator begin() { return iterator(*this, 0); }
  iterator end() { return iterator(*this, size()); }
  const_iterator begin() const { return const_iterator(*this, 0); }
  const_iterator end() const { return const_iterator(*this, size()); }

  /// Pointer to descendant's C-interface gsl_vector.
  gsl_vector *p() { return static_cast<D *>(this)->pv(); }

  /// Pointer to descendant's immutable C-interface gsl_vector.
  gsl_vector const *p() const { return static_cast<D const *>(this)->pv(); }

  /// Size of vector.
  /// @return  Size of vector.
  size_t size() const { return p()->size; }

  /// Stride of vector in memory.
  /// @return  Stride of vector.
  size_t stride() const { return p()->stride; }

  /// Pointer to first element in vector.
  /// @return  Pointer to first element.
  double *data() { return p()->data; }

  /// Pointer to first element in immutable vector.
  /// @return  Pointer to first immutable element.
  double const *data() const { return p()->data; }

  /// Pointer to first element of block containing vector's data.
  /// @return  Pointer to first element of block containing vector's data.
  gsl_block const *block() const { return p()->block; }

  /// Nonzero only if instance own its data.
  /// @return  Nonzero only if instance own its data.
  int owner() const { return p()->owner; }

  /// Read element with bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Value of element.
  double get(size_t i) const { return gsl_vector_get(p(), i); }

  /// Write element with bounds-checking.
  /// @parameter i  Offset of element.
  /// @parameter x  New value for element.
  void set(size_t i, double x) { gsl_vector_set(p(), i, x); }

  /// Read element without bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Reference to immutable element.
  double const &operator[](size_t i) const { return data()[i * stride()]; }

  /// Write element without bounds-checking.
  /// @parameter i  Offset of element.
  /// @return  Reference to mutable element.
  double &operator[](size_t i) { return data()[i * stride()]; }

  /// Retrieve pointer with bounds-checking.
  /// - This could be useful if stride unknown.
  /// @parameter i  Offset of element.
  /// @return  Pointer to mutable element.
  double *ptr(size_t i) { return gsl_vector_ptr(p(), i); }

  /// Retrieve pointer with bounds-checking.
  /// - This could be useful if stride unknown.
  /// @parameter i  Offset of element.
  /// @return  Pointer to immutable element.
  double const *ptr(size_t i) const { return gsl_vector_const_ptr(p(), i); }

  /// Set every element.
  /// @param x  Value to which each element should be set.
  void set_all(double x) { gsl_vector_set_all(p(), x); }

  /// Set every element to zero.
  void set_zero() { gsl_vector_set_zero(p()); }

  /// Set element at offset `i` to unity and every other element to zero.
  /// @param i  Offset of element set to unity.
  /// @return  TBD.
  int set_basis(size_t i) { return gsl_vector_set_basis(p(), i); }

  /// Write non-portable binary image of vector to file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fwrite(FILE *f) const { return gsl_vector_fwrite(f, p()); }

  /// Read non-portable binary image of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fread(FILE *f) { return gsl_vector_fread(f, p()); };

  /// Write ASCII-formatted representation of vector to file.
  /// @param flp  Pointer to structure for buffered interface.
  /// @param fmt  printf()-style format-string.
  /// @return  Zero only on success.
  int fprintf(FILE *flp, char const *fmt) const {
    return gsl_vector_fprintf(flp, p(), fmt);
  }

  /// Read ASCII-formatted representation of vector from file.
  /// @param f  Pointer to structure for buffered interface.
  /// @return  Zero only on success.
  int fscanf(FILE *f) { return gsl_vector_fscanf(f, p()); }

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
  view<double const> subvector(size_t n, size_t i=0, size_t s= 1) const;

  /// Swap elements within this vector.
  /// @param i  Offset of one element.
  /// @param j  Offset of other element.
  /// @return  TBD.
  int swap_elements(size_t i, size_t j) {
    return gsl_vector_swap_elements(p(), i, j);
  }

  /// Reverse order of elements.
  /// @return  TBD.
  int reverse() { return gsl_vector_reverse(p()); }

  /// Add contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be added into this.
  /// @param b  Vector whose contents should be added into this.
  /// @return  TBD.
  template<typename T> int add(vec_iface<T> const &b) {
    return gsl_vector_add(p(), b.p());
  }

  /// Subtract contents of `b` from this vector in place.
  /// @tparam T  Type of vector to be subtracted from this.
  /// @param b  Vector whose contents should be subtracted from this.
  /// @return  TBD.
  template<typename T> int sub(vec_iface<T> const &b) {
    return gsl_vector_sub(p(), b.p());
  }

  /// Multiply contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be multiplied into this.
  /// @param b  Vector whose contents should be multiplied into this.
  /// @return  TBD.
  template<typename T> int mul(vec_iface<T> const &b) {
    return gsl_vector_mul(p(), b.p());
  }

  /// Divide contents of `b` into this vector in place.
  /// @tparam T  Type of vector to be divided into this.
  /// @param b  Vector whose contents should be divided into this.
  /// @return  TBD.
  template<typename T> int div(vec_iface<T> const &b) {
    return gsl_vector_div(p(), b.p());
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
  int scale(double x) { return gsl_vector_scale(p(), x); }

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
  int add_constant(double x) { return gsl_vector_add_constant(p(), x); }

  /// Add constant into each element of this vector in place.
  /// @param x  Constant to add into this vector.
  /// @return  Reference to this vector after modification.
  vec_iface &operator+=(double x) {
    add_constant(x);
    return *this;
  }

  /// Sum of elements.
  /// @return  Sum of elements.
  double sum() const { return gsl_vector_sum(p()); }

  /// Greatest value of any element.
  /// @return  Greatest value of any element.
  double max() const { return gsl_vector_max(p()); }

  /// Least value of any element.
  /// @return  Least value of any element.
  double min() const { return gsl_vector_min(p()); }

  /// Greatest value and least value of any element.
  /// @param min_out  On return, least value.
  /// @param max_out  On return, greatest value.
  void minmax(double &min_out, double &max_out) const {
    gsl_vector_minmax(p(), &min_out, &max_out);
  }

  /// Offset of greatest value.
  /// @return  Offset of greatest value.
  size_t max_index() const { return gsl_vector_max_index(p()); }

  /// Offset of least value.
  /// @return  Offset of least value.
  size_t min_index() const { return gsl_vector_min_index(p()); }

  /// Offset of least value and offset of greatest value.
  /// @param imin  On return, offset of least value.
  /// @param imax  On return, offset of greatest value.
  void minmax_index(size_t &imin, size_t &imax) {
    gsl_vector_minmax_index(p(), &imin, &imax);
  }

  /// True only if every element have zero value.
  /// @return  True only if every element be zero.
  bool isnull() const { return gsl_vector_isnull(p()); }

  /// True only if every element be positive.
  /// @return  True only if every element be positive.
  bool ispos() const { return gsl_vector_ispos(p()); }

  /// True only if every element be negative.
  /// @return  True only if every element be negative.
  bool isneg() const { return gsl_vector_isneg(p()); }

  /// True only if every element be non-negative.
  /// @return  True only if every element be non-negative.
  bool isnonneg() const { return gsl_vector_isnonneg(p()); }
};


} // namespace gsl

// EOF
