/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:28:46 by kneth             #+#    #+#             */
/*   Updated: 2016/12/22 16:31:40 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstaddender(t_list *alst, t_list *new)
{
	if (alst->next)
		ft_lstaddender(alst->next, new);
	else
		alst->next = new;
	return (alst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = NULL;
	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!tmp || !f)
		return (NULL);
	return (ft_lstaddender(tmp, ft_lstmap(lst->next, f)));
}
