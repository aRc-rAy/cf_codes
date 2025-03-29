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
vector<ll> dp(600);
void fill()
{
      for (int i = 1; i < 600; i++)
      {
            dp[i] = dp[i - 1] + i;
      }
}
void solve(ll test)
{
      ll k;
      cin >> k;
      vector<pair<ll, ll>> points;
      points.push_back({0, 0});
      ll hor = 0;
      bool alt = 0;
      ll a = 0;
      ll b = 1;
      for (int i = 506; i >= 0; i--)
      {
            while (k >= dp[i] && k != 0)
            {
                  // cout << i << " " << dp[i] << " " << k << endl;
                  for (int j = 1; j <= i; j++)
                  {
                        points.push_back({a, b});
                        b++;
                  }
                  a++;
                  points.push_back({a, b});
                  b++;
                  k -= dp[i];
            }
      }
      cout << points.size() << endl;
      for (auto it : points)
      {
            cout << it.first << " " << it.second << endl;
      }
}
int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t = 1;
      fill();
      cin >> t;

      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}