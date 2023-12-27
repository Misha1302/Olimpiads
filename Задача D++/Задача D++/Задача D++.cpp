#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>


#define i16 short
#define i8 char
#define zero i8
#define size_t i16

i16 N;
i16 items[10'000];

void PrintBlocks(std::vector<std::vector<i16>> blocks) {
	return;
	for (size_t i = 0; i < blocks.size(); i++)
	{
		std::cout << i + 1 << ". ";

		for (size_t j = 0; j < blocks[i].size(); j++) {
			std::cout << blocks[i][j] << " ";
		}

		std::cout << "\n";
	}
}

std::vector<std::vector<i16>> SplitIntoBlock() {
	std::vector<std::vector<i16>> blocks;

	std::vector<i16> mapp;

	size_t i = 0;
	i16 ind = i;
	while (i < N)
	{
		i16 j = items[i];

		for (auto& el : mapp)
			if (el == j)
				goto next;

		blocks.push_back(std::vector<i16>());

		j = i + 1;
		do {
			mapp.push_back(j);
			blocks[ind].push_back(j);
			j = items[j - 1];
		} while (j != i + 1);
		blocks[ind].push_back(j);

		ind++;
	next:
		i++;
	}

	return blocks;
}

i16 CountLen(std::vector<std::vector<i16>> blocks) {
	i16 len = 0;

	for (size_t i = 0; i < blocks.size(); i++) {
		if (blocks[i].size() < 2 || blocks[i][0] == blocks[i][1]) 
			continue;

		len += blocks[i].size();
	}

	return len;
}

void Execute() {
	auto blocks = SplitIntoBlock();
	PrintBlocks(blocks);

	std::cout << CountLen(blocks);
}

void Input() {
	std::cin >> N;

	for (size_t i = 0; i < N; i++)
		std::cin >> items[i];
}

int main()
{
	for (size_t i = 1; i <= 18; i++)
	{
		auto s = std::to_string(i);
		if (i <= 9)
			s = s.insert(0, "0");

		std::ifstream in("F:\\DOWNLOADS\\7-d\\D\\Input" + s + ".txt");
		std::ifstream ans("F:\\DOWNLOADS\\7-d\\D\\Answer" + s + ".txt");

		in >> N;

		for (size_t i = 0; i < N; i++)
			in >> items[i];
		// Input();

		Execute();

		i16 temp;
		ans >> temp;
		std::cout << " " << temp << "\n";
	}
	// printNotOptimized();
}