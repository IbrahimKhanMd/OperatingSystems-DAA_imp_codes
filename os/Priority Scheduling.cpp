#include <iostream>
using namespace std;
struct Process {
    int id;
    int burstTime;
    int priority;
};
void priorityScheduling(Process processes[], int n) {
    // Sort processes by priority in descending order using a simple bubble sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (processes[j].priority < processes[j + 1].priority) {
                // Swap processes
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    int totalTime = 0;
    float averageWaitingTime = 0.0;
    cout << "Process\tBurst Time\tPriority\tWaiting Time" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "P" << processes[i].id << "\t" << processes[i].burstTime << "\t\t"
             << processes[i].priority << "\t\t" << totalTime << endl;
        averageWaitingTime += totalTime;
        totalTime += processes[i].burstTime;
    }
    averageWaitingTime /= n;
    cout << "\nAverage Waiting Time: " << averageWaitingTime << endl;
}
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    Process processes[n];
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "Enter burst time for process P" << processes[i].id << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter priority for process P" << processes[i].id << ": ";
        cin >> processes[i].priority;
    }
    priorityScheduling(processes, n);
    return 0;
}

