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
      vector<string> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      vector<vector<bool>> dp(n, vector<bool>(m, 0));

      vector<vector<bool>> vis(n, vector<bool>(m, 0));

      queue<pair<ll, ll>> q;

      for (int i = 0; i < n; i++)
      {
            if (v[i][0] == 'L')
            {

                  dp[i][0] = 1;
                  q.push({i, 0});
            }

            if (v[i][m - 1] == 'R')
            {
                  dp[i][m - 1] = 1;
                  q.push({i, m - 1});
            }
      }

      for (int j = 0; j < m; j++)
      {
            if (v[0][j] == 'U')
            {
                  dp[0][j] = 1;
                  q.push({0, j});
            }

            if (v[n - 1][j] == 'D')
            {
                  dp[n - 1][j] = 1;
                  q.push({n - 1, j});
            }
      }

      int dx[4] = {-1, 0, 1, 0};
      int dy[4] = {0, 1, 0, -1};

      while (q.size())
      {
            auto it = q.front();
            q.pop();

            ll x, y;
            x = it.first;
            y = it.second;

            if (vis[x][y])
            {
                  continue;
            }

            vis[x][y] = 1;
            dp[x][y] = 1;

            for (int i = 0; i < 4; i++)
            {
                  ll a = x + dx[i];
                  ll b = y + dy[i];

                  if (a >= 0 && a < n && b >= 0 && b < m)
                  {
                        if (!vis[a][b])
                        {
                              bool ist = 0;
                              if (i == 0 && v[a][b] == 'D')
                              {
                                    ist = 1;
                              }

                              if (i == 1 && v[a][b] == 'L')
                              {
                                    ist = 1;
                              }

                              if (i == 2 && v[a][b] == 'U')
                              {
                                    ist = 1;
                              }

                              if (i == 3 && v[a][b] == 'R')
                              {
                                    ist = 1;
                              }
                              if (ist)
                              {
                                    q.push({a, b});
                              }
                        }
                  }
            }
      }
      // cout << endl;

      // for (auto it : dp)
      // {
      //       for (auto i : it)
      //       {
      //             cout << i << " ";
      //       }
      //       cout << endl;
      // }
      // cout << endl;

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < m; j++)
            {
                  if (v[i][j] == '?')
                  {
                        bool ist = 0;
                        for (int t = 0; t < 4; t++)
                        {
                              ll a = i + dx[t];
                              ll b = j + dy[t];

                              if (a >= 0 && a < n && b >= 0 && b < m)
                              {
                                    if (v[a][b] == '?' || dp[a][b] == 0)
                                    {
                                          ist = 1;
                                          break;
                                    }

                                    if (t == 0 && (v[a][b] == 'D' || (dp[a][b] == 0)))
                                    {
                                          ist = 1;
                                          break;
                                    }

                                    if (t == 1 && (v[a][b] == 'L' || (dp[a][b] == 0)))
                                    {
                                          ist = 1;
                                          break;
                                    }

                                    if (t == 2 && (v[a][b] == 'U' || (dp[a][b] == 0)))
                                    {
                                          ist = 1;
                                          break;
                                    }

                                    if (t == 3 && (v[a][b] == 'R' || (dp[a][b] == 0)))
                                    {
                                          ist = 1;
                                          break;
                                    }
                              }
                        }
                        if (ist)
                        {
                        }
                        else
                        {
                              // cout << " " << i << " " << j << endl;
                              dp[i][j] = 1;
                        }
                  }
            }
      }
      // cout << endl;
      ll ans = 0;
      for (auto it : dp)
      {
            for (auto i : it)
            {
                  // cout << i << " ";
                  ans += (i == 0);
            }
            // cout << endl;
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