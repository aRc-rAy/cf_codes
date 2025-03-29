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
      string s;
      cin >> s;

      ll cost = 0;
      ll low = 1;
      ll high = n;

      set<ll> lat;

      set<ll> added;

      for (ll i = n - 1; i >= 0; i--)
      {
            if (s[i] == '1')
            {
                  // will pair with lower ones
                  lat.insert(i + 1);
            }
            else
            {
                  // will pair with max ones or will be not uns         old
                  if (lat.size())
                  {
                        cost += i + 1;
                        added.insert(i + 1);
                        added.insert(*lat.rbegin());
                        lat.erase(*lat.rbegin());
                  }
            }
      }

      while (lat.size())
      {
            ll num = *lat.begin();
            lat.erase(lat.begin());
            added.insert(num);
            cost += num;

            if (lat.size())
            {
                  added.insert(*lat.rbegin());
                  lat.erase(*lat.rbegin());
            }
      }

      for (int i = 1; i <= n; i++)
      {
            if (added.count(i) == 0)
            {
                  cost += i;
            }
      }

      cout << cost << endl;
      // cout << endl;
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