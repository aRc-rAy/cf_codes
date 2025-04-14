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
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define debug(x) cerr << COLOR_RED << "[" << __LINE__ << "]\t" << #x << " -> " << x << COLOR_RESET << endl;

void solve(ll test)
{
      ll n, m, k;
      cin >> n >> m >> k;
      debug(n);

      ll tot = n * m;
      ll oc = tot / k;

      if (m % k != 0)
      {
            int t = 1;
            for (int i = 0; i < n; i++)
            {
                  for (int j = 0; j < m; j++)
                  {
                        cout << t << " ";
                        t = (t % k) + 1;
                  }
                  cout << endl;
            }
      }
      else
      {
            for (int i = 0; i < n; i++)
            {
                  int t = (i % k) + 1;
                  for (int j = 0; j < m; j++)
                  {
                        cout << t << " ";
                        t = (t % k) + 1;
                  }
                  cout << endl;
            }
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