#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define i64 long long
#define size_t i64
#define i16 short

typedef struct size {
	i16 w;
	i16 h;
};

void InputSize(size& size) {
	//std::cin >> size.w >> size.h;
	size.w = rand() % 1000;
	size.h = rand() % 1000;
}

i64 binary_search(std::vector<i16>& m, i16 value) {
	i64 left = 0;
	i64 right = m.size();

	i64 count = 10;
	while (true)
	{
		i64 middle = (right + left) / 2;

		if (m[middle] == value)
			return middle;

		if (value > m[middle])
			left = middle;
		else right = middle;

		if (--count == 0)
			return ~left;
	}
}

bool CanSet(std::vector<i16>& m, i16 x, i16 maxSum) {
	i16 value = maxSum;
	i16 maxTry = 1 << 14;

	std::vector<i16> copy = m;

	for (size_t i = m.size() - 1; i >= 0; i--)
	{
		m = copy;

		while (true) {
			i64 index = binary_search(m, value - x);
			if (index < 0) index = ~index;
			value -= m[index];

			if (m[index] == -1)
				break;
			else if (x == value)
				return true;


			m[index] = -1;
		}

		copy[i] = -1;
	}

	return false;
}

int main()
{
	i64 len, distance, n;
	std::cin >> len >> distance >> n;

	std::vector<i16> m(n + 1);
	m[0] = -1;

	i64 maxSum = 0;

	for (size_t i = 1; i <= n; i++) {
		size s;
		InputSize(s);

		m[i] = std::max(s.w, s.h) - std::min(s.w, s.h);
		maxSum += std::max(s.w, s.h);
	}

	sort(m.begin(), m.end());
	std::cout << (CanSet(m, len - distance * (n + 1), maxSum) ? "true" : "false");
}