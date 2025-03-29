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
      string a, b;

      cin >> a >> b;
      vector<int> pos(26, -1);

      for (int i = 1; i < a.size(); i++)
      {
            ll id = a[i] - 'a';

            if (pos[id] == -1)
            {
                  pos[id] = i;
            }
      }

      ll dis = 1e10;

      ll f = -1;
      ll s = -1;

      for (int i = b.size() - 2; i >= 0; i--)
      {
            ll id = b[i] - 'a';
            if (pos[id] != -1)
            {
                  ll tot_len = b.size() - i + pos[id] + 1;

                  if (tot_len < dis)
                  {
                        dis = tot_len;
                        f = pos[id];
                        s = i;
                  }
            }
      }

      if (f == -1)
      {
            cout << -1 << endl;
            return;
      }

      string fs = a.substr(0, f);
      string ss = b.substr(s);

      string ans = fs + ss;

      cout << ans << endl;
}
int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t = 1;
      // cin >> t;
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}