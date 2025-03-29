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
      ll n;
      cin >> n;
      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }

      vector<vector<ll>> dp(n, vector<ll>(2005, 0));

      vector<ll> tot(n + 1, 0);

      for (int i = n - 1; i >= 0; i--)
      {

            dp[i][v[i]]++;

            for (int j = 1; j < 2004; j++)
            {
                  dp[i][j] += dp[i][j - 1];
            }

            for (int j = 0; j < 2004; j++)
            {
                  if (i + 1 < n)
                        dp[i][j] += dp[i + 1][j];
            }
      }

      ll ctot = 0;

      for (int i = n - 1; i >= 0; i--)
      {
            ll num = v[i];
            ll lower = dp[i][num - 1];

            ctot += lower;
            tot[i] = ctot;
      }

      ll curans = tot[0];

      ll l = 0, r = 0;
      for (int i = n - 1; i >= 0; i--)
      {
            ll num = v[i];
            for (int j = i; j < n; j++)
            {
                  ll cntlower = dp[i][num - 1];

                  ll cntHigher = dp[i][2002] - dp[i][num];

                  if (j + 1 < n)
                  {
                        cntlower -= dp[j + 1][num - 1];
                        cntHigher -= (dp[j + 1][2002] - dp[j + 1][num]);
                  }

                  ll allans = tot[0];
                  // reduce as I was larger
                  allans -= cntlower;
                  allans += cntHigher;

                  if (curans > allans)
                  {
                        curans = allans;
                        l = i;
                        r = j;
                  }
            }
      }
      cout << l + 1 << " " << r + 1 << endl;
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