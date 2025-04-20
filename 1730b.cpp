#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define debug(x) cerr << RED << "Line [" << __LINE__ << "]\t" << #x << " -> " << x << RESET << endl;
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}
void solve(ll test)
{
}
int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t = 1;
      cin >> t;
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}