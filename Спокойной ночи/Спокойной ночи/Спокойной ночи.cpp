#include <iostream>

#define i64 long long
#define size_t i64

void PrintTime(i64 h, i64 m) {
	if (h < 10)
		std::cout << "0";
	std::cout << h;

	std::cout << ":";

	if (m < 10)
		std::cout << "0";
	std::cout << m;
}

int main()
{
	i64 h, m, t;
	char tempC;

	std::cin >> h >> tempC >> m;
	std::cin >> t;


	i64 h1, m1, temp;

	m1 = t % 60;
	h1 = (t - m1) / 60;

	i64 resultM = m + m1;
	i64 resultH = h + h1;

	if (resultM >= 60) {
		resultH++;
		resultM %= 60;
	}

	PrintTime(resultH % 24, resultM);
}