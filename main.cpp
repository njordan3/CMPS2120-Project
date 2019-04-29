#include <stdio.h>
#include <cstring>
#include <ctime>
#include "arrays.h"
#include "searches.cpp"
#include "sorts.cpp"

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
double heapSortTime1 = 0.0;
double heapSortTime2 = 0.0;
double heapSortTime3 = 0.0;
double heapSortTime4 = 0.0;
double heapSortTime5 = 0.0;
double heapSortTime6 = 0.0;
double shellSortTime1 = 0.0;
double shellSortTime2 = 0.0;
double shellSortTime3 = 0.0;
double shellSortTime4 = 0.0;
double shellSortTime5 = 0.0;
double shellSortTime6 = 0.0;
double combSortTime1 = 0.0;
double combSortTime2 = 0.0;
double combSortTime3 = 0.0;
double combSortTime4 = 0.0;
double combSortTime5 = 0.0;
double combSortTime6 = 0.0;
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

void testBinarySearch();
void testLinearSearch();
void testInterpolationSearch();

void testHeapSort();
void testShellSort();
void testCombSort();

int main()
{
    testBinarySearch();
    printf("%f nanoseconds\n", binarySearchTime1);
    printf("%f nanoseconds\n", binarySearchTime2);
    printf("%f nanoseconds\n", binarySearchTime3);
    printf("%f nanoseconds\n", binarySearchTime4);
    printf("%f nanoseconds\n", binarySearchTime5);
    printf("%f nanoseconds\n", binarySearchTime6);
    testLinearSearch();
    printf("%f nanoseconds\n", linearSearchTime1);
    printf("%f nanoseconds\n", linearSearchTime2);
    printf("%f nanoseconds\n", linearSearchTime3);
    printf("%f nanoseconds\n", linearSearchTime4);
    printf("%f nanoseconds\n", linearSearchTime5);
    printf("%f nanoseconds\n", linearSearchTime6);
    testInterpolationSearch();
    printf("%f nanoseconds\n", interpolationSearchTime1);
    printf("%f nanoseconds\n", interpolationSearchTime2);
    printf("%f nanoseconds\n", interpolationSearchTime3);
    printf("%f nanoseconds\n", interpolationSearchTime4);
    printf("%f nanoseconds\n", interpolationSearchTime5);
    printf("%f nanoseconds\n", interpolationSearchTime6);
    testHeapSort();
    printf("%f nanoseconds\n", heapSortTime1);
    printf("%f nanoseconds\n", heapSortTime2);
    printf("%f nanoseconds\n", heapSortTime3);
    printf("%f nanoseconds\n", heapSortTime4);
    printf("%f nanoseconds\n", heapSortTime5);
    printf("%f nanoseconds\n", heapSortTime6);
    testShellSort();
    printf("%f nanoseconds\n", shellSortTime1);
    printf("%f nanoseconds\n", shellSortTime2);
    printf("%f nanoseconds\n", shellSortTime3);
    printf("%f nanoseconds\n", shellSortTime4);
    printf("%f nanoseconds\n", shellSortTime5);
    printf("%f nanoseconds\n", shellSortTime6);
    testCombSort();
    printf("%f nanoseconds\n", combSortTime1);
    printf("%f nanoseconds\n", combSortTime2);
    printf("%f nanoseconds\n", combSortTime3);
    printf("%f nanoseconds\n", combSortTime4);
    printf("%f nanoseconds\n", combSortTime5);
    printf("%f nanoseconds\n", combSortTime6);
    return 0;
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
void testHeapSort()
{
    printf("\nTesting Heap sort\n");
    
    struct timespec tstart, tend;

    timeGet(&tstart);
    heapSort(list1, 10);
    timeGet(&tend);
    heapSortTime1 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    heapSort(list2, 100);
    timeGet(&tend);
    heapSortTime2 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    heapSort(list3, 1000);
    timeGet(&tend);
    heapSortTime3 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    heapSort(list4, 10000);
    timeGet(&tend);
    heapSortTime4 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    heapSort(list5, 100000);
    timeGet(&tend);
    heapSortTime5 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    heapSort(list6, 250000);
    timeGet(&tend);
    heapSortTime6 = timeDiff(&tstart, &tend);

}
void testShellSort()
{
    printf("\nTesting Shell sort\n");
    
    struct timespec tstart, tend;

    timeGet(&tstart);
    shellSort(list1, 10);
    timeGet(&tend);
    shellSortTime1 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    shellSort(list2, 100);
    timeGet(&tend);
    shellSortTime2 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    shellSort(list3, 1000);
    timeGet(&tend);
    shellSortTime3 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    shellSort(list4, 10000);
    timeGet(&tend);
    shellSortTime4 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    shellSort(list5, 100000);
    timeGet(&tend);
    shellSortTime5 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    shellSort(list6, 250000);
    timeGet(&tend);
    shellSortTime6 = timeDiff(&tstart, &tend);
}
void testCombSort()
{
    printf("\nTesting Comb sort\n");
    
    struct timespec tstart, tend;

    timeGet(&tstart);
    combSort(list1, 10);
    timeGet(&tend);
    combSortTime1 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    combSort(list2, 100);
    timeGet(&tend);
    combSortTime2 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    combSort(list3, 1000);
    timeGet(&tend);
    combSortTime3 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    combSort(list4, 10000);
    timeGet(&tend);
    combSortTime4 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    combSort(list5, 100000);
    timeGet(&tend);
    combSortTime5 = timeDiff(&tstart, &tend);

    timeGet(&tstart);
    combSort(list6, 250000);
    timeGet(&tend);
    combSortTime6 = timeDiff(&tstart, &tend);
}
