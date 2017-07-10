#! /bin/bash
#clean up
#run as root
cd /var/log
cat /dev/null > massages
cat /dev/null > wtmp
echo "log files cleaned up"