/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrmone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:52:47 by dderny            #+#    #+#             */
/*   Updated: 2025/03/31 17:29:10 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_lstrmone(t_list **lst, void (*del)(void *))
{
	void	*tmpcontent;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = (*lst)->next;
	tmpcontent = (*lst)->content;
	free(*lst);
	*lst = tmp;
	del(tmpcontent);
}
