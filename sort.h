#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);

void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);

void swap(int *array, int x, int y);

void bubble(int *array, size_t size);

void insertion_sort_list(listint_t **list);

listint_t *swap_one(listint_t **list, listint_t *i, listint_t *n);

void selection_sort(int *array, size_t size);

int locOfSmallest(int a[], int s, int e);

void quick_sort(int *array, size_t size);

void quick_sort_recursion(int *array, int low, int high, size_t size);

int partition(int *array, int low, int high, size_t size);

void swp(int *x, int *y);

void shell_sort(int *array, size_t size);

void cocktail_sort_list(listint_t **list);

void swap_ahead(listint_t **list, listint_t **tail, listint_t **swp);

void swap_behind(listint_t **list, listint_t **tail, listint_t **swp);

void counting_sort(int *array, size_t size);

int max(int *array, int size);

void merge_sort(int *array, size_t size);

void mrg_sort_recursion(int a[], int s, int e);

void combine(int *array, int s, int m, int e);

void heap_sort(int *array, size_t size);

void max_heapify(int *array, size_t size, size_t base, size_t root);

void radix_sort(int *array, size_t size);

void radix_counting_sort(int *array, size_t size, int sig, int *buff);

#endif /* SORT_H */
