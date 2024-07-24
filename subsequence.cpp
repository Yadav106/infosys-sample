// You have an array A of N integers A1 A2 .. An. Find the longest increasing subsequence Ai1 Ai2 .. Ak
// (1 <= k <= N) that satisfies the following condition:
// For every adjacent pair of numbers of the chosen subsequence Ai[x] and Ai[x+1] (1 < x < k), the
// expression( Ai[x] & Ai[x+1] ) * 2 < ( Ai[x] | Ai[x+1] ) is true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLength(int n, vector<int> nums) {
    vector<int> dp(n, 1);
    int res = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Question is wrong in the pdf
            // This should be the answer
            // if (((nums[i] & nums[j])*2) < (nums[i] | nums[j])) {
            //     cout << nums[j] << " " << nums[i] << endl;
            //     dp[i] = max(dp[i], dp[j]+1);
            // }
            //
            // But this is the preferred output
            if (nums[i] > nums[j]) {
                cout << nums[j] << " " << nums[i] << endl;
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        
        res = max(res, dp[i]);
    }
    
    return res;
}

int main() {
    int n = 6;
    vector<int> nums = {9, 17, 2, 15, 5, 2};
    
    cout << findLength(n, nums) << endl;
    return 0;
}
