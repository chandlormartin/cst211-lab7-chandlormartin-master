#define _CRTDBG_MAP_ALLOC

#include <string>
#include <iostream>
#include <crtdbg.h>
#include <conio.h>
#include <fstream>
#include "BSTree.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

typedef bool(*FunctionPointer)();

bool default_ctor_test();
bool one_arg_ctor_test();
bool insert_test();
bool copy_ctor_and_copytree_test();
bool move_ctor_test();
bool purge_test();
bool op_equal_test();
bool move_op_equal_test();
bool delete_test();
bool delete_empty_test();
bool height_test();
bool in_order_test();
bool in_order_empty_test();
bool pre_order_test();
bool pre_order_empty_test();
bool post_order_test();
bool post_order_empty_test();
bool breadth_first_test();
bool breadth_first_empty_test();

bool default_ctor_complex_test();
bool one_arg_ctor_complex_test();
bool insert_complex_test();
//bool copy_ctor_and_copytree_complex_test();
//bool move_ctor_complex_test();
//bool purge_complex_test();
//bool op_equal_complex_test();
//bool move_op_equal_complex_test();
//bool delete_complex_test();
//bool delete_empty_complex_test();
//bool height_complex_test();
//bool in_order_complex_test();
//bool in_order_empty_complex_test();
//bool pre_order_complex_test();
//bool pre_order_empty_complex_test();
//bool post_order_complex_test();
//bool post_order_empty_complex_test();
//bool breadth_first_complex_test();
//bool breadth_first_empty_complex_test();


bool check_traversal_int(string trav_type);
bool check_traversal_string(string trav_type);
bool Int_Trees_Equal(BSNode<int>* root);
bool Str_Trees_Equal(BSNode<string>* root);
BSTree<int> ReturnIntBST();
BSTree<string> ReturnStrBST();

//const char* 
string MONSTERS[] = { "Rathalos", "Ceadeus","Valstrax", "Alatreon", "Lagiacrus", "Rathian" , "Zinogre" };
const int	VALUES[] = { 5, 3, 10, 1, 4, 7, 20 };
const int	NUM_MONSTERS = 7;
const int	NUM_VALUES = 7;
//
FunctionPointer tests[] = { default_ctor_test ,one_arg_ctor_test, insert_test, purge_test, copy_ctor_and_copytree_test, move_ctor_test,
							op_equal_test, move_op_equal_test, delete_test, delete_empty_test, height_test, in_order_test,
							in_order_empty_test, pre_order_test, pre_order_empty_test, post_order_test, post_order_empty_test, breadth_first_test,
							breadth_first_empty_test, default_ctor_complex_test, one_arg_ctor_complex_test, insert_complex_test /*, test_peek_empty_queue_complex,
							test_enqueue_complex, test_dequeue_complex, test_dequeue_empty_stack_complex, test_copy_ctor_complex,
							test_move_ctor_complex, test_op_equal_complex, test_move_op_equal_complex, test_isEmpty_complex */ };
//
int main()		//copied from past lab's tests. Some output modified
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	int f_tests = 0;
	for (FunctionPointer fptr : tests)
	{
		if (fptr())
			cout << " has passed\n";
		else
		{
			f_tests++;
			cout << " has failed\n";
		}
	}

	if (f_tests > 0)
		cout << "\nYou have failed --" << f_tests << "-- tests";
	else
		cout << "\nYou have passed all tests!";

	cout << "\nPress any key to exit";
	cin.get();

	return 0;
}

//used tests from previous labs as a reference for some of these tests.
bool default_ctor_test()
{
	bool			pass		= true;
	BSNode<int>*	default_top = nullptr;
	BSTree<int>		test_tree;

	if (test_tree.getRoot() != default_top)		//failst if root is not equal to default_top
			pass = false;

	cout << "Default constructor test";

	return pass;
}

bool one_arg_ctor_test()
{
	bool		pass		= true;
	int			test_data	= 2;
	BSTree<int> BSTree_test(test_data);

	if (BSTree_test.getRoot()->getData() != test_data)	//fails if Root of BST isn't 2
		pass = false;

	cout << "1 arg constructor test";

	return pass;
}

bool insert_test()
{
	bool		pass= true;
	BSTree<int> tree_test;
	
	for (int i = 0; i < NUM_VALUES; i++)				//insert integers from VALUES into tree_test
		tree_test.setRoot(tree_test.Insert(tree_test.getRoot(), VALUES[i]));

	pass = Int_Trees_Equal(tree_test.getRoot());		//check each node is correct

	cout << "Insert test";

	return pass;
}

bool purge_test()
{
	bool		pass = true;
	BSTree<int> tree_test;

	for (int i = 0; i < NUM_VALUES; i++)				//insert integers from VALUES into tree_test
		tree_test.setRoot(tree_test.Insert(tree_test.getRoot(), VALUES[i]));

	tree_test.setRoot(tree_test.Purge(tree_test.getRoot()));								//purge BST
	if (tree_test.getRoot() != nullptr)				//if tree_test's Root isn't nullptr, test fails
		pass = false;

	cout << "Purge test";

	return pass;
}

bool copy_ctor_and_copytree_test()
{
	//copy constructor uses copyTree so this tests both at the same time
	bool		pass = true;
	BSTree<int>	test_tree;

	for (int i = 0; i < NUM_VALUES; i++)			//insert VALUES onto test_tree
		test_tree.setRoot(test_tree.Insert(test_tree.getRoot(), VALUES[i]));

	BSTree<int> tree_test(test_tree);				//creates tree_test using test_tree as an argument

	pass = Int_Trees_Equal(tree_test.getRoot());	//check each node is correct
	
	cout << "Copy constructor and copyTree test";

	return pass;
}

bool move_ctor_test()
{
	bool		pass = true;
	BSTree<int>	test_tree(ReturnIntBST());			//create BST using another BST

	pass = Int_Trees_Equal(test_tree.getRoot());	//check each node is correct

	cout << "Move constructor test";

	return pass;
}

bool op_equal_test()
{
	bool		pass = true;
	BSTree<int> tree_test;
	BSTree<int> test_tree;

	tree_test = ReturnIntBST();
	for (int i = 0; i < NUM_VALUES; i++)				//insert integers from VALUES into tree_test
		tree_test.setRoot(tree_test.Insert(tree_test.getRoot(), VALUES[i]));

	test_tree	= tree_test;								//use equal operator
	pass		= Int_Trees_Equal(test_tree.getRoot());		//check each node is correct

	cout << "Operator equals test";

	return pass;
}

bool move_op_equal_test()
{
	bool		pass = true;
	BSTree<int> tree_test;

	tree_test	= ReturnIntBST();							//use move operator
	pass		= Int_Trees_Equal(tree_test.getRoot());		//check each node is correct

	cout << "Move Operator equals test";

	return pass;
}

bool delete_test()
{
	bool		pass = true;
	BSTree<int> tree_test;
	BSTree<int> left_test;
	BSTree<int> leftend_test;
	BSTree<int> right_test;
	BSTree<int> rightend_test;

	for (int i = 0; i < NUM_VALUES; i++)					//insert integers from VALUES into the 5 BST
	{
		tree_test.setRoot(tree_test.Insert(tree_test.getRoot(), VALUES[i]));
		left_test.setRoot(left_test.Insert(left_test.getRoot(), VALUES[i]));
		right_test.setRoot(right_test.Insert(right_test.getRoot(), VALUES[i]));
		leftend_test.setRoot(leftend_test.Insert(leftend_test.getRoot(), VALUES[i]));
		rightend_test.setRoot(rightend_test.Insert(rightend_test.getRoot(), VALUES[i]));
	}

	tree_test.setRoot(tree_test.Delete(tree_test.getRoot(), 5));		//test deleting root. if root isn't 7, test fails
	if (tree_test.getRoot()->getData() != 7)
		pass = false;

	left_test.setRoot(left_test.Delete(left_test.getRoot(), 3));		//test deleting left node with children. if node isn't 4, test fails
	if (left_test.getRoot()->getLeft()->getData() != 4)
		pass = false;

	right_test.setRoot(right_test.Delete(right_test.getRoot(), 10));		//test deleting right node with children. if node isn't 20, test fails
	if (right_test.getRoot()->getRight()->getData() != 20)
		pass = false;

	leftend_test.setRoot(leftend_test.Delete(leftend_test.getRoot(), 1));		//test deleting left node with no children. if node isn't nullptr, test fails
	if (leftend_test.getRoot()->getLeft()->getLeft()!=nullptr)
		pass = false;

	rightend_test.setRoot(rightend_test.Delete(rightend_test.getRoot(), 20));		//test deleting right node with no children. if node isn't nullptr, test fails
	if (rightend_test.getRoot()->getRight()->getRight() != nullptr)
		pass = false;

	cout << "Delete test";

	return pass;
}

bool delete_empty_test()
{
	bool		pass = false;
	BSTree<int> tree_test;

	try																//pass is true if deleting from empty BST throws exception
	{
		tree_test.setRoot(tree_test.Delete(tree_test.getRoot(), 5));
	}
	catch (Exception& exception)
	{
		pass = true;
	}

	cout << "Delete empty tree test";

	return pass;
}

bool height_test()
{
	bool		pass	 = true;
	BSTree<int> test_tree= ReturnIntBST();					//create filled BST

	if (test_tree.Height(test_tree.getRoot()) != 3)
		pass = false;

	//if (test_tree.Height(test_tree.getRoot(), 3, 0) != 2)	//test fails if height isn't 2
		//pass = false;

	//if (test_tree.Height(test_tree.getRoot(), 5, 0) != 1)	//test fails if height isn't 1
		//pass = false;

	//if (test_tree.Height(test_tree.getRoot(), 20, 0) != 3)	//test fails if height isn't 3
		//pass = false;

	cout << "Height test";

	return pass;
}

bool in_order_test()
{
	BSTree<int> test_tree = ReturnIntBST();		//create filled BST

	test_tree.InOrder();						//output tree in order and write to In_order.txt for testing
	cout << "In order traversal test ";

	return check_traversal_int("InOrder");		//checks the order of the numbers from the traversal
}

bool in_order_empty_test()
{
	bool		pass = false;
	BSTree<int> test_tree ;				//create empty BST

	try
	{
		test_tree.InOrder();
	}
	catch (Exception& exception)		//pass if exception is caught
	{
		pass = true;
	}

	cout << "In order empty traversal test ";

	return pass;
}

bool pre_order_test()
{
	BSTree<int> test_tree = ReturnIntBST();		//create filled BST

	test_tree.PreOrder();						//output tree preordered and write to Pre_order.txt for testing
	cout << "Pre order traversal test ";

	return check_traversal_int("PreOrder");		//checks the order of the numbers from the traversal
}

bool pre_order_empty_test()
{
	bool		pass = false;
	BSTree<int> test_tree;				//create empty BST

	try
	{
		test_tree.PreOrder();
	}
	catch (Exception& exception)		//pass if exception is caught
	{
		pass = true;
	}

	cout << "Pre order empty traversal test";
	return true;
}

bool post_order_test()
{
	BSTree<int> test_tree = ReturnIntBST();		//create filled BST

	test_tree.PostOrder();						//output tree postordered and write to Post_order.txt for testing
	cout << "Pre order traversal test ";

	return check_traversal_int("PostOrder");		//checks the order of the numbers from the traversal
}

bool post_order_empty_test()
{
	bool		pass = false;
	BSTree<int> test_tree;				//create empty BST

	try
	{
		test_tree.PostOrder();
	}
	catch (Exception& exception)		//pass if exception is caught
	{
		pass = true;
	}

	cout << "Post order empty traversal test";
	return true;
}

bool breadth_first_test()
{
	bool pass = true;
	BSTree<int> test_tree = ReturnIntBST();		//create filled BST

	test_tree.BreadthFirst();

	cout << "breadth first traversal test";
	return check_traversal_int("Breadth_First");
}

bool breadth_first_empty_test()
{
	cout << "Breadth first empty traversal test";
	return true;
}



//complex-------------------------------------------------------------------
//----------------------------------------------------------------------------
bool default_ctor_complex_test()
{
	bool			pass		= true;
	BSNode<string>* default_top = nullptr;
	BSTree<string>	test_tree;

	if (test_tree.getRoot() != default_top)		//failst if root is not equal to default_top
		pass = false;

	cout << "Default constructor complex test";

	return pass;
}

bool one_arg_ctor_complex_test()
{
	bool			pass = true;
	BSTree<string>	BSTree_test(MONSTERS[0]);

	if (BSTree_test.getRoot()->getData() != MONSTERS[0])	//fails if Root of BST isn't Alatreon
		pass = false;

	cout << "1 arg constructor complex test";

	return pass;
}

bool insert_complex_test()
{
	bool			pass = true;
	BSTree<string>	tree_test;

	for (int i = 0; i < NUM_MONSTERS; i++)										//insert strings from MONSTERS into tree_test
		tree_test.setRoot(tree_test.Insert(tree_test.getRoot(), MONSTERS[i]));

	pass = Str_Trees_Equal(tree_test.getRoot());								//check each node is correct

	cout << "Insert complex test";

	return pass;
}

bool purge_complex_test()
{
	bool			pass = true;
	BSTree<string>	tree_test;

	for (int i = 0; i < NUM_MONSTERS; i++)											//insert strings from MONSTERS into tree_test
		tree_test.setRoot(tree_test.Insert(tree_test.getRoot(), MONSTERS[i]));

	tree_test.setRoot(tree_test.Purge(tree_test.getRoot()));						//purge BST
	if (tree_test.getRoot() != nullptr)												//if tree_test's Root isn't nullptr, test fails
		pass = false;

	cout << "Purge comlplex test";

	return pass;
}

bool copy_ctor_and_copytree_complex_test()
{
	//copy constructor uses copyTree so this tests both at the same time
	bool			pass = true;
	BSTree<string>	test_tree;

	for (int i = 0; i < NUM_MONSTERS; i++)										//insert MONSTERS onto test_tree
		test_tree.setRoot(test_tree.Insert(test_tree.getRoot(), MONSTERS[i]));

	BSTree<string> tree_test(test_tree);										//creates tree_test using test_tree as an argument

	pass = Str_Trees_Equal(tree_test.getRoot());								//check each node is correct

	cout << "Copy constructor and copyTree complex test";

	return pass;
}

bool move_ctor_complex_test()
{
	bool			pass = true;
	BSTree<string>	test_tree(ReturnStrBST());		//create BST using another BST

	pass = Str_Trees_Equal(test_tree.getRoot());	//check each node is correct

	cout << "Move constructor complex test";

	return pass;
}

bool op_equal_complex_test()
{
	bool			pass = true;
	BSTree<string>	tree_test;
	BSTree<string>	test_tree;

	tree_test = ReturnStrBST();
	for (int i = 0; i < NUM_MONSTERS; i++)										//insert strings from MONSTERS into tree_test
		tree_test.setRoot(tree_test.Insert(tree_test.getRoot(), MONSTERS[i]));

	test_tree = tree_test;														//use equal operator
	pass = Str_Trees_Equal(test_tree.getRoot());								//check each node is correct

	cout << "Operator equals complex test";

	return pass;
}

bool move_op_equal_complex_test()
{
	bool			pass = true;
	BSTree<string>	tree_test;

	tree_test = ReturnStrBST();							//use move operator
	pass = Str_Trees_Equal(tree_test.getRoot());		//check each node is correct

	cout << "Move Operator equals complex test";

	return pass;
}

bool delete_complex_test()
{
	bool			pass = true;
	BSTree<string>	tree_test;
	BSTree<string>	left_test;
	BSTree<string>	leftend_test;
	BSTree<string>	right_test;
	BSTree<string>	rightend_test;

	for (int i = 0; i < NUM_VALUES; i++)					//insert strings from MONSTERS into the 5 BST
	{
		tree_test.setRoot(tree_test.Insert(tree_test.getRoot(), MONSTERS[i]));
		left_test.setRoot(left_test.Insert(left_test.getRoot(), MONSTERS[i]));
		right_test.setRoot(right_test.Insert(right_test.getRoot(), MONSTERS[i]));
		leftend_test.setRoot(leftend_test.Insert(leftend_test.getRoot(), MONSTERS[i]));
		rightend_test.setRoot(rightend_test.Insert(rightend_test.getRoot(), MONSTERS[i]));
	}

	tree_test.setRoot(tree_test.Delete(tree_test.getRoot(), "Valstrax"));		//test deleting root. if root isn't 7, test fails
	if (tree_test.getRoot()->getData() != "Valstrax")
		pass = false;

	left_test.setRoot(left_test.Delete(left_test.getRoot(), "Valstrax"));		//test deleting left node with children. if node isn't 4, test fails
	if (left_test.getRoot()->getLeft()->getData() != "Valstrax")
		pass = false;

	right_test.setRoot(right_test.Delete(right_test.getRoot(), "Valstrax"));		//test deleting right node with children. if node isn't 20, test fails
	if (right_test.getRoot()->getRight()->getData() != "Valstrax")
		pass = false;

	leftend_test.setRoot(leftend_test.Delete(leftend_test.getRoot(), "Valstrax"));		//test deleting left node with no children. if node isn't nullptr, test fails
	if (leftend_test.getRoot()->getLeft()->getLeft() != nullptr)
		pass = false;

	rightend_test.setRoot(rightend_test.Delete(rightend_test.getRoot(), "Valstrax"));		//test deleting right node with no children. if node isn't nullptr, test fails
	if (rightend_test.getRoot()->getRight()->getRight() != nullptr)
		pass = false;

	cout << "Delete test";

	return pass;
}

bool delete_empty_complex_test()
{
	bool			pass = false;
	BSTree<string>	tree_test;

	try																		//pass is true if deleting from empty BST throws exception
	{
		tree_test.setRoot(tree_test.Delete(tree_test.getRoot(), "Valstrax"));
	}
	catch (Exception& exception)
	{
		pass = true;
	}

	cout << "Delete empty tree complex test";

	return pass;
}

bool height_complex_test()
{
	bool			pass = true;
	BSTree<string>	test_tree = ReturnStrBST();					//create filled BST

	if (test_tree.Height(test_tree.getRoot()) != 3)
		pass = false;

	//if (test_tree.Height(test_tree.getRoot(), 3, 0) != 2)	//test fails if height isn't 2
		//pass = false;

	//if (test_tree.Height(test_tree.getRoot(), 5, 0) != 1)	//test fails if height isn't 1
		//pass = false;

	//if (test_tree.Height(test_tree.getRoot(), 20, 0) != 3)	//test fails if height isn't 3
		//pass = false;

	cout << "Height complex test";

	return pass;
}

bool in_order_complex_test()
{
	BSTree<string> test_tree = ReturnStrBST();		//create filled BST

	test_tree.InOrder();							//output tree in order and write to In_order.txt for testing
	cout << "In order traversal complex test ";

	return check_traversal_string("InOrder");		//checks the order of the numbers from the traversal
}

bool in_order_empty_complex_test()
{
	bool			pass = false;
	BSTree<string>	test_tree;				//create empty BST

	try
	{
		test_tree.InOrder();
	}
	catch (Exception& exception)		//pass if exception is caught
	{
		pass = true;
	}

	cout << "In order empty traversal complex test ";

	return pass;
}

bool pre_order_complex_test()
{
	BSTree<string> test_tree = ReturnStrBST();		//create filled BST

	test_tree.PreOrder();							//output tree preordered and write to Pre_order.txt for testing
	cout << "Pre order traversal complex test ";

	return check_traversal_int("PreOrder");			//checks the order of the numbers from the traversal
}

bool pre_order_empty_complex_test()
{
	bool			pass = false;
	BSTree<string>	test_tree;			//create empty BST

	try
	{
		test_tree.PreOrder();
	}
	catch (Exception& exception)		//pass if exception is caught
	{
		pass = true;
	}

	cout << "Pre order empty traversal complex  test";

	return true;
}

bool post_order_complex_test()
{
	BSTree<string> test_tree = ReturnStrBST();		//create filled BST

	test_tree.PostOrder();							//output tree postordered and write to Post_order.txt for testing
	cout << "Pre order traversal complex test ";

	return check_traversal_int("PostOrder");		//checks the order of the numbers from the traversal
}

bool post_order_empty_complex_test()
{
	bool			pass = false;
	BSTree<string>	 test_tree;			//create empty BST

	try
	{
		test_tree.PostOrder();
	}
	catch (Exception& exception)		//pass if exception is caught
	{
		pass = true;
	}

	cout << "Post order empty traversal complex test";
	return true;
}

bool breadth_first_complex_test()
{
	bool			pass		= true;
	BSTree<string>	test_tree	= ReturnStrBST();		//create filled BST

	test_tree.BreadthFirst();

	cout << "breadth first traversal complex test";
	return check_traversal_int("Breadth_First");
}

bool breadth_first_empty_complex_test()
{
	cout << "Breadth first empty traversal test";
	return true;
}





BSTree<int> ReturnIntBST()
{
	BSTree<int> temp_BST;							//create empty queue

	for (int i = 0; i < NUM_VALUES; i++)			//insert integers from VALUES into tree_test
		temp_BST.setRoot(temp_BST.Insert(temp_BST.getRoot(), VALUES[i]));

	return temp_BST;
}

BSTree<string> ReturnStrBST()
{
	BSTree<string> temp_BST;					//create empty BST

	for (int i = 0; i < NUM_MONSTERS; i++)		//populate temporary BST with strings from MONSTERS array
		temp_BST.setRoot(temp_BST.Insert(temp_BST.getRoot(), MONSTERS[i]));

	return temp_BST;
}


bool Int_Trees_Equal(BSNode<int>* root)
{
	bool check = true;

	//check if nodes match tree with balanced data from VALUES

	if (root->getData() != VALUES[0])							//check Root
		check = false;
	if (root->getLeft()->getData() != VALUES[1])				//check Root->Left
		check = false;
	if (root->getRight()->getData() != VALUES[2])				//check Root->Right
		check = false;
	if (root->getLeft()->getLeft()->getData() != VALUES[3])		//check Root->Left->Left
		check = false;
	if (root->getLeft()->getRight()->getData() != VALUES[4])	//check Root->Left->Right
		check = false;
	if (root->getRight()->getLeft()->getData() != VALUES[5])	//check Root->Right->Left
		check = false;
	if (root->getRight()->getRight()->getData() != VALUES[6])	//check Root->Right->Right
		check = false;


	//Check if ends of branches are nullptr

	if (root->getRight()->getRight()->getRight() != nullptr)	//check Root->Right->Right->Right
		check = false;
	if (root->getRight()->getRight()->getLeft() != nullptr)		//check Root->Right->Right->Left
		check = false; 

	if (root->getRight()->getLeft()->getRight() != nullptr)		//check Root->Right->Left->Right
		check = false;
	if (root->getRight()->getLeft()->getLeft() != nullptr)		//check Root->Right->Left->Left
		check = false;

	if (root->getLeft()->getLeft()->getLeft() != nullptr)		//check Root->Left->Left->Left
		check = false;
	if (root->getLeft()->getLeft()->getRight() != nullptr)		//check Root->Left->Left->Right
		check = false;

	if (root->getLeft()->getRight()->getLeft() != nullptr)		//check Root->Left->Right->Left
		check = false;
	if (root->getLeft()->getRight()->getRight() != nullptr)		//check Root->Left->Right->Right
		check = false;

	return check;
}

bool Str_Trees_Equal(BSNode<string>* root)
{
	bool check = true;

	//check if nodes match tree with balanced data from VALUES

	if (root->getData() != MONSTERS[0])							//check Root
		check = false;
	if (root->getLeft()->getData() != MONSTERS[1])				//check Root->Left
		check = false;
	if (root->getRight()->getData() != MONSTERS[2])				//check Root->Right
		check = false;
	if (root->getLeft()->getLeft()->getData() != MONSTERS[3])	//check Root->Left->Left
		check = false;
	if (root->getLeft()->getRight()->getData() != MONSTERS[4])	//check Root->Left->Right
		check = false;
	if (root->getRight()->getLeft()->getData() != MONSTERS[5])	//check Root->Right->Left
		check = false;
	if (root->getRight()->getRight()->getData() != MONSTERS[6])	//check Root->Right->Right
		check = false;


	//Check if ends of branches are nullptr

	if (root->getRight()->getRight()->getRight() != nullptr)	//check Root->Right->Right->Right
		check = false;
	if (root->getRight()->getRight()->getLeft() != nullptr)		//check Root->Right->Right->Left
		check = false;

	if (root->getRight()->getLeft()->getRight() != nullptr)		//check Root->Right->Left->Right
		check = false;
	if (root->getRight()->getLeft()->getLeft() != nullptr)		//check Root->Right->Left->Left
		check = false;

	if (root->getLeft()->getLeft()->getLeft() != nullptr)		//check Root->Left->Left->Left
		check = false;
	if (root->getLeft()->getLeft()->getRight() != nullptr)		//check Root->Left->Left->Right
		check = false;

	if (root->getLeft()->getRight()->getLeft() != nullptr)		//check Root->Left->Right->Left
		check = false;
	if (root->getLeft()->getRight()->getRight() != nullptr)		//check Root->Left->Right->Right
		check = false;

	return check;
}

//BSNode tests----------------------------------------------
//--------------------------------------------------------
bool bsnode_int_getLeft_empty_test()
{
	bool		pass = true;
	BSNode<int> node;

	if (node.getLeft() != nullptr)		//if getLeft() doesn't return a nullptr then test fails
		pass = false;


	return pass;
}

bool bsnode_int_getRight_empty_test()
{
	bool		pass = true;
	BSNode<int> node;

	if (node.getRight() != nullptr)		//if getRight() doesn't return a nullptr then test fails
		pass = false;

	return pass;
}

bool bsnode_int_getData_empty_test()
{
	bool		pass = true;
	BSNode<int> node;

	if (node.getLeft() != 0)		//if getData() doesn't return 0 then test fails
		pass = false;

	return pass;
}

bool bsnode_int_default_ctor_test()
{
	bool pass = true;

	BSNode<int> node;

	if (node.getLeft() != nullptr || node.getRight() != nullptr || node.getData() != 0)		//if returned values don't match then test fails
		pass = false;

	return pass;

}

bool bsnode_int_1_arg_ctor_test()
{
	bool pass = true;

	BSNode<int> node(5);

	if (node.getLeft() != nullptr || node.getRight() != nullptr || node.getData() != 5)		//if returned values don't match then test fails
		pass = false;

	return pass;

}

bool bsnode_int_setData_test()
{
	bool		pass = true;
	BSNode<int> node;

	node.setData(VALUES[0]);

	if (node.getData() != 5)		//if data returned isn't equal to 5 then test fails
		pass = false;

	return pass;
}

bool bsnode_int_setLeft_test()
{
	bool			pass	= true;
	BSNode<int>*	node_a	= new BSNode<int>;
	BSNode<int>*	node_b	= new BSNode<int>(7);
	BSNode<int>*	node_c	= new BSNode<int>(8);
	BSNode<int>*	node_d	= new BSNode<int>;

	node_b->setLeft(node_a);
	node_b->setRight(node_c);

	node_d->setLeft(node_b);

	if (node_d->getLeft() != node_b)		//if the nodes aren't equal then the test fails
		pass = false;

	return pass;
}

bool bsnode_int_setRight_test()
{
	bool			pass	= true;
	BSNode<int>*	node_a	= new BSNode<int>(5);
	BSNode<int>*	node_b	= new BSNode<int>(7);
	BSNode<int>*	node_c	= new BSNode<int>(8);
	BSNode<int>*	node_d;

	node_b->setLeft(node_a);
	node_b->setRight(node_c);

	node_d = node_b;

	if (node_d->getRight() != node_b->getRight() || node_d->getLeft() != node_b->getLeft() || node_d->getData() != node_b->getData())		//if the nodes aren't equal then the test fails
		pass = false;

	return pass;
}

bool bsnode_int_op_equal_test()
{
	bool			pass	= true;
	BSNode<int>*	node_a	= new BSNode<int>(5);
	BSNode<int>*	node_b	= new BSNode<int>(7);
	BSNode<int>*	node_c	= new BSNode<int>(8);
	BSNode<int>*	node_d	= new BSNode<int>;

	node_b->setLeft(node_a);
	node_b->setRight(node_c);
	node_d->setRight(node_b);

	node_d = node_b;

	if (node_d != node_b)		//if the nodes aren't equal then the test fails
		pass = false;

	return pass;
}

bool check_traversal_int(string trav_type)
{
	int BreadthFirst[7] = { 5,3,10,1,4,7,20 };
	int Inorder[7] = { 1,3,4,5,7,10,20 };
	int Postorder[7] = { 1,4,3,7,20,10,5 };
	int Preorder[7] = { 5,3,1,4,10,7,20};
	//int bst_holder[7];
	bool check = true;
	ifstream fpr;
	string data;
	int i = 0;	
	
	if (trav_type == "BreadthFirst")			//if being used to check InOrder function
	{
		fpr.open("Breadth_First.txt");			//open file from in order traversal
		while (getline(fpr, data, ' '))
		{
			if ((stoi(data)) != Inorder[i])		//convert string number to an integer and compare to what it should be
				check = false;

			i++;
		}

		fpr.close();
	}
	if (trav_type == "InOrder")					//if being used to check InOrder function
	{
		fpr.open("In_order.txt");				//open file from in order traversal
		while (getline(fpr, data , ' '))
		{
			if((stoi(data)) != Inorder[i])		//convert string number to an integer and compare to what it should be
				check = false;

			i++;
		}

		fpr.close();
	}

	if (trav_type == "PostOrder")				//if being used to check PostOrder function
	{
		fpr.open("Post_order.txt");				//open file from post order traversal
		while (getline(fpr, data, ' '))
		{
			if ((stoi(data)) != Postorder[i])	//convert string number to an integer and compare to what it should be
				check = false;

			i++;
		}

		fpr.close();
	}

	if (trav_type == "PreOrder")				//if being used to check PreOrder function
	{
		fpr.open("Pre_order.txt");				//open file from pre order traversal
		while (getline(fpr, data, ' '))
		{
			if ((stoi(data)) != Preorder[i])	//convert string number to an integer and compare to what it should be
				check = false;

			i++;
		}

		fpr.close();
	}

	return check;
}

bool check_traversal_string(string trav_type)
{
	int BreadthFirst[7] = { 5,3,10,1,4,7,20 };
	int Inorder[7] = { 1,3,4,5,7,10,20 };
	int Postorder[7] = { 1,4,3,7,20,10,5 };
	int Preorder[7] = { 5,3,1,4,10,7,20 };
	//int bst_holder[7];
	bool check = true;
	ifstream fpr;
	string data;
	int i = 0;

	if (trav_type == "BreadthFirst")			//if being used to check InOrder function
	{
		fpr.open("Breadth_First.txt");			//open file from in order traversal
		while (getline(fpr, data, ' '))
		{
			if ((stoi(data)) != Inorder[i])		//convert string number to an integer and compare to what it should be
				check = false;

			i++;
		}

		fpr.close();
	}
	if (trav_type == "InOrder")					//if being used to check InOrder function
	{
		fpr.open("In_order.txt");				//open file from in order traversal
		while (getline(fpr, data, ' '))
		{
			if ((stoi(data)) != Inorder[i])		//convert string number to an integer and compare to what it should be
				check = false;

			i++;
		}

		fpr.close();
	}

	if (trav_type == "PostOrder")				//if being used to check PostOrder function
	{
		fpr.open("Post_order.txt");				//open file from post order traversal
		while (getline(fpr, data, ' '))
		{
			if ((stoi(data)) != Postorder[i])	//convert string number to an integer and compare to what it should be
				check = false;

			i++;
		}

		fpr.close();
	}

	if (trav_type == "PreOrder")				//if being used to check PreOrder function
	{
		fpr.open("Pre_order.txt");				//open file from pre order traversal
		while (getline(fpr, data, ' '))
		{
			if ((stoi(data)) != Preorder[i])	//convert string number to an integer and compare to what it should be
				check = false;

			i++;
		}

		fpr.close();
	}

	return check;
}