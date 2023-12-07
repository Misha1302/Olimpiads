#include <iostream>

#define i64 long long
#define loop(x, y) for (int x = 0; y; x++)

i64 slow(i64 a, i64 b, i64 c);
i64 fast(i64 a, i64 b, i64 c, i64 step);

int main()
{
	i64 a, b, c;
	std::cin >> a >> b >> c;

	i64 sum;

	if (a > 1000000 && b > 1000000 && c > 1000000)
		sum = fast(a, b, c, 1000000);
	else if (a > 10000 && b > 10000 && c > 10000)
		sum = fast(a, b, c, 10000);
	else sum = slow(a, b, c);

	std::cout << sum;
}

i64 slow(i64 a, i64 b, i64 c) {
	i64 sum = 0;

	while (true) {
		if (a > 0) {
			if (b <= 0 && c <= 0)
				break;

			if (b > c) b--;
			else c--;

			a--;
		}
		else if (b > 0) {
			if (a <= 0 && c <= 0)
				break;

			if (a > c) a--;
			else c--;

			b--;
		}
		else if (c > 0) {
			if (a <= 0 && b <= 0)
				break;

			if (a > b) a--;
			else b--;

			c--;
		}
		else if (a <= 0 && b <= 0 && c <= 0) {
			break;
		}

		sum++;
	}

	return sum;
}

i64 fast(i64 a, i64 b, i64 c, i64 step) {
	i64 sum = 0;

	while (true) {
		if (a > step) {
			if (b <= step && c <= step)
				break;

			if (b > c) b -= step;
			else c -= step;

			a -= step;
		}
		else if (b > step) {
			if (a <= step && c <= step)
				break;

			if (a > c) a -= step;
			else c -= step;

			b -= step;
		}
		else if (c > step) {
			if (a <= step && b <= step)
				break;

			if (a > b) a -= step;
			else b -= step;

			c -= step;
		}
		else if (a <= step && b <= step && c <= step) {
			break;
		}

		sum += step;
	}

	if (step / 100 > 100 && a > 100 && b > 100 && c > 100)
		return sum + fast(a, b, c, step / 100);

	return sum + slow(a, b, c);
}