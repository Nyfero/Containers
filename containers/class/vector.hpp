#pragma once

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <string>
# include <iostream>
# include <iomanip>

namespace ft {
	
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			// T										value_type;
			// Allocator								allocator_type;
			// std::size_t								size_type;
			// std::ptrdiff_t							difference_type;
			// value_type &							reference;
			// const value_type &						const_reference;
			// Allocator::pointer						pointer;
			// Allocator::const_pointer				const_pointer;
			// value_type								iterator;
			// const value_type						const_iterator;
			// std::reverse_iterator<iterator>			reverse_iterator;
			// std::reverse_iterator<const_iterator>	reverse_const_iterator;
		
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
			
			vector();
			
			explicit vector( const Allocator& alloc );
			
			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator());
			
			template< class InputIt >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
			
			vector( const vector& other );
			
			
			/*
			**	Destructor
			**
			**	Destructs the vector. The destructors of the elements are called
			**	and the used storage is deallocated. Note, that if the elements are pointers,
			**	the pointed-to objects are not destroyed. 
			*/
			
			~vector();
			
			
			/*
			**	Operator=
			**
			**	Replaces the contents of the container.
			**	Copy assignment operator. Replaces the contents with a copy of the contents of other.
			*/
			
			vector& operator=( const vector& other );
			
			
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
			
			void assign( size_type count, const T& value );
			
			template< class InputIt >
			void assign( InputIt first, InputIt last );
			
			
			/*
			**	Get_allocator
			**
			**	Returns the allocator associated with the container.
			*/
			
			allocator_type get_allocator() const;
			
			
			
			/************************************/
			/*****      ELEMENT ACCESS      *****/
			/************************************/
			
			
			
			/*
			**	At
			**
			**	Returns a reference to the element at specified location pos, with bounds checking.
			**	If pos is not within the range of the container, an exception of type std::out_of_range is thrown.
			*/
			
			reference at( size_type pos );
			
			const_reference at( size_type pos ) const;
			
			
			/*
			**	Operator []
			**
			**	Returns a reference to the element at specified location pos.
			**	No bounds checking is performed.
			*/
			
			reference operator[]( size_type pos );
			
			const_reference operator[]( size_type pos ) const;
			
			
			/*
			**	Front
			**
			**	Returns a reference to the first element in the container.
			**	Calling front on an empty container is undefined.
			*/
			
			reference front();
			
			const_reference front() const;
			
			
			/*
			**	Back
			**
			**	Returns a reference to the last element in the container.
			**	Calling back on an empty container causes undefined behavior.
			*/
			
			reference back();
			
			const_reference back() const;
			
			
			/*
			**	Data
			**
			**	Returns pointer to the underlying array serving as element storage.
			**	The pointer is such that range [data(); data()+size()) is always
			**	a valid range, even if the container is empty (data() is not 
			**	dereferenceable in that case).
			*/
			
			T* data();
			
			const T* data() const;
			
			
			
			/******************************/
			/*****      ITERATOR      *****/
			/******************************/
			
			
			
			/*
			**	Begin
			**
			**	Returns an iterator to the first element of the vector.
			**	If the vector is empty, the returned iterator will be equal to end().
			*/
			
			iterator begin();
			
			const_iterator begin() const;
			
			
			/*
			**	End
			**
			**	Returns an iterator to the element following the last element of the vector.
			**	This element acts as a placeholder; attempting to access it results in undefined behavior.
			*/
			
			iterator end();
			
			const_iterator end() const;
			
			
			/*
			**	Rbegin
			**
			**	Returns a reverse iterator to the first element of the reversed vector.
			**	It corresponds to the last element of the non-reversed vector.
			**	If the vector is empty, the returned iterator is equal to rend(). 
			*/
			
			reverse_iterator rbegin();
			
			const_reverse_iterator rbegin() const;
			
			
			/*
			**	Rend
			**
			**	Returns a reverse iterator to the element following the last element of the reversed vector.
			**	It corresponds to the element preceding the first element of the non-reversed vector.
			**	This element acts as a placeholder, attempting to access it results in undefined behavior.
			*/
			
			reverse_iterator rend();
			
			const_reverse_iterator rend() const;
			
			
			
			/******************************/
			/*****      CAPACITY      *****/
			/******************************/
			
			
			
			/*
			**	Empty
			**
			**	Checks if the container has no elements, i.e. whether begin() == end().
			*/
			
			bool empty() const;
			
			
			/*
			**	Size
			**
			**	Returns the number of elements in the container, i.e. std::distance(begin(), end()).
			*/
			
			size_type size() const;
			
			
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
			
			void reserve( size_type new_cap );
			
			
			/*
			**	Capacity
			**
			**	Returns the number of elements that the container has currently allocated space for. 
			*/
			
			size_type capacity() const;
			
			
			
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
			
			void clear();
			
			
			/*
			**	Insert
			**
			**	Inserts elements at the specified location in the container.
			**	Causes reallocation if the new size() is greater than the old capacity().
			**	If the new size() is greater than capacity(), all iterators and references are invalidated.
			**	Otherwise, only the iterators and references before the insertion point remain valid.
			**	The past-the-end iterator is also invalidated.
			*/
			
			iterator insert( const_iterator pos, const T& value );
			
			iterator insert( const_iterator pos, size_type count, const T& value );
			
			constexpr iterator insert( const_iterator pos, size_type count, const T& value );
			
			template< class InputIt >
			iterator insert( const_iterator pos, InputIt first, InputIt last );
			
			
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
			
			iterator erase( iterator pos );
			
			iterator erase( iterator first, iterator last );
			
			
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
			
			void push_back( const T& value );
			
			
			/*
			**	Pop_back
			**
			**	Removes the last element of the container.
			**	Calling pop_back on an empty container results in undefined behavior.
			**	Iterators and references to the last element, as well as the end() iterator, are invalidated.
			*/
			
			void pop_back();
			
			
			/*
			**	Resize
			**
			**	Resizes the container to contain count elements.
			**	If the current size is greater than count, the container is reduced to its first count elements.
			**	If the current size is less than count,
			**		1) additional default-inserted elements are appended
			**		2) additional copies of value are appended.
			*/
			
			void resize( size_type count, T value = T() );
			
			
			/*
			**	Swap
			**
			**	Exchanges the contents of the container with those of other.
			**	Does not invoke any move, copy, or swap operations on individual elements.
			**	All iterators and references remain valid. The past-the-end iterator is invalidated. 
			*/
			
			void swap( vector& other );
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
	bool operator==( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
	
	//	Operator!=
	template< class T, class Alloc >
	bool operator!=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
	
	//	Operator<
	template< class T, class Alloc >
	bool operator<( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
	
	//	Operator<=
	template< class T, class Alloc >
	bool operator<=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
	
	//	Operator>
	template< class T, class Alloc >
	bool operator>( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );
	
	//	Operator>=
	template< class T, class Alloc >
	bool operator>=( const std::vector<T,Alloc>& lhs, const std::vector<T,Alloc>& rhs );

	/*
	**	Swap
	**
	**	Specializes the std::swap algorithm for std::vector. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
	*/
	
	template< class T, class Alloc >
	void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs );
}
#endif /* VECTOR_HPP */
