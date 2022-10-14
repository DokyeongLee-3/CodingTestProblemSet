#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct SetCompare
{
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

long long solution(int n, vector<int> works)
{
    long long answer = 0;

    int Remaining = n;

    multiset<int, SetCompare> worksmap;

    size_t Count = works.size();

    for (size_t i = 0; i < Count; ++i)
    {
        worksmap.insert(works[i]);
    }

    while (Remaining > 0)
    {
        auto First = worksmap.begin();
        int NewTime = *First;

        if (NewTime == 0)
            break;

        --Remaining;

        worksmap.erase(worksmap.begin());

        worksmap.insert(NewTime - 1);
    }


    for (auto tmp : worksmap)
        answer += (tmp * tmp);

    return answer;
}


int main()
{
    vector<int> works;

    works.emplace_back(4);
    works.emplace_back(3);
    works.emplace_back(3);


    solution(4, works);
}