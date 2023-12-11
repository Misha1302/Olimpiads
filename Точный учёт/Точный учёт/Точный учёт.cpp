#include <iostream>
#include <vector>
#include <algorithm>

#define i32 long
#define size_t i32

void PrintRepetitions(std::vector<i32>& vec1, std::vector<i32>& vec2) {
	i32 pointer1 = 0;
	i32 pointer2 = 0;

	auto vec = std::vector<i32>();

	// vec1 and vec2 sizes are equals
	auto top = vec1.size();

	while (pointer1 != pointer2 || pointer1 != top)
	{
		auto el1 = vec1[pointer1];
		auto el2 = vec2[pointer2];

		if (el1 == el2) {
			vec.push_back(el1);
			if (pointer1 + 1 < top) pointer1++;
			if (pointer2 + 1 < top) pointer2++;

			while (pointer1 < top && pointer2 < top && vec1[pointer1] == vec2[pointer2]) {
				pointer1++;
				pointer2++;
			}
		}
		else if (el1 < el2) {
			if (pointer1 + 1 < top) pointer1++;
			else break;
		}
		else if (el1 > el2) {
			if (pointer2 + 1 < top) pointer2++;
			else break;
		}
	}

	if (vec.size() == 0) {
		std::cout << "NO";
		return;
	}

	std::cout << vec.size() << "\n";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
}

int main()
{
	i32 n, m;

	std::cin >> n >> m;

	for (size_t k = 0; k < 1 /*true*/; k++)
	{
		auto vec1 = std::vector<i32>(std::max(n, m));
		for (size_t i = 0; i < n; i++)
			//std::cin >> vec1[i];
			vec1[i] = rand() * i % n;

		auto vec2 = std::vector<i32>(std::max(n, m));
		for (size_t i = 0; i < m; i++)
			//std::cin >> vec2[i];
			vec2[i] = rand() * i % m;

		std::sort(vec1.begin(), vec1.end());
		std::sort(vec2.begin(), vec2.end());

		PrintRepetitions(vec1, vec2);
	}
}