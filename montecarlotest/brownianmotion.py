import numpy as np
import matplotlib.pyplot as plt

def gbm_simulator(S0, mu, sigma, T, N, M):
    dt = T / N
    price_paths = np.zeros((M, N + 1))
    price_paths[:, 0] = S0

    for i in range(1, N + 1):
        Z = np.random.normal(0, 1, M)
        price_paths[:, i] = price_paths[:, i - 1] * np.exp(
            (mu - 0.5 * sigma**2) * dt + sigma * np.sqrt(dt) * Z
        )

    return price_paths

# Parameters
S0 = 100      # Initial stock price
mu = 0.05     # Drift (% annual return)
sigma = 0.2   # Volatility (%)
T = 1         # Number of Years
N = 252       # Number of trading days
M = 10        # Number of simulations

paths = gbm_simulator(S0, mu, sigma, T, N, M)

for i in range(M):
    plt.plot(paths[i], lw=1)

plt.title('Geometric Brownian Motion Simulation')
plt.xlabel('Time Steps')
plt.ylabel('Stock Price')
plt.grid(True)
plt.show()
