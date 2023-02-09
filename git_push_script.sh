#!/bin/bash
git add .
a=`date`
git commit -m "commit at $a"
git push
unset a
echo 'git push 完成'
