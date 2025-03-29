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
      ll n, m, k;
      cin >> n >> m >> k;
      vector<ll> v(m);
      vector<ll> q(k);

      for (auto &it : v)
      {
            cin >> it;
      }
      for (auto &it : q)
      {
            cin >> it;
      }

      if (q.size() == n)
      {
            for (int i = 0; i < m; i++)
            {
                  cout << 1;
            }
            cout << endl;
            return;
      }
      if (q.size() < n - 1)
      {
            for (int i = 0; i < m; i++)
            {
                  cout << 0;
            }
            cout << endl;
            return;
      }
      vector<ll> dp(n + 1, -1);
      for (auto it : q)
      {
            dp[it] = 0;
      }
      for (int i = 0; i < m; i++)
      {
            ll t = v[i];
            if (dp[t] == 0)
            {
                  cout << 0;
            }
            else
            {
                  cout << 1;
            }
      }
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