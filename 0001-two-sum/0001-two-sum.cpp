#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_index;  // value -> index
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            // If complement is already in the map, return the pair
            if (num_to_index.find(complement) != num_to_index.end()) {
                return {num_to_index[complement], i};
            }
            
            // Store current number and its index
            num_to_index[nums[i]] = i;
        }
        
        return {}; // Shouldn't be reached (as per problem constraint)
    }
};
