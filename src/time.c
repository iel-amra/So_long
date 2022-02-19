/*
t_time	current_time()
{
	t_time	now;

	gettimeofday(&now, (void *) 0);
	return (now);
}

int	time_inf(t_time time1, t_time time2)
{
	if (time1.tv_sec < time2.tv_sec)
		return (1);
	if (time1.tv_sec == time2.tv_sec && time1.tv_usec < time2.tv_usec)
		return (1);
	return (0);
}

t_time	time_diff(t_time time1, t_time time2)
{
	if (time2.tv_usec > time1.tv_usec)
	{
		time1.tv_sec--;
		time1.tv_usec += 1000000L;
	}
	time1.tv_sec -= time2.tv_sec;
	time1.tv_usec -= time2.tv_usec;
	return (time1);
}

t_time	time_add(t_time time1, t_time time2)
{
	if (time2.tv_usec > time1.tv_usec + time2.tv_usec)
	{
		time1.tv_sec++;
		time1.tv_usec -= 1000000L;
	}
	time1.tv_sec += time2.tv_sec;
	time1.tv_usec += time2.tv_usec;
	return (time1);
}

void	time_disp(t_time time)
{
	printf("%li,%06i\n", time.tv_sec, time.tv_usec);
}*/
