#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    std::stack<char> ParenStack;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    for (auto ch : s)
    {
        if (ch == '(')
        {
            ParenStack.push(ch);
        }

        else if (ch == ')')
        {
            if (!ParenStack.empty())
            {
                ParenStack.pop();
            }

            else
            {
                return false;
            }
        }
    }

    if (!ParenStack.empty())
        return false;

    return answer;
}
