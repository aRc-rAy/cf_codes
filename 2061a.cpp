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

      bool ev = 0;
      ll cnt = 0;

      for (int i = 0; i < n; i++)
      {
            ll t;
            cin >> t;
            if (t % 2)
                  cnt++;
            else
                  ev = 1;
      }
      if (ev)
      {
            cout << cnt + 1 << endl;
      }
      else
      {
            cout << cnt - 1 << endl;
      }
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