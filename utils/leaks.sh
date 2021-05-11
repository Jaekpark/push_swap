#! /bin/bash
ARG=`ruby -e "puts (1..10000).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
