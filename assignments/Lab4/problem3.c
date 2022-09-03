#include <stdio.h>
#define N 4

void rotate_anticlkwise(int arr[N][N]) {
    int L=0, R=N-1, T=0, B=N-1;
    while(L<=R) {
        for(int i=L; i<R; i++) {
            int val = arr[T][L+i];
            arr[T][L+i] = arr[T+i][R];
            arr[T+i][R] = arr[B][R-i];
            arr[B][R-i] = arr[B-i][L];
            arr[B-i][L] = val;
        }
        L++;
        R--;
        T++;
        B--;
    }
}

void print(int arr[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    rotate_anticlkwise(arr);
    
    print(arr);

    return 0;
}
