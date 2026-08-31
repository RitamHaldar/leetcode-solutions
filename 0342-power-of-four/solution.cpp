class Solution {
public:
    bool isPowerOfFour(int n) {
        float num=n/1.0;
        while (num>1.0) num=num/4.0;
        return num==1.0;
    }
};
