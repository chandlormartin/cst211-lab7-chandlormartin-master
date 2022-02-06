#include "pch.h"
#include "CppUnitTest.h"
#include "../BlankConsoleLab/BST_Tests.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int fails = 0;

int testout(bool pass)
{
	if (pass)
	{
		cout << " has passed" << endl;
		return 0;
	}
	else
	{
		cout << " has <<<<failed>>>>" << endl;
		return 1;
	}
}

namespace BSTTests
{
	TEST_CLASS(BSNodesTests)
	{
	public:

//BSNode TESTS--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
		TEST_METHOD(test_bsnode_int_getLeft_empty)
		{
			cout << "bsnode_int_getLeft_empty_test" << endl;
			bool expected = true;
			bool actual = bsnode_int_getLeft_empty_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_bsnode_int_getRight_empty)
		{
			cout << "bsnode_int_getRight_empty_test" << endl;
			bool expected = true;
			bool actual = bsnode_int_getRight_empty_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_bsnode_int_getData_empty)
		{
			cout << "bsnode_int_getData_empty_test" << endl;
			bool expected = true;
			bool actual = bsnode_int_getData_empty_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_bsnode_int_default_ctor)
		{
			cout << "bsnode_int_default_ctor_test" << endl;
			bool expected = true;
			bool actual = bsnode_int_default_ctor_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_bsnode_int_1_arg_ctor)
		{
			cout << "bsnode_int_1_arg_ctor_test" << endl;
			bool expected = true;
			bool actual = bsnode_int_1_arg_ctor_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_bsnode_int_setData)
		{
			cout << "bsnode_int_setData_test" << endl;
			bool expected = true;
			bool actual = bsnode_int_setData_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_bsnode_int_setLeft)
		{
			cout << "bsnode_int_setLeft_test" << endl;
			bool expected = true;
			bool actual = bsnode_int_setLeft_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_bsnode_int_setRight)
		{
			cout << "bsnode_int_setRight_test" << endl;
			bool expected = true;
			bool actual = bsnode_int_setRight_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_bsnode_int_op_equal)
		{
			cout << "bsnode_int_op_equal_test" << endl;
			bool expected = true;
			bool actual = bsnode_int_op_equal_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}
	};
//BINARY SEARCH TREE TEST---------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
	TEST_CLASS(BSTreeTests)
	{
	public:
		TEST_METHOD(test_default_ctor)
		{
			cout << "test_default_ctor" << endl;
			bool expected = true;
			bool actual = default_ctor_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_one_arg_ctor)
		{
			cout << "1_arg_ctor_test" << endl;
			bool expected = true;
			bool actual = one_arg_ctor_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_insert)
		{
			cout << "insert_test" << endl;
			bool expected = true;
			bool actual = insert_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_purge)
		{
			cout << "purge_test" << endl;
			bool expected = true;
			bool actual = purge_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_copy_ctor_and_copytree)
		{
			cout << "copy_ctor_and_copytree_test" << endl;
			bool expected = true;
			bool actual = copy_ctor_and_copytree_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_move_ctor)
		{
			cout << "move_ctor_test" << endl;
			bool expected = true;
			bool actual = move_ctor_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_op_equal)
		{
			cout << "op_equal_test" << endl;
			bool expected = true;
			bool actual = op_equal_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_move_op_equal)
		{
			cout << "move_op_equal_test" << endl;
			bool expected = true;
			bool actual = move_op_equal_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_delete)
		{
			cout << "delete_test" << endl;
			bool expected = true;
			bool actual = delete_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_delete_empty)
		{
			cout << "delete_empty_test" << endl;
			bool expected = true;
			bool actual = delete_empty_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_height)
		{
			cout << "height_test" << endl;
			bool expected = true;
			bool actual = height_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_height_empty)
		{
			cout << "height_empty_test" << endl;
			bool expected = true;
			bool actual = height_empty_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}
		//complex tests-------------------------------------------------------------
		//-------------------------------------------------------------------------
		TEST_METHOD(test_default_ctor_complex)
		{
			cout << "default_ctor_complex_test" << endl;
			bool expected = true;
			bool actual = default_ctor_complex_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_one_arg_ctor_complex)
		{
			cout << "one_arg_ctor_complex_test" << endl;
			bool expected = true;
			bool actual = one_arg_ctor_complex_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(test_height_empty)
		{
			cout << "height_empty_test" << endl;
			bool expected = true;
			bool actual = height_empty_test();

			fails = fails + testout(actual);

			Assert::AreEqual(expected, actual);
		}

		//TEST_METHOD(test_height_empty_test)
		//{
		//	cout << "height_empty_test" << endl;
		//	bool expected = true;
		//	bool actual = height_empty_test();

		//	fails = fails + testout(actual);

		//	Assert::AreEqual(expected, actual);
		//}
	};

//TEST_METHOD(test_bsnode_int_getRight_empty)
		//{
		//	cout << "bsnode_int_getRight_empty_test" << endl;
		//	bool expected = true;
		//	bool actual = bsnode_int_getRight_empty_test();

		//	fails = fails + testout(actual);

		//	Assert::AreEqual(expected, actual);
		//}
		//TEST_METHOD(BSNode_int_default_test)
		//{
		//	cout << "bsnode_int_getLeft_empty_test" << endl;
		//	bool expected = true;
		//	bool actual = bsnode_int_getLeft_empty_test();


		//	Assert::AreEqual(expected, actual);
		//}
		//TEST_METHOD(BSNode_int_default_test)
		//{
		//	cout << "bsnode_int_getLeft_empty_test" << endl;
		//	bool expected = true;
		//	bool actual = bsnode_int_getLeft_empty_test();


		//	Assert::AreEqual(expected, actual);
		//}
		//TEST_METHOD(BSNode_int_default_test)
		//{
		//	cout << "bsnode_int_getLeft_empty_test" << endl;
		//	bool expected = true;
		//	bool actual = bsnode_int_getLeft_empty_test();


		//	Assert::AreEqual(expected, actual);
		//}
		//TEST_METHOD(BSNode_int_default_test)
		//{
		//	cout << "bsnode_int_getLeft_empty_test" << endl;
		//	bool expected = true;
		//	bool actual = bsnode_int_getLeft_empty_test();


		//	Assert::AreEqual(expected, actual);
		//}
		//TEST_METHOD(InsertTest)
		//{
		//	bool expected = true;

		//	bool thang = insert_test();


		//	Assert::AreEqual(expected, thang);
		//}
	

}
