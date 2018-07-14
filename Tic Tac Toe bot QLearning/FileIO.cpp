#include "FileIO.h"



void FileIO::saveScore(string path, int score)
{
	ofstream file(path, ios::app);
	file << score << " ";
	file.close();
}

FileIO::FileIO()
{
}


FileIO::~FileIO()
{
}
