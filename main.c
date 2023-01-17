# include <unistd.h>
# include <stdlib.h>
#include <string.h>
# include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int		counter;
	void				*to_return;

	to_return = s;
	counter = 0;
	while (counter < n)
	{
		*((unsigned char *)s) = c;
		s++;
		counter++;
	}
	return (to_return);
}


void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	counter;

	counter = 0;
	while (*(s + counter) != '\0')
	{
		counter++;
	}
	return (counter);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	counter;
	unsigned int	size_src;

	size_src = ft_strlen(src);
	counter = 0;
	while (counter < size && counter <= size_src)
	{
		if (counter < size - 1 && counter < size_src)
			*dest = *src;
		else
			*dest = '\0';
		if (counter < size - 1)
			dest++;
		if (counter < size_src - 1)
			src++;
		counter++;
	}
	return (size_src);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}




static int	substring_comparison(char *s1, char *s2, size_t n)
{
	unsigned int	n2;
	char			*s1_aux;
	char			*s2_aux;

	n2 = n;
	s1_aux = s1;
	s2_aux = s2;
	while (*s1_aux == *s2_aux && n2 > 0)
	{
		if (*(s2_aux + 1) == '\0')
			return (1);
		if (*s1_aux == '\0')
			return (0);
		s1_aux++;
		s2_aux++;
		n2--;
	}
	return (3);
}

char	*ft_strnstr(char *s1, char *s2, size_t n)
{
	int		sub_s_comp;

	if (ft_strlen(s2) == 0)
		return (s1);
	while (*s1 != '\0' && n > 0)
	{
		if (*s1 == *s2)
		{
			sub_s_comp = substring_comparison(s1, s2, n);
			if (sub_s_comp == 1)
				return (s1);
			if (sub_s_comp == 2)
				return (0);
		}
		s1++;
		n--;
	}
	return (0);
}

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem == 0)
		return (0);
	ft_bzero(mem, count * size);
	return (mem);
}


static int	count_lines(char *text, char find)
{
	int	counter;
	
	counter = 0;
	while (*text != '\0')
	{
		if (*text != find && (*(text+1) == find || *(text+1) == '\0'))
			counter++;
		text++;
	}
	return (counter);
}

static char	*ft_min_str(char *s1, char *s2)
{
	if(s1==0 && s2 ==0)
		return (0);
	if (s1 == 0)
		return (s2);
	if (s2 == 0)
		return (s1);
	if(s1 < s2)
		return (s1);
	return (s2);
}

static int	ft_split_loop(char **matrix,char *s, int n_lines, char c)
{
	int		length;
	int		iterator;
	char 	*next_position;

	iterator = 0;
	while (iterator < n_lines)
	{
		next_position = ft_min_str(ft_strchr(s, c),ft_strchr(s, '\0'));
		length = next_position - s;
		if(length == 0)
		{
			s = next_position + 1;
			continue;
		}
		matrix[iterator] = (char *)malloc(length + 1);
		if(matrix[iterator]==0)
			return(iterator);
		ft_strlcpy(matrix[iterator], s, length + 1);
		if (*next_position != '\n')
			s = next_position + 1;
		iterator++;
	}
	return(-1);
}

char **ft_split(char *s, char c)
{
	char    **matrix;
	int		n_lines;
	int		error_asign;
	
	n_lines = count_lines (s, c);
	matrix = (char **) ft_calloc ((n_lines + 1), sizeof (char *));
	if (matrix == 0)
		return (0);
	error_asign=ft_split_loop(matrix,s,n_lines,c);
	if (error_asign == -1)
		return (matrix);
	while(error_asign-- >= 0)
		free(matrix[error_asign]);
	free(matrix);
	return (0);
}

int main(void)
{	
	ft_split("hello!", ' ');
    
}