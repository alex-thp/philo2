#include "philo.h"

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] > 7 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

int             find_size(long int nb)
{
    int i;

    i = 0;
    while(nb)
    {
        nb /= 10;
        i++;
    }
	i++;
	return (i);
}

char            *init_ret(int i)
{
    char *ret;

    ret = malloc(sizeof(char) * (i));
    while (i)
    {
        ret[i] = 0;
        i--;
    }
	ret[0] = 0;
    return (ret);
}

char            *itoa(long int nb)
{
    int         i;
    char        *ret;

    i = find_size(nb);
	//printf("i = %d, nb = %ld\n", i, nb);
    ret = init_ret(i);
	ret[i] = 0;
    i -= 1;
    while (i)
    {
        ret[i] = (nb % 10) + 48;
		//printf("ret[%d] = %ld\n", i, (nb % 10) + 48);
        nb /= 10;
        i--;
    }
	//printf("ret = %s\n", ret);
    return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(result = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

int 	ft_strlen(const char *s)
{
	int 	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}