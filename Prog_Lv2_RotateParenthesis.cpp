#include <string>
#include <stack>

using namespace std;

stack<char> ParenStack;


// }]()[{
bool CheckValid(const std::string& str)
{
    size_t Length = str.length();

    for (size_t i = 0; i < Length; ++i)
    {
        char Parenthesis = str[i];

        if (Parenthesis == '(' || Parenthesis == '[' || Parenthesis == '{')
            ParenStack.push(Parenthesis);

        else
        {
            if (ParenStack.empty())
                return false;

            char Top = ParenStack.top();
            if (Top == '(' && Parenthesis != ')')
                return false;

            else if (Top == '[' && Parenthesis != ']')
                return false;

            else if (Top == '{' && Parenthesis != '}')
                return false;

            ParenStack.pop();
        }
    }

    if (!ParenStack.empty())
        return false;

    return true;
}

int solution(string s)
{
    int answer = 0;

    size_t Length = s.length();

    for (size_t i = 0; i < Length; ++i)
    {
        std::string front = s.substr(0, i);
        std::string back = s.substr(i, Length - i);

        if (CheckValid(back + front))
            ++answer;
    }

    return answer;
}
