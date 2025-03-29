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
      ll n, m, k;
      cin >> n >> m >> k;

      char maxi = '0';
      char mini = '1';
      if (n < m)
      {
            swap(n, m);
            swap(maxi, mini);
      }

      ll maxp = 0;
      ll minp = 0;

      ll dif = 0;
      string ans = "";

      while (true)
      {
            bool first = 1;
            // go for creating maxi first
            if ((n - maxi) - (m - mini) > k)
            {
                  for (int i = 0; i < k; i++)
                  {
                        ans += maxi;
                        maxp++;
                  }
                  first = 0;
            }
            bool can = 0;
            // fill alternate
            for (int i = 0; i < k; i++)
            {
                  if (i % 2 == 0)
                  {
                        if (minp < m)
                        {

                              minp++;
                              ans += mini;
                        }
                        else
                        {
                              can = 1;
                              break;
                        }
                  }
                  else
                  {
                        if (maxp < n)
                        {

                              maxp++;
                              ans += maxi;
                        }
                        else
                        {
                              can = 1;
                              break;
                        }
                  }
            }

            if (k % 2 == 0)
            {
                  if (minp < m)
                  {
                        ans.push_back(mini);
                        minp++;
                  }
                  else
                  {
                        ans.pop_back();
                        maxp--;
                  }
            }

            if (maxp == n || minp == m)
            {
                  break;
            }
      }

      if (maxp == n)
      {
            while (minp < m)
            {
                  ans.push_back(mini);
                  minp++;
            }
            cout << ans << endl;
      }
      else
      {
            ll cnt = 0;
            for (int i = ans.size() - 1; i > 0; i--)
            {
                  if (ans[i] == ans[i - 1])
                  {
                        break;
                  }
                  else
                  {
                        cnt++;
                  }
            }
            while (maxp < n)
            {
                  ans.push_back(maxi);
                  maxp++;
            }
            if (cnt > k)
            {
                  cout << -1 << endl;
            }
            else
            {
                  cout << ans << endl;
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