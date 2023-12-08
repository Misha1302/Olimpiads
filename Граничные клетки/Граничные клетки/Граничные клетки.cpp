#include <iostream>

#define i64 long long

int main()
{
	i64 m, n;
	std::cin >> m >> n;

	std::cout << (m * n) - ((m - 2) * (n - 2));
}