#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
	char content[80];
	int opening = 0;
	if((opening=open("VDK7MU.txt", O_RDWR)) < 0){
		printf("Nem letezik ilyen fajl!\n");
		return -1;
	}

	int sizeOfTxt = read(opening, content, sizeof(content));

	content[sizeOfTxt] = '\0';
	printf("txt content: \"%s\"\nbyteok szama: %d\n", content, sizeOfTxt);

	lseek(opening, 0, SEEK_SET);
	printf("A txt elejen van a mutato.\n");

	char addition[] = "VDK7MU mernokinformatikus";
	int add_new = write(opening, addition, sizeof(addition));
	printf("Ez lett hozzaadva: \"%s\"\nbyteok szama: %d\n", addition, add_new);

	close(opening);

	return 0;
}
