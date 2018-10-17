set terminal png
set output "file.png"
set grid
set xlabel "u"
set ylabel "I"
plot "data1.1.1.txt" using 1:2 with lines lc 2 notitle,"data1.1.1.txt" using 1:2  notitle
