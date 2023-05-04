#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // Initializing the children(left, right)
    int left = 2*root + 1;
    int right = 2*root +2;

    // Getting the maximum.
    int maximum;
    // Checking whether the left child is greater than the root.
    if (left<n && arr[left]>arr[root]){   
        maximum = left;
    }
    else{
        maximum = root;
    }
    // Checking whether the right child is greater than the root.
    if(right<n && arr[right]>arr[root]){
        maximum = right;
    }

    // Heapifying - If a child is greater than the parent, swapping the parent with the maximum child.
    if (maximum != root){
        swap(arr[root], arr[maximum]);
        heapify(arr, n, maximum);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // Building a max heap.
    for (int i=n/2-1 ; i>=0; i--){
        heapify(arr, n, i);
    }

    // Sorting the elements.
    for (int i=n-1; i>=0; i--){
        swap (arr[0], arr[i]);
        heapify(arr, n, 0);
    } 

}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; i++){
    cout << arr[i] << " ";
   }
   cout << "\n";
}

// main program

int main()
{
   int heap_arr[] = {9,-4,3,5,1,0,-6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
