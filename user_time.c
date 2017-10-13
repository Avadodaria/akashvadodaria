#include<stdio.h>
#include<unistd.h>
#include<linux/unistd.h>
#include<linux/time.h>

int main()
{
	int a;
	struct timespec xyz ;
	a = syscall(326,&xyz);
	if(a==0)
	{
		printf("%ld\n",xyz.tv_sec);
		printf("%ld\n",xyz.tv_nsec);
	}
	else
	{
		printf("Error\n");
	}
	return 0;
}
