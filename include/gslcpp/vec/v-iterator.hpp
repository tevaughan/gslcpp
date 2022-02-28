/// \file       include/gslcpp/vec/v-iterator.hpp
/// \copyright  2022 Thomas E. Vaughan, all rights reserved.
/// \brief      Definition for gsl::v_iterator.

#pragma once

#include <iterator> // random_access_iterator_tag

namespace gsl {


/// Iterator for v_iface.  There is no `operator->` because element is always
/// of type double.  Even if vector actually have non-const elements, const
/// vector is treated as having const elements.
/// @tparam V  Either v_iface or v_iface const.
template<typename V> class v_iterator {
public:
  /// Type of difference of two iterators.
  using difference_type= std::ptrdiff_t;

private:
  V &vi_; ///< Reference to instance of container.
  difference_type off_; ///< Current offset pointed to in container.

  // Make each type of iterator be a friend to the other.
  template<typename OV> friend class v_iterator;

  /// Throw exception if each of two iterators point into different vector.
  /// @tparam B  Type of vector for second iterator.
  /// @param b  Second iterator.
  template<typename B> void check_same_vector(v_iterator<B> const &b) const {
    if(&vi_ != &b.vi_) {
      throw std::runtime_error("iterators for different vectors");
    }
  }

  /// Generic declaration for struct that gives type of vector's element.  Even
  /// if vector actually have non-const elements, const vector is treated as
  /// having const elements.
  /// @tparam is_const  True for constant-type element.
  template<bool is_const> struct element;

  /// Specialization for constant type of element of vector.  Even if vector
  /// actually have non-const elements, const vector is treated as having const
  /// elements.
  template<> struct element<true> { using type= double const; };

  /// Specialization for non-constant type of element for vector.  Even if
  /// vector actually have non-const elements, const vector is treated as
  /// having const elements.
  template<> struct element<false> { using type= double; };

  /// Type of element for vector.  Even if vector actually have non-const
  /// elements, const vector is treated as having const elements.
  using E= typename element<std::is_const_v<V>>::type;

public:
  using pointer= E *; ///< Type of pointer to element in container.
  using value_type= E; ///< Type of element in container.
  using reference= E &; ///< Type of reference to element in container.

  /// Indicate, to standard library, that iterator is random-access.
  using iterator_category= std::random_access_iterator_tag;

  /// Construct instance of iterator.
  /// @param vi  Reference to container of element pointed to.
  /// @param off  Offset of element pointed to in container.
  v_iterator(V &vi, difference_type off): vi_(vi), off_(off) {}

  /// Dereference iterator.
  /// @return  Reference to element pointed to by iterator.
  reference operator*() const { return vi_[off_]; }

  /// Dereference element at offset from element pointed to by iterator.
  /// @param i  Offset from element pointed to by iterator.
  /// @return  Reference to element at offset `i` from current element.
  reference operator[](difference_type i) const { return vi_[off_ + i]; }

  /// Increment offset of element pointed to.
  /// @return  Reference to this instance after increment of offset.
  v_iterator &operator++() {
    ++off_;
    return *this;
  }

  /// Increment offset of element pointed to.
  /// @return  Copy of this instance made before increment of offset.
  v_iterator operator++(int) {
    v_iterator tmp= *this;
    ++(*this); // Call prefix-increment!
    return tmp;
  }

  /// Decrement offset of element pointed to.
  /// @return  Reference to this instance after decrement of offset.
  v_iterator &operator--() {
    --off_;
    return *this;
  }

  /// Decrement offset of element pointed to.
  /// @return  Copy of this instance made before decrement of offset.
  v_iterator operator--(int) {
    v_iterator tmp= *this;
    --(*this); // Call prefix-decrement!
    return tmp;
  }

  /// For positive `n`, increase, by `n`, offset of element pointed to.  This
  /// is like fast forward in place for an iterator.  Do nothing when `n == 0`.
  /// Actually decrease offset when `n < 0`.
  /// @param n  Number by which to increase offset.
  /// @return  Reference to this instance after increase of offset.
  v_iterator &operator+=(difference_type n) {
    off_+= n;
    return *this;
  }

  /// For positive `n`, decrease, by `n`, offset of element pointed to.  This
  /// is like fast reverse in place for an iterator.  Do nothing when `n == 0`.
  /// Actually increase offset when `n < 0`.
  /// @param n  Number by which to decrease offset.
  /// @return  Reference to this instance after decrease of offset.
  v_iterator &operator-=(difference_type n) {
    off_-= n;
    return *this;
  }

  /// Produce new iterator at offset greater than that of existing iterator.
  /// This is like fast forward for an iterator.
  /// @param i  Iterator.
  /// @param n  Offset.
  /// @return  Iterator whose internal offset is `n` more than that of `i`.
  friend v_iterator operator+(v_iterator i, difference_type n) {
    i+= n;
    return i;
  }

  /// Produce new iterator at offset greater than that of existing iterator.
  /// This is like fast forward for an iterator.
  /// @param n  Offset.
  /// @param i  Iterator.
  /// @return  Iterator whose internal offset is `n` more than that of `i`.
  friend v_iterator operator+(difference_type n, v_iterator i) {
    return i + n;
  }

  /// Produce new iterator at offset less than that of existing iterator.  This
  /// is like fast reverse for an iterator.
  /// @param i  Iterator.
  /// @param n  Offset.
  /// @return  Iterator whose internal offset is `n` less than that of `i`.
  friend v_iterator operator-(v_iterator i, difference_type n) {
    i-= n;
    return i;
  }

  /// Difference in offset between two iterators.  Throw runtime_error if
  /// iterators do not point into same vector.
  /// @tparam I  Type of vector for iterator with offset to subtract.
  /// @param i  Iterator with offset to subtract.
  /// @return  Difference between offset of this iterator and offset of `i`.
  template<typename I>
  difference_type operator-(v_iterator<I> const &i) const {
    check_same_vector(i);
    return off_ - i.off_;
  }

  /// Compare two iterators for equality.  Throw runtime_error if iterators do
  /// not point into same vector.
  /// @tparam B  Type of vector for second iterator.
  /// @param b  Second iterator.
  /// @return  True only if this and second iterator point to same element.
  template<typename B> bool operator==(v_iterator<B> const &b) const {
    check_same_vector(b);
    return off_ == b.off_;
  }

  /// Compare two iterators for inequality.  Throw runtime_error if iterators
  /// do not point into same vector.
  /// @tparam B  Type of vector for second iterator.
  /// @param b  Second iterator.
  /// @return  True only if this and second do not point to same element.
  template<typename B> bool operator!=(v_iterator<B> const &b) const {
    check_same_vector(b);
    return off_ != b.off_;
  }

  /// Compare two iterators for ordering.  Throw runtime_error if iterators do
  /// not point into same vector.
  /// @tparam B  Type of vector for second iterator.
  /// @param b  Second iterator.
  /// @return  True only if this iterator point to element earlier in vector
  ///          than element pointed to by second iterator.
  template<typename B> bool operator<(v_iterator<B> const &b) const {
    check_same_vector(b);
    return off_ < b.off_;
  }

  /// Compare two iterators for ordering.  Throw runtime_error if iterators do
  /// not point into same vector.
  /// @tparam B  Type of vector for second iterator.
  /// @param b  Second iterator.
  /// @return  True only if this iterator point to element later in vector
  ///          than element pointed to by second iterator.
  template<typename B> bool operator>(v_iterator<B> const &b) const {
    check_same_vector(b);
    return off_ > b.off_;
  }

  /// Compare two iterators for ordering.  Throw runtime_error if iterators do
  /// not point into same vector.
  /// @tparam B  Type of vector for second iterator.
  /// @param b  Second iterator.
  /// @return  True only if this iterator point to element either same as or
  ///          earlier in vector than element pointed to by second iterator.
  template<typename B> bool operator<=(v_iterator<B> const &b) const {
    check_same_vector(b);
    return off_ <= b.off_;
  }

  /// Compare two iterators for ordering.  Throw runtime_error if iterators do
  /// not point into same vector.
  /// @tparam B  Type of vector for second iterator.
  /// @param b  Second iterator.
  /// @return  True only if this iterator point to element either same as or
  ///          later in vector than element pointed to by second iterator.
  template<typename B> bool operator>=(v_iterator<B> const &b) const {
    check_same_vector(b);
    return off_ >= b.off_;
  }
};


} // namespace gsl

// EOF
