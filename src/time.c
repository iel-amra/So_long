t_time	current_time()
{
	t_time	now;

	timespec_get( &now, TIME_UTC );
	return (now);
}

int	time_inf(t_time time1, t_time time2)
{
	if (time1.tv_sec < time2.tv_sec)
		return (1);
	if (time1.tv_sec == time2.tv_sec && time1.tv_nsec < time2.tv_nsec)
		return (1);
	return (0);
}

t_time	time_diff(t_time time1, t_time time2)
{
	if (time2.tv_nsec > time1.tv_nsec)
	{
		time1.tv_sec--;
		time1.tv_nsec += 1000000000L;
	}
	time1.tv_sec -= time2.tv_sec;
	time1.tv_nsec -= time2.tv_nsec;
	return (time1);
}

t_time	time_add(t_time time1, t_time time2)
{
	if (time2.tv_nsec > time1.tv_nsec + time2.tv_nsec)
	{
		time1.tv_sec++;
		time1.tv_nsec -= 1000000000L;
	}
	time1.tv_sec += time2.tv_sec;
	time1.tv_nsec += time2.tv_nsec;
	return (time1);
}

void	time_disp(t_time time)
{
	printf("%li,%09li\n", time.tv_sec, time.tv_nsec);
}
