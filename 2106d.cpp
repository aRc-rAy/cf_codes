#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define debug(x) cerr << RED << "Line [" << __LINE__ << "]\t" << #x << " -> " << x << RESET << endl;
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
      vector<ll> a(n), b(m);
      for (auto &it : a)
            cin >> it;
      for (auto &it : b)
            cin >> it;

      int i = 0;
      int j = 0;
      // check if no need
      {
            ll cnt = 0;
            while (j < m)
            {

                  while (i < n && a[i] < b[j])
                  {
                        i++;
                  }

                  if (i < n && a[i] >= b[j])
                  {
                        cnt++;
                  }
                  j++;
                  i++;
            }

            if (cnt >= m)
            {
                  cout << 0 << endl;
                  return;
            }
      }
      vector<ll> dp(m + 2, -1);
      vector<ll> fdp(m + 2, -1);
      // precompute last se and try to  find minimun
      {
            i = n - 1;
            j = m - 1;

            for (; j >= 0; j--)
            {
                  while (i >= 0 && a[i] < b[j])
                  {
                        i--;
                  }

                  if (i >= 0 && a[i] >= b[j])
                  {
                        dp[j] = i;
                  }
                  else
                  {
                        break;
                  }
                  i--;
            }
      }
      // front compute and
      {
            i = 0;
            j = 0;

            for (; j < m; j++)
            {
                  while (i < n && a[i] < b[j])
                  {
                        i++;
                  }

                  if (i < n && a[i] >= b[j])
                  {
                        fdp[j] = i;
                  }
                  else
                  {
                        break;
                  }
                  i++;
            }
      }

      // anyway possible by any chance

      {
            i = 0;
            j = 0;

            ll ans = 0;
            bool flag = 0;
            for (; j < m; j++)
            {
                  if (dp[j + 1] != -1 && fdp[j] != -1 && fdp[j] < dp[j + 1])
                  {
                        flag = 1;
                        break;
                  }
            }
            if (flag)
            {
                  cout << 0 << endl;
                  return;
            }
      }

      // find mininum to add
      {
            i = 0;
            j = 0;

            ll ans = 1e10;

            // place for each index

            for (; j < m; j++)
            {
                  // add this index if pos

                  if (j == 0)
                  {
                        if (m == 1)
                        {
                              ans = min(ans, b[j]);
                        }
                        else if (dp[j + 1] != -1)
                        {
                              ans = min(ans, b[j]);
                        }
                  }
                  else if (j == m - 1)
                  {
                        if (j - 1 >= 0)
                        {
                              if (fdp[j - 1] != -1)
                              {
                                    ans = min(ans, b[j]);
                              }
                        }
                  }
                  else
                  {
                        if (fdp[j - 1] != -1 && dp[j + 1] != -1 && fdp[j - 1] < dp[j + 1])
                        {
                              ans = min(ans, b[j]);
                        }
                  }
            }

            if (ans != 1e10)
            {
                  cout << ans << endl;
                  return;
            }
      }

      // no chance then -1
      {
            cout << -1 << endl;
      }
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