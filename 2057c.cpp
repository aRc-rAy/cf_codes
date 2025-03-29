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
      ll l, r;
      cin >> l >> r;

      ll a, b;
      ll ans = 0;

      for (ll i = 32; i >= 0; i--)
      {
            ll b1 = 0;
            ll b2 = 0;

            if ((1ll << i) & l)
            {
                  b1 = 1;
            }
            if ((1LL << i) & r)
            {
                  b2 = 1;
            }

            if (b1 == b2)
            {
                  ans = ans + b1 * (1 << i);
            }
            else
            {
                  a = ans + (1LL << i);
                  b = a - 1;
                  break;
            }
      }
      ll c = 0;
      for (ll i = l; i <= r; i++)
      {
            if (i != a && i != b)
            {
                  c = i;
                  break;
            }
      }

      cout << a << " " << b << " " << c << endl;
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