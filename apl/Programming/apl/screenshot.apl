#!/usr/bin/dyalogscript
⎕SH 'nohup scrot -l mode=edge -s -o -|tee /home/void/image.png| xclip -sel clip -t image/png > /dev/null'
