void	reset_objects(t_object *objects)
{
	while (objects->animes)
		reset_one_object(objects++);
}

void	reset_one_object(t_object *object)
{
	object->alive = 1;
	if (object->move)
	{
		object->move->old_x = object->x;
		object->move->old_y = object->y;
		object->x = object->move->begin_x;
		object->y = object->move->begin_y;
		object->move->x = object->x;
		object->move->y = object->y;
		object->move->speed_x = object->move->begin_speed_x;
		object->move->speed_y = object->move->begin_speed_y;
	}
}
