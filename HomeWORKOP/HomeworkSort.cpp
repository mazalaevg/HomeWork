#include <iostream>

using namespace std;

void FillArray(int* arr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand();
    }
}

void QuickSort(int* arr, int first, int last)
{
    if (first < last) {
        int left = first;
        int right = last;
        int middle = arr[(left + right) / 2];
        do {
            while (arr[left] < middle) {
                left++;
            }
            while (arr[right] > middle) {
                right--;
            }
            if (left <= right) {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }
        } while (left < right);
        QuickSort(arr, first, right);
        QuickSort(arr, left, last);
    }
}

void merge(int* array, int l, int m, int r) {
    int i, j, k, nl, nr;

    nl = m - l + 1; nr = r - m;
    int* larr = new int[nl];
    int* rarr = new int[nr];

    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];
    i = 0; j = 0; k = l;

    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            array[k] = larr[i];
            i++;
        }
        else {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl) {
        array[k] = larr[i];
        i++; k++;
    }
    while (j < nr) {
        array[k] = rarr[j];
        j++; k++;
    }

    delete[] larr;
    delete[] rarr;
}

void mergeSort(int* array, int l, int r) {
    int m;
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }

}


void BubbleSort(int* arr, int Size)
{
    int temp;
    for (int i = 0; i < Size; i++)
    {
        for (int k = 0; k < Size; k++)
        {
            for (int j = 0; j < Size; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

void insertionSort(int* arr,int size)
{
    size++;
    int i, count, j;
    for (i = 1; i < size; i++) {
        count = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > count) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = count;
    }
}

void SelectionSort(int* arr, int size)
{
    size++;
    int i, j, min_ind;

    for (i = 0; i < size - 1; i++)
    {
        min_ind = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min_ind])
                min_ind = j;
        swap(arr[min_ind], arr[i]);
    }
}



void heapify(int* arr, int size, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;


    if (r < size && arr[r] > arr[largest])
        largest = r;


    if (largest != i)
    {
        swap(arr[i], arr[largest]);


        heapify(arr, size, largest);
    }

}


void HeapSort(int* arr,int n, int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);


    for (int i = n - 1; i >= 0; i--)
    {

        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void CombSort(int* arr, int size)
{
    int temp, k;
    int s = size;
    long long count = 0;
    while (size > 1) {
        s /= 1.247f;
        if (s < 1) s = 1;
        k = 0;
        for (int i = 0; i + s < size; ++i)
        {
            if (arr[i] / 10 > arr[i + s] / 10)
            {
                temp = arr[i];
                arr[i] = arr[i + s];
                arr[i + s] = temp;
                k = i;
            }
            ++count;
        }
        if (s == 1)
            size = k + 1;
    }
}

int main()
{
    int size = 1000000;
    int* arr;
    for (int i = 0; i < 1; i++)
    {
        cout << "Sorting into 1000000 elements:" << endl;

        arr = new int[size];
        FillArray(arr, size - 1);

        auto start1 = clock();
        BubbleSort(arr, size - 1);
        auto end1 = clock();
        unsigned int time1 = end1 - start1;

        auto start2 = clock();
        insertionSort(arr, size - 1);
        auto end2 = clock();
        unsigned int time2 = end2 - start2;

        auto start3 = clock();
        SelectionSort(arr, size - 1);
        auto end3 = clock();
        unsigned int time3 = end3 - start3;


        auto start4 = clock();
        HeapSort(arr, size/2-1, size - 1);
        auto end4 = clock();
        unsigned int time4 = end4 - start4;


        auto start5 = clock();
        CombSort(arr, size - 1);
        auto end5 = clock();
        unsigned int time5 = end5 - start5;


        auto start6 = clock();
        mergeSort(arr, 0, size);
        auto end6 = clock();
        unsigned int time6 = end6 - start6;

        auto start7 = clock();
        QuickSort(arr, 0, size);
        auto end7 = clock();
        unsigned int time7 = end7 - start7;

        delete[] arr;
    }

}

