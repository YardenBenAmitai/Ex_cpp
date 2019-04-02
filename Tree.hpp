#include <iostream>

using namespace std;

struct Node{
	private:
		int value;
		struct Node *left;
		struct Node *right;
	public:
		Node(int val){cout<<"construct key"<<endl; value=val; right=NULL; left=NULL;}
		Node(struct Node* l, struct Node* r, int val) { cout<<"construct full"<<endl; value=val; right=r; left=l;}
	        
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
			
			cout<<"constructor tree"<<endl;
			Troot=NULL;
		}
		
		void insert(int key) {  
			cout<<"insert "<<key<<endl;
			Troot=insert(Troot, key);
			cout<<"insert end"<<endl;
		}
		
		void print() {
			cout<<"print"<<endl;
			if(Troot!=NULL) 
				inorder_print(Troot);	
			else 
				cout<<"print: empty";
			cout<<endl;
			cout<<"print end"<<endl;
		}
		
		void remove(int key) {
			cout<<"remove "<<key<<endl;
			Troot=remove(Troot,key);
			cout<<"remove end"<<endl;
		}

		bool contains(int key) {
			cout<<"contains "<<key<<endl;
			if(Troot!=NULL){
				if(Troot->getValue()==key)
					return true;
				else if(FindLeaf(Troot, key) !=NULL)
					return true;
			}
			cout<<"contains end"<<endl;
			return false;
		}
		
		int size() {
			cout<<"size"<<endl;
			return size(Troot);
			cout<<"size end"<<endl;
		}
		
		int root() {
			cout<<"root"<<endl;
			if(Troot!=NULL) 
				return Troot -> getValue(); 
			throw std::invalid_argument ("root: tree is empty");
		}
		
		int parent(int key) {
			cout<<"parent"<<endl;
			if(Troot->getValue()==key) 
			{cout<<"parent end"<<endl;
				return Troot->getValue(); }
			else {
				struct Node* temp=Troot;
				while (temp!=NULL){
					if(key > temp->getValue()){
						if(temp->getRight()->getValue()==key)
						{ cout<<"parent end"<<endl; return temp->getValue();}
						temp=temp->getRight();
					}else{
						if(temp->getLeft()->getValue()==key)
						{cout<<"parent end"<<endl; return temp->getValue();}
						temp=temp->getLeft();
					}
				}
				throw std::invalid_argument("parent: no such value in tree");
			}
		}
		
		int left(int key) {
			cout<<"left"<<endl;
			if(Troot->getValue()==key) 
			{cout<<"left end"<<endl;
				return Troot->getLeft()->getValue();}
			else if(FindLeaf(Troot, key)==NULL || FindLeaf(Troot,key)->getLeft()==NULL) 
				throw std::invalid_argument("left: no such value"); 
			else 
				return FindLeaf(Troot,key)-> getLeft() -> getValue();
		}
		
		int right(int key) {
			cout<<"right"<<endl;
			if (Troot->getValue()==key) 
			{cout<<"right end"<<endl;
				return Troot->getRight()->getValue();} 
			else if(FindLeaf(Troot, key)==NULL || FindLeaf(Troot, key) -> getRight()==NULL) 
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
