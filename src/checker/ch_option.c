#include "checker.h"

void	ch_print_manual(void)
{
	ft_putstr_fd("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 1);
	ft_putstr_fd("~~~~~~~~~~~~~checker man page~~~~~~~~~~~\n", 1);
	ft_putstr_fd("0. Do nothing if there is only one or no elements.\n", 1);
	ft_putstr_fd("1. sa : swap a - swap the first 2 elements at the top of", 1);
	ft_putstr_fd(" stack a.\n", 1);
	ft_putstr_fd("2. sb : swap b - swap the first 2 elements at the top of", 1);
	ft_putstr_fd(" stack b.\n", 1);
	ft_putstr_fd("3. ss : sa and sb at the same time.\n", 1);
	ft_putstr_fd("4. pa : push a - take the first element at the top of b ", 1);
	ft_putstr_fd("and put it at the top of a.\n", 1);
	ft_putstr_fd("5. pb : push b - take the first element at the top of a ", 1);
	ft_putstr_fd("and put it at the top of b.\n", 1);
	ft_putstr_fd("6. ra : rotate a - shift up all elements of stack a by 1", 1);
	ft_putstr_fd(". The first element becomes the last one.\n", 1);
	ft_putstr_fd("7. rb : rotate b - shift up all elements of stack b by 1", 1);
	ft_putstr_fd(". The first element becomes the last one.\n", 1);
	ft_putstr_fd("8. rr : ra and rb at the same time.\n", 1);
	ft_putstr_fd("9. rra : reverse rotate a - shift down all elements of ", 1);
	ft_putstr_fd("stack a by 1. The last element becomes the first one.\n", 1);
	ft_putstr_fd("10. rrb : reverse rotate b - shift down all elements of ", 1);
	ft_putstr_fd("stack b by 1. The last element becomes the first one.\n", 1);
	ft_putstr_fd("11. rrr : rra and rrb at the same time.\n", 1);
	ft_putstr_fd("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 1);
	ft_putstr_fd("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", 1);
}
