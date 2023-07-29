/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:59:20 by ychun             #+#    #+#             */
/*   Updated: 2023/07/29 22:59:55 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_BONUS_H
# define SETTINGS_BONUS_H

/*
	if you changed any value of this header file, you have to run the commande
	make re in terminal for apply your settings.
*/
# define WIDTH 800
# define HEIGHT 450
# define TITLE "miniRT"

// you have to put 0.0 ~ 1.0 value
# define ALBEDO_R 1.0
# define ALBEDO_G 1.0
# define ALBEDO_B 1.0

// 0 or 1, 0 is default(by img)
# define RENDER_BY_PIXEL 0

// Shininess value 64.0 is default 0.0 ~ infinit 
# define SHININESS_VALUE 64.0

// Specular strength 2 is default 0.0 ~ 2.0 value
# define SPECULAR_STRENGTH 2.0

// Light sharpness 4 is default 0.0 ~ infinit
# define LIGHT_SHARPNESS 2.0

// Amblight strength 3 is default 0.1 ~ infinit 
# define AMBLIGHT_STRENGTH 3

#endif