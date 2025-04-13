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

      ll x;
      cin >> x;

      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      ll sum = 0;
      ll ans = 0;

      ll tot_sum = accumulate(begin(v), end(v), 0LL);

      for (int i = n - 1; i >= 0; i--)
      {
            sum += v[i];

            if (sum >= x)
            {
                  ans += k;
                  continue;
            }

            ll req = (x - sum) / (tot_sum);
            if ((x - sum) % tot_sum)
                  req++;
            ll rem = k - req;

            if (rem > 0)
                  ans += rem;
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