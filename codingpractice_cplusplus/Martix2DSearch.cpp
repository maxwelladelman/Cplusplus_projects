#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);


int main() {
	
    vector<vector<int>> vect
    {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23,30, 34, 60}
    };

    int target = 34;
    cout << searchMatrix(vect, target);






}


bool searchMatrix(vector<vector<int>>& matrix, int target) {

    for (int k = 0; k < matrix.size(); k++) {

        for (int n = 0; n < matrix[k].size(); n++) {

            if (matrix[k][n] == target) return true;
        }


    }

	return false;
}