/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:59:20 by ychun             #+#    #+#             */
/*   Updated: 2023/08/03 12:57:41 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

/*
	if you changed any value of this header file, you have to run the commande
	make re in terminal for apply your settings.
*/

// Image window setting // 
# define WIDTH 512		// range : 1 ~ int max
# define HEIGHT 512		// range : 1 ~ int max

// Refelct ratio // default : 1.0 // range : 0.0 ~ 1.0 value
# define ALBEDO_R 1.0
# define ALBEDO_G 1.0
# define ALBEDO_B 1.0

// Light strength // default : 30 // range : 0 ~ int max
# define LIGHT_STRENGTH 30

// Light sharpness // default : 4 // range : 0.0 ~ int max
# define LIGHT_SHARPNESS 4.0

// Amblight strength // default : 1 // range : 0.1 ~ int max 
# define AMBLIGHT_STRENGTH 1

// Rendering methode // default : 0 (by img) // range : 0 or 1 (bool)
# define RENDER_BY_PIXEL 0

#endif
