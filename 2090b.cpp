#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}
void solve(ll test)
{
      int n, m;
      cin >> n >> m;
      vector<vector<ll>> v(n, vector<ll>(m, 0));
      for (int i = 0; i < n; i++)
      {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                  v[i][j] = s[j] - '0';
            }
      }

      // 1- upr se
      // 2- left se
      // 3- dono se

      vector<vector<ll>> dp(n, vector<ll>(m, 0));
      for (int i = 0; i < n; i++)
      {
            if (v[i][0])
                  dp[i][0] = 2;
      }
      for (int j = 0; j < m; j++)
      {
            if (v[0][j])
                  dp[0][j] = 1;
      }
      if (v[0][0])
            dp[0][0] = 3;

      for (int i = 1; i < n; i++)
      {
            for (int j = 1; j < m; j++)
            {
                  if (v[i][j])
                  {
                        // upr wala upr se aaya hai to usse lenge
                        ll upr = dp[i - 1][j];
                        if (upr & (1))
                        {
                              dp[i][j] += 1;
                        }

                        if ((dp[i][j - 1] & (1 << 1)))
                        {
                              dp[i][j] += 2;
                        }

                        if (dp[i][j] == 0)
                        {
                              cout << "no" << endl;
                              return;
                        }
                  }
            }
      }

      cout << "yes" << endl;
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