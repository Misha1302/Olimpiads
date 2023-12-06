#include <iostream>

#define f64 double
#define i64 long long
#define i32 long
#define bool char

int main()
{
	i64 length, width;
	i64 aDiagonal, bDiagonal;
	i64 packaging;

	std::cin >> length >> width;
	std::cin >> aDiagonal >> bDiagonal;
	std::cin >> packaging;

	i64 square = (width / bDiagonal * (length / aDiagonal))
		*
		((width / bDiagonal - 1) * (length / aDiagonal) - 1);

	i64 delta = square % packaging;
	square += delta;

	std::cout << square / packaging;
}