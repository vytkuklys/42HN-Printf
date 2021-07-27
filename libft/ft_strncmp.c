/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuklys <vkuklys@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:29:15 by vkuklys           #+#    #+#             */
/*   Updated: 2021/07/14 12:29:15 by vkuklys          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_strncmp(const char *str1, const char *str2, unsigned int n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{
		if (*s1 > *s2)
			return (*s1 - *s2);
		if (*s2 > *s1)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}
