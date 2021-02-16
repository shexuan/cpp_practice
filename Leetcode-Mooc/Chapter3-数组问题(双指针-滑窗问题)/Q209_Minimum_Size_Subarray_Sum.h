//
// Created by shexuan on 2021/2/16.
//

#ifndef __Q209_MINIMUM_SIZE_SUBARRAY_SUM_H
#define __Q209_MINIMUM_SIZE_SUBARRAY_SUM_H
#include <climits>
#include <vector>
#include <string>
using  namespace std;

// 双指针 + 滑窗


// 官方题解：暴力法
class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum >= s) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

//作者：LeetCode-Solution
//        链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/chang-du-zui-xiao-de-zi-shu-zu-by-leetcode-solutio/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// 官方题解：优化双指针法
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int slow=0, fast = 0;
        int sum, ret = 1000000;
        sum = 0;
        if(sum>=target) return 1;

        while(fast<n){
            sum+=nums[fast];
            while(slow<=fast && sum>=target){ // sum>=target时候，从左边减去数字
                ret = min(ret, fast-slow+1);
                sum-=nums[slow++];
            }
            fast++;
        }
        return ret==1000000?0:ret;
    }
};

#endif //__Q209_MINIMUM_SIZE_SUBARRAY_SUM_H
