#include <string>
#include <vector>

using namespace std;

long long Fibonacci(int n, long long prevFibo, long long prevprevFibo)
{
    if (n < 2)
        return (n * prevFibo) % 1234567;

    long long CurrentFibo = (prevFibo + prevprevFibo) % 1234567;

    prevprevFibo = prevFibo;

    prevFibo = CurrentFibo;

    return Fibonacci(n - 1, prevFibo, prevprevFibo);
}

int solution(int n)
{
    long long answer = 0;

    answer = Fibonacci(n, 1, 0);

    return answer;
}