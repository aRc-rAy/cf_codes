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
      vector<ll> v;
      for (int i = 0; i < n; i++)
      {
            string s;
            cin >> s;
            v.push_back(s.size());
      }
      // sort(v.begin(), v.end());
      ll ans = 0;
      ll sum = 0;
      for (auto it : v)
      {
            if (sum + it <= m)
            {
                  ans++;
                  sum += it;
            }
            else
            {
                  break;
            }
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