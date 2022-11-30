#include "main.h"

//Esta es una función que retornara el "path" del respectivo comando, por lo que
//retorna un char
char *route(char *c){
  char *path, *path_copy, *token_ruta, *file_path;
  int c_length, d_length;
  struct stat buffer;
  
  //Generamos el "path", este path se encuentra separado por ":/", es decir
  //Una posible ruta puede ser "/sbin:/usr/sbin:/bin:/usr/bin:/usr/local/bin"
  //Los dos puntos representan una separación, el path representa todas las rutas
  //Que el shell toma para encontrar si el respectivo comando existe o no
  path = getenv("PATH");
  
  //Guardo una copia de path en path_copy con la ayuda de la función strdup() que
  //me permite realizar lo anterior
  path_copy = strdup(path);
  
  //Guardo el length del comando ingresado
  c_length = strlen(c);

  //Vamos a guardar cada una de las posibles rutas para nuestro comando, recordemos
  //que este se encuentra separado por ":"
  token_ruta = strtok(path_copy, ":");

  //Y ahora probaremos cual es el path que funciona con nuestro respectivo comando
  //Usamos el while para probar cada ruta uwu.
  while (token_ruta != NULL){
    d_length = strlen(token_ruta);
    
    //Le otorgamos su respectiva tamano de memoria, siendo esta el length del
    //comando con su directorio y +2 por lo que nosotros le agregaremos para que
    //sirva como una ruta
    file_path = malloc(c_length + d_length + 2);

    //Concatenamos lo que se encuentra en token_ruta a file_path
    strcpy(file_path, token_ruta);
    //Le agregamos un slash
    strcat(file_path, "/");
    //Le agregamos el respetivo comando
    strcat(file_path, c);
    //Le agregamos el null terminator que es "\0"
    //Básicamente avisa que el comando fue escrito :P, como el enter
    strcat(file_path, "\0");

    //Ahora si probaremos si el comando en el respectivo directorio existe o no
    //Esto con ayuda de la función stat
    //Si esta retorna 0, signfica que existe, sino, significa lo contrario
    if (stat(file_path, &buffer) == 0){
      free(path_copy);

      return (file_path);

    } else {
      free(file_path);
      //Seguimos con la siguiente ruta porque no funcionó
      token_ruta = strtok(NULL, ":");
    }

  }
  
  //Ningunó funcionó, por lo que retornamos un NULL :P
  free(path_copy);
  return (NULL);

  

}
