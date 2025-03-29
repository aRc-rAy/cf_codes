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
int dp[1002][1002];
ll find(string &a, string &b, string &c, int i, int j)
{
      if (i == a.size() && j == b.size())
      {
            return 0;
      }
      int &ans = dp[i][j];

      if (ans != -1)
      {
            return ans;
      }

      ll ci = i + j;
      ll cur = 0;
      if (i == a.size())
      {
            if (c[ci] == b[j])
            {
                  cur = find(a, b, c, i, j + 1);
            }
            else
            {
                  cur = 1 + find(a, b, c, i, j + 1);
            }
      }
      else if (j == b.size())
      {
            if (c[ci] == a[i])
            {
                  cur = find(a, b, c, i + 1, j);
            }
            else
            {
                  cur = 1 + find(a, b, c, i + 1, j);
            }
      }
      else
      {
            ll first = 0;
            ll second = 0;

            if (c[ci] == b[j])
            {
                  first = find(a, b, c, i, j + 1);
            }
            else
            {
                  first = 1 + find(a, b, c, i, j + 1);
            }

            if (c[ci] == a[i])
            {
                  second = find(a, b, c, i + 1, j);
            }
            else
            {
                  second = 1 + find(a, b, c, i + 1, j);
            }

            cur = min(first, second);
      }

      return ans = cur;
}
void solve(ll test)
{
      string a, b, c;
      memset(dp, -1, sizeof(dp));

      cin >> a >> b >> c;

      cout << find(a, b, c, 0, 0) << endl;
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