#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    std::stack<char> ParenStack;

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
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
