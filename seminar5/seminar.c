считать весь буфер в массив
sys\stat.h
  stat заполняет сведениями о файле


Функции
_______________________________________________________________________
-+ReadFile();
-+CountAndChange();//Пройти по массиву,посчитать и заменить \n на \0
-+Divide();//делит массив на указатели,записать указатели на начала строк в массив text[]
--sort();
--Output();

Чтение текста из файла
_______________________________________________________________________
function TextSize()
{
    struct stat st={}
    stat ("имя файла",&st(адрес структуры))
    size=st.st_size;

    char * buf=(char*) calloc(size+1,sizeof(char*));
    FILE * onegin=fopen(...);

    fread("куда","Размер элемента","размер","файл");
    fread(buf,sizeof(char),size,onegin.txt);
    buf[size]='\n';
}


Алгоритм сортировки
________________________________________________________________________
qsort()

Операция сравнения:
_______________________________________________________________________
type(func)=int (*)(int,int)
type(comparator)=int (*)(void*,void*)

Создаем свой компаратор для функции qsort()
___________________________________________
Он должен быть такого типа:type(comparator)=int (*)(void*,void*)


int CompareInts(void* a_ptr,void* b_ptr)
{
  *((int*)a_ptr) - *((int*)a_ptr)
}

qsort("где лежат данные","сколько их", "размер", "компаратор");
qsort(data,N, sizeof(int), CompareInts);

Компаратор для сортировки текста:
int CompareStrings(void* ptr_1, void*ptr_2)
  {
    char *str1=*((char**)ptr_1);
    char *str2=*((char**)ptr_2);
for(;;)
{
    while(!CustomEncoding(*str1))str1++;
    while(!CustomEncoding(*str2))str2++;

  if (CustomEncoding(*str1)!=CustomEncoding(*str2))
      return CustomEncoding(*str1)-CustomEncoding(*str2);

    str1++;str2++;
}

  }
  qsort(text,nlines,sizeof(char*),&CompareStrings);

разрешенный массив alph[]="АБВ...Яабв...я"
CustomEncoding(char c)
  {
    alph[]="АБВ...Яабв...я";
    return i+1;
  }

_______________________________________________________________________
comb_sort()//Хороший тип сортировки, нужно изучить

/
