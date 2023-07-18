#include <stdio.h>
#include <conio.h>
#include "mas1.h"

#define MAX 100

void main( void )
{
  int mas[MAX], run = 1, n, mi, ma = 0, a, b;

  Fill0(mas, MAX);
  while (run)
  {
    printf("Array work\n"
      "1. Fill with random from 1 to N\n"
      "2. Fill from 1 to MAX\n"
      "3. Fill from MAX to 1\n"
      "4. Print out massive\n"
      "5. Get min and max from massive\n"
      "6. Get average\n"
      "7. Fill from A with step B\n"
      "8. Reverse massive\n"
      "9. Get number with max digit sum in massive\n"
      "a. Print out prime numbers from massive\n"
      "b. Count simmetrical numbers in massive\n"
      "0. Exit\n"
      "Enter your choice:\n");
    switch (_getch())
    {
      case '0':
        run = 0;
        break;
      case '1':
        printf("N:");
        scanf("%i", &n);
        FillRand(mas, MAX, n);
        break;
      case '2':
        FillIncr(mas, MAX);
        break;
      case '3':
        FillDecr(mas, MAX);
        break;
      case '4':
        OutMas(mas, MAX);
        break;
      case '5':
        GetMinMax(mas, MAX, &mi, &ma);
        printf("Min = %i, max = %i\n", mi, ma);
        break;
      case '6':
        printf("Average is %f\n", GetAverage(mas, MAX));
        break;
      case '7':
        printf("A:");
        scanf("%i", &a);
        printf("B:");
        scanf("%i", &b);
        FillWithStep(mas, MAX, a, b);
        break;
      case '8':
        Reverse(mas, MAX);
        break;
      case '9':
        GetMaxDigitSum(mas, MAX);
        break;
      case 'a':
        PrintOutPrime(mas, MAX);
        break;
      case 'b':
        printf("There are %i simmetrical numbers in the massive\n", CountSimmetrical(mas, MAX));
        break;
      default:
        printf("Invalid choice\n");
    }
  }
}
