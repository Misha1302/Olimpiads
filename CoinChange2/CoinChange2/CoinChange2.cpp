#include <iostream>
#include <vector>
#include <algorithm>

#define i64 signed long long

int main()
{
	std::vector<i64> coins = { 1, 5, 2 };
	i64 money = 11;

	std::sort(coins.begin(), coins.end());

	std::vector<i64> dp(money + 1, -1);

	dp[0] = 0;
	// с 1, т.к. ноль уже посчитан
	for (size_t i = 1; i < dp.size(); i++)
	{
		i64 optJ = -1;

		for (size_t j = 0; j < coins.size(); j++)
		{
			// УЗНАТЬ, ПОЧЕМУ МЕНЯЕТСЯ ТИП ПРИ МИНУСЕ
			i64 ind = i - coins[j];

			// прерываем цикл, если больше посчитать нельзя
			if (ind < 0ll)
				break;

			// если возможно достичь суммы (i - coins[j])
			if (dp[i - coins[j]] != -1) {
				// dp[i - coins[j]] - вычет из суммы значения по индексу j
				// dp[i - coins[optJ]] - вычет из суммы оптимального на данный момент
				// если optJ не инициализован или нашли индекс j, что dp[i - coins[j]] < dp[i - coins[optJ]]

				if (optJ == -1)
					optJ = j;
				else if (dp[i - coins[optJ]] > dp[i - coins[j]])
					optJ = j;
			}
		}

		if (optJ != -1) {
			// прибавляем 1 к самому оптимальному варианту
			dp[i] = dp[i - coins[optJ]] + 1;
		}
	}

	std::cout << dp[money];
}
