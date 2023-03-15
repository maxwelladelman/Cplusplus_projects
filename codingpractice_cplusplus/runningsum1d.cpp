#include <iostream>
#include <string>
#include <cmath>
#include <iomanip> 
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums);

//Input: nums = [1,2,3,4]
//Output: [1, 3, 6, 10]
//Explanation : Running sum is obtained as follows : [1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4] .
int main() {
	vector<int> nums = { 1,2,3,4 };

	/*cout << nums.size() << endl;*/
	vector<int> summed = runningSum(nums);

	for (int k = 0; k < summed.size(); k++) {
		cout << summed[k] << endl;
	}

}


vector<int> runningSum(vector<int>& nums) {
	vector<int> output(nums.size());
	
	int sum = 0;
	for (int k = 0; k < nums.size(); k++) {
		output[k] = nums[k] + sum;
		sum = output[k];
	}	

	

	return output;



}