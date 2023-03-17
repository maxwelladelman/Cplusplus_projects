#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
using namespace std;





class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        set<int> set2;
        for (int k : nums1) {
            set1.insert(k);
        }
        for (int k : nums2) {
            set2.insert(k);
        }

        vector<int> out;

        for (int k : set1) {
            if (set2.find(k) != set2.end()) {
                out.push_back(k);
            }
        }


        return out;
    }
};

int main() {


    vector<int> nums1 = { 4,9,5 };
    vector<int> nums2 = { 9,4,9,8,4 };

    Solution sol;

   vector<int> inter = sol.intersection(nums1, nums2);


    for (int k : inter) {
        cout << k << " ";
    }









}





