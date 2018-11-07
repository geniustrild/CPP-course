set terminal png
set output "file.png"
set grid
set xlabel "u"
set ylabel "I"
plot "data1.txt" using 1:2 with lines lc 2 notitle


int sort_v1()
{
  for (int n=0;n<size-1;n++)
  {
    for (int i=0;i<size-1;i++)
    {
      if (data[i]>data[i+1])
      {
        int temp=data[i];
                data[i]=data[i+1];
                        data[i+1]=temp;
                      }

      }
    }
}
