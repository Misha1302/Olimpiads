#include <iostream>

#define i64 long long
#define size_t i64

void FindNumbers(i64 k, i64 m, i64 width, i64 height, i64& horizontals, i64& verticals) {
	/*if ((width + 1) * (k - width + 1) < m)
		goto end;

	for (size_t first = std::max(k - height + 1, 0ll); first < width; first++)
	{
		i64 second = k - first;

		if ((first + 1) * (second + 1) == m) {
			horizontals = first;
			verticals = second;

			return;
		}
	}


end:
	horizontals = -1;
	verticals = -1;*/

	i64 D = k * k - 4 * (-1) * (k - m + 1);

	if (D <= 0) goto error;

	horizontals = (-k + sqrt(D)) / -2;
	verticals = (-k - sqrt(D)) / -2;

	if (horizontals >= width || verticals >= height) goto error;

	return;

error:
	horizontals = -1;
	verticals = -1;
}

int main()
{
	i64 t, a, b, k, m;

	std::cin >> t;

	for (size_t i = 0; i < t; i++)
	{
		std::cin >> a >> b >> k >> m;

		i64 n1, n2;
		auto t = clock();
		FindNumbers(k, m, a, b, n1, n2);
		std::cout << clock() - t << " --- ";

		if (n1 == -1 || n2 == -1)
			std::cout << "-1" << "\n";
		else std::cout << n1 << " " << n2 << "\n";// << " " << n1 + n2 << " " << (n1 + 1) * (n2 + 1) << "\n";
	}
}