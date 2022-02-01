/// @file       gsl/vec-iterator.hpp
/// @copyright  2022 Thomas E. Vaughan, all rights reserved.
/// @brief      Definition for gsl::vec_iterator.

#pragma once

#include <iterator>

namespace gsl {


/// @tparam VI  Either `vec_iface` or `vec_iface const`.
/// @tparam VT  Either `double` or `double const`.
template<typename VI, typename VT> class vec_iterator {
public:
  using difference_type= std::ptrdiff_t;

private:
  VI &vi_;
  difference_type off_;

public:
  using pointer= VT *;
  using value_type= VT;
  using reference= VT &;
  using iterator_category= std::random_access_iterator_tag;

  vec_iterator(VI &vi, difference_type off): vi_(vi), off_(off) {}

  reference operator*() const { return vi_[off_]; }
  pointer operator->() { return &vi_[off_]; }
  reference operator[](difference_type i) { return vi_[off_ + i]; }

  /// Prefix-increment.
  vec_iterator &operator++() {
    ++off_;
    return *this;
  }

  /// Postfix-increment.
  vec_iterator operator++(int) {
    vec_iterator tmp= *this;
    ++(*this); // Call prefix-increment!
    return tmp;
  }

  /// Prefix-decrement.
  vec_iterator &operator--() {
    --off_;
    return *this;
  }

  /// Postfix-increment.
  vec_iterator operator--(int) {
    vec_iterator tmp= *this;
    --(*this); // Call prefix-decrement!
    return tmp;
  }

  vec_iterator &operator+=(difference_type n) {
    off_+= n;
    return *this;
  }

  vec_iterator &operator-=(difference_type n) {
    off_-= n;
    return *this;
  }

  friend vec_iterator operator+(vec_iterator i, difference_type n) {
    i+= n;
    return i;
  }

  friend vec_iterator operator+(difference_type n, vec_iterator i) {
    return i + n;
  }

  friend vec_iterator operator-(vec_iterator i, difference_type n) {
    i-= n;
    return i;
  }

  friend difference_type operator-(vec_iterator j, vec_iterator i) {
    if(&j.vi_ != &i.vi_) throw "Each iterator refers to different base.";
    return (j.off_ - i.off_);
  }

  friend bool operator==(vec_iterator const &a, vec_iterator const &b) {
    return a.off_ == b.off_;
  }

  friend bool operator!=(vec_iterator const &a, vec_iterator const &b) {
    return a.off_ != b.off_;
  }

  friend bool operator<(vec_iterator const &a, vec_iterator const &b) {
    return a.off_ < b.off_;
  }

  friend bool operator>(vec_iterator const &a, vec_iterator const &b) {
    return a.off_ > b.off_;
  }

  friend bool operator<=(vec_iterator const &a, vec_iterator const &b) {
    return a.off_ <= b.off_;
  }

  friend bool operator>=(vec_iterator const &a, vec_iterator const &b) {
    return a.off_ >= b.off_;
  }
};


} // namespace gsl

// EOF
