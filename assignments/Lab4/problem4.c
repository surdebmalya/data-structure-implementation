#include <stdio.h>

int repeating, absent;

void solve(int arr[], int size) {
    int total1 = 0, total2=0;
    for(int i=0; i<size; i++) {
        total1+=arr[i];
        total2+=arr[i]*arr[i];
    }
    int a = size*(size+1)/2 - total1;
    int b = size*(size+1)*(2*size+1)/6 - total2;
    int x = (b-a*a)/2*a;
    int y = (b+a*a)/2*a;
    repeating = x;
    absent = y;
}

int main() {
    int arr[] = {1, 2, 3, 3, 5};
    int size = sizeof(arr)/sizeof(*arr);
    
    solve(arr, size);
    
    printf("Repeating Number: %d, Missing Number: %d", repeating, absent);

    return 0;
}
