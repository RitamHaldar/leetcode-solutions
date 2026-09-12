class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
    int n = nums.size();

    if (n <= 2) return true;

    int i = 0;
    int j = n - 1;

    bool increasing = true;
    bool decreasing = true;

    while (i < j) {
        if (nums[i] > nums[i + 1])
            increasing = false;

        if (nums[i] < nums[i + 1])
            decreasing = false;

        if (nums[j - 1] > nums[j])
            increasing = false;

        if (nums[j - 1] < nums[j])
            decreasing = false;

        i++;
        j--;
    }

    return increasing || decreasing;
    }
};
