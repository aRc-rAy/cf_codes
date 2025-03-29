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
      int n, x;
      cin >> n >> x;
      vector<int> v(n);

      for (auto &it : v)
      {
            cin >> it;
      }

      sort(rbegin(v), rend(v));

      int cur = 0;
      int cnt = 0;

      int prev = -1;
      int ans = 0;

      for (int i = 0; i < n; i++)
      {
            cur = v[i];

            int len = i - prev;

            if (cur * len >= x)
            {
                  prev = i;
                  cur = 0;
                  ans++;
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