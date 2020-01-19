#!/usr/bin/gnuplot

reset
set term epscairo enhanced color
set output "plot.eps"

plot 'data.dat' w p ls 7 lc 'black'notitle