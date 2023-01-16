# include <unistd.h>
# include <stdlib.h>
#include <string.h>
# include <stdio.h>


int ft_strlen(const char *s)
{
	int counter;

	counter = 0;
	while (*(s + counter) != '\0')
	{
		counter++;
	}
	return counter;
}
size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int		counter;
	unsigned int		size_src;
	
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
char	*ft_strdup(char *src)
{
	int		str_len;
	char	*dest;

	str_len = ft_strlen(src);
	dest = (char *) malloc ((ft_strlen(src) +1) * sizeof (char));
	if (dest == 0)
		return (0);	
	ft_strlcpy(dest,src,ft_strlen(src)+1);
	return (dest);
}


char *ft_substr(char const *s, unsigned int start,unsigned int  len)
{
	char	*to_return;
	
	to_return = (char *)malloc((len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	if(start > ft_strlen(s))
		ft_strlcpy(to_return,"",0);
	else
		ft_strlcpy(to_return,(char *) (s + start),len+1);
	return (to_return);
}

char *ft_strchr(const char *s, int c)
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

void	ft_delete_char(char *str)
{
	while (*str != '\0')
	{
		*str = *(str + 1);
		str++;
	}
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *end;
	char *s2;

	s2 =ft_strdup((char*)s1);
	if(s2 == 0)
		return (0);
	while(ft_strchr(set,(int)(*s2)) && *s2 != '\0')
	{
		ft_delete_char(s2);
	}
	if(ft_strlen(s2)==0)
		return (s2);
	end=s2+ft_strlen(s2)-1;
	while(ft_strchr(set,(int)(*end)) && ft_strlen(s2) > 0)
	{
		ft_delete_char(end);
		end--;
	}
    
	
	return (s2);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int length_s;
	int counter;
	char *to_return;

	length_s = ft_strlen((char *)s);
	to_return = (char *)malloc(length_s+1);
	if (to_return == 0)
		return (0);
	counter = 0;
	while (counter < length_s)
	{
		to_return[counter]=(*f)(counter,s[counter]);
		counter++;	
	}
	to_return[counter]='\0';
	return (to_return);
}

char            f_strmapi(unsigned i, char c) { return (c + i); }


int	count_char(char *text, char find)
{
	int	counter;

	counter = 0;
	while (*text != '\0')
	{
		if (*text == find)
			counter++;
		text++;
	}
	return (counter);
}

char **ft_split(char *s, char c)
{
	char    **matrix;
	int		n_lines;
	int		iterator;
	char	*position;
	char    *s2;
	char	*next_position;
	int		length;

	n_lines = count_char (s, c) + 1;
	matrix = (char **) malloc (n_lines * sizeof (int));
	iterator = 0;
	s2=ft_strdup(s);
	position = s2;
	while (iterator < n_lines)
	{
		if(iterator < n_lines -1)
			next_position = ft_strchr(position, c);
		else 
			next_position = ft_strchr(position, '\0');
		length = next_position - position;
		if(length == 0)
		{
			position = next_position +1;
			n_lines--;
			continue;
		}
		matrix[iterator]=(char *)malloc(length+1);
		ft_strlcpy(matrix[iterator],position,length+1);
		position = next_position + 1;
		iterator++;
	}
	matrix[iterator] = 0;
	return (matrix);
}


int main(void)
{	
	char **tabstr ;
	int i;


	tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	i =0;
 	while (tabstr[i] != NULL)
        {
            printf("%s\n",tabstr[i]);
            write(1, "\n", 1);
            i++;
        }
    
}