int ft_isalnum (int c)
{
   int is_alpha;
   int is_digit;

   is_alpha = (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'); 
   is_digit = (c >= '0' && c <= '9');
   return (is_alpha || is_digit);
} 