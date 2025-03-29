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
      ll n, d;
      cin >> n >> d;

      vector<ll> ans;
      ans.push_back(1);

      // 3
      if (d % 3 == 0 || n >= 3)
      {
            ans.push_back(3);
      }

      if (d % 5 == 0)
      {
            ans.push_back(5);
      }

      if (d % 7 == 0 || n >= 3)
      {
            ans.push_back(7);
      }

      if (d % 9 == 0 || n >= 6 || (d % 3 == 0 && n >= 3))
      {
            ans.push_back(9);
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