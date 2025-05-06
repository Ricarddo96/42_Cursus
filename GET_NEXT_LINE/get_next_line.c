#include	"get_next_line.h"

//la idea es que get_next_line lea un buffer concreto, de ese buffer se recorte lo que es una linea y se actualice el buffer para la siguiente llamada 


char *get_next_line(int fd)
{
	static char *buffer;
	char *buffer_temp;
	char *suma_buffers;
	char *linea;
	int bytes_leidos;
	int salto;
	int post_salto;

	// inicializamos los char * para que no tengan valor basura
	buffer_temp = NULL;
	suma_buffers = NULL;
	linea = NULL;

	if (buffer != NULL) // copiamos si hay algo en el buffer (el sobrante de la llamada anterior), en el buffer temp antes de que sobreescriba el buffer 
		buffer_temp = ft_strdup(buffer);

	 free(buffer);
	buffer = malloc(BUFFER_SIZE + 1);// reservamos para el nuevo buffer

	if (!buffer) 
	{
        free(buffer_temp);
        return (NULL);
    }

	bytes_leidos = read(fd, buffer, BUFFER_SIZE); //se actualiza el buffer
	buffer[bytes_leidos] = '\0';
	
	suma_buffers = ft_strjoin(buffer_temp, buffer); // si buff_temp no es nulo se concatenan, si no buscamos el salto de linea en el buffer normal
	free(buffer_temp);
		
	if (!suma_buffers) // Si ft_strjoin retornó NULL (fallo de malloc interno)
    {
        free(buffer); // Debes liberar el buffer que se usó para la lectura (el que asignaste antes con malloc)
        buffer = NULL; // Asegura que el buffer estático esté NULL
        return (NULL); // Retorna NULL para indicar el error
    }
	
	salto = ft_strlen(suma_buffers, 2);
	linea = ft_substr(suma_buffers, 0, (salto)); //sacamos la substring hasta el \n y la metemos en la linea
	post_salto = ft_strlen(suma_buffers, 1) - (salto); // longitud desde el salto hasta el final
	free(buffer);
	
	buffer = ft_substr(suma_buffers, salto, post_salto); //actualizamos el buffer desde el \n hasta el final

	return (linea);
}

/* 
char *get_next_line(int fd)
{


} */

int main()
{
	
	int fd = open("holi.txt", O_RDONLY);
	char *linea;

	linea = get_next_line(fd);
	printf("Linea: %s\n", linea);
	free(linea);
	linea = get_next_line(fd);
	printf("Linea: %s\n", linea);
	free(linea);
	linea = get_next_line(fd);
	printf("Linea: %s\n", linea);
	free(linea);
	linea = get_next_line(fd);
	printf("Linea: %s\n", linea);
	free(linea);
	linea = NULL;
	close(fd);
	return (1);
}