#include <stdio.h>

int	main()
{
	int x = 694269;
	int y = -42694;
	int z;
	char c1 = 'a';
	char c2;
	char c3;
	char *s1 = "Hello World";
	char *s2;
	char *s3;

	printf("\n-_-_-_-_-_ Printf test _-_-_-_-_-\n\n");

	printf("%%2d '694269' --> %2d!\n", x);
	printf("%%10d '-42694' --> %10d!\n", y);
	printf("%%6i '694269' --> %6i!\n", x);
	printf("%%7u '694269' --> %7u!\n", x);
	printf("%%1x '694269' --> %1x!\n", x);
	printf("%%20X '694269' --> %20X!\n", x);
	printf("%%20c 'a' --> %20c!\n", c1);
	printf("%%20s 'Hello World' --> %20s!\n", s1);

	printf("\n----------Flag '-' Flag----------\n\n");

	printf("%%-d '694269' --> %-d!\n", x);
	printf("%%--------10d '694269' --> %--------10d!\n", x);
	printf("%%-6d '694269' --> %-6d!\n", x);
	printf("%%-7i '694269' --> %-7i!\n", x);
	printf("%%-8u '694269' --> %-8u!\n", x);
	printf("%%-9x '694269' --> %-9x!\n", x);
	printf("%%-20X '694269' --> %-20X!\n", x);
	printf("%%-20c 'a' --> %-20c!\n", c1);
	printf("%%-20s 'Hello World' --> %-20s!\n", s1);


	printf("\n----------Flag '0' Flag----------\n\n");

	printf("%%02d '694269' --> %02d!\n", x);
	printf("%%0000000010d '694269' --> %0000000010d!\n", x);
	printf("%%010d '-42694' --> %010d!\n", y);
	printf("%%06i '694269' --> %06i!\n", x);
	printf("%%07u '694269' --> %07u!\n", x);
	printf("%%01x '694269' --> %01x!\n", x);
	printf("%%020X '694269' --> %020X!\n", x);

	printf("\n----------Flag '.' Flag----------\n\n");

	printf("%%.0d '694269' --> %.0d!\n", x);
	printf("%%.5d '694269' --> %.5d!\n", x);
	printf("%%.6d '694269' --> %.6d!\n", x);
	printf("%%.7i '694269' --> %.7i!\n", x);
	printf("%%.8u '694269' --> %.8u!\n", x);
	printf("%%.9x '694269' --> %.9x!\n", x);
	printf("%%.20X '694269' --> %.20X!\n", x);
	printf("%%.8s 'Hello World' --> %.8s!\n", s1);
	printf("%%.20s 'Hello World' --> %.20s!\n", s1);
	printf("%%.0s 'Hello World' --> %.0s!\n", s1);
	printf("%%.1s 'Hello World' --> %.1s!\n", s1);

	printf("\n----------Flag '*' Flag----------\n\n");

	printf("%%*d '694269' --> %*d!\n", 0, x);
	printf("%%*5d '694269' --> %*d!\n", 5, x);
	printf("%%*6d '694269' --> %*d!\n", 6, x);
	printf("%%*7i '694269' --> %*i!\n", 7, x);
	printf("%%*8u '694269' --> %*u!\n", 8, x);
	printf("%%*9x '694269' --> %*x!\n", 9, x);
	printf("%%*20X '694269' --> %*X!\n", 20, x);
	printf("%%*20s 'Hello World' --> %*s!\n",20, s1);

	printf("\n----------Flag n.n comb----------\n\n");

	printf("%%20.15d '694269' --> %20.15d!\n",x);
	printf("%%20.15d '-42694' --> %20.15d!\n",y);
	printf("%%20.8s 'Hello World' --> %20.8s!\n", s1);

	printf("\n----------Flag -.  comb----------\n\n");

	printf("%%-20.15d '694269' --> %-20.15d!\n",x);
	printf("%%-20.15d '-42694' --> %-20.15d!\n",y);
	printf("%%-20.8s 'Hello World' --> %-20.8s!\n", s1);

	printf("\n----------Flag 0.  comb----------\n\n");

	printf("%%020.15d '694269' --> %020.15d!\n",x);
	printf("%%021.15d '-42694' --> %021.15d!\n",y);

	printf("\n----------Flag -*  comb----------\n\n");

	printf("%%-*d '694269' --> %-*d!\n", 20, x);
	printf("%%-*s 'Hello World' --> %-*s!\n",20, s1);
	printf("%%0*d '694269' --> %0*d!\n", 20, x);
	printf("%%*.10d '694269' --> %*.10d!\n", 20, x);
	printf("%%*.8s 'Hello World' --> %*.8s!\n", 20, s1);
	printf("%%-*.10d '694269' --> %-*.10d!\n", 20, x);
	printf("%%-*.8s 'Hello World' --> %-*.8s!\n", 20, s1);

	return (0);
}
