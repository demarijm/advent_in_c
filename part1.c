#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getCalibrationValue(char *row)
{

  int total = 0;
  int length = strlen(row);

  char allNumbers[50] = {};
  int arraySize = 0;

  // Loop through the row and add all the numbers to the array
  for (int i = 0; i < length; i++)
  {
    if (isdigit(row[i]))
    {
      allNumbers[arraySize++] = row[i];
    }
  }



  if (arraySize == 0)
  {
    printf("No numbers in the row\n");
    return 0;
  }
  char firstNumber = allNumbers[0];

  int rowTotal = 0;

  if (arraySize == 1)
  {
    char bothNumbers[3] = {firstNumber, firstNumber, '\0'};
    printf("Only one number in the row, total is %d\n", atoi(bothNumbers));
    return atoi(bothNumbers);
  }

  char lastNumber = allNumbers[arraySize - 1];
  printf("Everything in the row: %s\n", row);
  printf("First number: %c\n", firstNumber);
  printf("Last number: %c\n", lastNumber);
  char bothNumbers[3] = {firstNumber, lastNumber, '\0'};
  int bothNumbersInt = atoi(bothNumbers);
  printf("Both numbers int: %d\n", bothNumbersInt);
  return bothNumbersInt;
}

int main()
{
  char *filename = "input.txt";
  FILE *file = fopen(filename, "r");

  if (file == NULL)
  {
    printf("Could not open file %s", filename);
    return 1;
  }

  const unsigned MAX_LENGTH = 256;
  char row[MAX_LENGTH];

  // make an array that is the size of the number of lines in the file
  int arraySize = 0;
  // Init the total Sum of the numbers in the file
  int totalCount = 0;
  // Init the array that will hold all the numbers
  int myNumbers[5000] = {};

  int lineCount = 0;

  // Loop through the file and add all the numbers to the array
  while (fgets(row, MAX_LENGTH, file) != NULL)
  {
      int rowTotal = getCalibrationValue(row);
      totalCount += rowTotal;
      printf("Total so far: %d\n", totalCount);
      lineCount++;
  }

  printf("\n");
  printf("\n");
  printf("\n");
  printf("Total lines: %d\n", lineCount);
  printf("Total Sum: %d", totalCount);
  printf("\n");
  fclose(file);

  return 0;
}
