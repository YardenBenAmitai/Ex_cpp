#include <iostream>

using namespace std;

struct Node{
	private:
		int value;
		Node *left;
		Node *right;
		Node *parent;
	public:
		Node(int val){value=val; right=NULL; left=NULL; parent=NULL;}
		Node(Node* p, Node* l, Node* r, int val) { value=val; right=r; left=l; parent = p;}
		Node* getLeft() { return left;}
		Node* getRight() {return right;}
		Node* getParent() {return parent;}
		int getValue(){return value;}
		void setLeft(Node* l){left=l; l->parent=this;}
		void setRight(Node* r){right=r; r->parent=this;}
		void setValue(int val){value=val;}
};


namespace ariel
{
	class Tree{
		
		Node *Troot;
		
		public:
		
		Tree() {
			Troot=NULL;
		}
		
		~Tree() {
			destroy_tree();
		}
		
		void insert(int key) {  
			if(Troot != NULL) 
				insert(Troot, key); 
			else 
				Troot = new Node(key);
		}
		
		void print() {
			if(Troot!=NULL) 
				inorder_print(Troot); 
			else 
				cout<<"empty"<<endl;
		}
		
		void remove(int key) {
			if(Troot == NULL)
				throw std::invalid_argument( "tree is empty");
			else if(Troot->getValue()==key){
				if(Troot->getLeft()!=NULL)
					Node* temp=FindMax(Troot->getLeft());
				else if(Troot->getRight()!=NULL)
					Troot=Troot->getRight();
				else
					Troot=NULL;
			}
			else
				remove(Troot, key);
		}

		bool contains(int key) {
			if(Troot !=NULL){
				if(Troot->getValue()==key || FindLeaf(Troot, key)!=NULL) 
					return true;
			}return false;
		}
		
		int size() {
			return size(Troot);
		}
		
		int root() {
			if(Troot!=NULL) 
				return Troot -> getValue(); 
			throw std::invalid_argument ("tree is empty");
		}
		
		int parent(int key) {
			if(Troot->getValue()==key) 
				return Troot->getValue(); 
			else 
				return FindLeaf(Troot, key)->getParent()->getValue();
		}
		
		int left(int key) {
			if(Troot->getValue()==key) 
				return Troot->getLeft()->getValue(); 
			else if(FindLeaf(Troot, key)==NULL) 
				throw std::invalid_argument("no such value"); 
			else 
				return FindLeaf(Troot,key)-> getLeft() -> getValue();
		}
		
		int right(int key) {
			if (Troot->getValue()==key) 
				return Troot->getRight()->getValue(); 
			else if(FindLeaf(Troot, key)==NULL) 
				throw std::invalid_argument("no such value"); 
			else 
				return FindLeaf(Troot, key) -> getRight() -> getValue();
		}




		private:
		void destroy_tree() {destroy_tree(Troot);}
						    	
		void destroy_tree(Node *leaf);
		void insert(Node *leaf, int key);
		void inorder_print(Node *leaf);
		Node* FindMax(Node* leaf);
		void remove(Node* leaf,int key);
		int size(Node* leaf);
		Node* FindLeaf(Node *leaf, int key);
	};
}
