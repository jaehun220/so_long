/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:50:40 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/19 00:50:40 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_param *param)
// 입력에따라 좌표로 사용할 값을 증감시킴
{
	if (keycode == KEY_W && param->y != 0)
		param->y -= param->he;
	if (keycode == KEY_S && param->y != 480)
		param->y += param->he;
	else if (keycode == KEY_A && param->x != 0)
		param->x -= param->wi;
	else if (keycode == KEY_D && param->x != 480)
		param->x += param->wi;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("y: %d x: %d\n", param->y, param->x);
	return (0);
}
