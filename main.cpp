//
//  main.cpp
//  2.4
//
//  Created by Stanislav Martynov on 30.12.2020.
//

#include <iostream>
#include <vector>
#include <tuple>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

std::tuple<int, int> partition (int *arr, int low, int high, int pivot)
{
    int low_iter;
    int high_iter;
    int pivot_iter;
    int temp;
    low_iter = low;
    pivot_iter = low;
    high_iter = high;
    temp = low;
    while(pivot_iter != high_iter+1)
    {
        if (arr[temp] < pivot)
        {
            swap(&arr[temp], &arr[low_iter]);
            low_iter += 1;
            pivot_iter += 1;
            temp += 1;
        }
        else if (arr[temp] == pivot){
            pivot_iter += 1;
            temp += 1;
        }
        else{
            swap(&arr[temp], &arr[high_iter]);
            high_iter -= 1;
        }
    }
    return std::make_tuple(low_iter, pivot_iter-1);
    
}
  
void quickSort(int *arr, int low, int high)
{
    int pivot;
    if (low == high){
        return;
    }
    pivot = arr[low + (rand() % static_cast<int>(high - low + 1))];
    std::tuple<int, int>  p = partition(arr, low, high, pivot);
    auto h = std::get<0>(p);
    auto z = std::get<1>(p);
        if (h > low){
        quickSort(arr, low, h - 1);
        }
        if (z != high){
        quickSort(arr, z + 1, high);
        }
}
  
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++){
    if (i < size - 1) {
        std::cout << arr[i] << " ";
    }
    else {
        std::cout << arr[i];
    }
}
}

int main(int argc, const char * argv[]) {
    std::vector<int> vec1;
    std::string line;
    int current = 0;
    int sign = 1;
    int k = 0;
    int j = 0;
    bool flag = false;
    std::getline(std::cin, line);
    vec1.resize(line.size());
    for (int i = 0; i < line.size(); i++){
        if(std::isdigit(line[i]))
        {
            current = current*10 + (line[i]-48);
            flag = true;
        }
        else if (line[i] == '-'){
            if (current == 0) sign = -1;
        }
        if ((!std::isdigit(line[i]) && (current != 0 || flag)) || line[i+1] == '\0'){
            k++;
            vec1[j] = current*sign;
            j++;
            current = 0;
            sign = 1;
            flag = false;
         }
    }
    if(!line.empty()){
    int der[k];
    for (int i =0; i < k; i++) {
        der[i] = vec1[i];
    }
    vec1.clear();
    quickSort(der, 0, k-1);
    printArray(der, k);
    }
}
