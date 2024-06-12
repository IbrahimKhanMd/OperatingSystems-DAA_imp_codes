#include <iostream>
#include <vector>
int main() {
    int n, l, m, k;
    float avg1, avg2;
    std::cout << "enter the no of processes\n";
    std::cin >> n;
    std::vector<int> a(n), b(n);  
    for (int i = 0; i < n; i++) {
        std::cout << "enter the burst time for process " << i + 1 << "\n ";
        std::cin >> a[i];
    }
    int i = 0, j = 0;
    k = m = l = 0;
    std::cout << "process no \t burst time\t waiting time\t TAT\n";
    while (i < n) {
        k += a[i];
        b[i] = k;
        m += b[i];
        l += i;
        std::cout << i + 1 << "\t\t" << a[i] << "\t\t" << j << "\t\t" << k << "\n";
        j += a[i];
        i++;
    }
    avg1 = (m - k) * 1.0 / n;
    avg2 = m * 1.0 / n;
    std::cout << "avg turn around time = " << avg2 << "\n";
    std::cout << "avg waiting time = " << avg1 << "\n"; 
    return 0;
}



