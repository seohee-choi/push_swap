#include "checker.h"
#include <sys/stat.h>
#include <fcntl.h>

void	ch_print_manual(void)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		rd_size;

	fd = open("checker_man.txt", O_RDONLY);
	if (fd < 0)
		return ;
	rd_size = 1;
	while (rd_size > 0)
	{
		rd_size = read(fd, buffer, BUFFER_SIZE);
		if (rd_size == -1)
			return;
		write(STDOUT_FILENO, buffer, rd_size);
	}
	write(STDOUT_FILENO, "\n", 1);
	return ;
}
