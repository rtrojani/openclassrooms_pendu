#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH_MAX 25

int		pick_nb(FILE *dictionary, int secret_word_nb)
{
	char	c;
	int		word_count;

	word_count = 0;
	while (c != EOF)
	{
		c = fgetc(dictionary);
		if (c == '\n')
			word_count++;
	}
	rewind(dictionary);
	srand(time(NULL));
	secret_word_nb = rand() % word_count;
	return (secret_word_nb);
}

void	put_backslash_zero(char *secret_word)
{
	int i;

	i = 0;
	while (i <= LENGTH_MAX)
	{
		if (secret_word[i] == '\n')
			secret_word[i] = '\0';
		i++;
	}
}

int		pick_word(char *secret_word)
{
	FILE	*dictionary;
	int		secret_word_nb;
	char	c;

	dictionary = NULL;
	secret_word_nb = 0;
	dictionary = fopen("dictionnaire.txt", "r");
	if (dictionary == NULL)
	{
		printf("Erreur, l'ouverture du dictionnaire à échoué.");
		return(0);
	}
	else
	{
		secret_word_nb = pick_nb(dictionary, secret_word_nb);
		while (secret_word_nb > 0)
		{
			c = fgetc(dictionary);
			if (c == '\n')
				secret_word_nb--;
		}
		fgets(secret_word, LENGTH_MAX, dictionary);
		fclose(dictionary);
		put_backslash_zero(secret_word);
		return (1);
	}
}

/*int main(void)
{
	char c[LENGTH_MAX] = {0};
	if (pick_word(c) == 1)
		printf("%s\n", c);
	else
		printf("La sélection du mot à échoué.");
	return (0);
}*/
