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
			MazeGenerationAlgorithm testCase;

			int result = testCase.chooseSize(2);

			Assert::AreEqual(result, 8);
		}

		TEST_METHOD(TestingSecondOptionOfFunction_chooseSize)
		{
			MazeGenerationAlgorithm testCase;

			int result = testCase.chooseSize(1);

			Assert::AreEqual(result, 6);
		}

		TEST_METHOD(TestingWithOptionThatNotExist1InFunction_chooseSize)
		{
			MazeGenerationAlgorithm testCase;

			int result = testCase.chooseSize(0);

			Assert::AreEqual(result, 0);
		}

		TEST_METHOD(TestingWithOptionThatNotExist2InFunction_chooseSize)
		{
			MazeGenerationAlgorithm testCase;

			int result = testCase.chooseSize(3);

			Assert::AreEqual(result, 0);
		}

		TEST_METHOD(TestingFirstOptionOfFunction_MovePixelsSize)
		{
			MazeGenerationAlgorithm testCase;

			int result = testCase.movePixelSize(1);

			Assert::AreEqual(result, 80);
		}

		TEST_METHOD(TestingSecondOptionOfFunction_MovePixelsSize)
		{
			MazeGenerationAlgorithm testCase;

			int result = testCase.movePixelSize(2);

			Assert::AreEqual(result, 100);
		}
	};
}
