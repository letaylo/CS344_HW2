void msort(int array[], int size)
{
	int middle = size / 2;
	if(size = 1)
	{
		break;
	}
	else
	{
		int temp1[middle];
		int temp2[size - middle];
		for(int i = 0; i < middle; i++)
		{
			temp1[i] = array[i];
		}
		for(int j = 0; j < size - middle; j++)
		{
			temp2[j] = array[j + middle];
		}
		msort(temp1, middle);
		msort(temp2, size - middle);
	}
	int k = 0;
	int n = 0;
	int p = 0;
	while(k < middle && n < size - middle)
	{
		if(temp1[k] <= temp2[n])
		{
			array[p] = temp1[k];
			k++;
		}
		else
		{
			array[p] = temp2[n];
			n++;
		}
		p++;
	}
	
	while (k < middle)
	{
		array[p] = temp1[k];
		k++;
		p++;
	}
	while(n < size - middle)
	{
		array[p] = temp2[k];
		n++;
		p++;
	}	
}
