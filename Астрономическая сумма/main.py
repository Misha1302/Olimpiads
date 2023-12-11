import sys

# SLOW https://tasks.olimpiada.ru/upload/files/tasks/73/2022/sol-iikt-9-11-mun-perm-22-23.pdf

sys.set_int_max_str_digits(0)

a, n = 10 ** 9, 10 ** 10  # map(int, input().split())

mod = (10 ** 9 + 7)
print((a * (2 ** (n + 1) - 1)) % mod)