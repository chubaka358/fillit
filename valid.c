#include "fillit.h"

int	is_obs(char c1, char c2, char c3)
{
	if ((c1 == '#') && (c2 == '#') && (c3 == '#'))
		return (1);
	return (0);
}