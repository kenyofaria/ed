//
// Created by Kenyo Faria on 24/09/25.
//

float average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float) sum / size;
}
