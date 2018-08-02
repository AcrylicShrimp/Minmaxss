
#include <cstdio>
#include <cstdlib>

void cpy(const int *src, int *dest, int len)
{
	for (int i = 0; i < len; ++i)
		dest[i] = src[i];
}

int main()
{
	int src = 100;
	int dest = 0;

	cpy(&src, &dest, 1);

	printf("%d\n", dest);

	return 0;
}