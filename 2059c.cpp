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
      ll v[n][n];
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  cin >> v[i][j];
            }
      }
      multiset<ll> ans;
      for (int i = 0; i < n; i++)
      {
            ll cnt = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                  if (v[i][j] != 1)
                        break;
                  cnt++;
            }
            ans.insert(cnt);
      }

      ll cnt = 0;
      for (auto it : ans)
      {
            if (it < cnt)
                  continue;
            cnt++;
      }
      cout << cnt << endl;
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