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

ll getmax(vector<ll> v, bool neg)
{
      ll maxi = 0;
      ll cur = 0;

      ll n = v.size();

      for (int i = 0; i < n; i++)
      {
            if (neg)
            {
                  v[i] *= -1;
            }

            cur = max(cur + v[i], v[i]);
            maxi = max(maxi, cur);
      }

      return maxi;
}
void solve(ll test)
{
      ll n;
      cin >> n;
      vector<ll> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }

      ll has = -1;
      ll num = -1;
      for (int i = 0; i < n; i++)
      {
            if (v[i] != -1 && v[i] != 1)
            {
                  has = i;
                  num = v[i];
                  break;
            }
      }
      set<ll> ans;
      if (has != -1)
      {
            ll minl = 0, minr = 0, maxl = 0, maxr = 0;

            vector<ll> left, right;

            for (int i = has - 1; i >= 0; i--)
            {
                  left.push_back(v[i]);
            }

            for (int i = has + 1; i < n; i++)
            {
                  right.push_back(v[i]);
            }

            ll sum = 0;
            set<ll> le;
            set<ll> ri;

            for (auto it : left)
            {
                  sum += it;
                  le.insert(sum);
            }
            sum = 0;
            for (auto it : right)
            {
                  sum += it;
                  ri.insert(sum);
            }

            le.insert(0);
            ri.insert(0);

            if (le.size())
            {
                  minl = *le.begin();
                  maxl = *le.rbegin();
            }

            if (ri.size())
            {
                  minr = *ri.begin();
                  maxr = *ri.rbegin();
            }

            ll a = -getmax(left, 1);
            ll b = getmax(left, 0);

            for (int i = a; i <= b; i++)
            {
                  ans.insert(i);
            }

            ll aa = -getmax(right, 1);
            ll bb = getmax(right, 0);

            for (int i = aa; i <= bb; i++)
            {
                  ans.insert(i);
            }

            ll aaa = minl + minr + num;
            ll bbb = maxl + maxr + num;

            cerr << minl << " " << minr << " " << endl;

            for (int i = aaa; i <= bbb; i++)
            {
                  ans.insert(i);
            }
      }
      else
      {
            ll a = -getmax(v, 1);
            ll b = getmax(v, 0);

            for (int i = a; i <= b; i++)
            {
                  ans.insert(i);
            }
      }
      cout << ans.size() << endl;
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