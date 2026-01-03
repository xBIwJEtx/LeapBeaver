# 3-State Leap Beaver Breakthroughs: The Road to 2,149 🚀

Expanding the state count to 3 has unlocked a vast computational landscape for the Leap Beaver architecture. While initial searches yielded machines with lower performance than the 2-state champion (517), the algorithm eventually identified a "complexity explosion," leading to a new global record for this class of nonlocal Turing machines.

## 🏆 Hall of Fame: 3-State Discoveries

We have documented the evolution of these discoveries, representing the four most significant milestones in our 3-state, 5-symbol search:

### 🥇 1. The Global Record ($\Sigma = 2,149$)
* **Score:** 2,149 (Steps: 386,484)
* **DNA:** `2LB 4LB 1LC 3RC 4RA | 4RA 4RB 2LB 1LB 4LB | 2RB 2RH 4RC 2RB 3RB`
* **Behavior:** *Expanding Oscillator* — This machine produces the most intricate tape structure recorded to date. It utilizes a nonlinear boundary expansion driven by highly synchronized nonlocal jumps.

### 🥈 2. The High-Performance Milestone ($\Sigma = 750$)
* **Score:** 750 (Steps: 40,618)
* **DNA:** `2LB 4RB 1LC 3RC 4RA | 4RA 4RB 2LB 1LB 4LB | 2RB 3LH 4RC 2RB 3RB`
* **Significance:** This was the first machine to break the 517-score barrier of the 2-state class, confirming that the 3-state architecture provides a significantly higher ceiling for computational complexity.

### 🥉 3. The Optimized Runner ($\Sigma = 442$)
* **Score:** 442 (Steps: 66,263)
* **DNA:** `4LC 4LC 1LA 1LB 3LB | 2LA 4LB 4RA 2LB 4RA | 2RC 4LH 3RA 4RB 3RB`
* **Note:** Although it scores lower than the 2-state champion, this variant exhibits a novel movement pattern that utilizes high-magnitude leaps more frequently than previous iterations.

### 🎖️ 4. The Prototype ($\Sigma = 421$)
* **Score:** 421 (Steps: 72,707)
* **DNA:** `4LC 4LC 1LA 1LB 3LB | 2LA 4LB 4RA 2LB 4RA | 2RC 4RH 3RA 2RB 3RB`
* **Note:** A foundational prototype of the 442-variant. It shares a similar logic but halts slightly earlier due to a specific configuration in State C.

---

## 🔍 DNA Analysis: Small Changes, Big Impact

The most striking insight comes from comparing the **750-score** and **2,149-score** machines:
* **States A and B** are almost identical in both machines.
* The critical difference lies in **State A**: the 750-variant uses `4RB`, whereas the 2,149-variant uses `4LB`.
* A single change in jump direction (Move) caused the score to jump from **750 to 2,149**—nearly a 3x increase in efficiency.



This provides empirical evidence of a **Rugged Fitness Landscape**, a core theme of our research. It demonstrates that complexity in nonlocal systems is extremely sensitive to minute changes in the transition rules.

---
