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
      ll n, m;
      cin >> n >> m;

      vector<ll> v(n);

      ll maxi = -1;
      for (auto &it : v)
      {
            cin >> it;
            maxi = max(maxi, it);
      }

      for (int i = 0; i < m; i++)
      {
            char c;
            cin >> c;
            ll l, r;
            cin >> l >> r;

            if (c == '+')
            {
                  if (maxi >= l && maxi <= r)
                  {
                        maxi++;
                  }
            }
            else
            {
                  if (maxi >= l && maxi <= r)
                  {
                        maxi--;
                  }
            }
            cout << maxi << " ";
      }
      cout << endl;
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