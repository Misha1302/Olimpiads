#include <iostream>
#include <stack>
#include <map>
#include <vector>

#define i32 long



typedef struct Reaction {
	i32 a, b, c;
} Reaction;

std::vector<i32> stack;
std::vector<Reaction> reactions;
i32 pointer;

void React() {
	if (pointer < 2)
		return;

	auto sub1 = stack[pointer - 1];
	auto sub2 = stack[pointer - 2];


	Reaction r = { -1, -1, -1 };
	if (sub1 == sub2)
	{
		pointer--;
		goto end;
	}

	for (size_t i = 0; i < reactions.size(); i++)
	{
		if ((reactions[i].a == sub1 && reactions[i].b == sub2) || (reactions[i].a == sub2 && reactions[i].b == sub1)) {
			r = reactions[i];
			break;
		}
	}

	if (r.a == -1)
		return;

	pointer -= 2;
	stack[pointer++] = r.c;

	end:
	React();
}

int main()
{
	i32 substancesMaxIndex, reactionsCount;
	std::cin >> substancesMaxIndex >> reactionsCount;

	reactions = std::vector<Reaction>(reactionsCount);

	for (size_t i = 0; i < reactionsCount; i++)
	{
		i32 a, b, c;
		std::cin >> a >> b >> c;

		reactions[i] = { a, b, c };
	}


	i32 substancesToExecute;
	std::cin >> substancesToExecute;

	std::vector<i32> substances(substancesToExecute);
	for (size_t i = 0; i < substancesToExecute; i++)
		std::cin >> substances[i];


	stack = std::vector<i32>(substancesToExecute);
	pointer = 0;
	for (size_t i = 0; i < substances.size(); i++)
	{
		stack[pointer++] = substances[i];

		React();
	}


	std::cout << "\n" << pointer << "\n";

	for (size_t i = 0; i < pointer; i++)
		std::cout << stack[i] << " ";
}