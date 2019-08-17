#include "iostream"


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

	Node<T> *root;
	void add_element_pv(Node<T> *node, T value);
 	bool search_pv(Node<T> *node,T value);	

public:
	Binary_tree(){
		root = new Node<T>();
		root->right = NULL;
		root->left = NULL;
	};
	~Binary_tree(){

		delete root->left;
		delete root->right;
	};

	void add_element(T value);
 	bool search(T value);	

};

template <class T>
void Binary_tree<T>::add_element(T value){

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

template <class T>
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
bool Binary_tree<T>::search(T value){

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

template <class T>
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

int main()
{
	try{

		Binary_tree<int> tree;
	

		if(tree.search(9)){
	
			std::cout << "yeah";
		}
		else{
			std::cout << "OFF";

		}

    }catch(const char *e){

    	std::cout << e << "\n";
    }

	return 0;
}	