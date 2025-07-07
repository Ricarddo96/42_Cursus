#include "pipex.h"

char *obtain_uncut_path(char **env)
{
    int i;
    int j;
    int k;
    int env_len;
    char *path = NULL;
    
    i = 0;
    j = 5;
    k = 0;
    env_len = 0;
    while (env[i] && (ft_strncmp(env[i], "PATH=", 5) != 0))
        i++;
    if (!env[i])
    {
        perror("PATH no encontrado");
        return(NULL);
    }
    env_len = ft_strlen(env[i]);
    path = malloc((env_len - 5 + 1) * sizeof(char));
    if (!path)
        return (NULL);
    while (j < env_len)
        path[k++] = env[i][j++]; 
    path[k] = '\0';
    return (path);
}
