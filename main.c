#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char* argv[])
{
  if (argc != 2) {
    printf("One argument: unsigned int!");
    return -1;
  }

  clock_t start = clock();

  unsigned int param = atoi(argv[1]);

  if (param == 1) {
    printf("The 1. prime is: 2");
    return 0;
  }

  if (param == 2) {
    printf("The 2. prime is: 3");
    return 0;
  }

  unsigned int counter = 1;
  unsigned int number = 3;
  unsigned int i;
  short int isprime = TRUE;
  unsigned int* primes = malloc(param * sizeof(int));

  if (param <= 2) {
    return -2;
  }

  primes[0] = 3;

  while (counter != param) {
    number += 2;
    isprime = TRUE;

    for (i = 0; i < counter; i++) {
      if (number % primes[i] == 0) {
        isprime = FALSE;
        break;
      }
    }

    if (isprime) {
      primes[counter] = number;
      counter++;
    }
  }

  printf("The %u prime is: %u\n", param, number);
  free(primes);

  clock_t end = clock();
  double secs = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Elapsed secs: %f\n", secs);

  return 0;
}
