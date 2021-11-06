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
	};
}
