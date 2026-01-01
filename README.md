# Leap Beaver: High-Performance Search in 2-State 5-Symbol TMs 🦫

This repository hosts the implementation of the **Leap Beaver** search algorithm. The core search engine is implemented in **C++** for performance, with **Python** scripts provided for behavioral verification and fitness landscape analysis.

## 🏆 Key Findings
- **Champion Machine:** Found a machine with a halting score of **$\Sigma = 517$**.
- **Architecture:** 2-State, 5-Symbol (Adaptive movement logic).
- **Complexity:** Analysis reveals a highly "rugged" fitness landscape with an isolated peak.

## 📊 Visualizations
Below is the fitness landscape analysis of the champion machine, confirming the "Twin" anomaly and the sensitivity of the configuration space:

![Fitness Landscape](results/MU517''.png)
*(Figure generated using the Python verification suite)*

## 🚀 Project Structure
- `cpp/`: Core search engine and simulation logic (C++17).
- `python/`: Verification tools and plotting scripts (NumPy/Matplotlib).

## 🛠️ Usage

### 1. C++ Core (Search & Simulation)
Navigate to the `cpp` directory to compile and run the main engine:

```bash
cd cpp
g++ -O3 main.cpp -o leap_beaver
./leap_beaver
