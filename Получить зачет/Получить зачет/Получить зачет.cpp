#include <iostream>
#include <vector>

#define i64 signed long long
#define size_t i64
#define i16 signed short

int main()
{
	i64 n, needToPass;
	std::cin >> n >> needToPass;

	auto vec = new std::vector<i16>(n);

	i64 sum = 0;
	size_t i;
	for (i = 0; i < n; i++) {
		//(*vec)[i] = rand() * i % needToPass;
		std::cin >> (*vec)[i];
		sum += (*vec)[i];
		//std::cout << (*vec)[i] << " ";
	}
	//std::cout << "\n";

	i64 count = 0;
	for (i = 0; sum >= needToPass && i < n; i++) {
		count++;
		sum -= (*vec)[i];
	}
	count--;

	

	//i64 res = vec->size() - count;
	std::cout << (count == 0 ? -1 : count);//(res == vec->size() ? (i64)(-1) : res);
}