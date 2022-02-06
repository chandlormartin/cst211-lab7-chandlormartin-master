#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
#include <fstream>
#include "Exception.h"
#include "BSNode.h"
#include <queue>


using std::cout;
using std::endl;
using std::max;
using std::ofstream;
using std::queue;

template <typename T>
class BSTree
{
public:
//Constructors & Destructors
	BSTree();
	BSTree(T val);
	BSTree(const BSTree<T>& copy);
	BSTree(BSTree<T>&& copy);
	~BSTree();

//Getters
	int			Height(BSNode<T>* root);// , int /*BSNode<T>**/ target, int h);
	BSNode<T>*	findMin(BSNode<T>* root); 
	BSNode<T>*	getRoot();

//Setters
	void setRoot(BSNode<T>* root);

	//Mutators
	BSNode<T>*	copyTree(BSNode<T>* rootcopy);					//done
	BSNode<T>*	Insert(BSNode<T>* root, const T& val);			//done
	BSNode<T>*	Purge(BSNode<T>* root);					//done
	BSNode<T>*	Delete(BSNode<T>* root, T val);

//Overloaded operators
	BSTree<T>& operator =(const BSTree<T>& rhs);
	BSTree<T>& operator =(BSTree<T>&& rhs);

//Traversal
	void InOrder();
	void PostOrder();
	void PreOrder();
	void BreadthFirst();
//others

private:
	BSNode<T>* Root;

//traversal
	void BreadthFirst(BSNode<T>* root, ofstream& fpr);
	void InOrder(BSNode<T>* root, ofstream& fpr);
	void PostOrder(BSNode<T>* root, ofstream& fpr);
	void PreOrder(BSNode<T>* root, ofstream& fpr);

	//void Insert(BSNode<T>* newnode);
};

#endif
//
//Constructors & Destructors---------------------------------------
//-----------------------------------------------------------------
template<typename T>
BSTree<T>::BSTree()
{
	Root = nullptr;	//Set Root to nullptr
}

template<typename T>
BSTree<T>::BSTree(T val)
{
	Root = new BSNode<T>(val);	//create a new node with "val" data and set Root to it
}

template<typename T>
BSTree<T>::BSTree(const BSTree<T>& copy)
{
	//Root = copyTree(copy.Root);
	*this = copy;
}

template<typename T>
BSTree<T>::BSTree(BSTree&& copy)
{
	Root		= copy.Root;		//Steal copy's Root
	copy.Root	= nullptr;			//Set copy's Root to nullptr
}	

template<typename T>
BSTree<T>::~BSTree()
{
	Purge(Root);		//delete tree
}

//Getters----------------------------------------------------------
//-----------------------------------------------------------------
template<typename T>						//from mod 4 lecture code
int BSTree<T>::Height(BSNode<T>* root)//, int /*BSNode<T>**/ target, int h)
{
	if (root == nullptr)
	{
		return 0;// throw(Exception("ERROR: Target vale does not exist."));
	}
	
	//if (root->getData() == target)//->getData())												//if root is nullptr, return 0
	//{
	//	h++;
	//	return h;
	//}
	//if (root->getData() < target)//->getData())
	//{
	//	h++;
	//	return Height(root->getRight(), target, h);
	//}
	//if (root->getData() > target)//->getData())
	//{
	//	h++;
	//	return Height(root->getLeft(), target, h);
	//}
		//return 0;

	return /*h*/ 1 + max(Height(root->getLeft()), Height(root->getRight()));	//returns the larger length
}

template<typename T>
BSNode<T>* BSTree<T>::findMin(BSNode<T>* root)
{
	if (!root)							//if root is nullptr, return nullptr
		return nullptr;
	if (!root->getLeft())				//if no left child, return root
		return root;

	return findMin(root->getLeft());	//recurses along left branch
}

template<typename T>
BSNode<T>* BSTree<T>::getRoot()
{
	if (!Root)		//if Root = nullptr, return nullptr
		return nullptr;
	else					// if Root isn't nullptr, return Root
		return Root;
}

//Setters----------------------------------------------------------
//-----------------------------------------------------------------
template<typename T>
void BSTree<T>::setRoot(BSNode<T>* root)
{
	if (root == nullptr)	//if root is nullptr, set Root to nullptr
		Root = nullptr;
	else
		Root = root;		//set this Root to root
}

//Mutators---------------------------------------------------------
//-----------------------------------------------------------------
template<typename T>
BSNode<T>*	BSTree<T>::copyTree(BSNode<T>* rootcopy)
{
	if (!rootcopy)												//if rootcopy is nullptr
		return nullptr;
	else
	{
		BSNode<T>* root = new BSNode<T>(rootcopy->getData());	//point root to new node

		root->setLeft(copyTree(rootcopy->getLeft()));			//recurse left child
		root->setRight(copyTree(rootcopy->getRight()));			//recurse right child
	}
}

template<typename T>
BSNode<T>* BSTree<T>::Delete(BSNode<T>* root, T val)
{
	if (root == nullptr)
	{
		throw(Exception("Cannot delete from emmpty list"));
	}
	else if (val < root->getData())
		root->setLeft(Delete(root->getLeft(), val));
	else if (val > root->getData())
		root->setRight(Delete(root->getRight(), val));
	else
	{
		if (!root->getLeft() && !root->getRight())		///no children
		{
			delete root;					//delete current node
			root = nullptr;					//set to nullptr
			//return root;	//added
		}
		else if (!root->getLeft())			//no left child
		{
			BSNode<T>* temp = root;			//make pointer to curr node
			root = root->getRight();		//set curr node to right child
			delete temp;					//delete node with val
			//return root;	//added
		}
		else if (!root->getRight())			//no right child
		{
			BSNode<T>* temp = root;			//make pointer to curr node
			root = root->getLeft();			//set curr node to left child
			delete temp;					//delete node with val
			//return root
		}
		else							//has two children
		{
			BSNode<T>* temp = findMin(root->getRight());	//find min value of right tree
			root->setData(temp->getData());				//set current node's data to temp's data
			root->setRight(Delete(root->getRight(), temp->getData()));		//delete duplicate node
			//return root
		}
	}

	return root;
}

template<typename T>
BSNode<T>* BSTree<T>::Insert(BSNode<T>* root, const T& val)
{
	if (root == nullptr)									//root is nullptr, set root to new BSNode<T> of val
		return new BSNode<T>(val);

	if (val < root->getData())								//if val is less than root's data, recurse to left child
		root->setLeft(Insert(root->getLeft(), val));
	else if(val > root->getData())							//if val is greater than or equal to root's data, recurse to right child
		root->setRight(Insert(root->getRight(), val));
	else
		return root;
}

template<typename T>
BSNode<T>* BSTree<T>::Purge(BSNode<T>* root)
{
	if (root)
	{
		root->setLeft(Purge(root->getLeft()));		//use purge on branches of root->getLeft
		root->setRight(Purge(root->getRight()));	//use Purge on branches of root->getRight
		delete root;								//delete current root node
		root = nullptr;								//set root to nullptr
		return root;
	}
	else
		return nullptr;
}
//Overloaded Operators---------------------------------------------
//-----------------------------------------------------------------
template<typename T>
BSTree<T>& BSTree<T>::operator =(const BSTree<T>& rhs)
{
	if (&rhs == this)				//if the two trees are equal then return this tree
		return *this;
	else
	{
		Purge(Root);				//clear this BST
		Root = copyTree(rhs.Root);	//copy rhs tree to this tree

		return *this;
	}
}

template<typename T>
BSTree<T>& BSTree<T>::operator =(BSTree<T>&& rhs)
{
	if (&rhs == this)			//if the two BST are equal then return this queue
		return *this;
	else
	{
		Purge(Root);			//clear this BST
		Root = rhs.getRoot();	//steal rhs' Root
		rhs.setRoot(nullptr);	//set rhs' Root to nullptr

		return *this;
	}
}

//Traversal--------------------------------------------------------
//-----------------------------------------------------------------
template<typename T>
void BSTree<T>::BreadthFirst()
{
	if (!getRoot())										//if root is nullptr, throw exception
		throw(Exception("ERROR: LIST IS EMPTY"));
	
	ofstream myfile;									//open file
	myfile.open("Breadth_First.txt");

	cout << endl << "BREADTH FIRST: ";
	BreadthFirst(getRoot(), myfile);					//print bst breadth first to file for testing
	cout << endl << endl;

	myfile.close();
}
template<typename T>
void BSTree<T>::InOrder()
{
	if (!getRoot())										//if root is nullptr, throw exception
		throw(Exception("ERROR: LIST IS EMPTY"));

	ofstream myfile;				//make file pointer
	myfile.open("In_order.txt");	//open file
	
	cout << endl << "IN ORDER: ";
	InOrder(getRoot(), myfile);		//print bst in order and write to file for testing
	cout << endl << endl;

	myfile.close();					//close file
}

template<typename T>
void BSTree<T>::PostOrder()
{
	if (!getRoot())										//if root is nullptr, throw exception
		throw(Exception("ERROR: LIST IS EMPTY"));

	ofstream myfile;				//make file pointer
	myfile.open("Post_order.txt");	//open file

	cout << endl << "POST ORDER: ";
	PostOrder(getRoot(), myfile);	//print bst postordered and write to file for testing
	cout << endl << endl;

	myfile.close();					//close file
}

template<typename T>
void BSTree<T>::PreOrder()
{
	if (!getRoot())										//if root is nullptr, throw exception
		throw(Exception("ERROR: LIST IS EMPTY"));

	ofstream myfile;				//make file pointer
	myfile.open("Pre_order.txt");	//open file

	cout << endl << "PRE ORDER: ";
	PreOrder(getRoot(), myfile);	//print bst preordered and write to file for testing
	cout << endl << endl;

	myfile.close();					//close file
}

//PRIVATE FUNCTIONS!!---------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

//Traversal-----------------------------------------------------
//--------------------------------------------------------------
template<typename T>
void BSTree<T>::BreadthFirst(BSNode<T>* root, ofstream& fpr)
{

	// used this for some help https://algorithms.tutorialhorizon.com/breadth-first-searchtraversal-in-a-binary-tree/

	if (!root)
		return;

	queue<BSNode<T>*> temp_q;	//create queue to hold roots

	temp_q.push(root);			//push root onto queue

	while (!temp_q.empty())
	{
		BSNode<T>* node = temp_q.front();		//set node to the node in the front of the queue
		temp_q.pop();							//remove the node at the front of the queue
		cout << node->getData();				//output value of node
		fpr << root->getData();

		if (node->getLeft() != nullptr)			//if there is a left child, push it onto queue
				temp_q.push(node->getLeft());
		if (node->getRight() != nullptr)		//if there is a right child, pyush it onto queue
			temp_q.push(node->getRight());
	}
}

template<typename T>
void BSTree<T>::InOrder(BSNode<T>* root, ofstream& fpr)
{
	if (root->getLeft())							//if left child exisits
		InOrder(root->getLeft(), fpr);

	fpr << root->getData() << " ";					//write to file
	cout << root->getData() << " ";					//Output data to console
	if (root->getRight())							//if there is no left child
		InOrder(root->getRight(), fpr);
}

template<typename T>
void BSTree<T>::PostOrder(BSNode<T>* root, ofstream& fpr)
{
	if (root->getLeft())							//if left child exists
		PostOrder(root->getLeft(), fpr);
	if (root->getRight())							//if there is no left child
		PostOrder(root->getRight(), fpr);

	fpr << root->getData() << " ";					//write to file
	cout << root->getData() << " ";					//Output data to console
}

template<typename T>
void BSTree<T>::PreOrder(BSNode<T>* root, ofstream& fpr)
{
	fpr << root->getData() << " ";					//write to file
	cout << root->getData() << " ";					//Output data to console

	if (root->getLeft())							//if left child exists
		PreOrder(root->getLeft(), fpr);
	if (root->getRight())							//if there is no left child
		PreOrder(root->getRight(), fpr);
}