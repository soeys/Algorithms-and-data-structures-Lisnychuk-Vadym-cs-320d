#include <iostream>
#include <iomanip>

struct student {
	std::string name;
	int booksTaken;
	int ticketNumber;
	student() {
		name = "";
		ticketNumber = 0;
		booksTaken = 0;
	}
	void set(std::string name, int booksTaken, int ticketNumber) {
		this->name = name;
		this->booksTaken = booksTaken;
		this->ticketNumber = ticketNumber;
	}
	friend std::ostream& operator << (std::ostream& os, const student& dt) {
		os << std::setw(20) << dt.name << "\t" << dt.ticketNumber << "\t" << dt.booksTaken;
		return os;
	}
	bool operator <(student field) {
		return this->booksTaken > field.booksTaken;
	}
	bool operator ==(int field) {
		return this->booksTaken == field;
	}
	bool operator <=(int field) {
		return this->booksTaken <= field;
	}
};

struct Node {
	student data;
	Node* parent;
	Node* left;
	Node* right;
	bool color; // 1 -> Red, 0 -> Black
};

typedef Node* NodePtr;

class RBTree {
	NodePtr root;
	NodePtr TNULL;

	void initializeNULLNode(NodePtr node, NodePtr parent) {
		node->data;
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = 0;
	}
	void leftRotate(NodePtr x) {
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != TNULL) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		}
		else if (x == x->parent->left) {
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}
	void rightRotate(NodePtr x) {
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != TNULL) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		}
		else if (x == x->parent->right) {
			x->parent->right = y;
		}
		else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}
	void fixInsert(NodePtr k) {
		NodePtr u;
		while (k->parent->color == 1) {
			if (k->parent == k->parent->parent->right) {
				u = k->parent->parent->left;
				if (u->color == 1) {
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->left) {
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			}
			else {
				u = k->parent->parent->right;

				if (u->color == 1) {
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else {
					if (k == k->parent->right) {
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root) {
				break;
			}
		}
		root->color = 0;
	}
	void printHelper(NodePtr root, std::string indent, bool last, int level = 0) {
		if (root) {
			std::string sColor = root->color ? "RED" : "BLACK";
			printHelper(root->left, indent, false, level + 1);
			for (int i = 0; i < level; i++)
				std::cout << "\t\t";
			std::cout << root->data.booksTaken << "(" << sColor << ")" << std::endl;
			printHelper(root->right, indent, true, level + 1);
		}
	}

	NodePtr minimum(NodePtr node) {
		while (node->left != TNULL) {
			node = node->left;
		}
		return node;
	}
	void rbTransplant(NodePtr u, NodePtr v) {
		if (u->parent == nullptr) {
			root = v;
		}
		else if (u == u->parent->left) {
			u->parent->left = v;
		}
		else {
			u->parent->right = v;
		}
		v->parent = u->parent;
	}
	void fixDelete(NodePtr x) {
		NodePtr s;
		while (x != root && x->color == 0) {
			if (x == x->parent->left) {
				s = x->parent->right;
				if (s->color == 1) {
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}

				if (s->left->color == 0 && s->right->color == 0) {
					s->color = 1;
					x = x->parent;
				}
				else {
					if (s->right->color == 0) {
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}
					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			}
			else {
				s = x->parent->left;
				if (s->color == 1) {
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == 0 && s->right->color == 0) {
					s->color = 1;
					x = x->parent;
				}
				else {
					if (s->left->color == 0) {
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
	}
	void deleteNodeHelper(NodePtr node, int key) {
		NodePtr z = TNULL;
		NodePtr x, y;
		while (node != TNULL) {
			if (node->data == key) {
				z = node;
			}

			if (node->data <= key) {
				node = node->right;
			}
			else {
				node = node->left;
			}
		}

		if (z == TNULL) {
			std::cout << "Couldn't find key in the tree" << std::endl;
			return;
		}

		y = z;
		int y_original_color = y->color;
		if (z->left == TNULL) {
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == TNULL) {
			x = z->left;
			rbTransplant(z, z->left);
		}
		else {
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z) {
				x->parent = y;
			}
			else {
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 0) {
			fixDelete(x);
		}
	}
public:
	RBTree() {
		TNULL = new Node;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}
	void insert(student key) {
		NodePtr node = new Node;
		node->parent = nullptr;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1;

		NodePtr y = nullptr;
		NodePtr x = this->root;

		while (x != TNULL) {
			y = x;
			if (node->data < x->data) {
				x = x->left;
			}
			else {
				x = x->right;
			}
		}
		node->parent = y;
		if (y == nullptr) {
			root = node;
		}
		else if (node->data < y->data) {
			y->left = node;
		}
		else {
			y->right = node;
		}

		if (node->parent == nullptr) {
			node->color = 0;
			return;
		}
		if (node->parent->parent == nullptr) {
			return;
		}
		fixInsert(node);
	}
	void show() {
		if(root)
			printHelper(this->root, "", true);
	}
	void deleteNode(int data) {
		deleteNodeHelper(this->root, data);
	}
	void set_up_default() {
		std::string namesArray[] = { "Clint Clark", "Prince Chaney", "Ashton Patterson", "Marshall Dickson", "Ashley Johns", "Simeon Frey", "Valentine Koch", "Elsworth Vaughn", "Stephen Clements", "Hays Petty" };
		int booksTakenArray[] = { 67, 76, 37, 34, 57, 13, 4, 10, 99, 74 };
		int ticketNumberArray[] = { 2401, 9587, 2793, 2963, 2237, 0240, 1936, 8369, 6468, 0714 };
		student temp;

		for (int i{}; i < 10; i++) {
			temp.set(namesArray[i], booksTakenArray[i], ticketNumberArray[i]);
			insert(temp);
		}
	}
};

int main()
{
	RBTree obj;
	obj.set_up_default();
	std::cout << "Before deleting 37: " << "\n";
	obj.show();
	obj.deleteNode(37);

	std::cout << "After deleting 37: " << "\n";
	obj.show();

}