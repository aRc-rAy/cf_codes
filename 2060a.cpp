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
ll find(auto &v)
{
      ll cnt = 0;
      for (int t = 2; t < 5; t++)
      {
            if (v[t] == v[t - 1] + v[t - 2])
            {
                  cnt++;
            }
      }
      return cnt;
}
void solve(ll test)
{
      vector<ll> v(5);
      for (int i = 0; i < 2; i++)
      {
            cin >> v[i];
      }
      for (int i = 3; i < 5; i++)
      {
            cin >> v[i];
      }
      ll ans = 0;

      for (int t = -300; t <= 300; t++)
      {
            v[2] = t;
            ll tot = find(v);
            ans = max(ans, tot);
      }
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