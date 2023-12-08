#include <iostream>
#include <vector>

#define i64 long long
#define size_t i64

i64 wi, he;

typedef struct point {
	i64 x;
	i64 y;
} point;

i64 ind(point p) {
	return p.x + p.y * wi;
}

void print(std::vector<char> arr) {
	for (size_t i = 0; i < arr.size(); i++) {
		if (i % wi == 0) {
			std::cout << "\n";
		}
		std::cout << arr[i];
	}

	std::cout << "\n";
}

void drawCell(point p, i64 size, std::vector<char>& arr) {
	for (size_t x = 0; x < size; x++)
	{
		for (size_t y = 0; y < size; y++)
		{
			point pix = { p.x + x, p.y + y };
			arr[ind(pix)] = '.';
		}
	}
}

int main()
{
	i64 k, w, h, t;
	std::cin >> k >> w >> h >> t;

	wi = w * k + (w + 1) * t;
	he = h * k + (h + 1) * t;

	std::vector<char> arr = std::vector<char>(wi * he);
	for (size_t i = 0; i < arr.size(); i++)
		arr[i] = '*';

	i64 cellsCount = wi / k;
	for (size_t i = 0; i < w; i++)
	{
		point p = { t * (i + 1) + k * i, -1 };

		for (size_t j = 0; j < h; j++) {
			p.y = t * (j + 1) + k * j;

			drawCell(p, k, arr);
		}
	}

	print(arr);
}