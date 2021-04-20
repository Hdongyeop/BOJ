/*
 * Quick Sort
 * Pivot / Left / Right
 * 엇갈림 : pivot의 위치를 정한다.
 *
 * Merge_Sort
 * 언제나 O(N*logN) 보장
 * 그러나 새로운 메모리공간이 필요함.
 */
#include <iostream>
#define MAX     1000000
using namespace std;
int N;
//int *sorted = new int[N];
int sorted[MAX];
int arr[MAX];

void merge(int a[], int m, int mid, int n){
    int i=m;
    int j=mid+1;
    int k=m;

    while(i <= mid && j <=n){
        if(a[i] <= a[j]){
            sorted[k] = a[i];
            i++;
        } else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }

    if(i > mid){
        for(int t=j;t<=n;t++){
            sorted[k] = a[t];
            k++;
        }
    } else {
        for(int t=i;t<=mid;t++){
            sorted[k] = a[t];
            k++;
        }
    }

    for(int t=m;t<=n;t++){
        a[t] = sorted[t];
    }
}

void mergeSort(int a[], int m, int n){
    if(m < n){
        int mid = (m+n)/2;
        mergeSort(a,m,mid);
        mergeSort(a,mid+1,n);
        merge(a,m,mid,n);
    }
}

int main() {
    cin >> N;
//    int *arr = new int[N];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    mergeSort(arr,0,N-1);
    for(int i=0;i<N;i++){
        cout << arr[i] << '\n';
    }

    return 0;
}
