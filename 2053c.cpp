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

      ll cur = 1;
      ll extra = 0;

      ll ans = 0;

      while (n >= k)
      {
            if (n % 2)
            {
                  ll num = n / 2;

                  ll cans = (num + 1) * cur + extra;

                  n = num;

                  ans += cans;

                  extra = 2 * extra + cur * (num + 1);
            }
            else
            {
                  ll num = n / 2;
                  n = num;

                  extra = 2 * extra + cur * num;
            }
            cur = cur * 2;
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