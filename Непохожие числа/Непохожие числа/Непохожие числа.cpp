#include <iostream>

#define i64 long long
#define size_t i64

i64 xSqrt = -1;
i64 numbers[1000];
i64 indexer = 0;

i64 dividers[1000];
i64 indexerDeviders = 0;


void setDeviders(i64 x) {
	for (size_t i = 2; i < x; i++)
	{
		if (x % i == 0)
			dividers[indexerDeviders++] = i;
	}
}

void FindNotSimilars(i64 x, i64 l, i64 r) {
	setDeviders(x);

	for (i64 i = l; i <= r; i++) {
		i64 count = 0;
		for (size_t j = 0; j < indexerDeviders; j++)
		{
			if (i % dividers[j] == 0) {
				count++;
				if (count >= 2)
					break;
			}
		}

		if (count < 2)
			numbers[indexer++] = i;
	}
}

int main()
{
	i64 x, l, r;
	std::cin >> x >> l >> r;

	clock_t t1 = clock();


	FindNotSimilars(x, l, r);


	std::cout << clock() - t1 << "\n";

	std::cout << indexer << "\n";

	for (size_t i = 0; i < indexer; i++)
	{
		std::cout << numbers[i] << " ";
	}
}