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

vector<int> getFactors(int number)
{
      std::vector<int> factors;
      for (int i = 1; i <= std::sqrt(number); ++i)
      {
            if (number % i == 0)
            {
                  factors.push_back(i);
                  if (i != number / i)
                  {
                        factors.push_back(number / i);
                  }
            }
      }
      return factors;
}
void solve(ll test)
{

      ll n, m, q;
      cin >> n >> m >> q;
      ll suma = 0;
      ll sumb = 0;
      vector<ll> v(n), vv(m);
      for (auto &it : v)
      {
            cin >> it;
            suma += it;
      }
      for (auto &it : vv)
      {
            cin >> it;
            sumb += it;
      }
      unordered_map<ll, ll> sa, sb;
      for (auto it : v)
      {
            sa[(suma - it)]++;
      }
      for (auto it : vv)
      {
            sb[(sumb - it)]++;
      }

      while (q--)
      {
            int num;
            cin >> num;

            vector<int> f = getFactors(abs(num));

            bool pos = 0;

            if (num < 0)
            {
                  for (auto it : f)
                  {
                        ll a = it;
                        ll b = num / a;

                        if (sa[(a)] && sb[(b)])
                        {
                              pos = 1;
                              break;
                        }

                        if (sa[(b)] && sb[(a)])
                        {
                              pos = 1;
                              break;
                        }
                        b = it;
                        a = num / b;
                        if (sa[(a)] && sb[(b)])
                        {
                              pos = 1;
                              break;
                        }

                        if (sa[(b)] && sb[(a)])
                        {
                              pos = 1;
                              break;
                        }
                  }
            }
            else
            {
                  for (auto it : f)
                  {
                        ll a = it;
                        ll b = num / a;

                        if (sa[(a)] && sb[(b)])
                        {
                              pos = 1;
                              break;
                        }

                        if (sa[(b)] && sb[(a)])
                        {
                              pos = 1;
                              break;
                        }
                        a = -a;
                        b = -b;
                        if (sa[(a)] && sb[(b)])
                        {
                              pos = 1;
                              break;
                        }

                        if (sa[(b)] && sb[(a)])
                        {
                              pos = 1;
                              break;
                        }
                  }
            }

            if (pos)
            {
                  cout << "yes" << endl;
            }
            else
            {
                  cout << "no" << endl;
            }
      }
}

int main()
{
      ios_base::sync_with_stdio(0), cin.tie(0);
      inn();
      int t = 1;
      // cin >> t;
      for (int i = 1; i <= t; i++)
      {
            solve(i);
      }
      return 0;
}