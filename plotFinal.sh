#!/usr/bin/gnuplot

reset
set term epscairo enhanced color
set output "final/wykres1.eps"

set key left top

set notitle

set ylabel "v(y) [j.s.]"

set xlabel "y"

set grid

g='final/final1.dat'

f(x) = a * x**2 + b * x + c

fit f(x) g u 1:2 via a,b,c

p f(x) lc 7 notitle,g u 1:2 lc 'black' notitle