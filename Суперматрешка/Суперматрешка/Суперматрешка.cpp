#include <iostream>

#define i64 long long
#define size_t i64

int main()
{
	i64 n, k;
	std::cin >> n >> k;

	for (size_t i = 0; i < n; i++)
	{
		i64 sum = 0;
		i64 max = -1;

		for (size_t j = 0; j < k; j++) {
			i64 temp;
			std::cin >> temp;

			sum += temp;

			if (max < temp)
				max = temp;
		}
		sum -= max;

		std::cout << ((sum <= max) == 1 ? "yes\n" : "no\n");
	}
}