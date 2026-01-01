import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import numpy as np

machine_code_str = "0RB 2LA 1RA 3LB 1LH | 1LA 1RB 3RB 4LB 2LB"
STEPS_TO_RUN = 100000
TAPE_SIZE = 200000   
START_POS = TAPE_SIZE // 2

def parse_leap_beaver(code_str):
    parts = code_str.replace('|', ' ').split()
    table = {}
    for i, cmd in enumerate(parts):
        state = 0 if i < 5 else 1 
        symbol = i % 5 
        write_val = int(cmd[0])
        direction = 1 if cmd[1] == 'R' else -1
        next_s = -1 if cmd[2] == 'H' else ord(cmd[2]) - ord('A')
        table[(state, symbol)] = (write_val, direction, next_s)
    return table

tm_table = parse_leap_beaver(machine_code_str)
tape = np.zeros(TAPE_SIZE, dtype=np.int8)
head = START_POS
state = 0
halted_step = -1

history_head = []
history_state = []

print("🚀 Running Leap Simulation...")

for step in range(1, STEPS_TO_RUN + 1):
    history_head.append(head)
    history_state.append(state)

    read_val = tape[head]
    if (state, read_val) in tm_table:
        write_val, direction, next_s = tm_table[(state, read_val)]
        tape[head] = write_val
        
        jump_dist = write_val if write_val != 0 else 1
        head += (direction * jump_dist)
        state = next_s
        
        if next_s == -1: 
            halted_step = step
            break
        if head < 0 or head >= TAPE_SIZE: break
    else: break

final_score = np.count_nonzero(tape)
print(f"🎯 Final Sigma Score: {final_score}")

if halted_step > 0:
    min_idx = min(min(history_head), head)
    max_idx = max(max(history_head), head)
    viz_tape = tape[min_idx:max_idx+1]

    fig = plt.figure(figsize=(15, 10))
    gs = gridspec.GridSpec(3, 2, figure=fig)
    fig.suptitle(f"Leap Beaver Analysis | Steps: {halted_step} | Score: {final_score}", fontsize=16)

    
    ax2 = fig.add_subplot(gs[1, :])
    relative_pos = [h - START_POS for h in history_head]
    ax2.plot(range(len(history_head)), relative_pos, color='blue', linewidth=0.5, alpha=0.7)
    ax2.set_title("2. Head Trajectory (Time vs Position)")
    ax2.set_xlabel("Step (Time)")
    ax2.set_ylabel("Position (Relative to Start)")
    ax2.grid(True, alpha=0.3)

    
    ax4 = fig.add_subplot(gs[2, :])
    symbols = [1, 2, 3, 4]
    counts = [np.count_nonzero(tape == s) for s in symbols]
    
    bars = ax4.bar(symbols, counts, color=['#FF9999', '#66B2FF', '#99FF99', '#FFCC99'], edgecolor='black', zorder=3)
    
    ax4.set_title("4. Non-Zero Symbol Distribution (Output Composition)")
    ax4.set_xlabel("Symbol Value")
    ax4.set_ylabel("Frequency (Count)")
    ax4.set_xticks(symbols)
    ax4.grid(axis='y', linestyle='--', alpha=0.5, zorder=0)

    for bar in bars:
        height = bar.get_height()
        if height > 0:
            ax4.text(bar.get_x() + bar.get_width()/2., height,
                     f'{int(height)}',
                     ha='center', va='bottom', fontsize=10, fontweight='bold')

    plt.tight_layout()
    plt.show()

    plt.tight_layout()
    plt.show()