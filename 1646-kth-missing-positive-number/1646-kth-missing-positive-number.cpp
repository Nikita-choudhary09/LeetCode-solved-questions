class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low=0, high=n-1;
        
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(arr[mid]-(mid+1) < k) low = mid+1;
            else high = mid-1;
        }
        // arr[high]+more = arr[high]+(k-(arr[high]-(high-1))) = high+k+1
        return high+k+1;
    }
};