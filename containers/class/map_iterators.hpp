#pragma once

#ifndef MAP_ITERATORS_HPP
# define MAP_ITERATORS_HPP

namespace ft {

  template < typename Compare, typename node, typename T >
  class map_iterators {

    public:

      /**********************************/
			/*****      MEMBER TYPES      *****/
			/**********************************/

      typedef T                               value_type;
      typedef T*                              pointer;
      typedef T&                              reference;
      typedef std::ptrdiff_t                  difference_type;
      typedef std::size_t                     size_type;
      typedef std::bidirectional_iterator_tag iterator_category;

    private:

      /**************************************/
      /*****      MEMBER ATTRIBUTES     *****/
      /**************************************/

      node    *_current;
      Compare _comp;

    public:

      /**************************************/
			/*****      MEMBER FUNCTIONS      *****/
			/**************************************/

      map_iterators()
        : _current(NULL) {
      };

      map_iterators( node *ptr )
        : _current(ptr), _comp(Compare()) {
      };

      map_iterators( const map_iterators &other ) {
        _current = other._current;
        _comp = other._comp;
      };

      virtual ~map_iterators() {
      };

      map_iterators &operator=( const map_iterators &other ) {
        if ( this != &other ) {
            this->_current = other._current;
        }
        return *this;
      };

      map_iterators &operator+=( difference_type n ) {
        for ( difference_type i = 0; i < n; ++i ) {
            _current++;
        }
        return *this;
      };

      map_iterators &operator-=( difference_type n ) {
        for ( difference_type i = 0; i < n; ++i) {
          _current--;
        }
        return *this;
      };



      /************************************/
      /*****      ELEMENT ACCESS      *****/
      /************************************/



      operator map_iterators<Compare, node, T const>() const {
        return map_iterators<Compare, node, T const>(_current);
      };

      reference operator*() const {
        return *(_current->data);
      };

      pointer operator->() const {
        return _current->data;
      };



      /*******************************/
      /*****      OPERATORS      *****/
      /*******************************/



      map_iterators& operator++() {
        if (_current->right) {
          _current = _current->right;
          while (_current->left) {
            _current = _current->left;
          }
        }
        else {
          node *tmp = _current;

          if (_current->parent) {
            if (_comp(_current->data->first, _current->parent->data->first)) {
              _current = _current->parent;
            }
            else {
              while (_current->parent && !(_comp(_current->data->first, _current->parent->data->first))) {
                _current = _current->parent;
              }
              if (_current->parent && _comp(_current->data->first, _current->parent->data->first)) {
                _current = _current->parent;
              }
              if (_comp(_current->data->first, tmp->data->first)) {
                _current = _current->right;
              }
            }
          }
          else {
            _current = _current->right;
          }
        }
        return *this;
      };

      map_iterators operator++(int) {
        node *tmp = _current;
        ++(*this);
        return map_iterators(tmp);
      };

      map_iterators& operator--() {
        if (_current->left) {
          _current = _current->left;
          while (_current->right) {
            _current = _current->right;
          }
        }
        else {
          while (_current->parent && _comp(_current->data->first, _current->parent->data->first)) {
            _current = _current->parent;
          }
          if (_current->parent && !(_comp(_current->data->first, _current->parent->data->first))) {
            _current = _current->parent;
          }
        }
        return *this;
      };

      map_iterators operator--(int) {
        node *tmp = _current;
        --(*this);
        return map_iterators(tmp);
      };

      friend bool operator==( const map_iterators& lhs, const map_iterators& rhs ) {
        return lhs._current == rhs._current;
      };

      friend bool operator!=( const map_iterators& lhs, const map_iterators& rhs ) {
        return lhs._current != rhs._current;
      };

      /************************************/
      /*****      ELEMENT ACCESS      *****/
      /************************************/

      node *go_top( node *N ) {
        node *tmp = N;

        while (tmp->parent) {
          tmp = tmp->parent;
        }
        return tmp;
      };

      node  *find_last( node *N ) {
        node *tmp = go_top(N);

        while (tmp->right) {
          tmp = tmp->right;
        }
        return tmp;
      };

      node *find_first( node *N ) {
        node *tmp = go_top(N);

        while (tmp->left) {
          tmp = tmp->left;
        }
        return tmp;
      };

      node *getNode() {
        return _current;
      };

  }; // map_iterators

}; // namespace ft


#endif /* MAP_ITERATORS_HPP */
