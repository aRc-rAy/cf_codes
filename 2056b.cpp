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
void find(ll i, ll j, auto perm, auto &graph, auto &ans)
{
      cout << i << " " << j << endl;
      ll pos = j;
      if (i == j)
      {
            ans[pos] = perm.back();
            return;
      }
      vector<ll> left;
      vector<ll> right;

      for (int t = 1; t < perm.size(); t++)
      {
            if (graph[perm[0]][perm[t]] == '1')
            {
                  pos--;
                  right.push_back(perm[t]);
            }
            else
            {
                  left.push_back(perm[t]);
            }
      }
      ans[pos] = perm[0];
      find(i, pos - 1, left, graph, ans);
      find(pos + 1, j, right, graph, ans);
}
void solve(ll test)
{
      ll n;
      cin >> n;
      vector<string> graph(n);

      for (auto &it : graph)
      {
            cin >> it;
      }

      vector<ll> perm(n);
      iota(begin(perm), end(perm), 0);
      sort(begin(perm), end(perm), [&](auto &a, auto &b)
           {
            if(graph[a][b]=='1'){
                  return a<b;
            }else{
                  return a>b;
            } });
      for (auto &it : perm)
      {
            cout << it + 1 << " ";
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