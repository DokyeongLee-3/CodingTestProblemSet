#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(int a, int b)
{
    return a > b;
}

// 6, 5, 5, 5, 3, 2, 1, 0
// 10 8 5 3 3 
// 9 9 0 0 0
//6 5 3 1 0
int solution(vector<int> citations)
{
    int answer = 0;

    std::sort(citations.begin(), citations.end(), Compare);

    size_t Count = citations.size();
    for (size_t i = 0; i < Count; ++i)
    {
        int Num = i + 1;

        if (citations[i] <= Num)
        {
            if (citations[i] >= Num)
                answer = Num;
            break;
        }
        else
            answer = Num;
    }


    return answer;
}