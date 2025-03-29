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
      vector<ll> v(n), vv(m);
      for (auto &it : v)
      {
            cin >> it;
      }
      for (auto &it : vv)
      {
            cin >> it;
      }
      sort(begin(vv), end(vv));
      ll cur = -1e18;

      vector<ll> ans(n);
      for (int i = 0; i < n; i++)
      {
            ll f = v[i];

            ll s = v[i];

            auto it = lower_bound(begin(vv), end(vv), cur + v[i]) - begin(vv);

            if (it != m)
            {
                  s = vv[it] - v[i];
            }
            if (f >= cur)
            {
                  ans[i] = min(f, s);
            }
            else
            {
                  ans[i] = s;
            }
            cur = ans[i];
      }

      for (int i = 1; i < n; i++)
      {
            if (ans[i] < ans[i - 1])
            {
                  cout << "no" << endl;
                  return;
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