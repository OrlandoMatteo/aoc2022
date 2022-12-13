#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main()
{
	string input;
	// generate map to map each letter to its position

	// Read from the text file

	ifstream inputFile("input");

	int spriteCenter = 1;
	int operation = 0;
	int stops[6] = {20, 60, 100, 140, 180, 220};
	int counter = 0;
	vector<int> reg;
	vector<int> inst;

	while (getline(inputFile, input))
	{
		// read input
		if (input.rfind("addx") == 0)
		{
			sscanf(input.c_str(), "addx %d", &operation);
			inst.emplace_back(0);
			inst.emplace_back(operation);
		}
		else
		{
			inst.emplace_back(0);
		}
	}
	// 4 cycle or 40
	
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 40; col++)
		{
			if (col==spriteCenter-1 || col==spriteCenter|| col==spriteCenter+1){
				cout<<"#";
			}
			else{
				cout<<" ";
			}
 			spriteCenter+=inst[counter];
			counter++;
		}
		cout<<endl;
	}
}
