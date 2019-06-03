#include "fillit.h"

void	lstaddend(t_list *alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		while (alst->next != NULL)
			alst = alst->next;
		alst->next = new;
	}
}