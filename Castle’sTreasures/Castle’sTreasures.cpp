#include <iostream>
#include <vector>

using namespace std;

const char WALL = '#';
const char EMPTY = '.';
const char DOOR = 'D';
const char KEY = 'K';
const char PLAYER = 'P';
const char COIN = 'G';

int N, M;
vector<vector<char>> castleMap;
vector<vector<bool>> visited;
int roomsVisited = 0;
int coinsCollected = 0;

void dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M || visited[x][y] || castleMap[x][y] == WALL) {
        return;
    }

    visited[x][y] = true;
    if (castleMap[x][y] == EMPTY || castleMap[x][y] == PLAYER || castleMap[x][y] == KEY || castleMap[x][y] == COIN) {
        roomsVisited++;
        if (castleMap[x][y] == COIN) {
            coinsCollected++;
        }
    }

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    cin >> N >> M;
    castleMap.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));

    int startX, startY;

    // Read castle map and find starting position
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> castleMap[i][j];
            if (castleMap[i][j] == PLAYER) {
                startX = i;
                startY = j;
            }
        }
    }

    dfs(startX, startY);
    cout << roomsVisited << endl;
    cout << coinsCollected << endl;

    return 0;
}
