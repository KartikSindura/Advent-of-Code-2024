#include <_stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

vector<int> dx = {1, -1, 0, 0, 1, 1, -1, -1};
vector<int> dy = {0, 0, -1, 1, -1, 1, 1, -1};
// int visited[140][140] = {0};
vector<vector<char>> grid;
string target = "XMAS";
int total = 0;

bool checkValid(int x, int y, int rows, int cols) {
  return x < rows && x >= 0 && y < cols && y >= 0;
  // && visited[x][y] != 1;
}

bool dfs(int x, int y, int index, int rows, int cols, int direction) {
  if (index == target.size()) {
    return true;
  }
  // visited[x][y] = 1;

  int nx = x + dx[direction];
  int ny = y + dy[direction];

  if (checkValid(nx, ny, rows, cols) && grid[nx][ny] == target[index]) {
    if (dfs(nx, ny, index + 1, rows, cols, direction)) {
      return true;
    }
  }
  // visited[x][y] = 0;
  return false;
}

void searchM(int x, int y, int rows, int cols) {
  for (int i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    int direction = i;
    if (checkValid(nx, ny, rows, cols) && grid[nx][ny] == target[1]) {
      if (dfs(nx, ny, 2, rows, cols, direction)) {
        total++;
        cout << "Found XMAS starting at (" << x << ", " << y << ")" << endl;
      }
    }
  }
}

int main() {
  fstream file;
  file.open("puzzle.txt");
  string line;
  while (getline(file, line)) {
    vector<char> row;
    for (auto val : line) {
      row.push_back(val);
    }
    grid.push_back(row);
  }
  file.close();

  int rows = grid.size(), cols = grid[0].size();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 'X') {
        searchM(i, j, rows, cols);
      }
    }
  }

  cout << total;
}
