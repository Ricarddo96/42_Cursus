#include "libft.h"

const char *ft_strnstr(const char *big, const char *little, size_t len)
{
     size_t i;
     size_t j;
     size_t little_len;

     i = 0;
     little_len = ft_strlen(little);
     if (little[0] == '\0')
          return (big);
     while (i < len && big[i] != '\0')
     {
          if (big[i] == little[0])
          {
               j = 1;
               while ((i + j) < len && j < little_len && big[i + j] == little[j])
               {
                    j++;
               }
               if (j == little_len)
                    return (big + i);
          }
          i++;
     }
     return NULL;
}
