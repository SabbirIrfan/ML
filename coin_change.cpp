
#include <iostream>
#include <cstdio>
#include <cstring>
  using namespace std;
  int abs(int a)
  {
      if(a>0) return a;
      return -a;
  }
 int main()
 {
     int n,m,i,j;
     int a[1005],dp[100005];
     scanf("%d",&n);
     while(n--)
     {
         int sum=0,s;
         cin>>m;
         for(i=0; i<m; i++)
         {
             cin>>a[i];
             sum+=a[i];
         }
         s=sum/2;     ///Ask the average as a maximum backpack capacity consisting of backpack capacity
         memset(dp,0,sizeof(dp));
         for(int i=0; i<m; i++){
            for(int j = sum/2; j>=a[i]; j--){
                if(dp[j]< dp[j-a[i]] + a[i])
                    dp[j] = dp[j-a[i]] + a[i];
            }
         }
         cout<<abs(sum-dp[s]-dp[s])<<endl;

     }
     return 0;
 }
