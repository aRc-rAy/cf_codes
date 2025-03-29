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
      ll n, x, k;
      cin >> n >> x >> k;
      string s;
      cin >> s;

      bool reach = 0;
      ll cnt = 0;

      for (int i = 0; i < n; i++)
      {
            if (s[i] == 'L')
            {
                  x--;
            }
            else
            {
                  x++;
            }
            cnt++;
            if (x == 0)
            {
                  reach = 1;
                  break;
            }
      }
      ll ans = 1;
      if (reach == 0)
      {
            cout << 0 << endl;
            return;
      }

      k -= cnt;

      cnt = 0;

      reach = 0;

      for (int i = 0; i < n; i++)
      {
            if (s[i] == 'L')
            {
                  x--;
            }
            else
            {
                  x++;
            }
            cnt++;
            if (x == 0 && cnt != 0)
            {
                  reach = 1;
                  break;
            }
      }

      if (reach == 0)
      {
            cout << 1 << endl;
            return;
      }

      ans += k / cnt;

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