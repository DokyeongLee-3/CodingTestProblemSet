#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> vecUsedTicket;
vector<int> vecPath;
bool End = false;

bool TicketSort(const vector<string> str1, const vector<string> str2)
{
    for (size_t i = 0; i < 2; ++i)
    {
        if (str1[i] != str2[i])
        {
            return str1[i] < str2[i];
        }
    }

    return str1 < str2;
}

// ["ICN", "SFO"] ["ICN", "ATL"]
void FindNextTicket(const vector<vector<string>>& tickets, const std::string& StartPoint, vector<vector<string>>& Next)
{
    size_t Count = tickets.size();
    for (size_t i = 0; i < Count; ++i)
    {
        if ((tickets[i][0] == StartPoint) && !vecUsedTicket[i])
            Next.emplace_back(tickets[i]);
    }

    if (Next.size() > 1)
        sort(Next.begin(), Next.end(), TicketSort);
}

void DFS(vector<vector<string>>& tickets, string Start)
{
    bool AllUsed = true;
    size_t UseCount = vecUsedTicket.size();

    for (size_t i = 0; i < UseCount; ++i)
    {
        if (!vecUsedTicket[i])
        {
            break;
        }

        if (i == UseCount - 1)
            End = true;
    }

    if (End)
        return;

    vector<vector<string>> vecStr;

    FindNextTicket(tickets, Start, vecStr);

    size_t NextTicketCandCount = vecStr.size();
    size_t UsedTicketIdx = 0;
    for (size_t j = 0; j < NextTicketCandCount; ++j)
    {
        // tickets중에 vecStr[0]와 매치되는 티켓 찾아서 그 티겟 인덱스를 vecUsedTicket = true
        size_t Count = tickets.size();

        for (size_t i = 0; i < Count; ++i)
        {
            if (tickets[i][0] == vecStr[j][0] && tickets[i][1] == vecStr[j][1] && !vecUsedTicket[i])
            {
                UsedTicketIdx = i;
                break;
            }
        }

        vecUsedTicket[UsedTicketIdx] = true;
        vecPath.emplace_back((int)UsedTicketIdx);

        DFS(tickets, tickets[UsedTicketIdx][1]);

        if (End)
            return;
    }

    int Last = vecPath[vecPath.size() - 1];
    vecPath.pop_back();
    vecUsedTicket[Last] = false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    size_t Count = tickets.size();

    vecUsedTicket.resize(Count);

    DFS(tickets, string("ICN"));

    size_t PathLength = vecPath.size();

    for (size_t i = 0; i < PathLength; ++i)
    {
        if (i == 0)
        {
            answer.emplace_back(tickets[vecPath[i]][0]);
            answer.emplace_back(tickets[vecPath[i]][1]);
        }

        else
        {
            answer.emplace_back(tickets[vecPath[i]][1]);
        }
    }

    return answer;
}
