#include <iostream>
#include <vector>

#define i64 long long

typedef struct wind {
	i64 left, right, power;
} wind;

void InputWind(wind& w) {
	std::cin >> w.left >> w.right >> w.power;
}

void PrintInfo(std::vector<wind> vec, i64 fieldIndex) {
	i64 sum = 0;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i].left <= fieldIndex && vec[i].right >= fieldIndex) {
			sum += vec[i].power * ((fieldIndex - vec[i].left) % 2 == 0 ? 1 : -1);
		}
	}
	std::cout << ">>> " << sum << "\n";
}

int main()
{
	i64 windCount, printInfoFieldsCount;
	std::cin >> windCount >> printInfoFieldsCount;

	std::vector<wind> winds(windCount);

	for (size_t i = 0; i < windCount; i++)
	{
		InputWind(winds[i]);
	}

	for (size_t i = 0; i < printInfoFieldsCount; i++)
	{
		i64 fieldIndex;
		std::cin >> fieldIndex;
		PrintInfo(winds, fieldIndex);
	}
}