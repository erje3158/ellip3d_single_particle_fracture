#!/bin/bash

for dir in *
  do
    if [ -d "$dir" ]
      then
        cp plot_boundary $dir
        cd $dir

	echo
	echo "Moving into "$PWD
	echo

        ./plot_boundary comp_particle 0 100 1
        cd ../
    fi
  done 
    
