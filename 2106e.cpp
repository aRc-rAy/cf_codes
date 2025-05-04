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
      ll n, q;
      cin >> n >> q;
      vector<ll> v(n + 1);
      unordered_map<ll, ll> ump;
      for (int i = 1; i <= n; i++)
      {
            cin >> v[i];
            ump[v[i]] = i;
      }

      while (q--)
      {
            ll l, r, k;
            cin >> l >> r >> k;

            ll act = ump[k];
            if (act < l || act > r)
            {
                  cout << -1 << " ";
                  continue;
            }
            ll ans = 0;
            ll usedmore = n - k;
            ll more = 0;

            ll less = 0;
            ll usedless = k - 1;

            while (l <= r)
            {
                  ll mid = (l + r) / 2;

                  if (v[mid] == k)
                  {
                        break;
                  }

                  if (act < mid)
                  {

                        r = mid - 1;
                        if (v[mid] < k)
                              more++;

                        usedmore--;
                  }
                  if (act > mid)
                  {

                        l = mid + 1;
                        if (v[mid] > k)
                              less++;

                        usedless--;
                  }

                  // debug(less);
                  // debug(more);
                  // debug(mid);
                  // debug(act);
            }

            if (usedless < 0 || usedmore < 0)
            {
                  cout << -1 << " ";
                  continue;
            }

            cout << 2 * max(less, more) << " ";
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