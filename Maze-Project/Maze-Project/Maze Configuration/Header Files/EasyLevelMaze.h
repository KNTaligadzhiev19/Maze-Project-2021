#pragma once
#include "MazeGenerationAlgorithm.h"
#include <fstream>

class EasyLevelMaze : public MazeGenerationAlgorithm
{
private:
	ofstream bestStatsForEasyLevelOut;
	ifstream bestStatsForEasyLevelIn;
public:

	EasyLevelMaze();

};

