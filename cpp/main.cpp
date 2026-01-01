#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <string>

constexpr int NUM_STATES = 2;
constexpr int NUM_SYMBOLS = 5;
constexpr int MAX_STEPS = 100000;
constexpr int TAPE_SIZE = 200000;
constexpr int CENTER = TAPE_SIZE / 2;

struct Transition {
    int write;
    int dir;
    int next;
};

struct Machine {
    Transition T[NUM_STATES][NUM_SYMBOLS];
};

struct Result {
    bool halted;
    int steps;
    int score;
    int span;
};


std::string get_machine_code(const Machine &m) {
    std::string s = "";
    char states[] = {'A', 'B'};
    char dirs[] = {'L', 'R'};
    
    for(int state=0; state<NUM_STATES; state++){
        for(int sym=0; sym<NUM_SYMBOLS; sym++){
            const auto &t = m.T[state][sym];
            s += std::to_string(t.write);
            s += (t.dir == 1 ? 'R' : 'L');
            if(t.next == -1) s += 'H';
            else s += states[t.next];
            s += " ";
        }
        if(state == 0) s += "| ";
    }
    return s;
}

Machine generate_machine(std::mt19937 &rng) {
    std::uniform_int_distribution<int> sym(1,4);
    std::uniform_int_distribution<int> coin(0,99);
    
    Machine m{};
    bool has_halt = false;

    for(int s=0;s<NUM_STATES;s++){
        for(int a=0;a<NUM_SYMBOLS;a++){
            auto &t = m.T[s][a];

            if(coin(rng) < 80) t.write = sym(rng);
            else t.write = a;

            t.dir = (coin(rng) < 50) ? 1 : -1;

            if (!has_halt && coin(rng) < 5) {
                t.next = -1;
                has_halt = true;
            } else if (coin(rng) < 2) {
                 t.next = -1;
                 has_halt = true;
            } else {
                t.next = coin(rng) < 50 ? 0 : 1;
            }
        }
    }

    if(!has_halt) {
        m.T[1][4].next = -1; 
    }
    
    return m;
}

Result run(const Machine &m) {
    std::vector<int8_t> tape(TAPE_SIZE, 0); 
    int head = CENTER;
    int state = 0;
    
    int minp = head;
    int maxp = head;

    for(int step=1; step<=MAX_STEPS; step++){
        if(head < 0 || head >= TAPE_SIZE) return {false, step, 0, 0};

        int cur = tape[head];
        const auto &t = m.T[state][cur];

        tape[head] = t.write;
        
        int jump = (t.write == 0 ? 1 : t.write);
        head += t.dir * jump;

        if (head < minp) minp = head;
        if (head > maxp) maxp = head;

        state = t.next;

        if(state == -1){
            int score = 0;
            for(int i=minp; i<=maxp; i++) {
                if(tape[i] != 0) score++;
            }
            return {true, step, score, maxp - minp};
        }
    }
    return {false, MAX_STEPS, 0, maxp - minp};
}

int main(){
    std::mt19937 rng(std::random_device{}());
    long long tries=0;
    int best_score=0;

    std::cout << "🚀 Leap Beaver Search Started...\n";

    while(true){
        tries++;
        Machine m = generate_machine(rng);
        Result r = run(m);

        if(r.halted){
            if(r.score > best_score){
                best_score = r.score;
                std::cout << "\n🔥 NEW RECORD FOUND!\n";
                std::cout << "---------------------------------------------\n";
                std::cout << "Code:  " << get_machine_code(m) << "\n";
                std::cout << "Score: " << r.score << "\n";
                std::cout << "Steps: " << r.steps << "\n";
                std::cout << "Span:  " << r.span << "\n";
                std::cout << "Tries: " << tries << "\n";
                std::cout << "---------------------------------------------\n";
            }
        }

        if(tries % 1000000 == 0)
            std::cout << "\rChecking... " << tries/1000000 << "M machines | Best: " << best_score << std::flush;
    }
}