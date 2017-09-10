#include "../wolf3d.h"

int			ft_hooks(int keycode, t_all *all)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 13)
		forward_vector(all);
	if (keycode == 1)
		back_vector(all);
	if (keycode == 2)
		rot_right(all);
	if (keycode == 0)
		rot_left(all);
	printf("kyc = %d\n", keycode);
	return (0);
}
