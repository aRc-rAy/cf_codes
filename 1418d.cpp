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
      ll n, q;
      cin >> n >> q;

      set<ll> s;
      multiset<ll> ms;

      auto add = [&](ll num)
      {
            auto res = s.insert(num);
            auto it = res.first;

            if (it != s.end() && it != s.begin() && next(it) != s.end())
            {
                  ll diff = *next(it) - *prev(it);
                  ms.erase(ms.find(diff));
            }

            if (it != s.begin())
            {
                  ms.insert(num - *prev(it));
            }

            if (it != s.end() && next(it) != s.end())
            {
                  ms.insert(*next(it) - num);
            }
      };

      auto remove = [&](ll num)
      {
            auto it = s.find(num);

            if (it != s.end() && it != s.begin() && next(it) != s.end())
            {
                  ll diff = *next(it) - *prev(it);
                  ms.insert(diff);
            }

            if (it != s.begin())
            {
                  ll diff = (num - *prev(it));
                  ms.erase(ms.find(diff));
            }

            if (it != s.end() && next(it) != s.end())
            {
                  ll diff = (*next(it) - num);
                  ms.erase(ms.find(diff));
            }

            s.erase(num);
      };

      for (int i = 0; i < n; i++)
      {
            ll num;
            cin >> num;
            add(num);
      }

      for (int qq = 0; qq <= q; qq++)
      {
            if (ms.empty())
            {
                  cout << 0 << endl;
            }
            else
            {
                  ll max_a = *prev(s.end());
                  ll min_a = *s.begin();

                  ll max_d = *prev(ms.end());
                  cout << max_a - min_a - max_d << endl;
            }

            if (qq == q)
                  break;

            ll a, b;
            cin >> a >> b;

            if (a == 0)
            {
                  remove(b);
            }
            if (a == 1)
            {
                  add(b);
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