void isort(int array[], int size)
{
	int value;
	for (int i = 0; i < size; i++)
	{
		int j = i - 1;
		value = array[i];
		while(j >= 0 && array[j] > value)
		{
			array[j+1] = array[j];
			j = j-1;
		}
		array[j+1] = value;
	}
}
