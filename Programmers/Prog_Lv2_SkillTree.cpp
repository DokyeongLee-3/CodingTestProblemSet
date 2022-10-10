#include <string>
#include <vector>

using namespace std;


int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;
	size_t Length = skill.length();

	size_t Count = skill_trees.size();
	for (size_t i = 0; i < Count; ++i)
	{
		size_t PrevPos = -1;
		size_t FindPos = -1;
		int Count = 0;

		for (int j = 0; j < Length; ++j)
		{
			char FindSkill = skill[j];

			FindPos = skill_trees[i].find(FindSkill);

			if (PrevPos == -1 && FindPos != string::npos)
			{
				if (j > 0)
					break;

				PrevPos = FindPos;
				++Count;
			}

			else if (PrevPos != -1 && FindPos != string::npos)
			{
				// 선행 스킬보다 먼저 찍으려는 경우
				if (PrevPos > FindPos)
					break;

				PrevPos = FindPos;
				++Count;
			}

			if (j == Length - 1)
			{
				++answer;
				break;
			}

			else if (FindPos == string::npos)
				PrevPos = -1;

		}
	}

	return answer;
}
