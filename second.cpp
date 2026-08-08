#include <iostream>
#include <vector>
using namespace std;
std::vector<int> tom = {5, 3, -2, 9, 7, 1};
vector<int> temp;
void merge(std::vector<int>& array, int begin, int mid, int end) {
    int l = 0 + begin;
    int d = mid + 1;

    while (l <= mid && d <= end) {
        if (array[l] <= array[d]) {
            temp.push_back(array[l]);
            ++l;
        }
        else {
            temp.push_back(array[d]);
            ++d;
        }
    }
    while (l <= mid) {
        temp.push_back(array[l]);
        ++l;
    }
    while (d <= end) {
        temp.push_back(array[d]);
        ++d;
    }
    for (size_t i = 0; i < temp.size(); ++i) {
        array[begin + i] = temp[i];
    }
    temp.clear();
}

void sort(std::vector<int>& array, int begin, int end) {
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2;



    sort(array, begin, mid);
    sort(array, mid + 1, end);

    vector<int> temp;

    for (int i = 0; i < end - mid + 1; ++i) {
        temp.push_back(array[mid + i]);
    }
    merge(array, begin, mid, end);
}
int main() {
    sort(tom, 0, tom.size() - 1);
    for (int i = 0; i < tom.size(); ++i) {
        std::cout << tom[i] << " ";
    }
    return 0;
}
