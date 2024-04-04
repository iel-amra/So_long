rm */*.xpm
for I in */*.png
do convert "$I" -resize 45% "$(echo $I | cut -f 1 -d .).xpm"
done
