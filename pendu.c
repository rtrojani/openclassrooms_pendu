#include <stdio.h>
#include <stdlib.h>

char	ask_char(void);
int		pick_word(char *secret_word);

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
	char	secret_word[25] = {0};
	char	*clone_word;
	int		i = 0;
	int		hint_count = 10;
	int		found = 0;
	int		good_answer = 0;

	printf("*****Bienvenue dans le pendu !*****\n\n");
	pick_word(secret_word);
	clone_word = malloc(sizeof(char) * ft_strlen(secret_word));
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
	return 0;
}
