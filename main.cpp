#include <iostream>
#include <vector>
using namespace std;
std::vector<int> tom = {5, 3, -2, 9, 7, 1};
void merge(std::vector<int>& array) {
    int l = 0;
    int d = array.size() / 2;
    vector<int> temp;
    int halfAnArray = array.size() / 2;
    while (l  < halfAnArray && d < array.size()) {
        if (array[l] > array[d]) {
            temp.push_back(array[l]);
            ++l;
        }
        else {
            temp.push_back(array[d]);
            ++d;
        }
    }
    while (l < halfAnArray) {
        temp.push_back(array[l]);
        ++l;
    }
    while (d < array.size()) {
        temp.push_back(array[d]);
        ++d;
    }
    array = temp;
}
void sort(std::vector<int>& array) {
    if (array.size() == 1) return;
    vector<int> left = vector<int>(array.begin(), array.begin() + array.size() / 2);
    vector<int> right = vector<int>(array.begin() + array.size() / 2, array.end());
    sort(left);
    sort(right);
    for (int i = 0; i < right.size(); ++i) {
        left.push_back(right[i]);
    }
    merge(left);
    array = left;
}
int main() {
    sort(tom);
    for (int i = 0; i < tom.size(); ++i) {
        std::cout << tom[i] << " ";
    }
    return 0;
}
