#pragma once

#ifndef MAP_HPP
# define MAP_HPP

# include "utils.hpp"
# include "map_iterators.hpp"

namespace ft {

	template <typename T>
	struct node {
	        T       *data;
	        node    *left;
	        node    *right;
	        node    *parent;
	        int     height;
	};

	template <typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:

			/**********************************/
			/*****      MEMBER TYPES      *****/
			/**********************************/

			typedef Key										key_type;
			typedef T										mapped_type;
			typedef typename ft::pair<const Key, T>					value_type;

			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;

			typedef Compare									key_compare;
			typedef Allocator								allocator_type;

			typedef value_type &							reference;
			typedef const value_type &						const_reference;

			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;

			typedef map_iterators<Compare, node<value_type>, value_type>								iterator;
			typedef map_iterators<Compare, node<value_type>, const value_type>						const_iterator;
			typedef ft::reverse_iterators<iterator>			reverse_iterator;
			typedef ft::reverse_iterators<const_iterator>	const_reverse_iterator;

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

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				protected:
					Compare comp;

				public:
					value_compare( Compare c ) : comp(c) {}
					bool operator()( const value_type& x, const value_type& y ) const {
						return comp(x.first, y.first);
					}
			};

		private:

			/***************************************/
			/*****      MEMBER ATTRIBUTES      *****/
			/***************************************/

			node <T>				*_root;
			node <T>				*_end;
			allocator_type	_alloc;
			size_type				_size;
			Compare					_comp;

		public:

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

			map()
				: _root(NULL), _end(NULL), _alloc(Allocator()), _size(0), _comp(Compare()) {
					initializeend();
			};

			explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
				: _root(NULL), _end(NULL), _alloc(alloc), _size(0), _comp(comp) {
					initializeend();
			};

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
				: _root(NULL), _end(NULL), _alloc(alloc), _size(0), _comp(comp) {
				initializeend();
				insert(first, last);
			};

			map( const map& other )
				: _root(NULL), _end(NULL), _alloc(other._alloc), _size(0), _comp(other._comp) {
				initializeend();
				insert(other.begin(), other.end());
			};


			/*
			**	Destructor
			**
			**	Destructs the map. The destructors of the elements are called and the used storage is deallocated.
			**	Note, that if the elements are pointers, the pointed-to objects are not destroyed.
			*/

			~map() {
				clear();
				delete _root;
				delete _end;
			};


			/*
			**	Operator=
			**
			**	Replaces the contents of the container.
			**	Copy assignment operator. Replaces the contents with a copy of the contents of other.
			*/

			map& operator=( const map& other ) {
				clear();
				_comp = other._comp;
				insert(other.begin(), other.end());
				return *this;
			};


			/*
			**	Get_allocator
			**
			**	Returns the allocator associated with the container.
			*/

			allocator_type	get_allocator() const {
				return _alloc;
			};



			/************************************/
			/*****      ELEMENT ACCESS      *****/
			/************************************/



			/*
			**	At
			**
			**	Returns a reference to the mapped value of the element with key equivalent to key.
			**	If no such element exists, an exception of type std::out_of_range is thrown.
			*/

			T& at( const Key& key ) {
				iterator it = find(key);
				if (it == end())
					throw std::out_of_range("Key not found");
				return it->second;
			};

			const T& at( const Key& key ) const {
				const_iterator it = find(key);
				if (it == end())
					throw std::out_of_range("Key not found");
				return it->second;
			};

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

			T& operator[]( const Key& key ) {
				iterator it = find(key);
				if (it == end()) {
					value_type add(key, T());
					insert(add);
				}
				it = find(key);
				return it->second;
			};



			/******************************/
			/*****      ITERATOR      *****/
			/******************************/



			/*
			**	Begin
			**
			**	Returns an iterator to the first element of the map.
			**	If the map is empty, the returned iterator will be equal to end().
			*/

			iterator begin() {
				if (!_size) {
					return iterator(_end);
				}
				return iterator(node_value_min(_root));
			};

			const_iterator begin() const {
				if (!_size) {
					return const_iterator(_end);
				}
				return const_iterator(node_value_min(_root));
			};


			/*
			**	End
			**
			**	Returns an iterator to the element following the last element of the map.
			**	This element acts as a placeholder; attempting to access it results in undefined behavior.
			*/

			iterator end() {
				return iterator(_end);
			};

			const_iterator end() const {
				return const_iterator(_end);
			};


			/*
			**	Rbegin
			**
			**	Returns a reverse iterator to the first element of the reversed map.
			**	It corresponds to the last element of the non-reversed map.
			**	If the map is empty, the returned iterator is equal to rend().
			*/

			reverse_iterator rbegin() {
				return reverse_iterator(end());
			};

			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(end());
			};


			/*
			**	Rend
			**
			**	Returns a reverse iterator to the element following the last element of the reversed map.
			**	It corresponds to the element preceding the first element of the non-reversed map.
			**	This element acts as a placeholder, attempting to access it results in undefined behavior.
			*/

			reverse_iterator rend() {
				return reverse_iterator(begin());
			};

			const_reverse_iterator rend() const {
				return const_reverse_iterator(begin());
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

			size_type	size() const {
				return _size;
			};


			/*
			**	Max_size
			**
			**	Returns the maximum number of elements the container is able to hold
			**	due to system or library implementation limitations,
			**	i.e. std::distance(begin(), end()) for the largest container.
			*/

			size_type	max_size() const {
				return _alloc.max_size();
			};



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

			void clear() {
				if (_size) {
					destroy_tree(_root);
				}
			};


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

			pair<iterator, bool> insert( const value_type& value ) {
				size_type tmp = _size;

				_root = insert_node(_root, value, NULL);
				if (!_end->parent) {
					_end->parent = _root;
					_end->left = _root;
				}
				else {
					node <T> *new_max = node_value_max(_root);
					if (_comp(_end->parent->data->first, new_max->data->first)) {
						_end->parent = new_max;
						_end->left = new_max;
					}
				}
				return pair<iterator, bool>(find(value.first), tmp != size());
			};

			iterator insert( iterator hint, const value_type& value ) {
				(void) hint;
				insert(value);
				return find(value.first);
			};

			template< class InputIt >
			void insert( InputIt first, InputIt last ) {
				for (; first != last; ++first)
					insert(*first);
			};


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

			iterator erase( iterator pos ) {
				_root = deleteNode(_root, *pos.getNode()->data);
				if (_root) {
					node <T> *new_max = node_value_max(_root);
					_end->parent = new_max;
					_end->left = new_max;
				}
				else {
					_end->parent = NULL;
					_end->left = NULL;
				}
			};

			iterator erase( iterator first, iterator last ) {
				map tmp(first, last);
				iterator it = tmp.begin() - 1;
				iterator ite = tmp.end() - 1;
				for (; it != ite;it++) {
					erase(it);
				}
				erase(it);
				if (!_size) {
						_end->parent = NULL;
						_end->left = NULL;
				}
			};

			size_type erase( const Key& key ) {
				iterator it = find(key);
				if (it == end()) {
					return 0;
				}
				erase(it);
				return 1;
			};


			/*
			**	Swap
			**
			**	Exchanges the contents of the container with those of other.
			**	Does not invoke any move, copy, or swap operations on individual elements.
			**	All iterators and references remain valid. The past-the-end iterator is invalidated.
			**	The Compare objects must be Swappable, and they are exchanged using unqualified call to non-member swap.
			*/

			void swap( map& other ) {
				node <T>				*tmp_root = _root;
				node <T>				*tmp_end = _end;
				allocator_type	tmp_alloc = _alloc;
				size_type				tmp_size = _size;
				Compare					tmp_comp = _comp;

				_root = other._root;
				_end = other._end;
				_alloc = other._alloc;
				_size = other._size;
				_comp = other._comp;
				other._root = tmp_root;
				other._end = tmp_end;
				other._alloc = tmp_alloc;
				other._size = tmp_size;
				other._comp = tmp_comp;
			};



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

			size_type count( const Key& key ) const {
				return find(key) == end() ? 0 : 1;
			};


			/*
			**	Find
			**
			**	Finds an element with key equivalent to key.
			*/

			iterator find( const Key& key ) {
				iterator it = begin();
				while (it != end()) {
					if (it->first == key) {
						return it;
					}
					++it;
				}
				return it;
			};

			const_iterator find( const Key& key ) const {
				const_iterator it = begin();
				while (it != end()) {
					if (it->first == key) {
						return it;
					}
					++it;
				}
				return it;
			};


			/*
			**	Equal_range
			**
			**	Returns a range containing all elements with the given key in the container.
			**	The range is defined by two iterators, one pointing to the first element
			**	that is not less than key and another pointing to the first element greater than key.
			**	Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
			**	Compares the keys to key.
			*/

			ft::pair<iterator,iterator> equal_range( const Key& key ) {
				return ft::pair<iterator,iterator>(lower_bound(key), upper_bound(key));
			};

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
				return ft::pair<const_iterator,const_iterator>(lower_bound(key), upper_bound(key));
			};


			/*
			**	Lower_bound
			**
			**	Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
			*/

			iterator lower_bound( const Key& key ) {
				iterator it = begin();
				while (it != end()) {
					if (!_comp(it->first,key)) {
						return it;
					}
					++it;
				}
				return it;
			};

			const_iterator lower_bound( const Key& key ) const {
				const_iterator it = begin();
				while (it != end()) {
					if (!_comp(it->first,key)) {
						return it;
					}
					++it;
				}
				return it;
			};


			/*
			**	Upper_bound
			**
			**	Returns an iterator pointing to the first element that is greater than key.
			*/

			iterator upper_bound( const Key& key ) {
				iterator it = begin();
				while (it != end()) {
					if (it->first > key)
						return it;
					++it;
				}
				return it;
			};

			const_iterator upper_bound( const Key& key ) const {
				const_iterator it = begin();
				while (it != end()) {
					if (it->first > key)
						return it;
					++it;
				}
				return it;
			};



			/*******************************/
			/*****      OBSERVERS      *****/
			/*******************************/



			/*
			**	Key_comp
			**
			**	Returns the function object that compares the keys,
			**	which is a copy of this container's constructor argument comp.
			*/

			key_compare key_comp() const {
				return _comp;
			};


			/*
			**	Value_comp
			**
			**	Returns a function object that compares objects of type std::map::value_type
			**	(key-value pairs) by using key_comp to compare the first components of the pairs.
			*/

			value_compare value_comp() const {
				return value_compare(Compare());
			};



	/******************************/
	/*****      AVL TREE      *****/
	/******************************/



	int	max( int a, int b ) {
		return (a > b) ? a : b;
	};

	node <T>	*new_node( const value_type& value, node <T> *parent ) {
		node <T> *nd = new node<T>;
		nd->left = NULL;
		nd->right = NULL;
		nd->parent = parent;
		nd->height = 1;
		nd->data = _alloc.allocate(1);
		_alloc.construct(nd->data, value);
		return (nd);
	};

	int height( node <T> *nd ) {
		if (!nd) {
			return 0;
		}
		return nd->height;
	};

	void destroy_tree( node <T> *nd ) {
		if (nd) {
			destroy_tree(nd->left);
			destroy_tree(nd->right);
			free_node(nd);
		}
	};

	void	free_node( node <T> *nd ) {
		if (nd->data) {
			_alloc.destroy(nd->data);
			_alloc.deallocate(nd->data, 1);
			nd->data = NULL;
		}
		nd->left = NULL;
		nd->right = NULL;
		nd->parent = NULL;
		nd->height = 0;
		free(nd);
		nd = NULL;
	};

	iterator find_in_tree( node <T> *nd, const Key& key ) {
		if (!nd) {
			return end();
		}
		if (nd->data->first == key) {
			return iterator(nd);
		}
		else if (_comp(key, nd->data->first)) {
			return find_in_tree(nd->left, key);
		}
		else {
			return find_in_tree(nd->right, key);
		}
	};

	const_iterator find_in_tree( node <T> *nd, const Key& key ) const {
		if (!nd) {
			return end();
		}
		if (nd->data->first == key) {
			return iterator(nd);
		}
		else if (_comp(key, nd->data->first)) {
			return find_in_tree(nd->left, key);
		}
		else {
			return find_in_tree(nd->right, key);
		}
	};

	node <T>	*rightRotate( node <T> *y ) {
		node <T>	*x = y->left;
		node <T>	*xr = x->right;

		x->parent = y->parent;
		y->parent = x;
		x->right = y;
		y->left = xr;
		if (xr) {
			xr->parent = y;
		}
		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;
		return x;
	};

	node <T>	*leftRotate( node <T> *x ) {
		node <T>	*y = x->right;
		node <T>	*yl = y->left;

		y->parent = x->parent;
		x->parent = y;
		y->left = x;
		x->right = yl;
		if (yl) {
			yl->parent = x;
		}
		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;
		return y;
	};

	int getBalanceFactor(node <T> *nd ) {
		if (!nd) {
			return 0;
		}
		return height(nd->left) - height(nd->right);
	};

	/* Insert a node in a recursive way
	/ 1- Find the correct position and Insert new node
	/ 2- Check the balance and rotate if necessary
	*/
	node <T>	*insert_node( node <T> *root, const value_type value, node <T> *parent ) {
		if (root == NULL) {
			_size++;
			return new_node(value, parent);
		}
		if (_comp(value.first, root->data->first)) {
			root->left = insert_node(root->left, value, root);
		}
		else if (!(_comp(value.first, root->data->first))) {
			if (value.first == root->data->first) {
				return root;
			}
			root->right = insert_node(root->right, value, root);
		}
		else {
			return root;
		}
		root->height = 1 + max(height(root->left), height(root->right));

		int balanceFactor = getBalanceFactor(root);
		if (balanceFactor > 1) {
			if (_comp(value.first, root->left->data->first)) {
				return rightRotate(root);
			}
			else if (!(_comp(value.first, root->left->data->first))) {
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1) {
			if (!(_comp(value.first, root->right->data->first))) {
				return leftRotate(root);
			}
			else if (_comp(value.first, root->right->data->first)) {
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	};

	node <T> *node_value_min( node <T> *nd ) const {
		node <T> *tmp = nd;
		while (tmp->left != NULL)
			tmp = tmp->left;
		return tmp;
	};

	node <T> *node_value_max( node <T> *nd ) const {
		node <T> *tmp = nd;
		while (tmp->right != NULL)
			tmp = tmp->right;
		return tmp;
	};

	node <T> *deleteNode( node <T> *root, const value_type value ) {
		if (!root) {
			return root;
		}
		if (_comp(value.first, root->data->first)) {
			root->left = deleteNode(root->left, value);
		}
		else if (!(_comp(value.first, root->data->first)) && value.first != root->data->first) {
			root->right = deleteNode(root->right, value);
		}
		else {
			if (!root->left || !root->right) {
				node <T> *tmp = root->left ? root->left : root->right;
				if (!tmp) {
					tmp = root;
					root = NULL;
				}
				else {
					node <T> swap;
					swap.data = root->data;
					root->data = tmp->data;
					root->left = tmp->left;
					root->right = tmp->right;
					tmp->data = swap.data;
				}
				_size--;
				free_node(tmp);
			}
			else {
				node <T> swap;
				swap.data = root->data;
				node <T> *tmp = node_value_min(root->right);
				if (tmp->data->first == root->right->data->first) {
					root->right = root->right->right;
				}
				else {
					tmp->parent->left = NULL;
				}
				root->data = tmp->data;
				tmp->data = swap.data;
				if (tmp->right) {
					tmp->right->parent = root;
				}
				_size--;
				free_node(tmp);
			}
		}
		if (!root) {
			return root;
		}
		root->height = 1 + max(height(root->left), height(root->right));
		int balanceFactor = getBalanceFactor(root);
		if (balanceFactor > 1) {
			if (getBalanceFactor(root->left) >= 0) {
				return rightRotate(root);
			}
			else {
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1) {
			if (getBalanceFactor(root->right) <= 0) {
				return leftRotate(root);
			}
			else {
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	};

	void	initializeend() {
		_end = new_node(value_type(key_type(), mapped_type()), NULL);
	};

	// Print the tree
	void printTree( node <T> *root, std::string indent, bool last ) {
		if (root != NULL) {
			std::cout << indent;
			if (last) {
				std::cout << "R----";
				indent += "   ";
			}
			else {
				std::cout << "L----";
				indent += "|  ";
			}
			std::cout << root->data->first << std::endl;
			printInfoNode(root);
			printTree(root->left, indent, false);
			printTree(root->right, indent, true);
		}
	};

	void printInfoNode( node <T> *nd ) {
		std::cout << "NODE " << nd->data->first;
		//  std::cout << "NODE " << nd->data->first << " HEIGHT LEFT = " << height(nd->left) << " HEIGHT RIGHT = " << height(nd->right) << " HEIGHT = " << height(nd->left) - height(nd->right);
		if (nd->left)
			std::cout<< " Value nd->left "<< nd->left->data->first;
		if (nd->right)
			std::cout<< " Value nd->right "<< nd->right->data->first;
		if (nd->parent)
			std::cout << " DAD = " << nd->parent->data->first;
		else
			std::cout << " DAD = NULL ";
		std::cout<< std::endl;
	};

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
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return false;
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it1 = lhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it2 = rhs.begin();
		while (it1 != lhs.end()) {
			if (it1->first != it2->first || it1->second != it2->second)
				return false;
			++it1;
			++it2;
		}
		return true;
	};

	//	Operator!=
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return !(lhs == rhs);
	};

	//	Operator<
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it1 = lhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it2 = rhs.begin();
		while (it1 != lhs.end() && it2 != rhs.end()) {
			if (it1->first < it2->first)
				return true;
			else if (it1->first > it2->first)
				return false;
			else if (it1->second < it2->second)
				return true;
			else if (it1->second > it2->second)
				return false;
			++it1;
			++it2;
		}
		if (it1 == lhs.end() && it2 != rhs.end())
			return true;
		return false;
	};

	//	Operator<=
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return !(rhs < lhs);
	};

	//	Operator>
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return (rhs < lhs);
	};

	//	Operator>=
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
		return !(lhs < rhs);
	};

	/*
	**	Swap
	**
	**	Specializes the std::swap algorithm for std::map. Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
	*/

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs ) {
		lhs.swap(rhs);
	};

} // namespace ft

#endif /*MAP_HPP*/
