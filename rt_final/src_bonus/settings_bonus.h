/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:59:20 by ychun             #+#    #+#             */
/*   Updated: 2023/08/03 04:46:54 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_BONUS_H
# define SETTINGS_BONUS_H

/*
	if you changed any value of this header file, you have to run the commande
	make re in terminal for apply your settings.
*/

// Image window setting // 
# define WIDTH 512		// range : 0 ~ int max
# define HEIGHT 512		// range : 0 ~ int max

// Refelct ratio // default : 1.0 // range : 0.0 ~ 1.0 value
# define ALBEDO_R 1.0
# define ALBEDO_G 1.0
# define ALBEDO_B 1.0

// Light strength // default : 15 // range : 0 ~ int max
# define LIGHT_STRENGTH 30

// Light sharpness // default : 4 // range : 0.0 ~ int max
# define LIGHT_SHARPNESS 4.0

// Amblight strength // default : 1 // range : 0.1 ~ int max 
# define AMBLIGHT_STRENGTH 1

// Rendering methode // default : 0 (by img) // range : 0 or 1 (bool)
# define RENDER_BY_PIXEL 0

// For bonus Options
// Shininess value // default : 64.0 // range : 0.0 ~ double max 
# define SHININESS_VALUE 64.0

// Specular strength // default : 2 // range : 0.0 ~ 2.0 value
# define SPECULAR_STRENGTH 2.0

// Checkboard value // default : 4 // range : 0 ~ int max
// (recommende even number)
# define CHECKBOARD_WIDTH 4
# define CHECKBOARD_HEIGHT 4

// Anti aliasing recursive value // default : 20 // range : 0 ~ infinit
// do not set too much!
# define ANTI_ALIASING 20

#endif