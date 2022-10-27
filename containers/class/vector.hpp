#pragma once

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "iterators/iterator_traits.hpp"
# include "iterators/reverse_iterator.hpp"
# include "side_func/enable_if.hpp"
# include "side_func/equal.hpp"
# include "side_func/is_integral.hpp"
# include "side_func/lexicographical_compare.hpp"

# include <iostream>
# include <sstream>

namespace ft {

	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

			/**********************************/
			/*****      MEMBER TYPES      *****/
			/**********************************/

			typedef T											value_type;
			typedef Allocator									allocator_type;

			typedef ft::iterator_traits<T>						iterator;
			typedef ft::iterator_traits<const T>				const_iterator;

			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		reverse_const_iterator;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;

			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;



			/************************************/
			/*****      MEMBER CLASSES      *****/
			/************************************/





		private:

			/**************************************/
			/*****      MEMBER ATTRIBUTES     *****/
			/**************************************/

			allocator_type	_alloc;
			pointer			_data;
			size_type		_size;
			size_type		_capacity;

		public:

			/**************************************/
			/*****      MEMBER FUNCTIONS      *****/
			/**************************************/



			/*
			**	Constructors
			**
			**	Constructs a new container from a variety of data sources,
			**	optionally using a user supplied allocator alloc.
			**		1) Default constructor. Constructs an empty container with a default-constructed allocator.
			**		2) Constructs an empty container with the given allocator alloc.
			**		3) Constructs the container with count copies of elements with value value.
			**		4) Constructs the container with the contents of the range [first, last).
			**		5) Copy constructor. Constructs the container with the copy of the contents of other.
			*/

			vector()
				: _alloc(), _data(NULL), _size(0), _capacity(0) {
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_data + i, value_type());
			};

			explicit vector( const Allocator& alloc )
				: _alloc(alloc), _data(NULL), _size(0), _capacity(0) {
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_data + i, value_type());
			};

			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() )
				: _alloc(alloc), _capacity(count), _size(0) {
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(_data + i, value);
				_size = _capacity;
			};

			template< class InputIt >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ) {
				_alloc = alloc;
				_size = 0;
				_capacity = 0;
				_data = _alloc.allocate(_capacity);
				for (InputIt it = first; it != last; it++) {
					push_back(*it);
				}
			};

			vector( const vector& other ) {
				_alloc = other._alloc;
				_size = other._size;
				_capacity = other._capacity;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(_data + i, other._data[i]);
			};


			/*
			**	Destructor
			**
			**	Destructs the vector. The destructors of the elements are called
			**	and the used storage is deallocated. Note, that if the elements are pointers,
			**	the pointed-to objects are not destroyed.
			*/

			~vector() {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				_alloc.deallocate(_data, _capacity);
			};


			/*
			**	Operator=
			**
			**	Replaces the contents of the container.
			**	Copy assignment operator. Replaces the contents with a copy of the contents of other.
			*/

			vector& operator=( const vector& other ) {
				if (this != &other) {
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(_data + i);
					_alloc.deallocate(_data, _capacity);
					_alloc = other._alloc;
					_size = other._size;
					_capacity = other._capacity;
					_data = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(_data + i, other._data[i]);
				}
				return *this;
			};


			/*
			**	Assign
			**
			**	Replaces the contents of the container.
			**		1) Replaces the contents with count copies of value value
			**		2) Replaces the contents with copies of those in the range [first, last).
			**	The behavior is undefined if either argument is an iterator into *this.
			**	This overload has the same effect as overload (1) if InputIt is an integral type.
			**	All iterators, pointers and references to the elements of the container are invalidated.
			**	The past-the-end iterator is also invalidated.
			*/

			void assign( size_type count, const T& value ) {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				_alloc.deallocate(_data, _capacity);
				_size = 0;
				_capacity = count;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(_data + i, value);
				_size = _capacity;
			};

			template< class InputIt >
			void assign( InputIt first, InputIt last ) {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				_alloc.deallocate(_data, _capacity);
				_size = 0;
				_capacity = 0;
				_data = _alloc.allocate(_capacity);
				for (InputIt it = first; it != last; it++) {
					push_back(*it);
				}
			};


			/*
			**	Get_allocator
			**
			**	Returns the allocator associated with the container.
			*/

			allocator_type get_allocator() const {
				return _alloc;
			};



			/************************************/
			/*****      ELEMENT ACCESS      *****/
			/************************************/



			/*
			**	At
			**
			**	Returns a reference to the element at specified location pos, with bounds checking.
			**	If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
			*/

			reference at( size_type pos ) {
			range_check(pos);
				return _data[pos];
			};

			const_reference at( size_type pos ) const {
			range_check(pos);
				return _data[pos];
			};

		private:
			void	range_check(size_type pos) {
				std::ostringstream c_n;
				std::ostringstream c_size;

				c_n << pos;
				c_size << _size;
				if (pos >= _size)
					throw std::out_of_range(
						std::string("vector::_M_range_check: __n ") + \
						std::string("(which is ") + c_n.str() + \
						std::string(") >= this->size() (which is ") + \
						c_size.str() + std::string(")"));
			}

		public:
			/*
			**	Operator []
			**
			**	Returns a reference to the element at specified location pos.
			**	No bounds checking is performed.
			*/

			reference operator[]( size_type pos ) {
				return _data[pos];
			};

			const_reference operator[]( size_type pos ) const {
				return _data[pos];
			};


			/*
			**	Front
			**
			**	Returns a reference to the first element in the container.
			**	Calling front on an empty container is undefined.
			*/

			reference front() {
				return _data[0];
			};

			const_reference front() const {
				return _data[0];
			};


			/*
			**	Back
			**
			**	Returns a reference to the last element in the container.
			**	Calling back on an empty container causes undefined behavior.
			*/

			reference back() {
				return _data[_size - 1];
			};

			const_reference back() const {
				return _data[_size - 1];
			};


			/*
			**	Data
			**
			**	Returns pointer to the underlying array serving as element storage.
			**	The pointer is such that range [data(); data()+size()) is always
			**	a valid range, even if the container is empty (data() is not
			**	dereferenceable in that case).
			*/

			T* data() {
				return _data;
			};

			const T* data() const {
				return _data;
			};



			/******************************/
			/*****      ITERATOR      *****/
			/******************************/



			/*
			**	Begin
			**
			**	Returns an iterator to the first element of the vector.
			**	If the vector is empty, the returned iterator will be equal to end().
			*/

			iterator begin() {
				return iterator(_data);
			};

			const_iterator begin() const {
				return const_iterator(_data);
			};


			/*
			**	End
			**
			**	Returns an iterator to the element following the last element of the vector.
			**	This element acts as a placeholder; attempting to access it results in undefined behavior.
			*/

			iterator end() {
				return iterator(_data + _size);
			};

			const_iterator end() const {
				return const_iterator(_data + _size);
			};


			/*
			**	Rbegin
			**
			**	Returns a reverse iterator to the first element of the reversed vector.
			**	It corresponds to the last element of the non-reversed vector.
			**	If the vector is empty, the returned iterator is equal to rend().
			*/

			reverse_iterator rbegin() {
				return reverse_iterator(_data + _size - 1);
			};

			reverse_const_iterator rbegin() const {
				return reverse_const_iterator(_data + _size - 1);
			};


			/*
			**	Rend
			**
			**	Returns a reverse iterator to the element following the last element of the reversed vector.
			**	It corresponds to the element preceding the first element of the non-reversed vector.
			**	This element acts as a placeholder, attempting to access it results in undefined behavior.
			*/

			reverse_iterator rend() {
				return reverse_iterator(_data - 1);
			};

			reverse_const_iterator rend() const {
				return reverse_const_iterator(_data - 1);
			};



			/******************************/
			/*****      CAPACITY      *****/
			/******************************/



			/*
			**	Empty
			**
			**	Checks if the container has no elements, i.e. whether begin() == end().
			*/

			bool empty() const {
				return _size == 0;
			};


			/*
			**	Size
			**
			**	Returns the number of elements in the container, i.e. std::distance(begin(), end()).
			*/

			size_type size() const {
				return _size;
			};


			/*
			**	Max_size
			**
			**	Returns the maximum number of elements the container is able to hold
			**	due to system or library implementation limitations,
			**	i.e. std::distance(begin(), end()) for the largest container.
			*/

			size_type max_size() const;


			/*
			**	Reserve
			**
			**	Increase the capacity of the vector (the total number of elements
			**	that the vector can hold without requiring reallocation) to a value
			**	that's greater or equal to new_cap. If new_cap is greater than
			**	the current capacity(), new storage is allocated, otherwise the function does nothing.
			**	reserve() does not change the size of the vector.
			**	If new_cap is greater than capacity(), all iterators,
			**	including the past-the-end iterator, and all references to the
			**	elements are invalidated. Otherwise, no iterators or references are invalidated.
			*/

			void reserve( size_type new_cap ) {
				if (new_cap > _capacity) {
					_capacity = new_cap;
					_data = _alloc.allocate(_capacity);
				}
			};


			/*
			**	Capacity
			**
			**	Returns the number of elements that the container has currently allocated space for.
			*/

			size_type capacity() const {
				return _capacity;
			};



			/*******************************/
			/*****      MODIFIERS      *****/
			/*******************************/



			/*
			**	Clear
			**
			**	Erases all elements from the container. After this call, size() returns zero.
			**	Invalidates any references, pointers, or iterators referring to contained elements.
			**	Any past-the-end iterators are also invalidated.
			**	Leaves the capacity() of the vector unchanged (note: the standard's
			**	restriction on the changes to capacity is in the specification of vector::reserve).
			*/

			void clear() {
				_size = 0;
			};


			/*
			**	Insert
			**
			**	Inserts elements at the specified location in the container.
			**	Causes reallocation if the new size() is greater than the old capacity().
			**	If the new size() is greater than capacity(), all iterators and references are invalidated.
			**	Otherwise, only the iterators and references before the insertion point remain valid.
			**	The past-the-end iterator is also invalidated.
			*/

			iterator insert( const_iterator pos, const T& value ) {
				if (_size == _capacity) {
					_capacity *= 2;
					_data = _alloc.allocate(_capacity);
				}
				_size++;
				iterator it = iterator(_data + _size - 1);
				while (it != pos) {
					*it = *(it - 1);
					it--;
				}
				*it = value;
				return it;
			};

			iterator insert( const_iterator pos, size_type count, const T& value ) {
				if (_size + count > _capacity) {
					_capacity = _size + count;
					_data = _alloc.allocate(_capacity);
				}
				_size += count;
				iterator it = iterator(_data + _size - 1);
				while (it != pos) {
					*it = *(it - count);
					it--;
				}
				while (it != pos + count) {
					*it = value;
					it++;
				}
				return it;
			};

			template< class InputIt >
			iterator insert( const_iterator pos, InputIt first, InputIt last ) {
				size_type count = 0;
				for (InputIt it = first; it != last; it++) {
					count++;
				}
				if (_size + count > _capacity) {
					_capacity = _size + count;
					_data = _alloc.allocate(_capacity);
				}
				_size += count;
				iterator it = iterator(_data + _size - 1);
				while (it != pos) {
					*it = *(it - count);
					it--;
				}
				while (it != pos + count) {
					*it = *first;
					it++;
					first++;
				}
				return it;
			};


			/*
			**	Erase
			**
			**	Erases the specified elements from the container.
			**		1) Removes the element at pos.
			**		2) Removes the elements in the range [first, last).
			**	Invalidates iterators and references at or after the point of the erase, including the end() iterator.
			**	The iterator pos must be valid and dereferenceable.
			**	Thus the end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for pos.
			**	The iterator first does not need to be dereferenceable if first == last: erasing an empty range is a no-op.
			*/

			iterator erase( iterator pos ) {
				iterator it = pos;
				while (it != end()) {
					*it = *(it + 1);
					it++;
				}
				_size--;
				return pos;
			};

			iterator erase( iterator first, iterator last ) {
				iterator it = first;
				while (it != last) {
					*it = *(it + (last - first));
					it++;
				}
				_size -= (last - first);
				return first;
			};


			/*
			**	Push_back
			**
			**	Appends the given element value to the end of the container.
			**		1) The new element is initialized as a copy of value.
			**		2) value is moved into the new element.
			**	If the new size() is greater than capacity() then all iterators
			**	and references (including the past-the-end iterator) are invalidated.
			**	Otherwise only the past-the-end iterator is invalidated.
			*/

			void push_back( const T& value ) {
				if (_size == _capacity) {
					_capacity *= 2;
					_data = _alloc.allocate(_capacity);
				}
				_data[_size] = value;
				_size++;
			};


			/*
			**	Pop_back
			**
			**	Removes the last element of the container.
			**	Calling pop_back on an empty container results in undefined behavior.
			**	Iterators and references to the last element, as well as the end() iterator, are invalidated.
			*/

			void pop_back() {
				_size--;
			};


			/*
			**	Resize
			**
			**	Resizes the container to contain count elements.
			**	If the current size is greater than count, the container is reduced to its first count elements.
			**	If the current size is less than count,
			**		1) additional default-inserted elements are appended
			**		2) additional copies of value are appended.
			*/

			void resize( size_type count, T value = T() ) {
				if (count > _size) {
					if (count > _capacity) {
						_capacity = count;
						_data = _alloc.allocate(_capacity);
					}
					for (size_type i = _size; i < count; i++) {
						_data[i] = value;
					}
				}
				_size = count;
			};


			/*
			**	Swap
			**
			**	Exchanges the contents of the container with those of other.
			**	Does not invoke any move, copy, or swap operations on individual elements.
			**	All iterators and references remain valid. The past-the-end iterator is invalidated.
			*/

			void swap( vector& other ) {
				allocator_type tmp_alloc = _alloc;
				_alloc = other._alloc;
				other._alloc = tmp_alloc;
				pointer tmp_data = _data;
				_data = other._data;
				other._data = tmp_data;
				size_type tmp_size = _size;
				_size = other._size;
				other._size = tmp_size;
				size_type tmp_capacity = _capacity;
				_capacity = other._capacity;
				other._capacity = tmp_capacity;
			};
	};

	/******************************************/
	/*****      NON-MEMBER FUNCTIONS      *****/
	/******************************************/



	/*
	**	Operators
	**
	**	Compares the contents of two vectors.
	**		1-2) Checks if the contents of lhs and rhs are equal, that is,
	**		 they have the same number of elements and each element in lhs compares equal
	**		 with the element in rhs at the same position.
	**		3-6) Compares the contents of lhs and rhs lexicographically.
	**		 The comparison is performed by a function equivalent to std::lexicographical_compare.
	*/

	//	Operator==
	template< class T, class Alloc >
	bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ) {
		if (lhs.size() != rhs.size()) {
			return false;
		}
		for (size_t i = 0; i < lhs.size(); i++) {
			if (lhs[i] != rhs[i]) {
				return false;
			}
		}
		return true;
	};

	//	Operator!=
	template< class T, class Alloc >
	bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ) {
		return !(lhs == rhs);
	};

	//	Operator<
	template< class T, class Alloc >
	bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ) {
		if (lhs.size() < rhs.size()) {
			return true;
		}
		for (size_t i = 0; i < lhs.size(); i++) {
			if (lhs[i] < rhs[i]) {
				return true;
			}
		}
		return false;
	};

	//	Operator<=
	template< class T, class Alloc >
	bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ) {
		return !(rhs < lhs);
	};

	//	Operator>
	template< class T, class Alloc >
	bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ) {
		return (rhs < lhs);
	};

	//	Operator>=
	template< class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ) {
		return !(lhs < rhs);
	};

	/*
	**	Swap
	**
	**	Specializes the std::swap algorithm for std::vector. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
	*/

	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs ) {
		lhs.swap(rhs);
	};

} // namespace ft

#endif /* VECTOR_HPP */
