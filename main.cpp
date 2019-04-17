#include <stdio.h>
#include <cstring>
#include <ctime>
#include "arrays.h"

using namespace std;

/* arrays found in arrays.h
 * int list1[] has 10 elements
 * int list2[] has 100 elements
 * int list3[] has 1,000 elements
 * int list4[] has 10,000 elements
 * int list5[] has 100,000 elements
 * int list6[] has 250,000 elements
 * int primes[] has first 1,000,000 primes */

struct timespec timeStart, timeCurrent;
double binarySearchTime1 = 0.0;
double binarySearchTime2 = 0.0;
double binarySearchTime3 = 0.0;
double binarySearchTime4 = 0.0;
double binarySearchTime5 = 0.0;
double binarySearchTime6 = 0.0;
double linearSearchTime1 = 0.0;
double linearSearchTime2 = 0.0;
double linearSearchTime3 = 0.0;
double linearSearchTime4 = 0.0;
double linearSearchTime5 = 0.0;
double linearSearchTime6 = 0.0;
double interpolationSearchTime1 = 0.0;
double interpolationSearchTime2 = 0.0;
double interpolationSearchTime3 = 0.0;
double interpolationSearchTime4 = 0.0;
double interpolationSearchTime5 = 0.0;
double interpolationSearchTime6 = 0.0;
void timeGet(struct timespec *t)
{
    clock_gettime(CLOCK_REALTIME, t);
}   
double timeDiff(struct timespec *start, struct timespec *end)
{
    //return the difference in two times
    double ret = 
        (double)(end->tv_sec - start->tv_sec) +
        (double)(end->tv_nsec - start->tv_nsec);
    return ret;
}
void timeCopy(struct timespec *dest, struct timespec *source)
{
    //copy one time structure to another
    memcpy(dest, source, sizeof(struct timespec));
}

int binarySearch(int *arr, int left, int right, int target);
int linearSearch(int *arr, int amount, int target);
int interpolationSearch(int *arr, int amount, int target);

void testBinarySearch();
void testLinearSearch();
void testInterpolationSearch();

int main()
{
    testBinarySearch();
    printf("%f microseconds\n", binarySearchTime1);
    printf("%f microseconds\n", binarySearchTime2);
    printf("%f microseconds\n", binarySearchTime3);
    printf("%f microseconds\n", binarySearchTime4);
    printf("%f microseconds\n", binarySearchTime5);
    printf("%f microseconds\n", binarySearchTime6);
    testLinearSearch();
    printf("%f microseconds\n", linearSearchTime1);
    printf("%f microseconds\n", linearSearchTime2);
    printf("%f microseconds\n", linearSearchTime3);
    printf("%f microseconds\n", linearSearchTime4);
    printf("%f microseconds\n", linearSearchTime5);
    printf("%f microseconds\n", linearSearchTime6);
    testInterpolationSearch();
    printf("%f microseconds\n", interpolationSearchTime1);
    printf("%f microseconds\n", interpolationSearchTime2);
    printf("%f microseconds\n", interpolationSearchTime3);
    printf("%f microseconds\n", interpolationSearchTime4);
    printf("%f microseconds\n", interpolationSearchTime5);
    printf("%f microseconds\n", interpolationSearchTime6);
    return 0;
}

int binarySearch(int *arr, int left, int right, int target)
{
    while (left <= right) {
        int position = left + (right - left) / 2;
        //check if the target is in the middle
        if (arr[position] == target)
            return position;
        //ignore the left half if the target is larger
        if (arr[position] < target)
            left = position + 1;
        //ignore the right half if the target is smaller
        else
            right = position - 1;
    }
    //target wasn't found
    return -1;
}

int linearSearch(int *arr, int amount, int target)
{
    //iterate through the array amount times until the target is found
    for (int i = 0; i < amount; i++) {
        if (arr[i] == target)
            return i;
    }
    //target wasn't found
    return -1;
}

int interpolationSearch(int *arr, int amount, int target)
{
    //find indexes of two corners
    int lo = 0, hi = amount - 1;

    while (lo <= hi && target >= arr[lo] && target <= arr[hi]) {
        if (lo == hi) {
            if (arr[lo] == target)
                return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (target - arr[lo]));
        //condition of target found
        if (arr[pos] == target)
            return pos;
        //target is in the upper part
        if (arr[pos] < target)
            lo = pos + 1;
        //target is in the lower part
        else
            hi = pos - 1;
    }
    //target wasn't found
    return -1;
}

void testBinarySearch()
{
    printf("Testing binary search with sorted prime numbers\n");
    
    struct timespec tstart1, tstart2, tstart3, tend1, tend2, tend3;
    
    timeGet(&tstart1);
    if (binarySearch(primes, 0, 9, 2) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (binarySearch(primes, 0, 9, 5) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (binarySearch(primes, 0, 9, 7) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    binarySearchTime1 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;

    timeGet(&tstart1);
    if (binarySearch(primes, 0, 99, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (binarySearch(primes, 0, 99, 229) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (binarySearch(primes, 0, 99, 523) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    binarySearchTime2 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (binarySearch(primes, 0, 999, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (binarySearch(primes, 0, 999, 3571) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (binarySearch(primes, 0, 999, 7907) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    binarySearchTime3 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (binarySearch(primes, 0, 9999, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (binarySearch(primes, 0, 9999, 48611) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (binarySearch(primes, 0, 9999, 104723) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    binarySearchTime4 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (binarySearch(primes, 0, 99999, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (binarySearch(primes, 0, 99999, 611953) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (binarySearch(primes, 0, 99999, 1299689) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    binarySearchTime5 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (binarySearch(primes, 0, 249999, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (binarySearch(primes, 0, 249999, 1655131) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (binarySearch(primes, 0, 249999, 3497849) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    binarySearchTime6 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;
}

void testLinearSearch()
{
    printf("\nTesting linear search with sorted prime numbers\n");
    
    struct timespec tstart1, tstart2, tstart3, tend1, tend2, tend3;
    
    timeGet(&tstart1);
    if (linearSearch(primes, 10, 2) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (linearSearch(primes, 10, 5) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (linearSearch(primes, 10, 7) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    linearSearchTime1 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;

    timeGet(&tstart1);
    if (linearSearch(primes, 100, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (linearSearch(primes, 100, 229) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (linearSearch(primes, 100, 523) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    linearSearchTime2 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (linearSearch(primes, 1000, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (linearSearch(primes, 1000, 3571) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (linearSearch(primes, 1000, 7907) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    linearSearchTime3 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (linearSearch(primes, 10000, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (linearSearch(primes, 10000, 48611) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (linearSearch(primes, 10000, 104723) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    linearSearchTime4 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (linearSearch(primes, 100000, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (linearSearch(primes, 100000, 611953) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (linearSearch(primes, 100000, 1299689) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    linearSearchTime5 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (linearSearch(primes, 250000, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (linearSearch(primes, 250000, 1655131) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (linearSearch(primes, 250000, 3497849) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    linearSearchTime6 += (timeDiff(&tstart1, &tend1) +
                          timeDiff(&tstart2, &tend2) +
                          timeDiff(&tstart3, &tend3)) / 3;
}

void testInterpolationSearch()
{
    printf("\nTesting interpolation search with sorted prime numbers\n");
    
    struct timespec tstart1, tstart2, tstart3, tend1, tend2, tend3;
    
    timeGet(&tstart1);
    if (interpolationSearch(primes, 10, 2) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (interpolationSearch(primes, 10, 5) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (interpolationSearch(primes, 10, 7) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    interpolationSearchTime1 += (timeDiff(&tstart1, &tend1) +
                                 timeDiff(&tstart2, &tend2) +
                                 timeDiff(&tstart3, &tend3)) / 3;

    timeGet(&tstart1);
    if (interpolationSearch(primes, 100, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (interpolationSearch(primes, 100, 229) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (interpolationSearch(primes, 100, 523) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    interpolationSearchTime2 += (timeDiff(&tstart1, &tend1) +
                                 timeDiff(&tstart2, &tend2) +
                                 timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (interpolationSearch(primes, 1000, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (interpolationSearch(primes, 1000, 3571) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (interpolationSearch(primes, 1000, 7907) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    interpolationSearchTime3 += (timeDiff(&tstart1, &tend1) +
                                 timeDiff(&tstart2, &tend2) +
                                 timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (interpolationSearch(primes, 10000, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (interpolationSearch(primes, 10000, 48611) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (interpolationSearch(primes, 10000, 104723) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    interpolationSearchTime4 += (timeDiff(&tstart1, &tend1) +
                                 timeDiff(&tstart2, &tend2) +
                                 timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (interpolationSearch(primes, 100000, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (interpolationSearch(primes, 100000, 611953) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (interpolationSearch(primes, 100000, 1299689) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    interpolationSearchTime5 += (timeDiff(&tstart1, &tend1) +
                                 timeDiff(&tstart2, &tend2) +
                                 timeDiff(&tstart3, &tend3)) / 3;
    
    timeGet(&tstart1);
    if (interpolationSearch(primes, 250000, 3) == -1)
        printf("target not found\n");
    timeGet(&tend1);
    timeGet(&tstart2);
    if (interpolationSearch(primes, 250000, 1655131) == -1)
        printf("target not found\n");
    timeGet(&tend2);
    timeGet(&tstart3);
    if (interpolationSearch(primes, 250000, 3497849) == -1)
        printf("target not found\n");
    timeGet(&tend3);

    interpolationSearchTime6 += (timeDiff(&tstart1, &tend1) +
                                 timeDiff(&tstart2, &tend2) +
                                 timeDiff(&tstart3, &tend3)) / 3;
}
