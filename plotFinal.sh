#!/usr/bin/gnuplot

reset
set term epscairo enhanced color
set output "final/wykres20.eps"

set key left top

set notitle

set ylabel "v(y) [j.s./t]"
set yrange [0:0.6]
set ytics 0,.1,.6

set xlabel "y[sektory]"
set xrange[0:14]
set xtics 0,1,14

set grid

g='final/final20.dat'

f(x) = a * x**2 + b * x + c

fit f(x) g u 1:2 via a,b,c

p f(x) lc 7 notitle,g u 1:2 lc 'black' notitle