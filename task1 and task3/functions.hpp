#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

bool isEven(int value)
{
  return (value & 1) == 0;
}

void sort(int* arrayToSort, const size_t size)
{
  if (!arrayToSort)
  {
    throw std::invalid_argument("You must input array that contains something");
  }

  if (size <= 0)
  {
    throw std::invalid_argument("The size of array must be positive");
  }

  for (size_t i = 0; i < size - 1; i++)
  {
    int min = INT_MAX;
    size_t indexOfMinElement;
    for (size_t j = i + 1; j < size; j++)
    {
      if (arrayToSort[j] < min)
      {
        min = arrayToSort[j];
        indexOfMinElement = j;
      }
    }

    if (min < arrayToSort[i])
    {
      int temp = arrayToSort[i];
      arrayToSort[i] = arrayToSort[indexOfMinElement];
      arrayToSort[indexOfMinElement] = temp;
    }
  }
}

#endif
