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
