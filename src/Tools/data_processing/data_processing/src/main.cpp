#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "getopt.h"
#include "data_processing.h"

using namespace std;

void printDebugColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
}

void pirntNormalColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main(int argc, char** argv)
{
	std::string data_file = "none";

	char c;
	while ((c = getopt(argc, argv, "d:h")) != EOF)
	{
		switch (c) {
		case 'd':
			data_file = optarg;
			break;
		default:
		case 'h':
			printf("-c data file\n\n");
			exit(0);
			break;
		}
	}

	printDebugColor();
	printf("=============================Read In============================\n");
	DataProcessing* dp = new DataProcessing();

	dp->readIn(data_file);
	printf("====================================================================\n");

	delete dp;

	return 0;
}
