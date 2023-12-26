#include <iostream>
#include <vector>

#define i64 long long
#define i32 long
#define i16 short
#define i8 char

i64 getIndex(std::vector<i32> arr, i64 i, i64 startIndex) {
	return (arr.size() - abs(startIndex) % arr.size() + (i - 1)) % arr.size();
}

void printArr(std::vector<i32>& arr, i64 startIndex) {
	return;
	std::cout << startIndex << " --- ";
	for (size_t i = 1; i < arr.size() + 1; i++)
	{
		i64 ind = getIndex(arr, i, startIndex);
		if (!(ind < 0 || ind >= arr.size()))
			std::cout << ind << "-" << arr[ind] << ", ";
	}
	std::cout << "\n";
}

void interpret(std::vector<i32>& arr, i64 cmdsCount) {
	i64 startIndex = 0;

	i64 sum = 0;
	for (auto i : arr)
		sum += i;
	printArr(arr, startIndex);

	for (size_t i = 0; i < cmdsCount; i++)
	{
		i64 intCmd;
		std::cin >> intCmd;

		// cmd 1
		if (intCmd == 1) {
			i64 index, value;
			std::cin >> index >> value;

			i64 ind = getIndex(arr, index, startIndex);
			sum -= arr[ind];
			sum += value;
			arr[ind] = value;
		}
		// cmd 2
		else if (intCmd == 2) {
			i64 k;
			std::cin >> k;

			startIndex += k;
		}
		printArr(arr, startIndex);

		std::cout << /*">>>" <<*/ sum << "\n";
	}
}

int main()
{
	i64 numbersCount, cmdsCount;
	std::cin >> numbersCount;

	std::vector<i32> arr(numbersCount);
	for (size_t i = 0; i < arr.size(); i++)
		std::cin >> arr[i];

	std::cin >> cmdsCount;
	interpret(arr, cmdsCount);
}