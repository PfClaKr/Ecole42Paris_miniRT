/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:29:55 by ychun             #+#    #+#             */
/*   Updated: 2023/06/05 00:49:11 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//생성자들
t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_point3	point3(double x, double y, double z)
{
	t_point3	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

t_color3	color3(double r, double g, double b)
{
	t_color3	c;

	c.x = r;
	c.y = g;
	c.z = b;
	return (c);
}
