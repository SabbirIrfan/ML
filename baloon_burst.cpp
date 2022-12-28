#include <iostream>
#include<vector>
using namespace std;

int n;
// recursive function to generate scores
int dp[100][100];

int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 1; len <= n; ++len)
            for (int left = 1; left <= n - len + 1; ++left) {
                int right = left + len - 1;
                for (int k = left; k <= right; ++k)
                    dp[left][right] = max(dp[left][right], nums[left-1]*nums[k]*nums[right+1] + dp[left][k-1] + dp[k+1][right]);
            }
        return dp[1][n];
    }

int main() // driver function
{


    cin>>n;

    vector<int> arr;

    for(int i=1;i<=n;i++){
        int t ;
        cin>>t;
        arr.push_back(t);
    }


    cout << maxCoins(arr)<< "\n";
    //}
    return 0;
}
/*
0
 0
1
4
 4
2
1 2
 4
3
1 2 3
 9
5
1 3 4 2 5
 50
5
1 1 1 1 1
 5
4
1 2 0 0
 6
3
1 0 0
 2
2
0 1
 2
10
1 2 3 4 0 9 8 7 7 6 5
 297
 */
