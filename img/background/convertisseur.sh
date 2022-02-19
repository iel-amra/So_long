rm -f *.xpm
export MAGICK_HOME="$HOME/Downloads/ImageMagick-7.0.10"
export PATH="$MAGICK_HOME/bin:$PATH"
export DYLD_LIBRARY_PATH="$MAGICK_HOME/lib/"
for I in *.png
do convert "$I" "$(echo $I | cut -f 1 -d .).xpm"
done
