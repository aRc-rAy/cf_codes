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
class point
{
public:
      int x;
      int y;
      point()
      {
            x = 0;
            y = 0;
      }
      point(int a, int b)
      {
            x = a;
            y = b;
      }
};

class leader
{
public:
      int head;
      point p;

      leader(int h, point a)
      {
            head = h;
            p = a;
      }
};
bool operator<(const leader &a, const leader &b)
{
      if (a.head == b.head)
      {
            if (a.p.x == b.p.x)
            {
                  return a.p.y > b.p.y;
            }
            return a.p.x > b.p.x;
      }
      return a.head > b.head;
}
void solve(ll test)
{
      int n;
      cin >> n;

      // set<pair<int, vector<pair<int, point>>>> group;
      // set<pair<int,<pair<int, point>>> group;
      priority_queue<leader> group, buffer;
      // set<pair<int, pair<int, int>>> buffer;
      vector<int> g(n);
      for (auto &it : g)
      {
            cin >> it;
      }

      for (int sum = 0; sum <= 250; sum++)
      {
            for (int i = 0; i <= sum; i++)
            {
                  int j = sum - i;

                  int head = 0;

                  int x = 3 * i + 1;
                  int y = 3 * j + 1;
                  point p;
                  p.x = x;
                  p.y = y;

                  head = x + y;

                  leader l(head, p);

                  group.push(l);
            }
      }

      // cout << group.size() << endl;

      for (auto itr : g)
      {
            int type = itr;

            if (type == 1 && buffer.size())
            {
                  // print all options
                  // cout << "print all options for 1 : " << endl;
                  // for (auto it : buffer)
                  // {
                  //       cout << it.first << " -> ";
                  //       cout << it.second.first << " " << it.second.second << endl;
                  // }
                  // cout << endl;
                  auto it = buffer.top();

                  int x = it.p.x;
                  int y = it.p.y;

                  cout << x << " " << y << endl;
                  buffer.pop();

                  continue;
            }

            // new group;
            if (group.size() == 0)
            {
                  cout << "khatam ho gya be" << endl;
                  continue;
            }

            leader it = group.top();
            group.pop();
            // // bool f = 1;

            point p = it.p;
            int x = p.x - 1;
            int y = p.y - 1;

            cout << p.x << " " << p.y << endl;

            for (int t = 1; t <= 2; t++)
            {
                  for (int s = 1; s <= 2; s++)
                  {
                        if (t == 1 && s == 1)
                              continue;
                        int nx = x + t;
                        int ny = y + s;
                        point np = point(nx, ny);
                        int cost = nx + ny;
                        if (t == 2 && s == 2)
                              cost += 2;
                        buffer.push({cost, {nx, ny}});
                  }
            }
      }
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