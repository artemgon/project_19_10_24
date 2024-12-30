#include "libs.h"

struct Node
{
	string _word, _translation;
	int _counter;
	Node* _left;
	Node* _right;
	Node(string word, string t) : _word(word), _translation(t), _counter(0), _left(nullptr), _right(nullptr) {}
};

class Dictionary
{
	Node* _root;
	Node* insert(Node* node, const string& word, const string& translation)
	{
		if (node == nullptr)
			return new Node(word, translation);
		if (word < node->_word)
			node->_left = insert(node->_left, word, translation);
		else if (word > node->_word)
			node->_right = insert(node->_right, word, translation);
		return node;
	}
	Node* search(Node* node, const string& word)
	{
		if (node == nullptr || node->_word == word)
			return node;
		if (word < node->_word)
			return search(node->_left, word);
		else if (word > node->_word)
			return search(node->_right, word);
	}
	void inOrderTraversal(Node* node, void (*f)(Node*))
	{
		if (node == nullptr)
			return;
		inOrderTraversal(node->_left, f);
		f(node);
		inOrderTraversal(node->_right, f);
	}
	Node* remove(Node* node, const string& word) {
		if (node == nullptr) return nullptr;

		if (word < node->_word) {
			node->_left = remove(node->_left, word);
		}
		else if (word > node->_word) {
			node->_right = remove(node->_right, word);
		}
		else {
			if (node->_left == nullptr) {
				Node* temp = node->_right;
				delete node;
				return temp;
			}
			else if (node->_right == nullptr) {
				Node* temp = node->_left;
				delete node;
				return temp;
			}

			Node* successor = minFunc(node->_right);
			node->_word = successor->_word;
			node->_translation = successor->_translation;
			node->_counter = successor->_counter;
			node->_right = remove(node->_right, successor->_word);
		}
		return node;
	}
	Node* minFunc(Node* node)
	{
		while (node->_left != nullptr) {
			node = node->_left;
		}
		return node;
	}
	void topFunc(Node* node, Node*& top1, Node*& top2, Node*& top3)
	{
		if (node == nullptr)
			return;
		topFunc(node->_left, top1, top2, top3);
		if (!top1 || node->_counter > top1->_counter)
		{
			top3 = top2;
			top2 = top1;
			top1 = node;
		}
		else if (!top2 || node->_counter > top2->_counter)
		{
			top3 = top2;
			top2 = node;
		}
		else if (!top3 || node->_counter > top3->_counter)
			top3 = node;
		topFunc(node->_right, top1, top2, top3);
	}

	void bottomFunc(Node* node, Node*& b1, Node*& b2, Node*& b3)
	{
		if (node == nullptr)
			return;
		bottomFunc(node->_left, b1, b2, b3);
		if (!b1 || node->_counter < b1->_counter)
		{
			b3 = b2;
			b2 = b1;
			b1 = node;
		}
		else if (!b2 || node->_counter < b2->_counter)
		{
			b3 = b2;
			b2 = node;
		}
		else if (!b3 || node->_counter < b3->_counter)
			b3 = node;
		bottomFunc(node->_right, b1, b2, b3);
	}

	public:
		Dictionary() : _root(nullptr) {}
		void add(const string& word, const string& translation)
		{
			_root = insert(_root, word, translation);
		}
		void printWord(const string& word)
		{
			Node* node = search(_root, word);
			if (node != nullptr) {
				node->_counter++;
				cout << "Word: " << node->_word << ", Translation: " << node->_translation << ", Access counter: " << node->_counter << endl;
			}
			else
				cout << "Word not found" << endl;
		}
		void changeTranslation(const string& word, const string& translation)
		{
			Node* node = search(_root, word);
			if (node != nullptr)
				node->_translation = translation;
			else
				cout << "Word not found" << endl;
		}
		void removeWord(const string& word)
		{
			_root = remove(_root, word);
		}
		void topThree()
		{
			Node* top1 = nullptr;
			Node* top2 = nullptr;
			Node* top3 = nullptr;
			topFunc(_root, top1, top2, top3);
			cout << "Top 3 accessed words: " << endl;
			if (top1) cout << top1->_word << " (" << top1->_counter << " times)" << endl;
			if (top2) cout << top2->_word << " (" << top2->_counter << " times)" << endl;
			if (top3) cout << top3->_word << " (" << top3->_counter << " times)" << endl;
		}
		void bottomThree()
		{
			Node* b1 = nullptr;
			Node* b2 = nullptr;
			Node* b3 = nullptr;
			bottomFunc(_root, b1, b2, b3);
			cout << "Bottom 3 accessed words: " << endl;
			if (b1) cout << b1->_word << " (" << b1->_counter << " times)" << endl;
			if (b2) cout << b2->_word << " (" << b2->_counter << " times)" << endl;
			if (b3) cout << b3->_word << " (" << b3->_counter << " times)" << endl;
		}
};