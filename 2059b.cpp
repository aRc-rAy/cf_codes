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

      ll k;
      cin >> k;

      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }

      if (k == n)
      {
            ll ans = 1;
            for (int i = 1; i < n; i += 2)
            {
                  if (v[i] != ans)
                  {
                        cout << ans << endl;
                        return;
                  }
                  ans++;
            }
            cout << ans << endl;
      }
      else
      {
            ll ans = 1;
            for (int i = 1; i < n; i++)
            {
                  if (v[i] != ans)
                  {
                        cout << ans << endl;
                        return;
                  }
                  if (n - 1 - i == k - 2)
                  {
                        break;
                  }
            }
            cout << ans + 1 << endl;
      }
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