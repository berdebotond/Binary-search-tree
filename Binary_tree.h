#include "iostream"

//structure of a leaf
template <class T>
struct Node
{
	Node<T> *right;
	Node<T> *left;
	T value;
};



template <class T>
class Binary_tree
{
private:

	Node<T> *root; //the first element of the tree but first of all it is NULL
	void add_element_pv(Node<T> *node, T value);
 	bool search_pv(Node<T> *node,T value);	

public:
	Binary_tree(){ //constructor 
		root = new Node<T>();
		root->right = NULL;
		root->left = NULL;
	};
	~Binary_tree(){ //destructor

		delete root->left;
		delete root->right;
		delete root;
	};

	void add_element(T value);
 	bool search(T value);	

};

template <class T> //add element to the tree, this function calls the private add element method  
void Binary_tree<T>::add_element(T value){ //only the first element added to the tree by this function

	if(root->left == NULL && root->right == NULL){
		root->value = value;
		root->left = new Node<T>();
		root->right = new Node<T>();
	}
	else if(root->value > value ){
		
		add_element_pv(root->right, value);
	}
	else if(root->value <= value){
		
		add_element_pv(root->left, value);
	}
};

template <class T> // this function works the rest of the elements.
void Binary_tree<T>::add_element_pv(Node<T> *node, T value){

	if(node->left == NULL && node->right == NULL){

		node->value = value;
		node->left = new Node<T>();
		node->right = new Node<T>();
	}
	else if(node->value > value ){
		
		add_element_pv(node->right, value);
	}
	else if(node->value <= value){
		
		add_element_pv(node->left, value);
	}

};

template <class T>
bool Binary_tree<T>::search(T value){ //this function searching elements in the tree looks like the add element method

	if(root->left == NULL && root->right == NULL){

		throw "Tree is empty";
		return false;
	}
	else if(root->value == value){

		return true;
	}
	else if(root->value > value ){
		
		return search_pv(root->right, value);
	}
	else if(root->value < value){
		
		return search_pv(root->left, value);
	}

	return false;

};

template <class T> // this is the private search method
bool Binary_tree<T>::search_pv(Node<T> *node, T value){

	if(node->left == NULL && node->right == NULL){

		return false;
	}
	else if(node->value == value){

		return true;
	}
	else if(node->value > value ){
		
		return search_pv(node->right, value);
	}
	else if(node->value < value){
		
		return search_pv(node->left, value);
	}

	return false;

};

