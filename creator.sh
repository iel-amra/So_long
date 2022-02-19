(cat argile.h
cat src/*.c | grep "^[^# 	{}].*)$" | grep -v "^int[ 	]*main(" | sed "s/$/;/" | sed -e "s/^int	/int		/" \
	-e "s/	/		/" -Ee "s/(t_cutter)	+/\1	/" -e "s/	/		/" -Ee "s/(unsigned [a-zA-Z0-9_]+)	+/\1	/"
echo "
#endif") > header/principal.h
