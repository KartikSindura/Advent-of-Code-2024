#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

int main() {
  fstream file;
  file.open("puzzle.txt");
  string line;
  int count = 0;

  smatch match;
  regex r("mul\\(\\d+,\\d+\\)");

  while (getline(file, line)) {
    while (regex_search(line, match, r)) {
      string word = match.str(0);
      int comma = word.find(',');
      int a = stoi(word.substr(4, comma - 1));
      int b = stoi(word.substr(comma + 1, word.size() - 1));
      cout << a << " " << b << endl;
      count += a * b;
      line = match.suffix().str();
    }
  }

  cout << count;
}
