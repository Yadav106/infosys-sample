// Your birthday is coming soon and one of your friends, Alex, is thinking about a gift for you. He knows
// that you really like integer arrays with interesting properties.
// He selected two numbers, N and K and decided to write down on paper all integer arrays of length K
// (in form a[1], a[2], ..., a[K]), where every number a[i] is in range from 1 to N, and, moreover, a[i+1] is
// divisible by a[i] (where 1 < i <= K), and give you this paper as a birthday present.

#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[]) {
    int n, k;
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter k : ";
    cin >> k;
    
    vector<vector<int> > dp(k+1, vector<int>(n+1, 0));
    
    // base case
    // all values are 1 for row 1
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            // dp[i][j] = summation(dp[i-1][x]) where element on position
            // x is a divisor of j
            if (j == 1) {
                dp[i][j] = 1;
                continue;
            }
            
            for (int k = 1; k <= n; k++) {
                if (j % k == 0) {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
    }
    
    // sum all the values of the kth row to get the final answer
    int res = 0;
    
    for (int i = 1; i <= n; i++) {
        res += dp[k][i];
    }
    
    cout << "The number of possible arrays are : " << res << endl;
    return 0;
}
