/*
Mr. Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home. Each location of
the office, his home, and the customers is given in the form of integer coordinates (x,y) (0≤x≤100, 0≤y≤100) . The distance between two arbitrary locations
(x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his
home, and the customers are all distinct. You should plan an optimal way to visit all the N customers and return to his among all the possibilities.
You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers is in the range of 5 to 10. Write a program that,
 starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. Your program only have to report the distance of
  a (the) shortest path.

Constraints

5≤N≤10. Each location (x,y) is in a bounded grid, 0≤x≤100, 0≤y≤100, and x, y are integers.

Input

You are given 10 test cases. Each test case consists of two lines; the first line has N, the number
 of the customers, and the following line enumerates the locations of the office, Mr. Kim’s home, and
 the customers in sequence. Each location consists of the coordinates (x,y), which is reprensented by ‘x y’.

Output

Output the 10 answers in 10 lines. Each line outputs the distance of a (the) shortest path.
 Each line looks like ‘#x answer’ where x is the index of a test case. ‘#x’ and ‘answer’ are separated by a space
*/
// Problem link: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/kim-and-refrigerators/submissions/code/1354123772

#include <iostream>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)
#define inf 1e9
int t,n, dp[1<<13][13], dist[13][13], arr[13][2], visited_all,p;

int abs(int x)
{
    if(x<0) return -x;
    return x;
}

int tsp(int mask, int pos)
{
    if(mask == visited_all) return dist[pos][n+1];  // because kim has to go home..

    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = inf;
    REP(i,0,n+1){
        if((mask&(1<<i)) == 0){
            int newAns = dist[pos][i] + tsp(mask|(1<<i), i);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
    t = 10;
    REP(k,1,t+1)
    {
        cin >> n;
        visited_all = (1<<(n+1)) - 1;
        p = 1<<(n+1);
        REP(i,0,p) REP(j,0,n+1) dp[i][j] = -1;
        cin >> arr[0][0] >> arr[0][1];
        cin >> arr[n+1][0] >> arr[n+1][1];
        REP(i,1,n+1) cin >> arr[i][0] >> arr[i][1];

        REP(i,0,n+2)REP(j,i+1,n+2){
            dist[i][j] = abs(arr[i][0]-arr[j][0]) + abs(arr[i][1]-arr[j][1]);
            dist[j][i] = dist[i][j];
        }


        cout << "# " << k << " " << tsp(1,0) << "\n";
    }

}
