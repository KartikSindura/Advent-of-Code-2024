#include <_stdio.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lp(i, n) for (int i = 0; i < n; i++)
#define lps(start, n) for (int i = start; i <= n; i++)

vector<int> dx = {1, 1};
vector<int> dy = {-1, 1};
vector<int> ddx = {-1, -1};
vector<int> ddy = {1, -1};

vector<vector<char>> grid;
int total = 0;

bool checkValid(int x, int y, int rows, int cols) {
  return (x < rows && x >= 0 && y < cols && y >= 0);
}

void search(int x, int y, int rows, int cols) {
  int nx = x + dx[0];
  int ny = y + dy[0];
  int ndx = x + ddx[0];
  int ndy = y + ddy[0];
  int nx1 = x + dx[1];
  int ny1 = y + dy[1];
  int ndx1 = x + ddx[1];
  int ndy1 = y + ddy[1];
  if (checkValid(nx, ny, rows, cols) && checkValid(ndx, ndy, rows, cols) &&
      checkValid(nx1, ny1, rows, cols) && checkValid(ndx1, ndy1, rows, cols)) {
    if (((grid[nx][ny] == 'M' && grid[ndx][ndy] == 'S') ||
         (grid[nx][ny] == 'S' && grid[ndx][ndy] == 'M')) &&
        ((grid[nx1][ny1] == 'M' && grid[ndx1][ndy1] == 'S') ||
         (grid[nx1][ny1] == 'S' && grid[ndx1][ndy1] == 'M'))) {
      cout << "Found at " << "(" << x << ", " << y << ")" << endl;
      total++;
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
      if (grid[i][j] == 'A') {
        search(i, j, rows, cols);
      }
    }
  }

  cout << total;
}
