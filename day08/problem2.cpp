#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
	// generate map to map each letter to its position
	string input;
	vector<vector<int>> grid;
	vector<vector<int>> visible;
	ifstream inputFile("input");
	char item = '_';
	int nOfStacks;
	int ROW = 0;
	int COL = 0;
	while (getline(inputFile, input))
	{
		grid.emplace_back();
		visible.emplace_back();
		for (COL = 0; COL < input.size(); COL++)
		{
			// if (COL == 0) {
			//   grid.at(ROW).emplace_back();
			// }
			char c = input.at(COL);
			grid.at(ROW).emplace_back(atoi(&c));
			visible.at(ROW).emplace_back(0);
		}
		ROW++;
	}
	int u = 0;
	int d = 0;
	int l = 0;
	int r = 0;
	int MaxScenicScore = 0;
	int scenicScore = 0;
	for (int row = 0; row < grid.size(); row++)
	{
		for (int col = 0; col < grid.at(row).size(); col++)
		{
			// check the distance to the left
			for (int p = col - 1; p > -1; p--)
			{
				if (grid.at(row).at(col) > grid.at(row).at(p))
				{
					l++;
				}
				else
				{
					l++;
					break;
				}
			}
			// check the distance to the right
			for (int p = col + 1; p < grid.at(row).size(); p++)
			{
				if (grid.at(row).at(col) > grid.at(row).at(p))
				{
					r++;
				}
				else
				{	
					r++;
					break;
				}
			}
			// check the distance to the top
			for (int p = row - 1; p > -1; p--)
			{
				if (grid.at(row).at(col) > grid.at(p).at(col))
				{
					u++;
				}
				else
				{	
					u++;
					break;
				}
			}
			// check the distance to the bottom
			for (int p = row + 1; p < grid.size(); p++)
			{
				if (grid.at(row).at(col) > grid.at(p).at(col))
				{
					d++;
				}
				else
				{	
					d++;
					break;
				}
			}

			scenicScore = u * d * l * r;
			// check if scenicScore is the max
			if (scenicScore > MaxScenicScore)
			{
				MaxScenicScore = scenicScore;
			}
			visible.at(row).at(col) = scenicScore;
			//cout << visible.at(row).at(col);
			d = 0;
			u = 0;
			l = 0;
			r = 0;
			scenicScore = 0;
		}
		//cout << endl;
	};
	cout << MaxScenicScore << endl;
	return 0;
}
