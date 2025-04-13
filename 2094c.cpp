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
      int n;
      cin >> n;
      vector<vector<ll>> v(n, vector<ll>(n));
      for (auto &it : v)
      {
            for (auto &i : it)
                  cin >> i;
      }

      vector<int> vis(2 * n + 2);
      bool flag = 0;

      vector<ll> ans(2 * n + 2);
      ll low = 1;
      ll high = 1;

      while (low + high <= 2 * n)
      {
            ll id = low + high;
            ans[id] = v[low - 1][high - 1];
            vis[ans[id]] = 1;

            if (flag)
            {
                  flag = 0;
                  low++;
            }
            else
            {
                  flag = 1;
                  high++;
            }
      }

      for (int i = 1; i <= 2 * n; i++)
      {
            if (!vis[i])
            {

                  ans[1] = i;
                  break;
            }
      }
      for (int i = 1; i <= 2 * n; i++)
            cout << ans[i] << " ";
      cout << endl;
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