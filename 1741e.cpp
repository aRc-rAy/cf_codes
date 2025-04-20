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
      ll n;
      cin >> n;
      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }

      vector<bool> dp(n + 2, 0);
      dp[0] = 1;
      dp[n + 1] = 1;
      for (int i = 1; i <= n; i++)
      {
            int num = v[i - 1];

            if (i - num - 1 >= 0)
            {
                  dp[i] = dp[i] || dp[i - num - 1];
            }

            if (dp[i - 1])
            {
                  if (i + num <= n + 1)
                  {
                        dp[i + num] = 1;
                  }
            }
      }

      cout << (dp[n] ? "YES" : "NO") << endl;
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