#!/bin/bash

export oscp=/usr/local/ossh/bin/scp
export ossh=/usr/local/ossh/bin/ssh

$oscp -rS $ossh erje3158@excalibur.arl.hpc.mil:/p/home/erje3158/ellip3d/ellip3d_single_particle_fracture/outputs/60157{38..48}/ ~/Desktop


