#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 998244353
#define MAXX 100005
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}

ll binpow(ll a, ll n)
{
      if (n == 0)
      {
            return 1LL;
      }

      ll ans = binpow(a, n / 2);

      ll mul = 1;

      if (n % 2)
            mul = (a) % mod;

      return (ans * ((ans * mul) % mod)) % mod;
}
void solve(ll test)
{
      ll n, q;
      cin >> n >> q;
      vector<ll> a(n), b(n);
      for (auto &it : a)
      {
            cin >> it;
      }
      for (auto &it : b)
      {
            cin >> it;
      }

      auto c = a;
      auto d = b;
      sort(begin(c), end(c));
      sort(begin(d), end(d));

      ll ans = 1;
      for (int i = 0; i < n; i++)
      {
            ans = (ans * min(c[i], d[i])) % mod;
            ans = ans % mod;
      }

      cout << ans << " ";

      for (int i = 0; i < q; i++)
      {
            ll type, id;
            cin >> type >> id;
            id--;
            if (type == 1)
            {
                  ll num = a[id];
                  ll idx = upper_bound(begin(c), end(c), a[id]) - begin(c) - 1;

                  ans = (ans * binpow(min(c[idx], d[idx]), mod - 2)) % mod;

                  ++c[idx];
                  a[id]++;
                  ans = (ans * min(c[idx], d[idx])) % mod;
            }
            else
            {
                  ll num = b[id];
                  ll idx = upper_bound(begin(d), end(d), b[id]) - begin(d) - 1;

                  ans = (ans * binpow(min(c[idx], d[idx]), mod - 2)) % mod;

                  ++b[id];
                  d[idx]++;
                  ans = (ans * min(c[idx], d[idx])) % mod;
            }

            cout << ans << " ";
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