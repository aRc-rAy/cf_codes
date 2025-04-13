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

vector<pair<char, int>> agg(auto &s)
{
      vector<pair<char, int>> ans;
      int n = s.size();

      int cnt = 1;
      char p = s[0];
      int i = 1;
      while (i < n)
      {
            if (s[i] == s[i - 1])
            {
                  cnt++;
            }
            else
            {
                  ans.push_back({s[i - 1], cnt});
                  cnt = 1;
            }
            i++;
      }
      ans.push_back({s[i - 1], cnt});

      return ans;
}
void solve(ll test)
{
      string p, s;
      cin >> p >> s;

      int pi = 0;
      int si = 0;

      int np = p.size();
      int ns = s.size();

      auto vp = agg(p);

      auto vs = agg(s);

      if (vp.size() != vs.size())
      {
            cout << "NO" << endl;
            return;
      }

      for (int i = 0; i < vp.size(); i++)
      {
            cerr << vp[i].first << " " << vp[i].second << " | " << vs[i].first << " " << vs[i].second << endl;
            if (vp[i].first != vs[i].first)
            {
                  cout << "NO" << endl;
                  return;
            }

            ll cntp = vp[i].second;
            ll cnts = vs[i].second;

            if (cnts < cntp || cnts > 2 * cntp)
            {
                  cout << "NO" << endl;
                  return;
            }
      }

      cout << "YES" << endl;
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