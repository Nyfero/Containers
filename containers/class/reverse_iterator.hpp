#pragma once

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <cstddef>
# include <iterator>
# include "iterator_traits.hpp"

namespace ft {

    template <class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator								iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
            typedef typename ft::iterator_traits<Iterator>::reference			reference;

        protected:
            Iterator	_current;

        public:
            reverse_iterator() : _current() {}
            explicit reverse_iterator(iterator_type it) : _current(it) {}
            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter>& rev_it) : _current(rev_it.base()) {}
            reverse_iterator& operator=(const reverse_iterator& rev_it)
            {
                if (this != &rev_it)
                    _current = rev_it._current;
                return *this;
            }
            ~reverse_iterator() {}

            iterator_type	base() const { return _current; }

            reference		operator*() const
            {
                Iterator tmp = _current;
                return *--tmp;
            }
            pointer			operator->() const { return &(operator*()); }

            reverse_iterator&	operator++()
            {
                --_current;
                return *this;
            }
            reverse_iterator	operator++(int)
            {
                reverse_iterator tmp = *this;
                --_current;
                return tmp;
            }
            reverse_iterator&	operator--()
            {
                ++_current;
                return *this;
            }
            reverse_iterator	operator--(int)
            {
                reverse_iterator tmp = *this;
                ++_current;
                return tmp;
            }

            reverse_iterator	operator+(difference_type n) const { return reverse_iterator(_current - n); }
            reverse_iterator&	operator+=(difference_type n)
            {
                _current -= n;
                return *this;
            }
            reverse_iterator	operator-(difference_type n) const { return reverse_iterator(_current + n); }
            reverse_iterator&	operator-=(difference_type n)
            {
                _current += n;
                return *this;
            }

            reference			operator[](difference_type n) const { return *(*this + n); }
    };

    template <class Iterator>
    bool	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>&rhs) { return lhs.base() == rhs.base(); }

    template <class Iterator>
    bool	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>&rhs) { return lhs.base() != rhs.base(); }

    template <class Iterator>
    bool	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>&rhs) { return lhs.base() > rhs.base(); }

    template <class Iterator>
    bool	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>&rhs) { return lhs.base() >= rhs.base(); }

    template <class Iterator>
    bool	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>&rhs) { return lhs.base() < rhs.base(); }

    template <class Iterator>
    bool	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>&rhs) { return lhs.base() <= rhs.base(); }

    template <class Iterator>
    reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) { return reverse_iterator<Iterator>(rev_it.base() - n); }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return rhs.base() - lhs.base(); }

} // namespace ft

#endif // REVERSE_ITERATOR_HPP