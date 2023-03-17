#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>


using namespace std;
/// <summary>
/// FIND ANY TWO NUMBERS IN THE VECTOR THAT ADD UP TO THE TARGET
/// </summary>
class Solution {
public:

	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> myMap; //<VALUE, INDEX>
		vector<int> answer;
		//find the diff
		for (int k = 0; k < nums.size(); k++) {
			int diff = target- nums[k];
			//if diff exists in the vector, then we have an answer
			//example: target = 4; vector = [2,1,5,3]
			//for last element: diff = 4 - 3= 1; 1 is at index 1. therefore answer is [1,3]
			if (myMap.find(diff) != myMap.end()) {
				//if value found add both indicies to answer
				answer.push_back(k);//index of current element
				answer.push_back(myMap.find(diff)->second);
				return answer;
			}
			else {

				myMap.insert(make_pair(nums[k], k));


			}

		}
		//if nothing found just return empty vector
		return answer;
		



	}

	//TWO POINTER METHOD MUST BE SORTED
	vector<int> twoSumTwoPointer(vector<int>& nums, int target) {
		//sort(nums.begin(), nums.end());//O(nlogn)
		if (nums.size() < 1) return vector<int>();//if vector has zero of 1 elements, then just return
		vector<int> answer;
		int left = 0;
		int right = nums.size() - 1;

		while (left < right) {
			int sum = nums[left] + nums[right];

			if (sum == target) {
				answer.push_back(left);
				answer.push_back(right);
				return answer;

			}
			else if (sum < target) {
				left++;
			}
			else {
				//if sum > target move right leftwards
				right--;
			}



		}

		return answer;








	}

};



int main() {


	vector<int> nums = { 3,2,4};

	Solution sol;
	vector<int> answer = sol.twoSum(nums, 6);

	for (auto k : answer) {
		cout << k << " ";
	}
	cout << endl;


}