class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0, right = (long long)sqrt((long long)c);
        while(left <= right) {
            if(left * left + right * right == c) return true;
            else if(left * left + right * right > c) right--;
            else left++;
        }

        return false;
    }
};