#!/usr/bin/sh
#curl mpv yt-dlp sed

# File/directory locations:
    URL_FILE="$XDG_CACHE_HOME/vtuber-urls"
 SEARCH_FILE="$XDG_CACHE_HOME/vtuber-search"
    TMP_FILE="$XDG_CACHE_HOME/temp.xml"
     XML_DIR="$XDG_DATA_HOME/vtuber-xml"
      CONFIG="$HOME/Scripts/config"

# Run through the main loop.
MAIN="TRUE"

helpText() {
    while IFS= read -r LINE; do
        printf "%s\n" "$LINE"
    done <<-EOF
Usage: ${0##*/} [OPTION]... [TAG GROUPS]
    
    Options:
     update              updates the XML cache
     list                lists streams in the XML cache
     -h, --help, help    list this help
     -d, --download      download the selected stream
     opt                 tui

    Tag groups:
     music               includes the following tags: karaoke|sing|song|mv|cover
     asmr                includes the following tags: sleep|asmr|rain
     anything            includes every stream

EOF
}

update() {

    # Optionally update the URL cache.
    printf "Do you want to update the URL cache? [y/N] "
    read -r BOOLEAN

    [ y = "$BOOLEAN" ] && \
        printf "\nUpdating URL cache . . .\n" && \
        config
    [ y != "$BOOLEAN" ] && \
        printf "\nContinuing . . .\n"

    # Check if the XML directory exists, if not, create one.
    [ ! -d "$XML_DIR" ] && \
        mkdir "$XML_DIR" && \
        printf "Creating XML cache directory at: %s . . .\n" "$XML_DIR" && \
        printf "Success!\n"
    
    # Update the XML cache.
    printf "\nUpdating XML cache . . .\n"
    COUNTER=0

    while read -r line; do
        curl -s "$line" -o "$TMP_FILE"

        CHANNEL_TITLE="$(xmllint --xpath '/*/*[6]/*[1]/text()' "$TMP_FILE")"
        # Create an ascii-readable channel title.   
        case $CHANNEL_TITLE in
            *Ch*)CHANNEL_TITLE=${CHANNEL_TITLE%Ch*}Ch;;
            */*)CHANNEL_TITLE=$(echo "$CHANNEL_TITLE"|sed --posix 's#[ ?]/[ ?]# #');;
            *);;
        esac

        COLUMNS=$(( $(tput cols) - 33 - ${#CHANNEL_TITLE} ))
        printf "\rCurling XML file for %s . . .%*s/%s" "$CHANNEL_TITLE" "$COLUMNS" "($COUNTER" "$(wc -l < "$URL_FILE"))"

        mv "$TMP_FILE" "$XML_DIR/$CHANNEL_TITLE.xml"
        COUNTER=$(( COUNTER + 1 ))
        sed -i "$COUNTER s# # $XML_DIR/$CHANNEL_TITLE.xml #" "$SEARCH_FILE"
    done < "$URL_FILE"

    printf "\rCurling XML file for %s . . .%*s/%s" "$CHANNEL_TITLE" "$COLUMNS" "($COUNTER" "$(wc -l<"$URL_FILE"))"
    printf "\nDone."
}

channelPrint() {
    for FILE in "$XML_DIR"/*; do
        FILE=${FILE%.xml}
        FILE=${FILE##*/}
        echo "$FILE"
    done
}

configPrint() {
    [ -f "$SEARCH_FILE" ] && \
        rm "$SEARCH_FILE"

    [ -f "$URL_FILE" ] && \
        rm "$URL_FILE"

    printf "Found %s entries.\n" "$(wc -l<"$CONFIG")"
    COUNTER=0

    # Converts config file to JSON.
    sed -E 's/(.*) (.*) (.*)/"\1":{"url":"\2","tags":"\3"},/g ; 1i{' "$CONFIG" | \
        sed -E '/(\"#.*)|(^[^\"{}].*)/d' | \
        sed -E '$ s/,$//g ; $a}'

    while read -r LINE; do
        printf "\r(%s/%s) Completed entries . . ." "$COUNTER" "$(wc -l<"$CONFIG")"

        case $LINE in
            \#)
                PRINT=FALSE
                ;;
            *channel*)
                XML_URL=${LINE#* *channel/}
                XML_URL=${XML_URL%% *}
                XML_URL="https://www.youtube.com/feeds/videos.xml?channel_id=$XML_URL"
                SEARCH=${LINE%% *}
                TAGS=${LINE#* * }
                ;;
            */c/*)
                OUTPUT=$(XML_URL=${line#* }
                XML_URL=${XML_URL%% *}
                curl -s "$XML_URL" | \
                    grep -Eo "\"><meta itemprop=\"paid\" content=\"false\"><meta itemprop=\"channelId\" content=\".{24}" | \
                    tail -c25)
                XML_URL="https://www.youtube.com/feeds/videos.xml?channel_id=$OUTPUT"
                SEARCH=${LINE%% *}
                TAGS=${LINE#* * }
                ;;
            *)
                ;;
        esac

        COUNTER=$(( COUNTER + 1 ))
        [ "$PRINT" = TRUE ] && \
            echo "$XML_URL" >> "$URL_FILE"
        [ "$PRINT" = TRUE ] && \
            printf "%s %s\n" "$SEARCH" "$TAGS" >> "$SEARCH_FILE"

        PRINT=TRUE
    done < "$CONFIG"

    printf "\r(%s/%s) Completed entries . . .\n" "$COUNTER" "$(wc -l<"$CONFIG")"
    printf "URL cache succesfully updated. URL file can be found at: %s\n" "$URL_FILE"
}

#tui_(){
##printf "> "
##read -r opt
#}

while [ -n "$1" ];do
    case $1 in
        music)
            TAGS="karaoke|sing|song|mv|cover"
            shift
            ;;
        asmr)
            TAGS="sleep|asmr|rain"
            shift
            ;;
        anything)
            TAGS=".*"
            shift
            ;;
        update)
            update
            unset MAIN
            shift
            ;;
        list)listPrint
            unset MAIN
            shift
            ;;
        help)
            helpText
            unset MAIN
            shift
            ;;
        -d|--download)
            DOWNLOAD=TRUE
            shift
            ;;
        opt)
            tui
            shift
            ;;
        *)
            break
            ;;
    esac
done

print_(){
    FILE=$(sed --posix -nE "s/$SEARCH (.*\.xml)( .*)/\1/p" "$SEARCH_FILE")
    TAGS=$(sed --posix -nE "s/$SEARCH (.*\.xml) (.*)/\2/p" "$SEARCH_FILE" | sed --posix 's/ /|/g')

    CHANNEL_TITLE="$(xmllint --xpath '/*/*[6]/*[1]/text()' "$TMP_FILE")"
    CHANNEL_LINK="$(xmllint --xpath '/*/*[6]/*[2]/text()' "$TMP_FILE")"
    ENTRY_COUNT="$(xmllint --xpath '/*' "$TMP_FILE" | rg "<entry>" | wc -l)"

    COUNTER="$(( 7 + ENTRY_COUNT ))"
    VIDEO_INDEX=1

    printf "%s\n%s\n\n" "$CHANNEL_TITLE" "$CHANNEL_LINK"
    set -- "$@" temp

    while [ "$COUNTER" -gt 7 ]; do
        VIDEO="$(xmllint --xpath "/*/*[$COUNTER]/*[4]/text()" "$TMP_FILE"|sed -nE "s/($TAGS)/\1/Ip")"
    
        [ "$VIDEO" ] && \
            echo "$VIDEO_INDEX) $VIDEO" && \
            VIDEO_INDEX="$(( VIDEO_INDEX + 1 ))" && \
            set -- "$@" $COUNTER
    
        COUNTER="$(( COUNTER - 1 ))"
    done
    
    [ "$FILE" = "$HOME/.cache/temp.xml" ] && \
        echo "Provide a valid streamer." && \
        exit 1
    
    printf "Choose a video to watch: \n> "
    
    read -r INDEX
    shift "$INDEX"
    
    LINK=$(xmllint --xpath "/*/*[$1]/*[5]" "$FILE" | sed -E 's/.*href="(.*)"\/>/\1/')
    [ ! "$DOWNLOAD" ] && \
        mpv "$LINK" --msg-level=cplayer=no,status=no
    [ "$DOWNLOAD" ] && \
        yt-dlp "$LINK"
}

[ $MAIN ] && print || exit 0
