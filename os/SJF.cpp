#include <stdio.h>
int main() {
    int i, j, n, a[10], pro[10], b[10], l, m, k, temp1, temp2;
    float avg1, avg2;
  printf("Enter the number of processes:\n");
    scanf("%d", &n);
    printf("Enter the process number and burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("\nEnter the process number:\n");
        scanf("%d", &pro[i]);
        printf("Enter the burst time for the process:\n");
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                temp1 = a[i];
                a[i] = a[j];
                a[j] = temp1;
                temp2 = pro[i];
                pro[i] = pro[j];
                pro[j] = temp2;
            }
    i = l = m = k = j = 0;
    printf("\nProcess No\tBurst Time\tWaiting Time\tTurnaround Time");
    while (i < n) {
        k = k + a[i];
        b[j] = k;
        m = m + b[i];
        l = l + j;
        printf("\n%d\t\t%d\t\t%d\t\t%d", pro[i], a[i], j, k);
        j = a[i] + j;
        i = i + 1;
    }
    avg1 = l * 1.0 / n;
    avg2 = m * 1.0 / n;
    printf("\nAvg Turnaround Time = %.2f", avg2);
    printf("\nAvg Waiting Time = %.2f\n", avg1);
    return 0;
}
