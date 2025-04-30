#include	"get_next_line.h"

//la idea es que get_next_line lea un buffer concreto, de ese buffer se recorte lo que es una linea y se actualice el buffer para la siguiente llamada 


char *update_buffer(char *buffer)
{
	while (*buffer != '\n')
	{
		buffer++;		
	}
	buffer++;
	return (buffer);
}

char *get_next_line(int fd)
{
	static char *buffer; // buffer que va a llenarse con lo de read
	char *buffer_temp;
	char *linea; // la linea que se va a imprimir que se tiene que limpiar
	unsigned int i;
	
	i = 0;
	buffer_temp = buffer;
	if (buffer == NULL)
	{
		buffer = malloc(42); // aqui el buffer nos lo tendrian que dar externamente, pero le ponemos uno para probar
	}
	read(fd, buffer, 42);
	linea = malloc(42);

	while(buffer[i] != '\n')
	{
		linea[i] = buffer[i];
		i++;
	}
	buffer_temp = malloc(ft_strlen(buffer) - i);
	buffer_temp = ft_substr(buffer, i, (ft_strlen(buffer) - i));/// actualizo el buffer empezando desde i que es donde termina el anterior
	buffer = buffer_temp;
	linea[i] = '\0';
	return (linea);
}

int main()
{
	
	int fd = open("holi.txt", O_RDONLY);
	char *linea;

	linea = get_next_line(fd);
	printf("en la linea pone: %s\n", get_next_line(fd));
	free(get_next_line(fd));
	printf("en la siguiente linea pone: %s\n", get_next_line(fd));
	free(get_next_line(fd));
	printf("en la siguiente linea pone: %s\n", get_next_line(fd));
	free(get_next_line(fd));
	close(fd);
	return (1);
}