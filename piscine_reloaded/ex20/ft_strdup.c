#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	char *head;

	head = dest;
	while ((*dest++ = *src++))
		;
	return (head);
}

int		ft_strlen(char *str)
{
	int		len;
	char	*tmp_str;

	len = 0;
	tmp_str = str;
	while (*str)
	{
		len++;
		str++;
	}
	str = tmp_str;
	return (len);
}

char	*ft_strdup(char *src)
{
	char *dest;

	dest = (char*)malloc(sizeof(*dest) * ft_strlen(src) + 1);
	if (!dest)
		return (0);
	dest = ft_strcpy(dest, src);
	return (dest);
}
