#include<stdio.h>
struct Points{
	int x;
	int y;
};

void main()
{
	int N;
	scanf("%d", &N);
	struct Points point_array[N];
	for(int i = 0; i < N; i++){
		scanf("%d %d", &point_array[i].x, &point_array[i].y);
	}
	int i;
	int j;
	//printf("%lld", 800000 * 800000 * 2);
	
	for(i = 0; i < N; i++)
	{
		int min_distance=-1;
		int tmp;
		int  short_num = 0;
		for(j = 0; j < N; j++)
		{
			if(i!=j)
			{	
			//long long tmp;
			tmp = ((point_array[i].x - point_array[j].x)
				* (point_array[i].x - point_array[j].x)) 
				+ 
				((point_array[i].y - point_array[j].y)
				* (point_array[i].y - point_array[j].y));
			
			if(tmp < min_distance || min_distance == -1) 
			{
				min_distance = tmp;
				short_num = j;
			}
			}
		//printf("%d\n", short_num);
		}
		printf("%d\n", short_num);
	}
	
}
