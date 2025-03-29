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
      ll n, k;
      cin >> n >> k;

      ll ans = 0;
      map<ll, ll> ump;
      for (int t = 0; t < n; t++)
      {
            ll num;
            cin >> num;
            ump[num]++;
      }
      for (auto it : ump)
      {
            ll num = it.first;
            ll cnt = it.second;

            if (ump.find(k - num) != ump.end() && k != 2 * num)
            {
                  ll tcnt = ump[k - num];

                  ll mini = min(tcnt, cnt);
                  ump[num] -= mini;
                  ump[k - num] -= mini;
                  ans += mini;
            }
            else if (k == 2 * num)
            {
                  ans += cnt / 2;
            }
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