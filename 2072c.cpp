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
      ll n, x;
      cin >> n >> x;

      vector<ll> ans;

      for (int i = 0; i < n; i++)
      {
            if (i <= x)
            {
                  if ((i | x) == x)
                  {
                        ans.push_back(i);
                  }
                  else
                  {
                        ans.push_back(0);
                  }
            }
            else
            {
                  ans.push_back(0);
            }
      }

      ll cans = 0;

      for (auto it : ans)
      {
            cans = cans | it;
      }

      if (cans != x)
      {
            ans.pop_back();
            ans.push_back(x);
      }
      for (auto it : ans)
      {
            cout << it << " ";
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