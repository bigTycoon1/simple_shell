#!/bin/bash
if [ "$(getconf LONG_BIT)" -eq 32 ]; then
	PID_MAX=32767
elif [ "$(getconf LONG_BIT)" -eq 64 ]; then
	PID_MAX=2147483647
else
	echo "Unable to determine maximum PID for this system"
	exit 1
fi
echo "Maximum PID value is : $PID_MAX"
