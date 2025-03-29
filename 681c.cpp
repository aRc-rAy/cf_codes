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

      vector<pair<string, ll>> ans;
      string ins = "insert", gt = "getMin", rm = "removeMin";
      multiset<ll> st;
      for (ll i = 0; i < n; i++)
      {
            string a;
            ll num;
            cin >> a;
            if (a == rm)
            {
                  if (st.size())
                  {
                        ans.push_back({rm, 0});
                        // cout << rm << endl;
                        st.erase(st.begin());
                  }
                  else
                  {
                        ans.push_back({ins, 1});
                        ans.push_back({rm, 0});
                  }
                  continue;
            }

            cin >> num;
            if (a == ins)
            {
                  ans.push_back({ins, num});
                  // cout << ins << " " << num << endl;
                  st.insert(num);
                  continue;
            }

            if (st.size() && num == *st.begin())
            {
                  ans.push_back({gt, num});
                  // cout << gt << " " << num << endl;
                  continue;
            }

            while (st.size() && *st.begin() < num)
            {
                  ans.push_back({rm, 0});
                  // cout << rm << endl;
                  st.erase(st.begin());
            }

            if (st.size() && *st.begin() == num)
            {

                  {
                        ans.push_back({gt, num});
                        // cout << gt << " " << num << endl;
                        continue;
                  }
            }
            else
            {
                  // cout << ins << " " << num << endl;
                  // cout << gt << " " << num << endl;
                  st.insert(num);
                  ans.push_back({ins, num});
                  ans.push_back({gt, num});
            }
      }
      cout << ans.size() << endl;
      for (auto it : ans)
      {
            cout << it.first << " ";
            if (it.first == rm)
            {
                  cout << endl;
                  continue;
            }
            cout << it.second << endl;
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