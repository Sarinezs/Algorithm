#include <iostream>
#include <algorithm>

using namespace std;

double greedyMeanRetrieval(int files[], int n) {
    sort(files, files + n);
    double totalTime = 0, meanTime = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            totalTime += files[j];
        }
    }

    meanTime = totalTime / n;
    return meanTime;
}

int main() {
    int n;
    cin >> n;

    int files[n];
    for (int i = 0; i < n; ++i) {
        cin >> files[i];
    }

    double result = greedyMeanRetrieval(files, n);
    cout << fixed << result << endl;

    return 0;
}