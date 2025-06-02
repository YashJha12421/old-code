#include <stdio.h>
#include <stdlib.h>

// Function to compute the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int t;
    scanf("%d", &t); // Number of test cases

    while (t--) {
        int n;
        scanf("%d", &n); // Size of the array
        int arr[n];

        // Read the array elements
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int max_distance = -1; // Initialize maximum distance

        // Precompute the last occurrence of each element
        int last_occurrence[1001] = {0}; // Assuming array elements are <= 1000
        for (int i = 0; i < n; i++) {
            last_occurrence[arr[i]] = i;
        }

        // Find the maximum distance between coprime elements
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= 1000; j++) {
                if (last_occurrence[j] > i && gcd(arr[i], j) == 1) {
                    int distance = last_occurrence[j] - i;
                    if (distance > max_distance) {
                        max_distance = distance;
                    }
                }
            }
        }

        // Print the result
        if (max_distance == -1) {
            printf("-1\n"); // No coprime pairs found
        } else {
            printf("%d\n", max_distance + 1); // Add 1 to convert index difference to distance
        }
    }

    return 0; // Indicate successful execution
}