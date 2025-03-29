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
      ll n, a, b, c;
      cin >> n >> a >> b >> c;

      ll tot = n / (a + b + c);

      ll rem = n % (a + b + c);

      ll ans = tot * 3;

      if (rem > a + b)
      {
            ans += 3;
      }
      else if (rem > a)
      {
            ans += 2;
      }
      else if (rem > 0)
      {
            ans += 1;
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