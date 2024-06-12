#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int **alloc = (int **)malloc(n * sizeof(int *));
    int **max = (int **)malloc(n * sizeof(int *));
    int *avail = (int *)malloc(m * sizeof(int));

    for (i = 0; i < n; i++) {
        alloc[i] = (int *)malloc(m * sizeof(int));
        max[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available resources vector: ");
    for (j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
    }

    int *f = (int *)malloc(n * sizeof(int));
    int *ans = (int *)malloc(n * sizeof(int));
    int ind = 0;

    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    int **need = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        need[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1) {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++) {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);
    }

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(alloc[i]);
        free(max[i]);
        free(need[i]);
    }
    free(alloc);
    free(max);
    free(avail);
    free(f);
    free(ans);
    free(need);

    return 0;
}
