#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <iomanip>
using namespace std;

int binarySearch(int arr[], int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k) return mid;
        if (arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

double measureTime(int arr[], int n, int k, int iterations = 7000000) {
    auto start = chrono::high_resolution_clock::now();
    int result = -1;
    for (int i = 0; i < iterations; ++i) result = binarySearch(arr, n, k);
    auto end = chrono::high_resolution_clock::now();
    auto totalTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    return static_cast<double>(totalTime) / iterations;
}

double measureTimePrecise(int arr[], int n, int k, int iterations = 7000000) {
    double totalAvgTime = 0.0;
    const int runs = 5;
    for (int run = 0; run < runs; ++run) {
        auto start = chrono::high_resolution_clock::now();
        int result = -1;
        for (int i = 0; i < iterations; ++i) result = binarySearch(arr, n, k);
        auto end = chrono::high_resolution_clock::now();
        auto runTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        totalAvgTime += static_cast<double>(runTime) / iterations;
    }
    return totalAvgTime / runs;
}

void testBestCases() {
    cout << "Testing Best Cases:" << endl;
    cout << fixed << setprecision(3);
    random_device rd; mt19937 gen(rd()); uniform_int_distribution<> dis(1, 1000);

    int bestCase1[5]; for (int i = 0; i < 5; ++i) bestCase1[i] = dis(gen); sort(bestCase1, bestCase1 + 5);
    int bestCase1Size = sizeof(bestCase1) / sizeof(bestCase1[0]), bestCase1k = bestCase1[2];
    cout << "Best Case 1 Time: " << measureTimePrecise(bestCase1, bestCase1Size, bestCase1k) << " ns" << endl;

    int bestCase2[15]; for (int i = 0; i < 15; ++i) bestCase2[i] = dis(gen); sort(bestCase2, bestCase2 + 15);
    int bestCase2Size = sizeof(bestCase2) / sizeof(bestCase2[0]), bestCase2k = bestCase2[7];
    cout << "Best Case 2 Time: " << measureTimePrecise(bestCase2, bestCase2Size, bestCase2k) << " ns" << endl;

    int bestCase3[100]; for (int i = 0; i < 100; ++i) bestCase3[i] = dis(gen); sort(bestCase3, bestCase3 + 100);
    int bestCase3Size = sizeof(bestCase3) / sizeof(bestCase3[0]), bestCase3k = bestCase3[49];
    cout << "Best Case 3 Time: " << measureTimePrecise(bestCase3, bestCase3Size, bestCase3k) << " ns" << endl;

    int bestCase4[6]; for (int i = 0; i < 6; ++i) bestCase4[i] = dis(gen); sort(bestCase4, bestCase4 + 6);
    int bestCase4Size = sizeof(bestCase4) / sizeof(bestCase4[0]), bestCase4k = bestCase4[2];
    cout << "Best Case 4 Time: " << measureTimePrecise(bestCase4, bestCase4Size, bestCase4k) << " ns" << endl;

    int bestCase5[7]; for (int i = 0; i < 7; ++i) bestCase5[i] = dis(gen); sort(bestCase5, bestCase5 + 7);
    int bestCase5Size = sizeof(bestCase5) / sizeof(bestCase5[0]), bestCase5k = bestCase5[3];
    cout << "Best Case 5 Time: " << measureTimePrecise(bestCase5, bestCase5Size, bestCase5k) << " ns" << endl;
}

void testWorstCases() {
    cout << "\nTesting Worst Cases:" << endl;
    cout << fixed << setprecision(3);
    random_device rd; mt19937 gen(rd()); uniform_int_distribution<> dis(1, 1000);

    int worstCase1[5]; for (int i = 0; i < 5; ++i) worstCase1[i] = dis(gen); sort(worstCase1, worstCase1 + 5);
    int worstCase1Size = sizeof(worstCase1) / sizeof(worstCase1[0]), worstCase1k = worstCase1[4] + 100;
    cout << "Worst Case 1 Time: " << measureTime(worstCase1, worstCase1Size, worstCase1k, 5000000) << " ns" << endl;

    int worstCase2[15]; for (int i = 0; i < 15; ++i) worstCase2[i] = dis(gen); sort(worstCase2, worstCase2 + 15);
    int worstCase2Size = sizeof(worstCase2) / sizeof(worstCase2[0]), worstCase2k = worstCase2[14] + 100;
    cout << "Worst Case 2 Time: " << measureTime(worstCase2, worstCase2Size, worstCase2k, 5000000) << " ns" << endl;

    int worstCase3[100]; for (int i = 0; i < 100; ++i) worstCase3[i] = dis(gen); sort(worstCase3, worstCase3 + 100);
    int worstCase3Size = sizeof(worstCase3) / sizeof(worstCase3[0]), worstCase3k = worstCase3[99] + 100;
    cout << "Worst Case 3 Time: " << measureTime(worstCase3, worstCase3Size, worstCase3k, 3000000) << " ns" << endl;

    int worstCase4[100]; for (int i = 0; i < 100; ++i) worstCase4[i] = dis(gen); sort(worstCase4, worstCase4 + 100);
    int worstCase4Size = sizeof(worstCase4) / sizeof(worstCase4[0]), worstCase4k = worstCase4[0];
    cout << "Worst Case 4 Time: " << measureTime(worstCase4, worstCase4Size, worstCase4k, 3000000) << " ns" << endl;

    int worstCase5[100]; for (int i = 0; i < 100; ++i) worstCase5[i] = dis(gen); sort(worstCase5, worstCase5 + 100);
    int worstCase5Size = sizeof(worstCase5) / sizeof(worstCase5[0]), worstCase5k = worstCase5[99];
    cout << "Worst Case 5 Time: " << measureTime(worstCase5, worstCase5Size, worstCase5k, 3000000) << " ns" << endl;
}

void testAverageCases() {
    cout << "\nTesting Average Cases:" << endl;
    cout << fixed << setprecision(3);
    random_device rd; mt19937 gen(rd()); uniform_int_distribution<> dis(1, 1000);

    int avgCase1[5]; for (int i = 0; i < 5; ++i) avgCase1[i] = dis(gen); sort(avgCase1, avgCase1 + 5);
    int avgCase1Size = sizeof(avgCase1) / sizeof(avgCase1[0]), avgCase1k = avgCase1[1];
    cout << "Average Case 1 Time: " << measureTime(avgCase1, avgCase1Size, avgCase1k, 5000000) << " ns" << endl;

    int avgCase2[15]; for (int i = 0; i < 15; ++i) avgCase2[i] = dis(gen); sort(avgCase2, avgCase2 + 15);
    int avgCase2Size = sizeof(avgCase2) / sizeof(avgCase2[0]), avgCase2k = avgCase2[6];
    cout << "Average Case 2 Time: " << measureTime(avgCase2, avgCase2Size, avgCase2k, 4000000) << " ns" << endl;

    int avgCase3[100]; for (int i = 0; i < 100; ++i) avgCase3[i] = dis(gen); sort(avgCase3, avgCase3 + 100);
    int avgCase3Size = sizeof(avgCase3) / sizeof(avgCase3[0]), avgCase3k = avgCase3[29];
    cout << "Average Case 3 Time: " << measureTime(avgCase3, avgCase3Size, avgCase3k, 3000000) << " ns" << endl;

    int avgCase4[100]; for (int i = 0; i < 100; ++i) avgCase4[i] = dis(gen); sort(avgCase4, avgCase4 + 100);
    int avgCase4Size = sizeof(avgCase4) / sizeof(avgCase4[0]), avgCase4k = avgCase4[24];
    cout << "Average Case 4 Time: " << measureTime(avgCase4, avgCase4Size, avgCase4k, 3000000) << " ns" << endl;

    int avgCase5[100]; for (int i = 0; i < 100; ++i) avgCase5[i] = dis(gen); sort(avgCase5, avgCase5 + 100);
    int avgCase5Size = sizeof(avgCase5) / sizeof(avgCase5[0]), avgCase5k = avgCase5[74];
    cout << "Average Case 5 Time: " << measureTime(avgCase5, avgCase5Size, avgCase5k, 3000000) << " ns" << endl;
}

void testEdgeCases() {
    cout << "\nTesting Edge Cases:" << endl;
    cout << fixed << setprecision(3);
    random_device rd; mt19937 gen(rd()); uniform_int_distribution<> dis(1, 1000);

    int *edgeCase1 = nullptr; int edgeCase1Size = 0; int edgeCase1k = 5;
    cout << "Edge Case 1 (Empty Array): " << binarySearch(edgeCase1, edgeCase1Size, edgeCase1k) << " in " << measureTime(edgeCase1, edgeCase1Size, edgeCase1k, 10000000) << " ns" << endl;

    int edgeCase2[] = {dis(gen)}; sort(edgeCase2, edgeCase2 + 1);
    int edgeCase2Size = sizeof(edgeCase2) / sizeof(edgeCase2[0]), edgeCase2k = edgeCase2[0];
    cout << "Edge Case 2 (Single Element Present): " << binarySearch(edgeCase2, edgeCase2Size, edgeCase2k) << " in " << measureTime(edgeCase2, edgeCase2Size, edgeCase2k, 10000000) << " ns" << endl;

    int edgeCase3[] = {dis(gen)}; sort(edgeCase3, edgeCase3 + 1);
    int edgeCase3Size = sizeof(edgeCase3) / sizeof(edgeCase3[0]), edgeCase3k = edgeCase3[0] + 100;
    cout << "Edge Case 3 (Single Element Not Present): " << binarySearch(edgeCase3, edgeCase3Size, edgeCase3k) << " in " << measureTime(edgeCase3, edgeCase3Size, edgeCase3k, 10000000) << " ns" << endl;

    int edgeCase4[5]; for (int i = 0; i < 5; ++i) edgeCase4[i] = dis(gen); sort(edgeCase4, edgeCase4 + 5);
    int edgeCase4Size = sizeof(edgeCase4) / sizeof(edgeCase4[0]), edgeCase4k = edgeCase4[0];
    cout << "Edge Case 4 (Element at First Position): " << binarySearch(edgeCase4, edgeCase4Size, edgeCase4k) << " in " << measureTime(edgeCase4, edgeCase4Size, edgeCase4k, 5000000) << " ns" << endl;

    int edgeCase5[5]; for (int i = 0; i < 5; ++i) edgeCase5[i] = dis(gen); sort(edgeCase5, edgeCase5 + 5);
    int edgeCase5Size = sizeof(edgeCase5) / sizeof(edgeCase5[0]), edgeCase5k = edgeCase5[4];
    cout << "Edge Case 5 (Element at Last Position): " << binarySearch(edgeCase5, edgeCase5Size, edgeCase5k) << " in " << measureTime(edgeCase5, edgeCase5Size, edgeCase5k, 5000000) << " ns" << endl;

    int edgeCase6[7]; for (int i = 0; i < 7; ++i) edgeCase6[i] = dis(gen); sort(edgeCase6, edgeCase6 + 7);
    int edgeCase6Size = sizeof(edgeCase6) / sizeof(edgeCase6[0]), edgeCase6k = edgeCase6[1];
    cout << "Edge Case 6 (Potential Duplicates): " << binarySearch(edgeCase6, edgeCase6Size, edgeCase6k) << " in " << measureTime(edgeCase6, edgeCase6Size, edgeCase6k, 4000000) << " ns" << endl;

    int edgeCase7[7]; uniform_int_distribution<> negDis(-100, 100); for (int i = 0; i < 7; ++i) edgeCase7[i] = negDis(gen);
    sort(edgeCase7, edgeCase7 + 7);
    int edgeCase7Size = sizeof(edgeCase7) / sizeof(edgeCase7[0]), edgeCase7k = edgeCase7[1];
    cout << "Edge Case 7 (Negative Values): " << binarySearch(edgeCase7, edgeCase7Size, edgeCase7k) << " in " << measureTime(edgeCase7, edgeCase7Size, edgeCase7k, 4000000) << " ns" << endl;

    int edgeCase8[100]; for (int i = 0; i < 100; ++i) edgeCase8[i] = dis(gen); sort(edgeCase8, edgeCase8 + 100);
    int edgeCase8Size = sizeof(edgeCase8) / sizeof(edgeCase8[0]), edgeCase8k = edgeCase8[0];
    cout << "Edge Case 8 (Large Array, First Position): " << binarySearch(edgeCase8, edgeCase8Size, edgeCase8k) << " in " << measureTime(edgeCase8, edgeCase8Size, edgeCase8k, 3000000) << " ns" << endl;

    int edgeCase9[100]; for (int i = 0; i < 100; ++i) edgeCase9[i] = dis(gen); sort(edgeCase9, edgeCase9 + 100);
    int edgeCase9Size = sizeof(edgeCase9) / sizeof(edgeCase9[0]), edgeCase9k = edgeCase9[99];
    cout << "Edge Case 9 (Large Array, Last Position): " << binarySearch(edgeCase9, edgeCase9Size, edgeCase9k) << " in " << measureTime(edgeCase9, edgeCase9Size, edgeCase9k, 3000000) << " ns" << endl;

    int edgeCase10[100]; for (int i = 0; i < 100; ++i) edgeCase10[i] = dis(gen); sort(edgeCase10, edgeCase10 + 100);
    int edgeCase10Size = sizeof(edgeCase10) / sizeof(edgeCase10[0]), edgeCase10k = edgeCase10[99] + 100;
    cout << "Edge Case 10 (Large Array, Not Present): " << binarySearch(edgeCase10, edgeCase10Size, edgeCase10k) << " in " << measureTime(edgeCase10, edgeCase10Size, edgeCase10k, 3000000) << " ns" << endl;
}

int main() {
    cout << "Binary Search Performance Analysis:" << endl;
    testBestCases();
    testWorstCases();
    testAverageCases();
    testEdgeCases();
    return 0;
}