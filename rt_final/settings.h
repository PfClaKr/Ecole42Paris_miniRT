/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:59:20 by ychun             #+#    #+#             */
/*   Updated: 2023/07/27 02:57:18 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

/*
	if did you changed any value of this header file, you have to run the commande
	make re in terminal for apply your settings.
*/
# define WIDTH 512
# define HEIGHT 512
# define TITLE "miniRT"

// you have to put 0.0 ~ 1.0 value
# define ALBEDO_R 1
# define ALBEDO_G 1
# define ALBEDO_B 1

// 0 or 1, 0 is default(by img)
# define RENDER_BY_PIXEL 0

#endif