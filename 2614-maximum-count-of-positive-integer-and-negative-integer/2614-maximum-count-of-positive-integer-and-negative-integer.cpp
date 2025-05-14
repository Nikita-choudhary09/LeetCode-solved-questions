class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(pos, neg);
    }
};
/* \U0001f3af Goal of the Problem:
You are given a sorted list of numbers (some may be negative, zero, or positive). You want to find out:

Which is greater: the number of negative numbers or the number of positive numbers?

You should ignore zeroes (they are neither negative nor positive).

✅ Example:
Let’s say this is your input:

cpp
Copy
Edit
nums = {-4, -2, -1, 0, 0, 1, 3, 5}
Negative numbers: -4, -2, -1 → 3 numbers

Zeroes: 0, 0 → ignored

Positive numbers: 1, 3, 5 → 3 numbers

Answer: return 3 because the maximum of positive and negative counts is 3.

\U0001f9e0 What’s the Trick in the Optimized Code?
Normally, you’d use a loop to count each number — that takes O(n) time.

But since the array is already sorted, we can use a faster way: binary search.

We use two special C++ functions:

1. lower_bound(nums.begin(), nums.end(), 0)
This finds the first place where 0 or more starts.

It tells us: how many numbers are less than 0 (i.e., negative numbers).

In our example:

cpp
Copy
Edit
nums = {-4, -2, -1, 0, 0, 1, 3, 5}
The first 0 is at index 3, so:

cpp
Copy
Edit
int neg = 3;
2. upper_bound(nums.begin(), nums.end(), 0)
This finds the first place where numbers become greater than 0.

We subtract that from the end to find how many positive numbers are at the end.

In our example:

The first number greater than 0 is at index 5 (nums[5] = 1)

Total numbers = 8 → so from index 5 to 7 are positive

cpp
Copy
Edit
int pos = 8 - 5 = 3;
✅ Final Step:
cpp
Copy
Edit
return max(pos, neg); // returns max(3, 3) = 3
\U0001f9fe Full Code Again (for Copy-Paste):
cpp
Copy
Edit
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0);
        return max(pos, neg);
    }
};
\U0001f4cc Summary for Beginners:
We use lower_bound to count negative numbers.

We use upper_bound to count positive numbers.

We ignore zeros.

This method is much faster than using a loop when the array is sorted.*/