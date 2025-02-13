/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findMedian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 21:23:35 by muxammad          #+#    #+#             */
/*   Updated: 2024/12/26 20:01:15 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper function to extract elements of the same chunk into an array
void	extract_chunk_elements(t_list *list, int chunk, int *arr)
{
	int	index;

	index = 0;
	while (list)
	{
		if (list->chunk == chunk)
			arr[index++] = list->content;
		list = list->next;
	}
}

static void	mini_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

	// temp = arr[pivot];
	// arr[pivot] = arr[right];
	// arr[right] = temp;
// Partition function for Quickselect
int	partition(int arr[], int left, int right, int pivot)
{
	int	pivot_value;
	int	temp;
	int	store_index;
	int	i;

	pivot_value = arr[pivot];
	mini_swap(&arr[pivot], &arr[right]);
	store_index = left;
	i = left;
	while (i < right)
	{
		if (arr[i] < pivot_value)
		{
			temp = arr[i];
			arr[i] = arr[store_index];
			arr[store_index] = temp;
			store_index++;
		}
		i++;
	}
	temp = arr[store_index];
	arr[store_index] = arr[right];
	arr[right] = temp;
	return (store_index);
}

// Quickselect function
int	quickselect(int arr[], int left, int right, int k)
{
	int	pivot_index;

	if (left == right)
		return (arr[left]);
	pivot_index = left + rand() % (right - left + 1);
	if (pivot_index < left || pivot_index > right)
		exit(EXIT_FAILURE);
	pivot_index = partition(arr, left, right, pivot_index);
	if (k == pivot_index)
		return (arr[k]);
	else if (k < pivot_index)
		return (quickselect(arr, left, pivot_index - 1, k));
	else
		return (quickselect(arr, pivot_index + 1, right, k));
}

// Find the median of elements with the same chunk
int	find_median(t_list *list, int chunk, float percentile)
{
	int	median;
	int	n;
	int	*arr;
	int	target_index;

	if (!list)
		return (-1);
	n = ft_chunksize(list, chunk);
	if (n <= 0)
		return (-1);
	arr = (int *)malloc(n * sizeof(int));
	extract_chunk_elements(list, chunk, arr);
	target_index = (int)((percentile / 100.0) * n);
	if (target_index >= n)
		target_index = n - 1;
	median = quickselect(arr, 0, n - 1, target_index);
	return (free(arr), median);
}
