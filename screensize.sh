#!/bin/bash
temp=`xdpyinfo  | grep dimensions`
width=`expr "$temp" : ".\{17\}\([^x]*\)"`
height=`expr "$temp" : ".\{17\}\([^ ]*\)"| rev`
height=`expr "$height" : "\([^x]*\)"| rev`
echo -n $width $height
