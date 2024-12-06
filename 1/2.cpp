#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  fstream file;
  file.open("puzzle.txt", ios::in);

  string x;
  multiset<int> a, b;
  int hash[100000] = {0};
  int count = 0;

  while (getline(file, x)) {
    int f = stoi(x.substr(0, 5));
    int l = stoi(x.substr(8, 13));
    a.insert(f);
    b.insert(l);
  }

  for (auto &val : a) {
    hash[val]++;
  }

  for (auto &val : b) {
    count += val * hash[val];
  }
  cout << count;
}
