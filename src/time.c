/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-amra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:15:42 by iel-amra          #+#    #+#             */
/*   Updated: 2023/05/03 13:53:08 by iel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	time_is_inf(struct timeval t1, struct timeval t2)
{
	if (t1.tv_sec > t2.tv_sec)
		return (0);
	if (t1.tv_sec < t2.tv_sec)
		return (1);
	if (t1.tv_usec < t2.tv_usec)
		return (1);
	return (0);
}

struct timeval	time_add(struct timeval t1, struct timeval t2)
{
	struct timeval	time;

	time.tv_usec = (t1.tv_usec + t2.tv_usec) % 1000000;
	time.tv_sec = t1.tv_sec + t2.tv_sec + (t1.tv_usec + t2.tv_usec > 1000000);
	return (time);
}

struct timeval	ms_to_timeval(unsigned long ms)
{
	struct timeval	time;

	time.tv_usec = ms * 1000 % 1000000;
	time.tv_sec = ms / 1000;
	return (time);
}

struct timeval	time_minus(struct timeval t1, struct timeval t2)
{
	struct timeval	time;

	time.tv_usec = (1000000 + t1.tv_usec - t2.tv_usec) % 1000000;
	time.tv_sec = t1.tv_sec - t2.tv_sec - (t1.tv_usec < t2.tv_usec);
	return (time);
}