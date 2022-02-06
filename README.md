[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6832787&assignment_repo_type=AssignmentRepo)
# CST211-Lab7
Lab 7
Binary Search Tree
Description
Create a Binary Search Tree ADT as discussed in class.
Stipulations
You will need to create your own class diagram including the correct relationship. This must be submitted with your program. I suggest you use Dia.
You must include the following functions.
* Insert
* Delete
* Purge
* Height
* InOrder Traversal
* PreOrder Traversal
* PostOrder Traversal
* BreadthFirst Traversal
* Appropriate Manager Functions

All traversal functions must accept a function pointer to the visit function to be called. See the example below.
* //BSTree method 
* void BSTree::InOrder(BSNode* root, void (*visit)(T data))
* {
* }
* //Consumer function
* void Display(int data)
* {
* 	cout << data << endl;
* }

* //Consumer call to the InOrder traversal
* bst.InOrder(Display);

Deliverables

One file including:
* Your code
* Your test(s) similar to Lab1_test.cpp & Lab2_test.cpp and their results
