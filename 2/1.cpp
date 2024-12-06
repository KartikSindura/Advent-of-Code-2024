#include <bits/stdc++.h>
#include <sstream>
#include <vector>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

bool check(vector<int> store) {
  int direction = (store[0] > store[1]) ? -1 : 1;

  for (size_t i = 0; i < store.size() - 1; ++i) {
    int diff = store[i + 1] - store[i];
    if (diff * direction <= 0 || abs(diff) > 3) {
      return false;
    }
  }

  return true;
}

int main() {
  fstream file;
  file.open("puzzle.txt");
  string line;
  int count = 0;

  while (getline(file, line)) {
    vector<int> store;
    stringstream ss(line);
    string word;
    while (ss >> word) {
      int a = stoi(word);
      store.push_back(a);
    }
    if (check(store)) {
      count++;
    }
  }
  cout << count;
}
