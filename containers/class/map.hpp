#pragma once

#ifndef MAP_HPP
# define MAP_HPP

# include <string>
# include <iostream>
# include <iomanip>

namespace ft {
	
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
	class map
	{
		public:
			
			/**********************************/
			/*****      MEMBER TYPES      *****/
			/**********************************/
			
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef std::pair<const Key, T>					value_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			
			typedef value_type &							reference;
			typedef const value_type &						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			
			typedef value_type								iterator;
			typedef const value_type						const_iterator;
			typedef std::reverse_iterator<iterator>			reverse_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		
		public:
			
			/************************************/
			/*****      MEMBER CLASSES      *****/
			/************************************/
			
			
			
			/*
			**	Value_compare
			**
			**	std::map::value_compare is a function object that compares objects of type
			**	std::map::value_type (key-value pairs) by comparing of the first components of the pairs.
			*/
			
			class value_compare
			{
				private:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;
					
				protected:
					Compare comp;
					value_compare( Compare c );
					
				public:
					bool operator()( const value_type& lhs, const value_type& rhs ) const;
			};
			
			
			
			/**************************************/
			/*****      MEMBER FUNCTIONS      *****/
			/**************************************/
			
			
			
			/*
			**	Constructors
			**
			**	Constructs new container from a variety of data sources and optionally
			**	using user supplied allocator alloc or comparison function object comp.
			**		1-2) Constructs an empty container.
			**		3) Constructs the container with the contents of the range [first, last).
			**		 If multiple elements in the range have keys that compare equivalent,
			**		 it is unspecified which element is inserted (pending LWG2844).
			**		4) Copy constructor. Constructs the container with the copy of the contents of other.
			*/
			
			map();
			
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() );
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
			
			map( const map& other );
			
			
			/*
			**	Destructor
			**
			**	Destructs the map. The destructors of the elements are called and the used storage is deallocated.
			**	Note, that if the elements are pointers, the pointed-to objects are not destroyed.
			*/
			
			~map();
			
			
			/*
			**	Operator=
			**
			**	Replaces the contents of the container.
			**	Copy assignment operator. Replaces the contents with a copy of the contents of other.
			*/
			
			map& operator=( const map& other );
			
			
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
			**	Returns a reference to the mapped value of the element with key equivalent to key.
			**	If no such element exists, an exception of type std::out_of_range is thrown. 
			*/
			
			T& at( const Key& key );
			
			const T& at( const Key& key ) const;
			
			/*
			**	Operator[]
			**
			**	Returns a reference to the value that is mapped to a key equivalent to key,
			**	performing an insertion if such key does not already exist.
			**	Inserts value_type(key, T()) if the key does not exist.
			**	This function is equivalent to return insert(std::make_pair(key, T())).first->second;
			**	- key_type must meet the requirements of CopyConstructible.
			**	- mapped_type must meet the requirements of CopyConstructible and DefaultConstructible.
			**	If an insertion is performed, the mapped value is value-initialized
			**	(default-constructed for class types, zero-initialized otherwise) and a reference to it is returned.
			*/
			
			T& operator[]( const Key& key );
			
			
			
			/******************************/
			/*****      ITERATOR      *****/
			/******************************/
			
			
			
			/*
			**	Begin
			**
			**	Returns an iterator to the first element of the map.
			**	If the map is empty, the returned iterator will be equal to end().
			*/
			
			iterator begin();
			
			const_iterator begin() const;
			
			
			/*
			**	End
			**
			**	Returns an iterator to the element following the last element of the map.
			**	This element acts as a placeholder; attempting to access it results in undefined behavior.
			*/
			
			iterator end();
			
			const_iterator end() const;
			
			
			/*
			**	Rbegin
			**
			**	Returns a reverse iterator to the first element of the reversed map.
			**	It corresponds to the last element of the non-reversed map.
			**	If the map is empty, the returned iterator is equal to rend(). 
			*/
			
			reverse_iterator rbegin();
			
			const_reverse_iterator rbegin() const;
			
			
			/*
			**	Rend
			**
			**	Returns a reverse iterator to the element following the last element of the reversed map.
			**	It corresponds to the element preceding the first element of the non-reversed map.
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
			
			
			
			/*******************************/
			/*****      MODIFIERS      *****/
			/*******************************/
			
			
			
			/*
			**	Clear
			**
			**	Erases all elements from the container. After this call, size() returns zero.
			**	Invalidates any references, pointers, or iterators referring to contained elements.
			**	Any past-the-end iterator remains valid.
			*/
			
			void clear();
			
			
			/*
			**	Insert
			**
			**	Inserts element(s) into the container, if the container doesn't already
			**	contain an element with an equivalent key.
			**		1) Inserts value. The overload (2) is equivalent to emplace(std::forward<P>(value)
			**		 and only participates in overload resolution if std::is_constructible<value_type, P&&>::value == true.
			**
			**		2) Inserts value in the position as close as possible, just prior(since C++11), to hint.
			**		 The overload (5) is equivalent to emplace_hint(hint, std::forward<P>(value))
			**		 and only participates in overload resolution if std::is_constructible<value_type, P&&>::value == true.
			**
			**		3) Inserts elements from range [first, last). If multiple elements in the range
			**		 have keys that compare equivalent, it is unspecified which element is inserted (pending LWG2844).
			*/
			
			std::pair<iterator, bool> insert( const value_type& value );
			
			iterator insert( iterator hint, const value_type& value );
			
			template< class InputIt >
			void insert( InputIt first, InputIt last );
			
			
			/*
			**	Erase
			**
			**	Removes specified elements from the container.
			**		1) Removes the element at pos.
			**		2) Removes the elements in the range [first; last), which must be a valid range in *this.
			**		3) Removes the element (if one exists) with the key equivalent to key.
			**	References and iterators to the erased elements are invalidated.
			**	Other references and iterators are not affected.
			**	The iterator pos must be valid and dereferenceable.
			**	Thus the end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for pos.
			*/
			
			iterator erase( iterator pos );
			
			iterator erase( iterator first, iterator last );
			
			size_type erase( const Key& key );
			
			
			/*
			**	Swap
			**
			**	Exchanges the contents of the container with those of other.
			**	Does not invoke any move, copy, or swap operations on individual elements.
			**	All iterators and references remain valid. The past-the-end iterator is invalidated.
			**	The Compare objects must be Swappable, and they are exchanged using unqualified call to non-member swap.
			*/
			
			void swap( map& other );
			
			
			
			/****************************/
			/*****      LOOKUP      *****/
			/****************************/
			
			
			
			/*
			**	Count
			**
			**	Returns the number of elements with key that compares equivalent to the specified argument,
			**	which is either 1 or 0 since this container does not allow duplicates.
			**	Returns the number of elements with key key.
			*/
			
			size_type count( const Key& key ) const;
			
			
			/*
			**	Find
			**
			**	Finds an element with key equivalent to key.
			*/
			
			iterator find( const Key& key );
			
			const_iterator find( const Key& key ) const;
			
			
			/*
			**	Equal_range
			**
			**	Returns a range containing all elements with the given key in the container.
			**	The range is defined by two iterators, one pointing to the first element
			**	that is not less than key and another pointing to the first element greater than key.
			**	Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
			**	Compares the keys to key.
			*/
			
			std::pair<iterator,iterator> equal_range( const Key& key );
			
			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
			
			
			/*
			**	Lower_bound
			**
			**	Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
			*/
			
			iterator lower_bound( const Key& key );
			
			const_iterator lower_bound( const Key& key ) const;
			
			
			/*
			**	Upper_bound
			**
			**	Returns an iterator pointing to the first element that is greater than key.
			*/
			
			iterator upper_bound( const Key& key );
			
			const_iterator upper_bound( const Key& key ) const;
			
			
			
			/*******************************/
			/*****      OBSERVERS      *****/
			/*******************************/
			
			
			
			/*
			**	Key_comp
			**
			**	Returns the function object that compares the keys, 
			**	which is a copy of this container's constructor argument comp.
			*/
			
			key_compare key_comp() const;
			
			
			/*
			**	Value_comp
			**
			**	Returns a function object that compares objects of type std::map::value_type
			**	(key-value pairs) by using key_comp to compare the first components of the pairs.
			*/
			
			value_compare value_comp() const;
	};
	
	/******************************************/
	/*****      NON-MEMBER FUNCTIONS      *****/
	/******************************************/
	
	
	
	/*
	**	Operators
	**
	**	Compares the contents of two maps.
	**		1-2) Checks if the contents of lhs and rhs are equal, that is, 
	**		 they have the same number of elements and each element in lhs compares equal
	**		 with the element in rhs at the same position.
	**		3-6) Compares the contents of lhs and rhs lexicographically.
	**		 The comparison is performed by a function equivalent to std::lexicographical_compare.
	**		 This comparison ignores the map's ordering Compare.
	*/
	
	//	Operator==
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );
	
	//	Operator!=
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );
	
	//	Operator<
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );
	
	//	Operator<=
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );

	//	Operator>
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );
				
	//	Operator>=
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs );
	
	/*
	**	Swap
	**
	**	Specializes the std::swap algorithm for std::map. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
	*/
	
	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs );
}

#endif /*MAP_HPP*/
