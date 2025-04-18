#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define mod 1000000007
#define MAXX 100005
#define RED "\033[31m"
#define debug(x) cerr << RED << "Line [" << __LINE__ << "]\t" << #x << " -> " << x << endl;
void inn()
{
#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
#endif
}
int n;
vector<ll> get_all_factors(ll num)
{
      vector<ll> ans;
      for (int i = 1; i * i <= num; i++)
      {
            if (num % i == 0)
            {
                  ans.push_back(i);
                  ans.push_back(num / i);
            }
      }
      return ans;
}
void solve(ll test)
{
      int kk;
      cin >> kk;
      string s;
      cin >> s;
      n = s.size();

      vector<vector<ll>> count(26);
      for (int i = 0; i < n; i++)
      {
            count[s[i] - 'a'].push_back(i);
      }

      vector<pair<ll, ll>> cp;
      for (int i = 0; i < 26; i++)
      {
            cp.push_back({count[i].size(), i});
      }

      sort(rbegin(cp), rend(cp));

      auto allfactors = get_all_factors(n);
      sort(begin(allfactors), end(allfactors));

      ll ans = 1;
      ll diff = n;
      for (auto len : allfactors)
      {
            ll tot = n;
            ll add = 0;
            ll remove = 0;

            for (auto it : cp)
            {
                  if (tot)
                  {
                        if (it.first > len)
                              remove += it.first - len;
                        if (len >= it.first)
                              add += len - it.first;
                        tot -= len;
                  }
            }

            if (tot == 0)
            {
                  if (diff > max(add, remove))
                  {
                        diff = max(add, remove);
                        ans = len;
                  }
            }
      }

      vector<int> inserted(26, ans);
      vector<int> dp(n, -1);
      ll add = n / ans;
      for (auto it : cp)
      {
            int cnt = it.first;
            int id = it.second;

            for (auto ids : count[id])
            {
                  if (inserted[id])
                  {
                        dp[ids] = id;
                        inserted[id]--;
                  }
            }
            add--;
            if (add == 0)
                  break;
      }

      queue<int> q;
      for (int i = 0; i < n; i++)
      {
            if (dp[i] == -1)
                  q.push(i);
      }

      vector<pair<ll, ll>> ccp;
      for (int i = 0; i < 26; i++)
      {
            ccp.push_back({inserted[i], i});
      }

      sort(begin(ccp), end(ccp));

      for (auto it : ccp)
      {
            ll ch = it.second;
            ll len = it.first;
            while (q.size() && len)
            {
                  int id = q.front();
                  q.pop();
                  dp[id] = ch;
                  len--;
            }
            if (q.size() == 0)
                  break;
      }

      string t = "";
      for (auto it : dp)
      {
            t += (it + 'a');
      }
      diff = 0;
      for (int i = 0; i < n; i++)
      {
            diff += (s[i] != t[i]);
      }
      cout << diff << endl;
      cout << t << endl;
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