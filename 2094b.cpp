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
      ll n, m, l, r;
      cin >> n >> m >> l >> r;

      ll al = -m;
      ll ar = m;

      ll low = 0;

      low = min(-l, m);
      m -= low;

      low = -low;
      // cout << m << " m" << endl;

      ll high = 0;

      high = min(m, r);

      cout << low << " " << high << endl;
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