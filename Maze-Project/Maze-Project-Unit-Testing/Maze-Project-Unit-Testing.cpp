#include "pch.h"
#include "CppUnitTest.h"
#include "Maze Configuration/Header Files/MazeGenerationAlgorithm.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MazeProjectUnitTesting
{
	TEST_CLASS(Testing_MazeGenertionAlgorithm)
	{
	public:
		
		TEST_METHOD(TestingFirstOptionOfFunction_chooseSize)
		{
			MazeGenerationAlgorithm test;

			int a = test.chooseSize(2);

			Assert::AreEqual(a, 8);
		}

		TEST_METHOD(TestingSecondOptionOfFunction_chooseSize)
		{
			MazeGenerationAlgorithm test;

			int a = test.chooseSize(1);

			Assert::AreEqual(a, 6);
		}
	};
}
