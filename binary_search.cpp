#include<bits/stdc++.h>

using namespace std;

int is_square(int n )
{
    int i = 0,j= n/3,mid,sq;
    if(n == 4 ) return 2;
    if(n==9) return 3;
    while(i<=j)
    {
        mid = i+(j-i)/2;
        sq = mid*mid;

        if(sq == n)
        {
            return mid;
        }
        else if(sq>n)
        {
            j = mid-1;
        }
        else
            i = mid +1;
    }
    return 0;

}
int main()
{
    int n;
    while(cin>>n)
    {

        if(!is_square(n)){
            cout<<"NO"<<endl;
        }
        else
            cout<<is_square(n)<<endl;
    }
}
