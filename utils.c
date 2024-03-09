/**
 * @brief checks if a character is a ascii digit
 * 
 * @param c character that is going to be checked
 * @returns 1 if a character is a number 0 if its not
 */
int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}