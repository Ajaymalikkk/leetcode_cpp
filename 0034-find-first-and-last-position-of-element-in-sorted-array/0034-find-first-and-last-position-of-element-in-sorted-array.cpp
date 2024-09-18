class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        result[0] = findStart(nums, target);
        if (result[0] != -1) {
            result[1] = findEnd(nums, target);
        }
        return result;
    }

private:
    int findStart(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int start = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                start = mid;
                right = mid - 1; // Move left to find the first occurrence
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return start;
    }

    int findEnd(const vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int end = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                end = mid;
                left = mid + 1; // Move right to find the last occurrence
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return end;
        
    }
};