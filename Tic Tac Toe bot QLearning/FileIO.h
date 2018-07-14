#pragma once

#include <string>
#include <fstream>

using namespace std;

class FileIO
{
public:
	static void saveScore(string path, int score);

private:
	FileIO();
	~FileIO();
};