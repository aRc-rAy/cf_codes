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
const int maxi = 1e7 + 2;
int dp[maxi];
void calc()
{
      auto get_prime = [&](int n) -> ll
      {
            ll cnt = 0;

            for (int i = 2; i * i <= n; i++)
            {
                  if (n % i == 0)
                  {
                        cnt++;

                        while (n % i == 0)
                        {
                              n = n / i;
                        }
                  }
            }
            if (n > 1)
                  cnt++;

            return cnt;
      };

      vector<int> pr(maxi);
      for (int i = 1; i < maxi; i++)
      {
            pr[i] = i;
            dp[i] = 0;
      }

      for (int i = 2; i < maxi; i++)
      {
            if (pr[i] == i)
            {
                  for (int j = i; j < maxi; j += i)
                  {
                        dp[j]++;
                        pr[j] = i;
                  }
            }
      }

      // for (int i = 1; i < maxi; i++)
      // {
      //       dp[i] = get_prime(i);
      // }
}
void solve(ll test)
{
      int n;
      cin >> n;

      auto get_prime = [&](int n) -> ll
      {
            ll cnt = 0;

            for (int i = 2; i * i <= n; i++)
            {
                  if (n % i == 0)
                  {
                        cnt++;

                        while (n % i == 0)
                        {
                              n = n / i;
                        }
                  }
            }
            if (n > 1)
                  cnt++;

            return cnt;
      };

      ll ans = 0;
      for (int i = 2; i <= n; i++)
      {
            ll count = 0;
            if (i <= 1e6)
            {
                  count = dp[i];
            }
            else
                  count = dp[i];

            if (count == 0)
                  count++;

            ans += count;
      }
      cout << ans << endl;
}
int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t = 1;
      cin >> t;
      calc();
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}