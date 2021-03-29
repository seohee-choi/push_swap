/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohchoi <seohchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:47:31 by jolim             #+#    #+#             */
/*   Updated: 2021/03/29 15:51:54 by seohchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static 	void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}

void	quick_sort(int *number, int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
				swap(&(number[i]), &(number[j]));
		}
		swap(&(number[pivot]), &(number[j]));
		quick_sort(number, first, j - 1);
		quick_sort(number, j + 1, last);
	}
	return ;
}
