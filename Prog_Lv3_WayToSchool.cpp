#include <string>
#include <vector>

using namespace std;

int Count = 0;

vector<vector<int>> vecWay;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;

    vecWay.resize(n + 1);

    for (int i = 0; i < n + 1; ++i)
        vecWay[i].resize(m + 1);

    size_t Count = puddles.size();
    for (size_t i = 0; i < Count; ++i)
    {
        vecWay[puddles[i][1]][puddles[i][0]] = -1;
    }

    vecWay[1][1] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (vecWay[i][j] == -1)
                continue;

            if (i == 1 && j == 1)
                continue;

            int a = 0;
            int b = 0;

            if (vecWay[i][j - 1] != -1)
                a = vecWay[i][j - 1];

            if (vecWay[i - 1][j] != -1)
                b = vecWay[i - 1][j];

            vecWay[i][j] = (a + b) % 1000000007;
        }
    }



    return vecWay[n][m];
}

int main()
{
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles;

    puddles.resize(m);

    for (int i = 0; i < m; ++i)
    {
        puddles[i].resize(n);
    }

    vector<int> pd;
    pd.emplace_back(2);
    pd.emplace_back(2);

    puddles.push_back(pd);

    solution(m, n, puddles);

    return 0;
}