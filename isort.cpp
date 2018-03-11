void isort(int array[], int size)
{
	int value;
	for (int i = 0; i < size; i++)
	{
		int j = i - 1;
		value = array[i];
		while(j >= 0 && arr[j] > value)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = value;
	}
}
