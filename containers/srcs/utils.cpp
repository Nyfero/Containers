#include "../class/utils.hpp"

void	title(std::string str) {
	std::cout << std::endl << str << std::endl;
}

void	annonce(std::string msg) {
	std::cout << msg << std::endl;
}

void	Test_failure() {
	std::cout << "\e[31m[KO]\e[39m" << std::endl;
}

void	Test_performance(long real_time, long mine_time) {
	if (mine_time <= real_time * 20) {
		Test_success();
	}
	else {
		Test_timeout();
		std::cout << "Real time: " << real_time << std::endl;
		std::cout << "Mine time: " << mine_time << std::endl;
	}
}

void	Test_success() {
	std::cout << "\e[92m[OK]\e[39m" << std::endl;
}

void	Test_timeout() {
	std::cout << "\e[93m[TIMEOUT]\e[39m" << std::endl;
}

long	get_time() {
	struct timeval tv;
	long time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

int     int_max(int a, int b) {
	return (a > b ? a : b);
}

template <typename T>
Node <T>   *newNode(T data) {
    Node <T> *node = new Node <T>;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->height = 1;
    return (node);
}

template <typename T>
int     height(Node <T> *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

template <typename T>
Node <T>   *rightRotate(Node <T> *y) {
    Node <T> *x = y->left;
    Node <T> *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = int_max(height(y->left), height(y->right)) + 1;
    x->height = int_max(height(x->left), height(x->right)) + 1;
    return x;
}

template <typename T>
Node <T>   *leftRotate(Node <T> *x) {
    Node <T> *y = x->right;
    Node <T> *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = int_max(height(x->left), height(x->right)) + 1;
    y->height = int_max(height(y->left), height(y->right)) + 1;
    return y;
}

template <typename T>
int     getBalance(Node <T> *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

template <typename T>
Node <T>   *insert(Node <T> *node, T data) {
    if (node == NULL)
        return (newNode(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->height = 1 + int_max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

template<typename T>
Node <T>   *minValueNode(Node <T> *node) {
    Node <T> *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

template<typename T>
Node <T>   *deleteNode(Node <T> *root, T data) {
    if (root == NULL) {
        return root;
    }
  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  }
  else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  }
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      Node <T> *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else {
        *root = *temp;
      }
      free(temp);
    } else {
      Node <T> *temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  if (root == NULL) {
    return root;
  }
  root->height = 1 + int_max(height(root->left), height(root->right));
  int balanceFactor = getBalance(root);
  if (balanceFactor > 1) {
    if (getBalance(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalance(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

template <typename T>
void printTree(Node <T>*root, std::string indent, bool last) {
  if (root != NULL) {
    std::cout << indent;
    if (last) {
      std::cout << "R----";
      indent += "   ";
    } else {
      std::cout << "L----";
      indent += "|  ";
    }
    std::cout << root->data << std::endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}
