#include <iostream>
#include <vector>
#include <climits>
struct Process {
    int pid;
    int bt;
    int art;
};
void findWaitingTime(const std::vector<Process>& proc, std::vector<int>& wt) {
    int n = proc.size();
    std::vector<int> rt(n);
    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if (!check) {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;
        if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }    
        t++;
    }
}
void findTurnAroundTime(const std::vector<Process>& proc, const std::vector<int>& wt, std::vector<int>& tat) {
    int n = proc.size();
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}
void findavgTime(std::vector<Process>& proc) {
    int n = proc.size();
    std::vector<int> wt(n), tat(n);
    int total_wt = 0, total_tat = 0;
    findWaitingTime(proc, wt);
    findTurnAroundTime(proc, wt, tat);
    std::cout << " P\t\tBT\t\tWT\t\tTAT\t\t\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        std::cout << " " << proc[i].pid << "\t\t" << proc[i].bt << "\t\t " << wt[i] << "\t\t " << tat[i] << "\n";
    }
    std::cout << "\nAverage waiting time = " << static_cast<float>(total_wt) / n;
    std::cout << "\nAverage turn around time = " << static_cast<float>(total_tat) / n;
}
int main() {
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;
    std::vector<Process> proc(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Enter details for Process " << i + 1 << ":\n";
        std::cout << "Process ID: ";
        std::cin >> proc[i].pid;
        std::cout << "Burst Time: ";
        std::cin >> proc[i].bt;
        std::cout << "Arrival Time: ";
        std::cin >> proc[i].art;
    }
    findavgTime(proc);
    return 0;
}
