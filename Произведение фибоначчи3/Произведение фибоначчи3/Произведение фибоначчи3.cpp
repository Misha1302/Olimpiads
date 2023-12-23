#include <iostream>
#include <vector>

#define i64 long long
#define u64 unsigned long long
#define size_t i64

std::vector<i64> fibs;

// генерация чисел фибоначчи
void genFibs() {
    fibs = std::vector<i64>();
    fibs.push_back(2);
    fibs.push_back(3);

    i64 i = 2;
    while ((u64)fibs[i - 1] + (u64)fibs[i - 2] < ((1ull << 63ull) - 1ull)) {
        fibs.push_back(fibs[i - 1] + fibs[i - 2]);
        i++;
    }
}


// обход графа в глубину
i64 sum(i64 n, i64 index) {
    if (n == 1) // если достигли конечной точки
        return 1; // конечная точка - 1

    i64 s = 0; // переменная для хранения суммы
    // перебираем числа от index до момента, пока не найдем число в ряду фибоначчи больше n, или пока числа не закончатся 
    for (size_t i = index; i < fibs.size() && n >= fibs[i]; i++)
    {
        // если нашли число, которое способно делиться на число фибоначчи без остатка
        if (n % fibs[i] == 0) {
            // то запускаем ветвь с более маленьким числом (64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1)
            s += sum(n / fibs[i], i);
        }
    }

    // возвращаем итоговую сумму
    return s;
}

int main()
{
    genFibs();

    i64 n = 10e17;
    std::cout << sum(n, 0);
}