#include <stdio.h>

int	main()
{
	FILE *infile;
	infile = fopen("myfile.txt", "w");
	if (!infile)
	{
		printf("%s", "file not opened");
		return (0);
	}
	
	fprintf(infile, "%s", "line 1\n");
	fprintf(infile, "%c", 117);
	fprintf(infile, "%s", "line 2\n");
	fclose(infile);
	return (0);
}
