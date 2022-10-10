#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool solution(vector<string> phone_book)
{

    sort(phone_book.begin(), phone_book.end());

    bool answer = true;

    size_t Count = phone_book.size();

    for (size_t i = 0; i < Count - 1; ++i)
    {
        std::string Src = phone_book[i];

        if (Src.length() <= 0)
            continue;

        int j = i + 1;

        size_t Pos = -1;

        if ((Pos = phone_book[j].find(Src)) != std::string::npos)
        {
            if (Pos == 0)
            {
                return false;
            }
        }

    }

    return answer;
}