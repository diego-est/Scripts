#!/usr/bin/env bash
#Script to download or make a list of every map on an osu! install
IDGEN=true
OSUDL=true
IDFILE=songids.txt

help_text(){ while IFS= read -r line; do
        printf "%s\n" "$line"
    done <<-EOF
    Usage: osudl [OPTION]... [path/to/osu!/directory]

    Downloads all of the beatmaps in your current osu! folder. 
    Consequently, can also be used to create a text file with all the beatmap id's in your /Songs folder, and/or be used to download all of the beatmap id's in a specified text file.

    -h, --help                  show this help text
    -g, --generate FILENAME     generate beatmap id's text file
                                    The default beatmap id's text file is named songids.txt and it is created into your /Songs folder. If you wish to create a file with a different name, specify the name here.
    -d, --download [path/to/beatmap-id-file]         download beatmaps from the beatmap id's text file (the default is located in your /Songs folder and that is where the program will look for the text file)
                                    If you changed the beatmap id's filename then specify the new name.
    -T, --test                  test if everything is working correctly; will only download the first beatmap id in the beatmap id's text file
EOF
}

while [ "$1" != "" ];do
    case $1 in
        -h | --help)help_text;exit 0;;
        -g)unset OSUDL;shift;;
        --generate)shift;unset OSUDL;IDFILE=$1;shift;;
        -d)unset IDGEN;shift;;
        --download)shift;unset IDGEN;IDPATH=$1;shift;;
        *)break;;
    esac
done

[ "$1" ]&&DLPATH=$1||echo "Usage : supply a valid path to your osu! directory. Use -h or --help for more information"
[ ! "$IDPATH" ]&&IDPATH=$DLPATH/$IDFILE

id_gen(){ [ -d "$DLPATH" ]&&[ ! -s "$IDPATH" ]&&file_parse|awk '{FS="/"} {print $NF}'|grep -o '[0-9]\+'|awk '!a[$0]++'|sed '/^.\{7\}..*/d' > "$IDPATH"
}

file_parse(){ for file in "$DLPATH"/*;do
    echo "$file"
done
}


osudl(){ for i in $(cat "$IDPATH");do
        DLLINK=$(curl -sI https://api.chimu.moe/v1/download/"${i}"?n=1|awk 'FNR == 3 {print $2}'|tr -d '\r"')
        BEATMAPNAME=$(echo "$DLLINK" | cut -d= -f 2 - | sed 's/%20/\ /g')
        curl "$(echo -E "$DLLINK")" > "$BEATMAPNAME"
done
}

[ ! "$OSUDL"  ]&&id_gen
[ ! "$IDGEN" ]&&osudl
[ "$OSUDL" ]&&[ "$IDGEN" ]&&id_gen osudl
