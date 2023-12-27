#include <iostream>
#include <vector>
#include <fstream>
#include <string>


#define i16 short
#define i8 char


struct var {
	i16 value;
};

struct el {
	i16 value;
};

struct swapCmd {
	i16 ind1;
	i16 ind2;
};


std::ostream& operator <<(std::ostream& a, var b) { return a << b.value; }
std::ostream& operator <<(std::ostream& a, el b) { return a << b.value; }


el items[10'000];
var vars[26];
i16 N;
std::vector<swapCmd> swaps;

void printInfo() {
	std::cout << "array: ";
	for (size_t i = 0; i < N; i++)
		std::cout << items[i] << ", ";
	std::cout << "\b\b --- ";

	std::cout << "vars: ";
	for (size_t i = 0; i < 3; i++)
		std::cout << vars[i] << ", ";
	std::cout << "\b\b \n";
}

void swapEls(i16 el1, i16 el2) {
	//std::cout << "a" << "<-" << el1 << "\n";
	//std::cout << el1 << "<-" << el2 << "\n";
	//std::cout << el2 << "<-" << "a" << "\n";

	auto temp = items[el1];
	items[el1] = items[el2];
	items[el2] = temp;

	//printInfo();
}

void swapsGenerator() {
	i16 greaterThan = -1;

	for (i16 i = 0; i < N; i++)
	{
		if (i == items[i].value)
			continue;

		i16 minInd = i;
		for (i16 j = 0; j < N; j++)
		{
			if (greaterThan < items[j].value && items[j].value < items[minInd].value)
				minInd = items[j].value;
		}


		if (i != minInd) {
			// swapCmd cmd = { std::min(i + 1, minInd + 1), std::max(i + 1, minInd + 1) };
			swapCmd cmd = { i + 1, minInd + 1 };
			swaps.push_back(cmd);
			swapEls(i, minInd);
		}

		greaterThan = items[i].value;
	}

}

void printOptimized() {
	i16 len = 0;
	for (i16 i = 0; i < swaps.size(); i++) {
		auto& e = swaps[i];

		len++;
		// std::cout << "a" << "<-" << e.ind1 << "\n";
		len++;
		// std::cout << e.ind1 << "<-" << e.ind2 << "\n";

		while
			(
				i + 1 < swaps.size() &&
				(
					swaps[i].ind2 == swaps[(i16)i + (i16)1].ind1
					|| swaps[i].ind2 == swaps[(i16)i + (i16)1].ind1
					)
				)
		{
			i++;
			e = swaps[i];
			// std::cout << e.ind1 << "<-" << e.ind2 << "\n";
			len++;
			//std::cout << "opt";
		}

		// std::cout << e.ind2 << "<-" << "a" << "\n";
		len++;
		// std::cout << "\n";
	}
	std::cout << len;
}

void printNotOptimized() {
	for (i16 i = 0; i < swaps.size(); i++) {
		auto& e = swaps[i];
		std::cout << "swap " << e.ind1 << " " << e.ind2 << "\n";
	}
}

int main()
{
	swaps = std::vector<swapCmd>();
	/*std::cin >> N;

	for (size_t i = 0; i < N; i++)
		std::cin >> items[i].value;*/


	for (size_t i = 1; i <= 18; i++)
	{
		auto s = std::to_string(i);
		if (i <= 9)
			s = s.insert(0, "0");

		std::ifstream in("F:\\DOWNLOADS\\7-d\\D\\Input" + s + ".txt");
		std::ifstream ans("F:\\DOWNLOADS\\7-d\\D\\Answer" + s + ".txt");

		in >> N;
		swaps = std::vector<swapCmd>();

		for (size_t i = 0; i < N; i++)
			in >> items[i].value;


		std::cout << i << ". ";
		swapsGenerator();

		printOptimized();

		i16 temp;
		ans >> temp;
		std::cout << " " << temp << "\n";
	}
	// printNotOptimized();
}