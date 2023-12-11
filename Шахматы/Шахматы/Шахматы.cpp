#include <iostream>
#include <vector>

#define i64 long long

int main()
{
	i64 n;
	std::cin >> n;

	i64 count = 0;

	for (size_t i = 0; i < n; i++) {
		i64 len;
		std::cin >> len;

		if (len <= i)
			break;

		count++;
	}

	std::cout << count << "\n";
	for (size_t i = 0; i < count; i++)
		std::cout << i + 1 << " " << i + 1 << "\n";
}