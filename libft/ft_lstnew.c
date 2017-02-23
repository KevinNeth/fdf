/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:36:39 by kneth             #+#    #+#             */
/*   Updated: 2016/12/22 16:31:44 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;
	void	*content_cpy;
	size_t	content_size_cpy;

	if (!(new = (void*)malloc(sizeof(*new))))
		return (NULL);
	if (content == NULL)
	{
		content_cpy = NULL;
		content_size_cpy = 0;
	}
	else if (!(content_cpy = (void*)malloc(content_size)))
		return (NULL);
	else
	{
		ft_memcpy(content_cpy, (void*)content, content_size);
		content_size_cpy = content_size;
	}
	new->content = content_cpy;
	new->content_size = content_size_cpy;
	new->next = NULL;
	return (new);
}
