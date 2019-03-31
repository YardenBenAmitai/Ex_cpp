#include <iostream>

using namespace std;

struct Node{
	private:
		int value;
		struct Node *left;
		struct Node *right;
	public:
		Node(int val){value=val; right=NULL; left=NULL;}
		Node(struct Node* l, struct Node* r, int val) { value=val; right=r; left=l;}
		struct Node* getLeft() { return left;}
		struct Node* getRight() {return right;}
		int getValue(){return value;}

		void setLeft(struct Node* l){left=l;}
		void setRight(struct Node* r){right=r;}
		void setValue(int val){value=val;}
};


namespace ariel
{
	class Tree{
		
		struct Node *Troot;
		
		public:
		
		Tree() {
			Troot=NULL;
		}
		
		~Tree() {
			destroy_tree(Troot);
		}
		
		void insert(int key) {  
			Troot=insert(Troot, key);
		}
		
		void print() {
			if(Troot!=NULL) 
				inorder_print(Troot);	
			else 
				cout<<"print: empty";
			cout<<endl;
		}
		
		void remove(int key) {
			Troot=remove(Troot,key);
		}

		bool contains(int key) {
			if(Troot!=NULL){
				if(Troot->getValue()==key)
					return true;
				else if(FindLeaf(Troot, key) !=NULL)
					return true;
			}
			return false;
		}
		
		int size() {
			return size(Troot);
		}
		
		int root() {
			if(Troot!=NULL) 
				return Troot -> getValue(); 
			throw std::invalid_argument ("root: tree is empty");
		}
		
		int parent(int key) {
			if(Troot->getValue()==key) 
				return Troot->getValue(); 
			else {
				struct Node* temp=Troot;
				while (temp!=NULL){
					if(key > temp->getValue()){
						if(temp->getRight()->getValue()==key)
							return temp->getValue();
						temp=temp->getRight();
					}else{
						if(temp->getLeft()->getValue()==key)
							return temp->getValue();
						temp=temp->getLeft();
					}
				}
				throw std::invalid_argument("parent: no such value in tree");
			}
		}
		
		int left(int key) {
			if(Troot->getValue()==key) 
				return Troot->getLeft()->getValue(); 
			else if(FindLeaf(Troot, key)==NULL) 
				throw std::invalid_argument("left: no such value"); 
			else 
				return FindLeaf(Troot,key)-> getLeft() -> getValue();
		}
		
		int right(int key) {
			if (Troot->getValue()==key) 
				return Troot->getRight()->getValue(); 
			else if(FindLeaf(Troot, key)==NULL) 
				throw std::invalid_argument("right: no such value"); 
			else 
				return FindLeaf(Troot, key) -> getRight() -> getValue();
		}




		private:
						    	
		void destroy_tree(struct Node *leaf);
		struct Node* insert(struct Node *leaf, int key);
		void inorder_print(struct Node *leaf);
		struct Node* FindMax(struct Node* leaf);
		struct Node* remove(struct Node *leaf,int key);
		int size(struct Node* leaf);
		struct Node* FindLeaf(struct Node *leaf, int key);
	};
}
