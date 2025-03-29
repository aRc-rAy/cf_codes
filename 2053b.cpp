#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

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

      vector<int> a(n);
      vector<int> b(n);

      unordered_map<int, int> ump;
      vector<int> run;

      ll max_val = 0;

      for (int i = 0; i < n; i++)
      {
            ll x, y;
            cin >> x >> y;

            if (x == y)
            {
                  if (ump[x] == 0)
                  {
                        run.push_back(x);
                  }
                  ump[x]++;
            }
            a[i] = x;
            b[i] = y;

            max_val = max(max_val, max(x, y));
      }

      vector<int> prefix_sum(max_val + 1, 0);

      for (int i : run)
      {
            prefix_sum[i] += 1;
      }

      for (int i = 1; i <= max_val; i++)
      {
            prefix_sum[i] += prefix_sum[i - 1];
      }

      string ans = "";
      for (int i = 0; i < n; i++)
      {
            ll x = a[i];
            ll y = b[i];

            ll pin = prefix_sum[y] - prefix_sum[x - 1];

            if (x == y)
            {
                  if (ump[x] == 1)
                        ans += '1';
                  else
                        ans += '0';
                  continue;
            }

            if (pin == (y - x + 1))
            {
                  ans += '0';
            }
            else
            {
                  ans += '1';
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
