#include <iostream>

#define i64 long long
#define i32 long

int main()
{
	i64 m;
	i64 n;

	std::cin >> n >> m;

	i64* rights = new i64[m];
	i64* lefts = new i64[n];

	for (i64 i = 0; i < n; i++)
		std::cin >> lefts[i];
	
	for (i64 i = 0; i < m; i++)
		std::cin >> rights[i];


	i64 right = 0;
	i64 left = 0;

	while (true) {
		if (right < m && left < n) {
			if (rights[right] == lefts[left]) {
				std::cout << 0 << " " << rights[right] << "\n";
				right++;
				left++;
			}
			else if (rights[right] < lefts[left]) {
				std::cout << (lefts[left] - rights[right]) / 2 << " " << (rights[right] + lefts[left]) / 2 << "\n";

				right++;
				left++;
			}
			else if (rights[right] >= lefts[left]) {
				std::cout << 0 << " " << lefts[left] << "\n";

				left++;
			}
		}
		else if (right < m) {
			for (; right < m; right++)
				std::cout << 0 << " " << rights[right] << "\n";
		}
		else if (left < n) {
			for (; left < n; left++)
				std::cout << 0 << " " << lefts[left] << "\n";
		}
		else {
			break;
		}
	}
}