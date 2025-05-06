class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
       vector<string> result;
        int n = nums.size();
        if (n == 0) return result;

        int start = nums[0];

        for (int i = 1; i <= n; ++i) {
            // At the end or if the current number is not consecutive
            if (i == n || nums[i] != nums[i - 1] + 1) {
                int end = nums[i - 1];

                // Format range
                if (start == end) {
                    result.push_back(to_string(start));
                } else {
                    result.push_back(to_string(start) + "->" + to_string(end));
                }

                // Start new range if not at the end
                if (i < n) start = nums[i];
            }
        }

        return result;
    } 

};