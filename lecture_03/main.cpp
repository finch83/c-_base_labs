#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>

void reversePrint(long);
void bubbleSort(int * arr, size_t size);

int main()
{
    std::random_device rd;
    std::default_random_engine generator(rd());

    // Sort
    {
    std::cout << "\n!!!Sort!!!\n";

    std::uniform_int_distribution<size_t> distrib(1, 20);
    size_t nArrSize = distrib(generator);
    std::cout << "Array size: " << nArrSize << std::endl;
    int * arr = new int [nArrSize];
    std::generate(arr, arr + nArrSize, [&distrib, &generator]() { return distrib(generator);});
    std::copy(arr, arr + nArrSize, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    bubbleSort(arr, nArrSize);
    std::copy(arr, arr + nArrSize, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    delete [] arr;
    }

    // Revers
    {
    std::cout << "\n!!!Revers!!!\n";
    std::uniform_int_distribution<long> distrib(0, 10000000000);
    long nInitVal = distrib(generator);
    std::cout << "Initial value: " << nInitVal << std::endl;
    std::cout << "Reverse value: ";
    reversePrint(nInitVal);
    }

    return 0;
}

void reversePrint(long nVal )
{
    if (nVal == 0) {
        std::cout << std::endl;
        return;
    }
    else {
        std::cout << nVal % 10 << " ";
        reversePrint(nVal / 10);
    }
}

void bubbleSort(int * arr, size_t size)
{
    int tmp;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
