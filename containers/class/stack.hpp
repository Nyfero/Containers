#pragma once

#ifndef STACK_HPP
# define STACK_HPP

# include <string>
# include <iostream>
# include <iomanip>

namespace ft {
	
	template <class T, class Container = std::deque<T> >
	class stack
	{
		private:
			// Container					container_type;
			// Container::value_type		value_type;
			// Container::size_type		size_type;
			// Container::reference		reference;
			// Container::const_reference	const_reference;
		
		protected:
			Container	c;

		public:
			
			/**************************************/
			/*****      MEMBER FUNCTIONS      *****/
			/**************************************/
			
			
			
			/*
			**	Constructors
			**
			**	Constructs new underlying container of the container adaptor from a variety of data sources.
			**		1) Copy-constructs the underlying container c with the contents of cont.
			**		 This is also the default constructor.
			**		2) Copy constructor. The adaptor is copy-constructed with the contents of other.c.
			*/
			
			explicit stack( const Container& cont = Container() );
			
			stack( const stack& other );
			
			
			/*
			**	Destructor
			**
			**	Destructs the stack. The destructors of the elements are called and the used storage is deallocated.
			**	Note, that if the elements are pointers, the pointed-to objects are not destroyed.
			*/
			
			~stack();
			
			
			/*
			**	Operator=
			**
			**	Replaces the contents of the container adaptor with those of other.
			**	Copy assignment operator. Replaces the contents with a copy of the contents of other.
			**	Effectively calls c = other.c;.
			*/
			
			stack& operator=( const stack& other );
			
			
			
			/************************************/
			/*****      ELEMENT ACCESS      *****/
			/************************************/
			
			
			
			/*
			**	Top
			**
			**	Returns reference to the top element in the stack.
			**	This is the most recently pushed element. This element will be removed on a call to pop().
			**	Effectively calls c.back().
			*/
			
			reference top();
			
			const_reference top() const;
			
			
			
			/******************************/
			/*****      CAPACITY      *****/
			/******************************/
			
			
			
			/*
			**	Empty
			**
			**	Checks if the underlying container has no elements, i.e. whether c.empty().
			*/
			
			bool empty() const;
			
			
			/*
			**	Size
			**
			**	Returns the number of elements in the underlying container, that is, c.size().
			*/
			
			size_type size() const;
			
			
			
			/*******************************/
			/*****      MODIFIERS      *****/
			/*******************************/
			
			
			
			/*
			**	Push
			**
			**	Pushes the given element value to the top of the stack.
			**	Effectively calls c.push_back(value).
			*/
			
			void push( const value_type& value );
			
			
			/*
			**	Pop
			**
			**	Removes the top element from the stack. Effectively calls c.pop_back().
			*/
			
			void pop();
	};
	
	/******************************************/
	/*****      NON-MEMBER FUNCTIONS      *****/
	/******************************************/
	
	
	
	/*
	**	Operators
	**
	**	Compares the contents of the underlying containers of two container adaptors.
	**	The comparison is done by applying the corresponding operator to the underlying containers.
	*/
	
	//	Operator==
	template< class T, class Container >
	bool operator==( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
	
	//	Operator!=
	template< class T, class Container >
	bool operator!=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
	
	//	Operator<
	template< class T, class Container >
	bool operator<( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
	
	//	Operator<=
	template< class T, class Container >
	bool operator<=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
	
	//	Operator>
	template< class T, class Container >
	bool operator>( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
	
	//	Operator>=
	template< class T, class Container >
	bool operator>=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
}

#endif /*STACK_HPP*/
