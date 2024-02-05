#include <iostream>

// Function to calculate the summation of an integer array
int summation(const int array[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += array[i];
    }
    return sum;
}

// Function to find the maximum element in an integer array
int maximum(const int array[], int n) {
    if (n == 0) {
        std::cerr << "Error: Cannot find maximum in an empty array.\n";
        return -1;  // Return a sentinel value indicating an error
    }

    int maxElement = array[0];
    for (int i = 1; i < n; ++i) {
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }
    return maxElement;
}

int main() {
    int n;

    // Get the size of the array from the user
    std::cout << "Enter the length of the array (0 <= n <= ∞): ";
    std::cin >> n;

    if (n < 0) {
        std::cerr << "Error: Invalid array size.\n";
        return 1;  // Return an error code
    }

    // Declare the array of length n
    int* array = new int[n];

    // Get the array elements from the user
    std::cout << "Enter " << n << " integers for the array:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> array[i];
    }

    // Call the summation function and display the result
    int sum = summation(array, n);
    std::cout << "Summation: " << sum << "\n";

    // Call the maximum function and display the result
    int maxElement = maximum(array, n);
    if (maxElement != -1) {
        std::cout << "Maximum: " << maxElement << "\n";
    }

    // Deallocate the dynamically allocated array
    delete[] array;

    return 0;
}
