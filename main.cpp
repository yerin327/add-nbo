#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[])
{
		int i = argc;

		if ( argc < 3 ) {
					printf("Usage : %s <file1> <file2>\n", argv[0]);
					return 0;
		}

		uint8_t buffer1[256];
		uint8_t buffer2[256];

		FILE *fd1, *fd2;

		fd1 = fopen(argv[1], "rb");
		fd2 = fopen(argv[2], "rb");

		fread(buffer1, sizeof(buffer1), 1, fd1);
		fread(buffer2, sizeof(buffer2), 1, fd2);

		uint32_t* p1 = reinterpret_cast<uint32_t*>(buffer1);
		uint32_t* p2 = reinterpret_cast<uint32_t*>(buffer2);

		uint32_t n1 = ntohl(*p1); 
		uint32_t n2 = ntohl(*p2);

		uint32_t sum = n1 + n2;

		printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, sum, sum);

		fclose(fd1);
		fclose(fd2);
		return 0;
}
