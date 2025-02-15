import numpy as np


def change(n):
    coins = np.array([1, 5, 10, 25])
    coinsAmount = np.zeros(4, dtype=int)

    for idx in range(len(coins)-1,-1,-1):
        coinsAmount[idx] = n // coins[idx]
        n -= coins[idx]*coinsAmount[idx]
        print(f"{coins[idx]} : {coinsAmount[idx]}")
    print(coinsAmount.sum())

change(75)