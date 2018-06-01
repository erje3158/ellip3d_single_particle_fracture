#!/bin/bash

export work_dir=animate
export macro=animate_plot.mcr

mkdir $work_dir
cp $macro $work_dir

a=1

for dir in *
  do
    if [ -d "$dir" ] && [ "$dir" != "$work_dir" ]
      then
	cp $dir/*.dat $work_dir 
        cd $work_dir
        tec360 -b $macro
        new=$(printf "%02d.avi" "$a")
        mv -- "untitled.avi" "$new"
        let a=a+1
        cd ../
    fi
  done

mv $work_dir/*.avi ./
rm -r $work_dir
