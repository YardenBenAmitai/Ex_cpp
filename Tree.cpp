
#include "Tree.hpp"
using namespace ariel;

void Tree::destroy_tree(Node *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->getLeft());
		destroy_tree(leaf->getRight());
		delete leaf;
	}
}

void Tree::insert(Node* leaf, int key){
	if(key < leaf->getValue()){
		if(leaf->getLeft() != NULL){
			insert(leaf->getLeft(), key);
		}else{
			leaf->setLeft(new Node(key));
		}
	}else if(key > leaf->getValue()){
		if(leaf->getRight() != NULL){
			insert(leaf->getRight(),key);
		}else{
			leaf->setRight(new Node(key));
		}
	}else
		throw std::invalid_argument( "This value already exists!");
}

void Tree::inorder_print(Node *leaf){
	if(leaf != NULL){
		inorder_print(leaf->getLeft());
		cout << leaf->getValue() << " ";
		inorder_print(leaf->getRight());
	}
}

Node* Tree::FindMax(Node* leaf){
	if(leaf==NULL)
		return NULL;
	while(leaf->getRight() != NULL){
		leaf = leaf->getRight();
	}
	return leaf;
}

void Tree::remove(Node* leaf,int key){
	if(leaf==NULL)
		throw std::invalid_argument( "No such value to remove");
	else if(key < leaf->getValue()) 
		remove(leaf->getLeft(), key);
	else if (key > leaf->getValue())
		remove(leaf->getRight(), key);
	else{
		if(leaf->getRight() == NULL && leaf->getLeft() == NULL){
			leaf = NULL;
		}
		else if(leaf->getRight() == NULL && leaf->getLeft()!=NULL){
			Node* temp=leaf;
			leaf=leaf->getLeft();
			delete temp;
		}
		else if(leaf->getLeft() == NULL){
			Node* temp = leaf;
			leaf= leaf->getRight();
			delete temp;
		}
		else{
			Node* temp = FindMax(leaf->getLeft());
			leaf->setValue(temp->getValue());
			remove(leaf->getLeft(), temp->getValue());
		}
	}
}

int Tree::size(Node* leaf){
	if (leaf == NULL)
		return 0;
	else
		return(size(leaf->getLeft()) + 1 + size(leaf->getRight()));
}

Node* Tree::FindLeaf(Node *leaf, int key){
	
	if ( leaf->getValue() > key && leaf->getLeft()!=NULL){
		if(leaf->getLeft()->getValue()==key)
			return leaf->getLeft();
		FindLeaf(leaf->getLeft(), key);
	}else if (leaf->getValue() < key && leaf->getRight()!=NULL){
		if(leaf->getRight()->getValue()==key)
			return leaf->getRight();
		FindLeaf(leaf->getRight(), key);
	}
	return NULL;
}
