#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH_MAX 25

int		pick_word(char *secret_word)

{
	FILE	*dictionary = NULL;
	int		word_count = 0;
	int		secret_word_nb;
	char	c;

	dictionary = fopen("dictionnaire.txt", "r");
	if (dictionary == NULL)
		printf("Erreur, l'ouverture du dictionnaire à échoué.");
	else
	{
		while (c != EOF)
		{
			c = fgetc(dictionary);
			if (c == '\n')
				word_count++;
		}
		rewind(dictionary);
		srand(time(NULL));
		secret_word_nb = rand() % word_count;
		while (secret_word_nb > 0)
		{
			c = fgetc(dictionary);
			if (c == '\n')
				secret_word_nb--;
		}
		if (fgets(secret_word, LENGTH_MAX, dictionary) = 1);
			fclose(dictionary);
			return (1);
		else
			fclose(dictionary);
			printf("La séléction du mot a échoué.\n");
			return (0);
	}
	return 
}

int main(void)
{
	char c[LENGTH_MAX] = {0};
	pick_word(c);
	printf("%s\n", c);
	return (0);
}
