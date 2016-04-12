#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\TreeTest_for_OliveTree\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		//define example trees to be tested on
		tree_Node* tree1 = new tree_Node(1, NULL, NULL);
			//		1
		tree_Node* tree2 = new tree_Node(2, NULL, NULL);
			//		2
		tree_Node* tree3 = new tree_Node(3, NULL, NULL);
			//		3
		tree_Node* tree4 = new tree_Node(4, tree1, tree2);
			//		4
			//   1	    2
		tree_Node* tree5 = new tree_Node(5, tree1, tree4);
			//				5
			//		 1			4
			//	  -		-	 1	   2
		tree_Node* tree6 = new tree_Node(6, tree3, tree3);
			//		6
			//	 3		3
		tree_Node* tree7 = new tree_Node(7, tree6, tree5);
			//					7
			//			6				5
			//		3		3		1		4
			//	-	  -   -	  -	  -	  -	  1	   2
		tree_Node* tree8 = new tree_Node(8, tree4, tree2);
			//			8
			//		4		2
			//   1	  2	  -   -
		TEST_METHOD(TestMethod1)
		{
			//tests ability to match data values correctly
			Assert::AreEqual(true, tree1->checkSameAs(new tree_Node(1, NULL, NULL)));
		}
		TEST_METHOD(TestMethod2)
		{
			//tests tree2 against
			//			2
			//		1		-
			//ability to distinguish differences in children - one NULL, one with a value
			Assert::AreEqual(false, tree2->checkSameAs(new tree_Node(2, new tree_Node(1, NULL, NULL), NULL)));
		}
		TEST_METHOD(TestMethod3)
		{
			//tests ability to return false on a node data value difference by checking tree3 against tree1
			Assert::AreEqual(false, tree3->checkSameAs(tree1));
		}
		TEST_METHOD(TestMethod4)
		{
			//tests tree4 against
			//			3
			//		1		2
			//to ensure false will still be returned if the two trees have 2 different main nodes but the same children
			Assert::AreEqual(false, tree4->checkSameAs(new tree_Node(3, new tree_Node(1, NULL, NULL), new tree_Node(2, NULL, NULL))));
		}
		TEST_METHOD(TestMethod5)
		{
			//tests tree5 against
			//				5
			//		1				4
			//	 -	    -		1		2
			//which is identical, but requires the method to correctly identify both active children and NULL children in comparisons
			Assert::AreEqual(true, tree5->checkSameAs(new tree_Node(5, new tree_Node(1, NULL, NULL), tree4)));
		}
		TEST_METHOD(TestMethod6)
		{
			//tests tree7 against
			//					7
			//			6				5
			//		3		3		1		4
			//	-	  -   -	  -	  -	  -	  1	   2
			//to ensure that a matching tree will still be identified after multiple embedded recursive calls
			Assert::AreEqual(true, tree7->checkSameAs(new tree_Node(7, new tree_Node(6, new tree_Node(3, NULL, NULL), new tree_Node(3, NULL, NULL)), 
				new tree_Node(5, new tree_Node(1, NULL, NULL), new tree_Node(4, new tree_Node(1, NULL, NULL), new tree_Node(2, NULL, NULL))))));
		}
		TEST_METHOD(TestMethod7)
		{
			//tests tree8 against 
			//						8
			//			4						2
			//		1		2				1		-
			//to ensure that 2 layers deep a NULL-value incongruency will still result in a false return
			Assert::AreEqual(false, tree8->checkSameAs(new tree_Node(8, new tree_Node(4, new tree_Node(1, NULL, NULL), new tree_Node(2, NULL, NULL)), new tree_Node(2, new tree_Node(1, NULL, NULL), NULL))));
		}
	};
}