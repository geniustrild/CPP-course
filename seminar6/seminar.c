считать весь буфер в массив
sys\stat.h
  stat заполняет сведениями о файле

Пишем алгоритм пузырьковой сортировки
void BubbleSort(char* text[], int size)
  {
    for (int n = 0; n < size;n++)
      {
        if (strcmp(text[i], text[i+1])<0)
          swap (&text[i], &text[i+1]);
      }
  } //добавить проверку, что если swap не вызвался, завершать сортировку

//функция сортировки по рифмам т.е с концов строк

int strcmpfrrghtsd (const char* strA, const char* strB)
  {
    int len1=strlen(strA);
    ...
    return ...;
  }
____________________________________________________________________________
void BubbleSort(char* text[], int size, int (*cmp_func_ptr)(const char* str1,const str2))
  {
    for (int n = 0; n < size;n++)
      {
        if (cmp_func_ptr(text[i],text[i+1])<0)
          swap(&text[i],&text[i+1])
      }
  } //добавить проверку, что если swap не вызвался, завершать сортировку

//функция вывода тригонометрических функций
вызов Функции
PrintTrig(&sin); //&можноне писать
сама фунуция:
PrintTrig(double (*func)(double x))
  {
    for (;;)
    {
      y=(*func)(x);// или y=func(x);
      printf("%d\n",y);
    }
  }



//СПИСКИ
