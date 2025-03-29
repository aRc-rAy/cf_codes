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
      ll n, k;
      cin >> n >> k;
      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      sort(rbegin(v), rend(v));
      map<ll, ll, greater<ll>> ump;
      for (int i = 0; i < n - 1; i++)
      {
            ump[v[i] - v[n - 1]]++;
      }

      ll cut = 0;
      ll sum = 0;

      ll count = 0;
      for (auto it = ump.begin(); it != ump.end(); it++)
      {
            ll num = it->first;
            count += it->second;

            if (next(it) != ump.end())
            {
                  auto nex = next(it);
                  ll cnum = nex->first;
                  ll piece = num - cnum;

                  ll req = (k - sum) / count;

                  if (req < piece)
                  {
                        cut++;
                        sum = 0;

                        ll groupSize = k / count;

                        ll rem = piece - req;

                        ll groups = rem / groupSize;
                        cut += groups;
                        sum += (rem - groups * groupSize) * count;
                  }
                  else
                  {
                        sum += (piece * count);
                  }
            }
            else
            {

                  ll piece = num;

                  ll req = (k - sum) / count;

                  if (req < piece)
                  {
                        cut++;
                        sum = 0;

                        ll groupSize = k / count;

                        ll rem = piece - req;

                        ll groups = rem / groupSize;
                        cut += groups;
                        sum += (rem - groups * groupSize) * count;
                  }
                  else
                  {
                        sum += (piece * count);
                  }
            }
      }
      if (sum)
            cut++;
      cout << cut << endl;
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