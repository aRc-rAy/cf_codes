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
string ans = "";
// vector<vector<ll>> ump(10);
unordered_map<ll, set<ll>> ump;
ll rem(string &s, set<ll> &st)
{
      set<ll> nst;
      for (int i = 1; i <= 7; i++)
      {
            if (s[i] == '1')
            {
                  nst.insert(i);
            }
      }

      return (ll)(st.size() - nst.size());
}
bool ispos(string s, set<ll> &st)
{
      for (int i = 1; i <= 7; i++)
      {
            if (s[i] == '1')
            {
                  if (st.find(i) == st.end())
                  {
                        return false;
                  }
            }
      }
      return true;
}

void find(vector<string> &v, ll id, ll k, string &s)
{
      if (id == v.size())
      {
            // cout << s << " " << k << endl;
            if (k)
                  return;
            if (ans.size() == 0)
            {
                  ans = s;
            }
            else
            {
                  ans = max(ans, s);
            }
            return;
      }
      if (k < 0)
            return;

      for (int i = 9; i >= 0; i--)
      {
            if (ispos(v[id], ump[i]) && (k - rem(v[id], ump[i])) >= 0)
            {
                  s.push_back((i + '0'));
                  find(v, id + 1, k - rem(v[id], ump[i]), s);
                  s.pop_back();
            }
      }
}

void solve(ll test)
{
      ump[0] = {1, 2, 3, 5, 6, 7};
      ump[1] = {3, 6};
      ump[2] = {1, 3, 4, 5, 7};
      ump[3] = {1, 3, 4, 6, 7};
      ump[4] = {2, 4, 3, 6};
      ump[5] = {1, 2, 4, 6, 7};
      ump[6] = {1, 2, 5, 7, 6, 4};
      ump[7] = {1, 3, 6};
      ump[8] = {1, 2, 3, 4, 5, 6, 7};
      ump[9] = {1, 2, 3, 4, 6, 7};
      ans = "";
      ll n, k;
      cin >> n >> k;
      vector<string> v(n);
      for (auto &it : v)
      {
            cin >> it;
      }
      string s = "";
      find(v, 0, k, s);
      cout << ans << endl;
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