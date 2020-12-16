//
//  3sum.cpp
//  DecemberLeetcode
//
//  Created by Akshat Jindal on 12/16/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> triplets = {};
		if(nums.size() < 3)
			return triplets;
		
		
		sort(nums.begin(), nums.end());
		unordered_map<int, int> num_to_rightmost_index;
		for(int i = 0; i < nums.size(); ++i){
			auto iter = num_to_rightmost_index.find(nums[i]);
			if(iter == num_to_rightmost_index.end()){
				num_to_rightmost_index.insert(make_pair(nums[i], i));
			}
			else{
				iter->second = i;
			}
		}
		
		for(int a_th = 0; a_th < nums.size() - 2; ++a_th){
			if(a_th >= 1){
				if(nums[a_th-1] == nums[a_th]){
					a_th = num_to_rightmost_index.find(nums[a_th])->second;
					continue;
				}
			}//if the number to the left is the same then u can go to the rightmost occurence of this num.
			
			
			for(int b_th = a_th + 1; b_th < nums.size() - 1; ++b_th){
				if(b_th - 1 != a_th && nums[b_th] == nums[b_th - 1]){
					b_th = num_to_rightmost_index.find(nums[b_th])->second;
					continue;
				}//shift b_th to the right
				
				int complement = -1 * (nums[a_th] + nums[b_th]);
				auto compl_iter = num_to_rightmost_index.find(complement);
				if(compl_iter != num_to_rightmost_index.end()){
					if(compl_iter->second > b_th){
						vector<int> temp = {nums[a_th], nums[b_th], complement};
						triplets.push_back(temp);
					}
				}
			}//inner
		}
		
		
		return triplets;
	}
};


int main(){
	
}
