
#include "ft_display_file.h"

int		ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (*str)
	{
		str++;
		counter++;
	}
	return (counter);
}

void	ft_display_file(char *path)
{
	int		fd;
	int		ret;
	char	buffer[BUFF_SIZE + 1];

	fd = open(path, O_RDONLY, S_IREAD);
	if (fd == -1)
	{
		write(2, "open() error\n", 13);
		return ;
	}
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		write(1, buffer, ft_strlen(buffer));
	}
	if (close(fd) == -1)
	{
		write(2, "close() error\n", 14);
		return ;
	}
}
