#!/usr/bin/sh
#Arch system updater
while [ "$1" != "" ]; do case $1 in
    -d)download=true;shift;;
    *)break;;
esac
done

dl(){ echo "$updts"|xargs -I {} dunstify 'Downloading pending updates . . .' '{} pending packages out of date';checkupdates -d&&dunstify 'Updates succesfully downloaded.'
}

updts=$(checkupdates | wc -l)
[ 1 = "$updts" ]&&dunstify 'Update available' '1 out of date package.'&&unset updts
[ "$download" ]&&[ -n "$updts" ]&&dl&&unset updts
[ -n "$updts" ]&&echo "$updts"|xargs -I {} dunstify 'Updates available' '{} out of date packages.'
