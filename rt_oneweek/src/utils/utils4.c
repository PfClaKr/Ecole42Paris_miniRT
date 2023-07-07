/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychun <ychun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:42:13 by ychun             #+#    #+#             */
/*   Updated: 2023/06/05 00:48:54 by ychun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//벡터 내적
double	vdot(t_vec3 v1, t_vec3 v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

//벡터 외적
t_vec3	vcross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	tmp;

	tmp.x = (v1.y * v2.z) - (v1.z * v2.y);
	tmp.y = (v1.z * v2.x) - (v1.x * v2.z);
	tmp.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (tmp);
}

//단위 벡터
t_vec3	vunit(t_vec3 v)
{
	double	len;

	len = vlength(v);
	if (len == 0)
		ft_error("Error : Devider is 0\n", 2);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}

// 두 벡터 비교후 작은값만 리턴
t_vec3	vmin(t_vec3 v1, t_vec3 v2)
{
	if (v1.x > v2.x)
		v1.x = v2.x;
	if (v1.y > v2.y)
		v1.y = v2.y;
	if (v1.z > v2.z)
		v1.z = v2.z;
	return (v1);
}
