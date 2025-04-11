#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
     size_t i = 0;
     size_t j;

     if (little[0] == '\0')
          return (big);
     while (i < len && big[i] != '\0')
     {
          if (big[i] == little[0])
          {
               j = 1;
               while ((i + j) < len && big[i + j] == little[j])
               {
                    j++;
               }
               if (little[j] == '\0')
                    return (big + i);
          }
          i++;
     }
     return NULL;
}
