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
      ll l, r, g;
      cin >> l >> r >> g;

      bool has = 0;

      ll num1 = -1;
      ll num2 = -1;

      ll low = ceil(l * 1.0 / g);
      ll high = r / g;

      if (g * low >= l && g * low <= r)
      {
            // odd _ ev
            if (low % 2 != high % 2)
            {
                  num1 = low * g;
            }
      }

      cout << num1 << " " << num2 << endl;
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