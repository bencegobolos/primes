#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define ERROR "Error: "

/*
 * This program is for finding the N-th prime number.
 * Waits for one argument: N (unsigned int).
 * Returns the N-th prime.
 */

int main(int argc, char* argv[])
{
  // Input handling.
  if (argc != 2) {
    printf("%sOne argument: unsigned int!\n", ERROR);
    return -1;
  }

  // Input parameter.
  unsigned int param = atoi(argv[1]);

  // Early return when param is 1.
  if (param == 1) {
    printf("The 1. prime is: 2\n");
    return 0;
  }

  // Start measuring time.
  clock_t start = clock();

  // Array to store prime numbers.
  unsigned int* primes = malloc(param * sizeof(int));
  // Is the number a prime?
  short isprime = TRUE;
  // Loop variable.
  unsigned int i;
  // How many primes we have found.
  unsigned int counter = 2;
  // The number that is being checked.
  unsigned int number = 3;
  // The number's half. It is for optimization purpose.
  unsigned int number_third;

  // Primes' array initialization.
  primes[0] = 2;
  primes[1] = 3;

  while (counter < param) {
    number += 2;
    number_third = number/3;
    isprime = TRUE;

    for (i = 1; i < counter; i++) {
      if (primes[i] > number_third)
        break;

      if (!(number % primes[i])) {
        isprime = FALSE;
        break;
      }
    }

    if (isprime) {
      primes[counter] = number;
      counter++;
    }
  }

  printf("The %u. prime is: %u\n", param, number);
  free(primes);

  // Stop measuring time.
  clock_t end = clock();
  double secs = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Elapsed secs: %f\n", secs);

  return 0;
}
