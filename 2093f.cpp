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
      vector<string> a(n);
      for (auto &it : a)
      {
            cin >> it;
      }
      vector<vector<string>> b(m, vector<string>(n));

      for (auto &v : b)
      {
            for (auto &it : v)
            {
                  cin >> it;
            }
      }

      ll maxi = 0;
      vector<bool> ispr(n, 0);
      for (int i = 0; i < m; i++)
      {
            int cur = 0;
            for (int j = 0; j < n; j++)
            {
                  cur += (a[j] == b[i][j]);
                  ispr[j] = ispr[j] || (a[j] == b[i][j]);
            }
            maxi = max(maxi, cur * 1LL);
      }

      for (auto it : ispr)
            if (!it)
            {
                  cout << -1 << endl;
                  return;
            }

      cout << n + (n - maxi) * 2 << endl;
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