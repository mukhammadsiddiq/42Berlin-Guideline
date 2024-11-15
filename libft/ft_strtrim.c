/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:13:13 by mukibrok          #+#    #+#             */
/*   Updated: 2024/11/15 10:14:19 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char *set, char c)
{
	while (*set)
	{
		if (*set == (const char)c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	i;

	trimmed = NULL;
	end = ft_strlen(s1);
	if (*s1 == '\0')
		return (ft_strdup(""));
	start = 0;
	while (is_set(set, s1[start]) && s1[start])
		start++;
	while (end > start && is_set(set, s1[end - 1]))
		end--;
	trimmed = (char *) malloc(sizeof(*s1) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start <= end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
// int	main(int argc, char **argv)
// {
// 	char s1[] = "";
// 	char *s3 = argv[1];
// 	char	*s2 = ft_strtrim(s1, "te");
// 	printf("%s\n", s2);
// }