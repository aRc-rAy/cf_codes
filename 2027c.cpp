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
unordered_map<ll, ll> dp;
ll dfs(auto &ump, ll len)
{
      if (ump.find(len) == ump.end())
      {
            // cout << "nhi mila" << endl;
            return 0;
      }
      if (dp.find(len) != dp.end())
      {
            return dp[len];
      }

      ll ans = 0;
      for (auto it : ump[len])
      {
            if (it - 1 > 0)
                  ans = max(ans, it - 1 + dfs(ump, len + it - 1));
      }
      return dp[len] = ans;
}
void solve(ll test)
{
      ll n;
      cin >> n;
      dp.clear();

      map<ll, vector<ll>> ump;
      for (int i = 1; i <= n; i++)
      {
            ll num;
            cin >> num;
            ll key = num + (i)-1;

            ump[key].push_back(i);

            // cout << key << " " << num << endl;
      }

      for (auto it : ump)
      {
            // cout << it.first << endl;
      }
      ll ans = 0;

      ans = dfs(ump, n) + n;

      cout << ans << endl;
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