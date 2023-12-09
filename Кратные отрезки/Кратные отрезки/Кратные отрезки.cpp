#include <iostream>

#define i64 long long
#define size_t i64

i64 A[200000];

void PrintSubArray(i64 A[], i64 l, i64 r) {
	std::cout << "[";
	for (size_t i = l; i < r; i++)
		std::cout << A[i] << ", ";

	if (r - l >= 1)
		std::cout << "\b\b]\n";
	else std::cout << "]\n";
}


i64 CountSubArrays(i64 A[], i64 n, i64 k) {
	i64 sum = 0;

	for (size_t l = 0; l < n; l++) {
		i64 tempSum = 0;
		for (size_t r = l; r < n; r++) {
			tempSum += A[r];
			sum += tempSum % k == 0;
		}
	}

	return sum;
}

int main()
{
	// SLOW! ONLY 1 AND 2 SUBTASKS CAN BE EXECUTED

	i64 n, k;

	std::cin >> n >> k;

	for (size_t i = 0; i < n; i++)
		A[i] = rand() * i;
		//std::cin >> A[i];

	auto t1 = clock();
	std::cout << CountSubArrays(A, n, k);
	std::cout << "\n" << clock() - t1;
}