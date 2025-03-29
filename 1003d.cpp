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
      ll n, q;
      cin >> n >> q;
      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }

      vector<ll> cnt(35);
      for (auto it : v)
      {
            for (ll i = 33; i >= 0; i--)
            {
                  if (it % (1LL << i) == 0)
                  {
                        cnt[i]++;
                        break;
                  }
            }
      }

      while (q--)
      {
            ll num;
            cin >> num;
            ll ans = 0;

            for (ll i = 33; i >= 0; i--)
            {
                  ll take = min(num / (1LL << i), cnt[i]);
                  num -= ((1LL << i) * take);
                  ans += take;
            }
            cout << ((num == 0) ? ans : -1) << endl;
      }
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