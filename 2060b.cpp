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
      ll n, m;
      cin >> n >> m;
      map<ll, set<ll>> ump;
      for (ll t = 0; t < n; t++)
      {
            for (int j = 0; j < m; j++)
            {
                  ll num;
                  cin >> num;
                  ump[t].insert(num % n);
            }
      }
      vector<pair<ll, ll>> vp;
      for (int t = 0; t < n; t++)
      {
            if (ump[t].size() > 1)
            {
                  cout << -1 << endl;
                  return;
            }
      }

      for (int t = 0; t < n; t++)
      {
            vp.push_back({
                *ump[t].begin() + 1,
                t + 1,
            });
            // cout << *ump[t].begin() + 1 << " ";
      }
      sort(begin(vp), end(vp));
      for (auto it : vp)
      {
            cout << it.second << " ";
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