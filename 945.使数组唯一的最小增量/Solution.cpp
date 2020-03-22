#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
#if 0
	int minIncrementForUnique(vector<int>& A) {
		sort(A.begin(), A.end());
		int move = 0;
		for (int i = 1; i < A.size(); ++i)
		{
			if (A[i] <= A[i - 1])
			{
				int tmp = A[i];
				A[i] = A[i - 1] + 1;
				move += A[i] - tmp;
			}
		}
		return move;
	}
#endif 

	int minIncrementForUnique(vector<int>& A) {
		int counter[40001] = { 0 };
		int max = -1;
		for (auto num : A)
		{
			counter[num]++;
			max = max > num ? max : num;
		}

		int move = 0;
		for (int i = 0; i <= max; i++)
		{
			if (counter[i] > 1)
			{
				int d = counter[i] - 1;
				move += d;
				counter[i + 1] += d;
			}
		}

		int d = counter[max + 1] - 1;
		move += (1 + d) * d / 2;

		return move;
	}
};

int main()
{
	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);

	vector<int> A;
	int a;
	while (cin >> a)
	{
		A.push_back(a);
	}

	Solution s;
	cout << s.minIncrementForUnique(A);

	return 0;

}