# Sorting Algorithms

Often classified by:
* Computational complexity
* Memory usage
* Recursive or not
* General method (insertion, exchange, selection...)
* Stability - Stable sorting algorithms maintain the relative order of records with equal values.

## Selection Sort O(N^2)
Repeatedly finds the minimum element (for ascending order) from the unsorted part. So, in every iteration of selection sort, the minimum element from the unsorted subarray is picked and moved to the sorted subarray. 

Selection sort is an in-place sorting algorithm, so it does not require additional storage.

```
repeat (numOfElements - 1) times

  set the first unsorted element as the minimum

  for each of the unsorted elements

    if element < currentMinimum

      set element as new minimum

  swap minimum with first unsorted position
```

## Bubble Sort O(N^2)
Repeatedly stepping through the list, comparing each pair of adjacent items and swapping them if they are in the wrong order. 

Bubble sort is a stable algorithm.

```
do

  swapped = false

  for i = 1 to indexOfLastUnsortedElement-1

    if leftElement > rightElement

      swap(leftElement, rightElement)

      swapped = true

while swapped
```

## Insertion Sort O(N^2)
The array is virtually split into a sorted and unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.

Again, stable algorithm.

```
mark first element as sorted

for each unsorted element X

  'extract' the element X

  for j = lastSortedIndex down to 0

    if current element j > X

      move sorted element to the right by 1

    break loop and insert X here
```

Note: For a small array (up to 10 elements) insertion sort is better than quicksort.

## Quicksort O(N^2)
First divides a large list into two smaller sublists then recursively sorts the sublists. The key process is partition(). Given an array and an element X of this array as pivot put X at its correct position in a sorted array and all smaller elements before X and all greater elements after X.

Quicksort can be stable but it typically isn't implemented that way.

```
for each (unsorted) partition

set first element as pivot

  storeIndex = pivotIndex + 1

  for i = pivotIndex + 1 to rightmostIndex

    if element[i] < element[pivot]

      swap(i, storeIndex); storeIndex++

  swap(pivot, storeIndex - 1)
```

## Mergesort O(NlogN)
Conceptually, a merge sort works as follow: Divide the unsorted list into n sublist, each containing 1 element (a list of 1 element is sorted). Repeatedly merge sublists to produce new sublists until there is one list remaining.

The algorithm is higly parallelizable and stable.

```
split each element into partitions of size 1

recursively merge adjacent partitions

  for i = leftPartIdx to rightPartIdx

    if leftPartHeadValue <= rightPartHeadValue

      copy leftPartHeadValue

    else: copy rightPartHeadValue

copy elements back to original array
```

## Counting Sort O(N+R)
Algorithm for sorting a collection of objects according to keys that are small integers. We have to know the range of numbers in the input array.

```
create key (counting) array

for each element in list

  increase the respective counter by 1

for each counter, starting from smallest key

  while counter is non-zero

    restore element to list

    decrease counter by 1
```