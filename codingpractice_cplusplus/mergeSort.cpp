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



class Solution {
public:


	vector<int> mergeSort(vector<int>& nums) {

		int length = nums.size();
		if (length <= 1) return nums;
		int middle = length / 2;
		vector<int> leftV;
		vector<int> rightV;
		int n = 0; //right array iterator
		for (int k = 0; k < length; k++) {
			if (k < middle) {
				leftV.push_back(nums[k]);
			}
			else {
				rightV.push_back(nums[k]);
			}

		}
		vector<int> newLeft = mergeSort(leftV);
		vector<int> newRight = mergeSort(rightV);
		return merge(newLeft, newRight);


	}

	vector<int> merge(vector<int>& v1, vector<int>& v2) {


		vector<int> combined;


		int k = 0; //v1
		int n = 0; //v2

		while (k < v1.size() && n < v2.size()) {

			if (v1[k] < v2[n]) {
				combined.push_back(v1[k]);
				k++;

			}
			else if (v1[k] > v2[n]) {
				combined.push_back(v2[n]);
				n++;
			}
			else {
				//if equal
				combined.push_back(v1[k]);
				combined.push_back(v2[n]);
				n++;
				k++;
			}


		}
		//either k or n will not have completed
		while (k < v1.size()) {
			combined.push_back(v1[k]);
			k++;
		}

		while (n < v2.size()) {
			combined.push_back(v2[n]);
			n++;
		}


		return combined;





	}






};




int main() {

	vector<int> nums = { 3,7,8,5,4,2,6,1 };

	Solution sol;

	vector<int> answer;

	answer = sol.mergeSort(nums);

	for (auto c : answer) {
		cout << c << " ";
	}
	cout << endl;














}