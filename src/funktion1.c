#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
FILE *C;
float Stewdent(int i)//Выводит коэфициент Стьюдента
    {
        if(i == 2)
            return 12.71;
        if(i == 3)
            return 4.30;
        if(i == 4)
            return 3.188;
        if(i == 5)
            return 2.77;
        if(i == 6)
            return 2.57;
        if(i == 7)
            return 2.45;
        if(i == 8)
            return 2.36;
        if(i == 9)
            return 2.31;
        if(i == 10)
            return 2.26;
        if(i <= 12 && i>10)
            return 2.20;
        if(i <= 14 && i>12)
            return 2.16;
        if(i <= 16 && i>14)
            return 2.13;
        if(i <= 18 && i>16)
            return 2.11;
        if(i <= 20 && i>18)
            return 2.09;
        if(i <= 30 && i>20)
            return 2.04;

    }
int main(void) { //Считает погрешности с динамическим выделением памяти
    setlocale(LC_ALL,"Rus");
	int i=0,j;
	float sr_zn,k=0.0,disp,pogr,n,s=0.0,*A=NULL;
	double t;
	char c;
	float N;
    C = fopen("input.txt", "r");
    while(fscanf(C,"%f",&N)!=EOF)//Берет информацию из файла и записывает в динамический массив
    {
        A=(float*)realloc(A,(i+1)*sizeof(float));
        A[i]=N;
        s=s+A[i];
        i++;
    }
    fclose(C);
    for(j=0;j<i;j++)
        printf("%f\n",A[j]);
	do//Считает погрешность так же опирируя на динамическим массивом
    {
        printf("Введите число: ");
        scanf("%f",&n);
        printf("n=%f\n",n);
        //fprintf(C,"%f ",n);
        A=(float*)realloc(A,(i+1)*sizeof(float));
        A[i]=n;
        s=s+A[i];
        i++;
        printf("Сумма=%f\n",s);
        sr_zn=s/i;
        printf("Cреднее значение=%f\n",sr_zn);
        if(i!= 1)
        {
            for(j=0;j<i;j++)
                {
                    k=k+(A[j]-sr_zn)*(A[j]-sr_zn);
                }

            disp=sqrt(k/(i*(i-1)));
            printf("Дисперсия=%f\n",disp);
            t=disp*Stewdent(i);
            printf("Погреность:%f\n",t);
            k=0;
        }
        getchar();
        printf("Next (y/n)? ");
        c = getchar();
	}
	while(c == 'y');
	C=fopen("input.txt","w");
    for(j=0;j<i;j++)//записывает новую информацию в тот же файл
        fprintf(C,"%f ",A[j]);
	return 0;
}
