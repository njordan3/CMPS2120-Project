#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*==================[Heap Sort]====================*/ 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
}
/*==================[Cycle Sort]====================*/ 
void shellSort(int arr[], int n) 
{ 
    // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
              
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        } 
    } 
} 
/*==================[Comb Sort]====================*/ 

//to find gap between elements
int getNextGap(int gap)
{
	gap = (gap*10)/13;
	if (gap < 1)
		return 1;
	return gap;
}

// Function to sort a[0..n-1] using Comb Sort 
void combSort(int a[], int n) 
{ 
    // Initialize gap 
    int gap = n; 
  
    // Initialize swapped as true to make sure that 
    // loop runs 
    bool swapped = true; 
  
    // Keep running while gap is more than 1 and last 
    // iteration caused a swap 
    while (gap != 1 || swapped == true) 
    { 
        // Find next gap 
        gap = getNextGap(gap); 
  
        // Initialize swapped as false so that we can 
        // check if swap happened or not 
        swapped = false; 
  
        // Compare all elements with current gap 
        for (int i=0; i<n-gap; i++) 
        { 
            if (a[i] > a[i+gap]) 
            { 
                swap(a[i], a[i+gap]); 
                swapped = true; 
            } 
        } 
    } 
} 
