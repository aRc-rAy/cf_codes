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
      ll n, m, q;
      cin >> n >> m >> q;

      vector<ll> v(q);
      for (auto &it : v)
      {
            cin >> it;
      }

      vector<pair<ll, ll>> pos;
      pos.push_back({m, m});

      vector<ll> ans;

      for (int i = 0; i < q; i++)
      {
            ll cnum = v[i];

            vector<pair<ll, ll>> temp;

            for (auto &it : pos)
            {
                  if (cnum < it.first)
                  {
                        it.first--;
                  }
                  else if (cnum > it.second)
                  {
                        it.second++;
                  }
                  else
                  {
                        if (it.first == it.second)
                        {
                              it.first = 1;
                              it.second = 1;

                              temp.push_back({n, n});
                        }
                        else
                        {
                              temp.push_back({1, 1});
                              temp.push_back({n, n});
                        }
                  }
            }

            for (auto it : temp)
            {
                  pos.push_back(it);
            }

            temp.resize(0);

            sort(begin(pos), end(pos));
            // merge intervals
            ll fnum = pos[0].first;
            ll sec = pos[0].second;

            for (auto it : pos)
            {

                  if (it.first > sec)
                  {
                        temp.push_back({fnum, sec});
                        fnum = it.first;
                        sec = it.second;
                  }
                  else
                  {
                        sec = max(sec, it.second);
                  }
            }
            temp.push_back({fnum, sec});
            pos = temp;

            ll ctot = 0;

            for (auto it : pos)
            {
                  // cout << it.first << " " << it.second << endl;
                  ctot += it.second - it.first + 1;
            }
            // cout << endl;
            ans.push_back(ctot);
      }
      for (auto it : ans)
      {
            cout << it << " ";
      }
      cout << endl;
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