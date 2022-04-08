/*
 * @Author: linkenzone
 * @Date: 2022-03-26 16:29:08
 * @Descripttion: Do not edit
 */
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

inline void printVector_1d(const vector<int> vec)
{
    cout << "[";
    for (auto item : vec)
    {
        cout << item << ",";
    }
    cout << "],";
}

//* 调试: 打印 2维 vector<T>
inline void printVector_2d(vector<vector<int>> vec)
{
    cout << "{";
    for (auto item : vec)
    {
        printVector_1d(item);
    }
    cout << "}";
    cout << endl;
}

// 方向向量
vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
int Global_maxHeight = 2147483647;
int N ,M ,X ,Y, Z, W;

void dfs(vector<vector<int>> grid,int x,int y, int maxHeight) {
    // cout << x << " " << y << endl;
    if((x >= N || x < 0) || (y >= M || y < 0) ) {
        return;
    }
    if(grid[x][y] == -1){
        return;
    }
    maxHeight = max(maxHeight , grid[x][y]);
    if(x == Z-1 && y == W-1) {
        cout << x << " " << y << endl;
        Global_maxHeight = min(Global_maxHeight , maxHeight);
        return;
    }
    grid[x][y] = -1;

    dfs(grid,x + 1,y,maxHeight);
    dfs(grid,x ,y + 1,maxHeight);
    dfs(grid,x - 1,y,maxHeight);
    dfs(grid,x ,y - 1,maxHeight);
}


int main(){
    FILE *fp;
    fp = freopen("data.txt", "r", stdin);

    cin >> N >> M >> X >> Y >> Z >> W;
    
    vector<vector<int>> grid(N,vector<int>(M,-1));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j< M; j++) {
            cin >> grid[i][j];
        }
    }
    printVector_2d(grid);
    
    dfs(grid,X,Y,0);
    
    cout << Global_maxHeight << endl;
    return 0;
}