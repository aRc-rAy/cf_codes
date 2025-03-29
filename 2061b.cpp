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
      ll n;
      cin >> n;

      vector<ll> v(n);
      map<ll, ll> ump;
      bool pos = 1;
      for (auto &it : v)
      {
            cin >> it;
            ump[it]++;

            if (ump[it] > 1)
            {
                  pos = 0;
            }
      }
      if (pos)
      {
            cout << -1 << endl;
            return;
      }
      // cnt=4
      ll num = -1;
      for (auto it : ump)
      {
            if (it.second >= 4)
            {
                  num = it.first;
                  break;
            }
      }

      if (num != -1)
      {
            for (int i = 0; i < 4; i++)
            {
                  cout << num << " ";
            }
            cout << endl;
            return;
      }

      // cnt=3
      set<ll> s3;
      set<ll> extra;
      for (auto it : ump)
      {
            if (it.second == 3)
            {
                  s3.insert(it.first);
            }
            else
            {
                  extra.insert(it.first);
            }
      }

      for (auto num : s3)
      {
            auto it = extra.lower_bound(3 * num);
            if (it != extra.begin())
            {
                  it = prev(it);
                  if (*it < 3 * num && *it != num)
                  {
                        for (int i = 0; i < 3; i++)
                        {
                              cout << num << " ";
                        }
                        cout << *it << endl;
                        return;
                  }
            }
      }

      // cnt=2
      set<ll> s2;
      extra.clear();
      for (auto it : ump)
      {
            if (it.second >= 2)
            {
                  s2.insert(it.first);
                  extra.insert(it.first);
            }
            else
            {
                  extra.insert(it.first);
            }
      }
      if (s2.size() >= 2)
      {
            cout << *s2.begin() << " " << *s2.begin() << " ";
            cout << *s2.rbegin() << " " << *s2.rbegin() << endl;

            return;
      }
      num = *s2.begin();
      extra.erase(num);
      for (auto it : extra)
      {
            if (it != num)
            {

                  auto pt = extra.lower_bound(it + 2 * num);
                  if (pt != extra.begin())
                  {
                        pt = prev(pt);

                        ll last = *pt;
                        if (last != num && last != it)
                        {
                              if (last < it + 2 * num)
                              {
                                    cout << last << " " << it << " ";
                                    cout << num << " " << num << endl;
                                    return;
                              }
                        }
                  }
            }
      }

      cout << -1 << endl;
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