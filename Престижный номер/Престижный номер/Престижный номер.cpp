#include <iostream>
#include <vector>

#define i64 long long 
#define i32 long
#define i8 char
#define str std::string
#define print(x) std::cout << x;

int main()
{
	while (true) {
		i64 n;
		std::cin >> n;

		std::vector<i64> digits;

		for (i64 i = 9; i >= 1; i--) {
			if (n <= 1) {
				for (i64 i = digits.size() - 1; i >= 0; i--)
					print(digits[i]);

				print('\n');
				break;
			}

			if (i == 1) {
				print(-1);
				print('\n');
				break;
			}

			if (n % i == 0) {
				digits.push_back(i);
				n /= i;

				i = 10;
				continue;
			}
		}
	}
}