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
      ll n, m, k;
      cin >> n >> m >> k;
      string s;
      cin >> s;

      ll ans = 0;
      ll cur = 0;

      ll extra = 0;

      for (int i = 0; i < n; i++)
      {
            if (extra > 0)
            {
                  cur = 0;
                  extra--;
                  continue;
            }

            if (s[i] == '1')
            {
                  if (cur >= m)
                  {
                        ans++;
                  }
                  cur = 0;
            }
            else
            {
                  cur++;
                  if (cur == m)
                  {
                        ans++;
                        extra = k - 1;
                        cur = 0;
                  }
            }
      }

      if (cur >= m)
      {
            ans++;
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