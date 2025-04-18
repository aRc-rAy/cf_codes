#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define debug(x) cerr << RED << "Line [" << __LINE__ << "]\t" << #x << " -> " << x << RESET << endl;
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}
void solve(ll test)
{
      ll n, k;
      cin >> n >> k;

      if ((n & k) != k)
      {
            cout << -1 << endl;
            return;
      }

      set<ll> a, b;
      for (ll i = 0; i < 62; i++)
      {
            if ((1LL << i) & n)
                  a.insert(i);
      }
      for (ll i = 0; i < 62; i++)
      {
            if ((1LL << i) & k)
                  b.insert(i);
      }
      b.insert(66);
      ll first = *b.begin();

      auto lesser = a.lower_bound(first);

      if (lesser == a.begin())
      {
            if (n == k)
            {
                  cout << n << endl;
                  return;
            }
            cout << -1 << endl;
            return;
      }

      lesser = prev(lesser);

      ll num = *lesser;

      if (num + 1 == first)
      {
            cout << -1 << endl;
            return;
      }

      ll ans = (1LL << (num + 1));

      lesser = next(lesser);

      while (lesser != a.end())
      {
            ans += (1LL << (*lesser));
            lesser = next(lesser);
      }

      for (ll i = num + 1; i < 64; i++)
      {
            ll bit_n = (1LL << i) & n ? 1 : 0;
            ll bit_k = (1LL << i) & k ? 1 : 0;

            if (bit_n != bit_k)
                  ans = -1;
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