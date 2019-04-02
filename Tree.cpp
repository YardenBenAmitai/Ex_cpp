
#include "Tree.hpp"
using namespace ariel;

void Tree::destroy_tree(struct Node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->getLeft());
		destroy_tree(leaf->getRight());
		delete leaf;
		leaf=NULL;
	}
}

struct Node* Tree::insert(struct Node* leaf, int key){
	if(leaf==NULL){
		return new Node(key);
	}else if(key < leaf->getValue()){
		leaf->setLeft(insert(leaf->getLeft(), key));
	}else if(key > leaf->getValue()){
		leaf->setRight(insert(leaf->getRight(), key));
	}else{
		leaf=NULL;
		throw std::invalid_argument("insert: This value already exists!");
	}
	return leaf;
}

void Tree::inorder_print(struct Node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->getLeft());
		cout << leaf->getValue() << " ";
		inorder_print(leaf->getRight());
	}
}

struct Node* Tree::FindMax(struct Node* leaf){
	if(leaf==NULL)
		return NULL;
	while(leaf->getRight() != NULL){
		leaf = leaf->getRight();
	}
	return leaf;
}

struct Node* Tree::remove(struct Node* leaf,int key){
	if(leaf==NULL){
		throw std::invalid_argument("remove: No such value to remove");
		return NULL;
	}
	else if(key < leaf->getValue()) 
		leaf->setLeft(remove(leaf->getLeft(), key));
	else if (key > leaf->getValue())
		leaf->setRight(remove(leaf->getRight(), key));
	else{
		if(leaf->getRight() == NULL && leaf->getLeft() == NULL){
			delete leaf;
			leaf=NULL;
		}
		else if(leaf->getRight() == NULL){
			struct Node* temp=leaf->getLeft();
			delete leaf;
			return temp;
		}

		else if(leaf->getLeft() == NULL){
			struct Node* temp =leaf->getRight();
			delete leaf;
			return temp;
		}
		else{
			struct Node* temp = FindMax(leaf->getLeft());
			leaf->setValue(temp->getValue());
			leaf->setLeft(remove(leaf->getLeft(), temp->getValue()));
		}
	}
	return leaf;
}

int Tree::size(struct Node* leaf){
	if (leaf == NULL)
		return 0;
	else
		return(size(leaf->getLeft()) + 1 + size(leaf->getRight()));
}

struct Node* Tree::FindLeaf(struct Node *leaf, int key){	
	if ( leaf->getValue() > key && leaf->getLeft()!=NULL){
		if(leaf->getLeft()->getValue()==key)
			return leaf->getLeft();
		else
			return FindLeaf(leaf->getLeft(), key);
	}else if (leaf->getValue() < key && leaf->getRight()!=NULL){
		if(leaf->getRight()->getValue()==key)
			return leaf->getRight();
		else
			return FindLeaf(leaf->getRight(), key);
	}
	return NULL;
}
