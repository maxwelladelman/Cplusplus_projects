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
/// TAKE A VECTOR OF NUMBERS
/// AND RETURN ALL UNQIUE TRIPLETS THAT EQUATE TO ZERO
/// Input: nums = [-1,0,1,2,-1,-4]
///Output: [[-1, -1, 2], [-1, 0, 1]]
///Explanation :
/// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
///nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
///nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
/// 
/// </summary>


class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums, int target) {


        if (nums.size() < 3) return vector<vector<int>>();//return empty vector
        vector<vector<int>> answer;
        
        unordered_map<int, int> myMap; //<VALUE,INDEX>

        myMap.insert(make_pair(nums[0], 0));
        for (int k = 0; k < nums.size() - 1; k++) {

            for (int n = k + 1; n < nums.size(); n++) {

                int diff =target - (nums[k] + nums[n]);
                //if diff is in the vector nums, then return all indicies

                

                if (myMap.find(diff) != myMap.end()) {
                    //make sure what's found is not k or n, no repeats of indicies
                    if (myMap.find(diff)->second != k && myMap.find(diff)->second != n) {

                        cout << "diff index  :  " << myMap.find(diff)->second << endl;
                        vector<int> temp = { k,n,myMap.find(diff)->second };
                        sort(temp.begin(), temp.end());//sort em
                        
                        //if not already in the vector vector, add it
                        if (find(answer.begin(), answer.end(), temp) == answer.end()) {
                            answer.push_back(temp);
                        }

                    }


                }
                else {
                    myMap.insert(make_pair(nums[n], n));
                }


            }

        }
        return answer;
        












    }



    //THREE SUM BUT FOR SORTED ARRAYS ONLY
    vector<vector<int>> threeSumOther(vector<int>& nums) {


        if (nums.size() < 3) return vector<vector<int>>();//return empty vector
        set<vector<int>> combos; // holds array of the numbers and their sum
        vector<int> temp(3);
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size() - 2; k++) {

            for (int n = k + 1; n < nums.size()-1; n++) {

                for (int m = n + 1; m < nums.size(); m++) {
                    temp[0] = nums[k];
                    temp[1] = nums[n];
                    temp[2] = nums[m];
                    int sum = temp[0] + temp[1] + temp[2];
                    if (sum == 0) {
                        
                        combos.insert(temp);
                        
                    }
                
                }


            }


        }
        vector<vector<int>> results;

        for (auto c : combos) {
            results.push_back(c);
        }

        return results;

    }






 



};




int main() {


    
    Solution sol;

    vector<int> test = { -1,0,1,2,-1,-4 };


    vector<vector<int>> results = sol.threeSum(test,0);

    for (auto c : results) {

        int sum = 0;
        for (auto d : c) {
            
            cout << d << " ";
            
            sum += test[d];
           
        }

        cout <<"  answer =  "<< sum << endl;
    }






}