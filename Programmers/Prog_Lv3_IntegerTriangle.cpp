#include <string>
#include <vector>

using namespace std;

int Sum = 0;
int PartialSum[500][500] = { 0, };

int solution(vector<vector<int>> triangle)
{
    int answer = 0;

    size_t Count = triangle.size();

    PartialSum[0][0] = triangle[0][0];

    for (size_t i = 1; i < Count; ++i)
    {
        for (size_t j = 0; j < triangle[i].size(); ++j)
        {
            if (j == 0)
            {
                PartialSum[i][j] = triangle[i][j] + PartialSum[i - 1][0];
            }

            else if (j == triangle[i].size() - 1)
            {
                PartialSum[i][j] = triangle[i][j] + PartialSum[i - 1][j - 1];
            }

            else
            {
                PartialSum[i][j] = triangle[i][j] + max(PartialSum[i - 1][j], PartialSum[i - 1][j - 1]);
            }
        }
    }

    size_t LastLevelCount = triangle[Count - 1].size();

    for (size_t i = 0; i < LastLevelCount; ++i)
        answer = max(answer, PartialSum[Count - 1][i]);


    return answer;
}