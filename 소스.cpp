#include <string>
#include <vector>

using namespace std;

// 임의의 숫자에 대해 연속 자연수의 합이 몇개로 표현되는지 알아보는 문제다.
// 연속 자연수의 합이기 때문에 임의의 수/2 + 1을 넘는 숫자로는 표현될 수 없다.
// 그리고 현재 더하고 있는 수중에서 가장 큰 수에 의한 경우의 수는 1개 밖에 없다.
// 
// 그러므로 임의의 수/2 + 1 부터 시작해서 1씩 빼면서 더한다.
// 더하다가 합이 임의의 수와 같아지면 경우가 1개 있는 것이다.
// 같아지지 않고 합이 더 크면 현재 더하고 있는 수중에서 가장 큰 수에 의한 경우의 수는 없다.
// 그리고 가장 큰수를 1빼면서 위의 과정을 반복한다.
// 마지막 수인 1까지 더했는데도 임의의 수보다 작다면 이후 숫자들에 대해서는 경우의 수가 없다.
//
int solution(int n) {
    int answer = 1;
    int halfNum = n / 2 + 1;
    while (1)
    {
        int sumNum = halfNum;
        if (sumNum == 1)
        {
            return answer;
        }
        for (int i = halfNum - 1; i >= 0; i--)
        {
            sumNum += i;
            if (sumNum == n)
            {
                answer++;
                break;
            }
            else if (sumNum > n)
            {
                break;
            }
            else if (i == 0)
            {
                return answer;
            }
        }
        halfNum--;
    }
    return answer;
}