#include <stdio.h>
#include <stdlib.h>

int		check_char(char c)
{
	while (getchar() != '\n')
	{
		while (getchar() != '\n');
		return (0);
	}
	while (!((c >= 65 && c <= 90) || (c = 97 && c <= 122)))
		return (0);
	return (1);
}

char	ask_char(void)
{
	char	given_char;

	printf("Choisissez une lettre :\n");
	given_char = getchar();
	while (check_char(given_char) != 1)
	{
		printf("Votre saisie est invalide.\nChoisissez une lettre :\n");
		given_char = getchar();
	}
	if (given_char >= 97 && given_char <= 122)
		given_char = given_char - 32; 
	printf("Vous avez choisi la lettre %c.\n\n", given_char);
	return (given_char);
}

int		hangman_game(char *secret_word, char *clone_word)
{
	char	c;
	int		i;
	int		good_answer;

	c = ask_char();
	i = 0;
	good_answer = 0;
	while (secret_word[i] != '\0')
	{
		if (secret_word[i] == c)
		{
			clone_word[i] = secret_word[i];
			good_answer = 1;
		}
		i++;
	}
	return (good_answer);
}

int		main(void)
{
	char	*secret_word = "TOPINAMBOUR";
	char	clone_word[7] = {0};
	int		i = 0;
	int		hint_count = 10;
	int		found = 0;
	int		good_answer = 0;

	printf("*****Bienvenue dans le pendu !*****\n\n");
	while (secret_word[i] != '\0')
	{
		clone_word[i] = '*';
		i++;
	}
	clone_word[i] = '\0';

	while (hint_count > 0 && found == 0)
	{
		printf("%s\n", clone_word);
		printf("Il vous reste %d tentative(s).\n", hint_count);
		good_answer = hangman_game(secret_word, clone_word);
		found = 1;
		i = 0;
		while (clone_word[i] != '\0')
		{
			if (clone_word[i] == '*')
				found = 0;
			i++;
		}
		if (good_answer == 0)
			hint_count--;
	}
	if (hint_count == 0)
			printf("Vous avez perdu !\nVous êtes pendu ! X(\n");
	else
		printf("Bravo, le mot mystère était bien %s !\n", clone_word);
	return (0);
}
