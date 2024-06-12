#include <iostream>
#include <vector>
void findWaitingTime(const std::vector<int>& processes, const std::vector<int>& bt, std::vector<int>& wt, int quantum) {
    int n = processes.size();
    std::vector<int> rem_bt = bt;
    int t = 0; // Current time
    while (true) {
        bool done = true; // Assume all processes are done
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = false; // There is a pending process
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done)
            break;
    }
}
void findTurnAroundTime(const std::vector<int>& processes, const std::vector<int>& bt, const std::vector<int>& wt, std::vector<int>& tat) {
    int n = processes.size();
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
void findAvgTime(const std::vector<int>& processes, const std::vector<int>& bt, int quantum) {
    int n = processes.size();
    std::vector<int> wt(n), tat(n);
    int total_wt = 0, total_tat = 0;
    findWaitingTime(processes, bt, wt, quantum);
    findTurnAroundTime(processes, bt, wt, tat);
    std::cout << "PN\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        std::cout << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\n";
    }
    std::cout << "Average waiting time = " << static_cast<float>(total_wt) / n << "\n";
    std::cout << "Average turn around time = " << static_cast<float>(total_tat) / n << "\n";
}
int main() {
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;
    std::vector<int> processes(n);
    std::vector<int> burst_time(n);
    std::cout << "Enter burst times for each process:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Process " << i + 1 << ": ";
        std::cin >> burst_time[i];
        processes[i] = i + 1;
    }
    int quantum;
    std::cout << "Enter the time quantum: ";
    std::cin >> quantum;
    findAvgTime(processes, burst_time, quantum);
    return 0;
}



