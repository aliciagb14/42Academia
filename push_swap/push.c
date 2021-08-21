/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agonzale <agonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:25:01 by agonzale          #+#    #+#             */
/*   Updated: 2021/08/21 11:30:43 by agonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//le paso 1 puntero al primer elemento de lista y otro al 2 elemento de la lista
void	push_a(t_stacks *stack, t_bool print)
{
	t_list_dbl	*aux;

	if (!stack->stack_b)
		return ;
	aux = stack->stack_b;
	stack->stack_b = stack->stack_b->next;
	if (stack->stack_b != NULL)
	{
		if (aux == stack->stack_b->next)
		{
			stack->stack_b->prev = NULL;
			stack->stack_b->next = NULL;
		}
		else
		{
			stack->stack_b->prev = aux->prev;
			aux->prev->next = stack->stack_b;
		}
	}
	if (!stack->stack_a)
	{
		stack->stack_a = aux;
		stack->stack_a->next = NULL;
		stack->stack_a->prev = NULL;
	}
	else if (stack->stack_a->next == NULL)
	{
		aux->next = stack->stack_a;
		aux->prev = stack->stack_a;
		stack->stack_a->next = aux;
		stack->stack_a->prev = aux;
		stack->stack_a = aux;
	}
	else
	{
		aux->next = stack->stack_a;
		aux->prev = stack->stack_a->prev;
		aux->prev->next = aux;
		aux->next->prev = aux;
		stack->stack_a = aux;
	}
	stack->size_a++;
	stack->size_b--;
	if (print)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	push_b(t_stacks *stack, t_bool print)
{
	t_list_dbl	*aux;

	if (!stack->stack_a)
		return ;
	aux = stack->stack_a;
	stack->stack_a = stack->stack_a->next;
	if (stack->stack_a != NULL)
	{
		if (aux == stack->stack_a->next)
		{
			stack->stack_a->prev = NULL;
			stack->stack_a->next = NULL;
		}
		else
		{
			stack->stack_a->prev = aux->prev;
			aux->prev->next = stack->stack_a;
		}
	}
	if (!stack->stack_b)
	{
		stack->stack_b = aux;
		stack->stack_b->next = NULL;
		stack->stack_b->prev = NULL;
	}
	else if (stack->stack_b->next == NULL)
	{
		aux->next = stack->stack_b;
		aux->prev = stack->stack_b;
		stack->stack_b->next = aux;
		stack->stack_b->prev = aux;
		stack->stack_b = aux;
	}
	else
	{
		aux->next = stack->stack_b;
		aux->prev = stack->stack_b->prev;
		aux->prev->next = aux;
		aux->next->prev = aux;
		stack->stack_b = aux;
	}
	stack->size_b++;
	stack->size_a--;
	if (print)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
}
