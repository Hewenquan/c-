class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        
        // 左遍历：比左边大就+1
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
        }
        
        int right = 1, ret = 0;
        // 右遍历：比右边大就更新right
        for (int i = n-1; i >= 0; i--) {
            if (i < n-1 && ratings[i] > ratings[i+1])
                right = right + 1;
            else
                right = 1;
            
            ret += max(left[i], right);
        }
        return ret;
    }
};
