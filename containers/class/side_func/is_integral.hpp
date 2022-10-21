#pragma once

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

# include "enable_if.hpp"

/*
**	Is_integral
**
**	Checks whether T is an integral type. Provides the member constant value which is equal to true,
**	if T is the type bool, char, char16_t, char32_t, wchar_t, short, int, long, long long
**	or any implementation-defined extended integer types, including any signed, unsigned
**	and cv-qualified variants. Otherwise, value is equal to false.
**	The behavior of a program that adds specializations for is_integral is undefined.
*/

namespace ft {

	template <class T>
	struct is_integral : public ft::false_type {};

	template <>
	struct is_integral<bool> : public ft::true_type {};

	template <>
	struct is_integral<char> : public ft::true_type {};

	template <>
	struct is_integral<signed char> : public ft::true_type {};

	template <>
	struct is_integral<unsigned char> : public ft::true_type {};

	template <>
	struct is_integral<wchar_t> : public ft::true_type {};

	template <>
	struct is_integral<char16_t> : public ft::true_type {};

	template <>
	struct is_integral<char32_t> : public ft::true_type {};

	template <>
	struct is_integral<short> : public ft::true_type {};

	template <>
	struct is_integral<unsigned short> : public ft::true_type {};

	template <>
	struct is_integral<int> : public ft::true_type {};

	template <>
	struct is_integral<unsigned int> : public ft::true_type {};

	template <>
	struct is_integral<long> : public ft::true_type {};

	template <>
	struct is_integral<unsigned long> : public ft::true_type {};

	template <>
	struct is_integral<long long> : public ft::true_type {};

	template <>
	struct is_integral<unsigned long long> : public ft::true_type {};

} // namespace ft

#endif /* IS_INTEGRAL_HPP */
