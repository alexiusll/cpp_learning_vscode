/*
 * @Author: linkenzone
 * @Date: 2022-03-19 15:35:37
 * @Descripttion: Do not edit
 */
// 各种好用的辅助函数

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//* 调试: 打印 1维 vector<T>
template <typename T>
inline void printVector_1d(const vector<T> vec)
{
    cout << "[";
    for (auto item : vec)
    {
        cout << to_string(item) << ",";
    }
    cout << "],";
}

//* 调试: 打印 2维 vector<T>
template <typename T>
inline void printVector_2d(vector<vector<T>> vec)
{
    cout << "{";
    for (auto item : vec)
    {
        printVector_1d(item);
    }
    cout << "}";
    cout << endl;
}

// * 处理多组 a b 类型的数据
inline void input_a_b()
{
    FILE *fp;
    fp = freopen("data_1d.txt", "r", stdin);
    int t;
    cin >> t;
    cout << t << endl;

    int a, b;

    while (t--)
    {
        cin >> a >> b;
        // 处理 a + b
        cout << a << "+" << b << "=" << a + b << endl;
    }
    fclose(fp);
}

// * 处理1维数组的输入
inline void input_1d_list()
{
    FILE *fp;
    fp = freopen("data_1d_list.txt", "r", stdin);
    
    int t;
    cin >> t;
    cout << t << endl;

    int m = 0, n = 0;
    cin >> m;
    cin >> n;
    cout << m << " " << n << endl;

    vector<vector<int>> graph(m, vector<int>(n, 0));

    while (t--)
    {
        for (int y = 0; y < m; y++)
        {
            for (int x = 0; x < n; x++)
            {
                cin >> graph[y][x];
            }
        }

        printVector_2d(graph);
    }
    fclose(fp);
}

// 方向向量
vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
// 坐标的定义方式1
int x[3][3],y[3][3];

int main()
{
    // input_a_b();

    input_1d_list();
}