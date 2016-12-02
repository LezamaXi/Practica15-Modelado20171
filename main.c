#include "main.h"

int main(int argc, char const **argv)
{
  if (argc < 3) {
    imprime_instrucciones();
    return -1;
  }

  
  word *palabras;
  word* auxiliar_palabras;
  const char *limitantes = "\n ,.-";
  char *token;
  char * line = NULL;
  char* str_aux;
  FILE *f_output = fopen(argv[argc - 1], "w");
  FILE * fp;
  int index_word = -1;
  int indice_ultimo_agreg = -1;
  size_t len = 0;
  ssize_t lee;
  
  
  for (int i = 1; i < argc - 1 ; i++) {
    palabras = calloc(MAX, sizeof(word));

    fp = fopen(argv[i], "r");
    if (fp == NULL)
      return -1;

    if (i == 1) {
      fprintf(f_output, "Nombre del archivo\tPalabra más repetida\tNúmero de repeticiones\n");
      printf("Nombre del archivo\tPalabra más repetida\tNúmero de repeticiones\n");
    }

    indice_ultimo_agreg = -1;
    index_word = -1;

    while ((lee = getline(&line, &len, fp)) != -1) {
      token = strtok(line, limitantes);

      while (token != NULL) {
        str_aux = (char*)malloc(strlen(token) * sizeof(char));
        strcpy(str_aux, token);


        int index = -1;
        for (int i = 0; i < MAX; i++) {
          if (palabras[i].s != NULL && strcmp(palabras[i].s, str_aux) == 0) {
            index = i;
            break;
          }
        }

        index_word = index;

        if (index_word == -1) {
          indice_ultimo_agreg++;

          word aux;
          aux.s = str_aux;
          aux.n = 1;
          palabras[indice_ultimo_agreg] = aux;
        } else {
          palabras[index_word].n++;
        }
        token = strtok(NULL, limitantes);
      }
    }

    fclose(fp);
    word* aux_p = NULL;
    int aux_n = -1;
    for (int i = 0; i < MAX; i++) {
      if (palabras[i].s == NULL)
        break;
      if (palabras[i].n > aux_n) {
        aux_p = &palabras[i];
        aux_n = palabras[i].n;
      }
    }
    auxiliar_palabras = aux_p;
    fprintf(f_output, "%s\t\t\t%s\t\t\t%d\n", argv[i], auxiliar_palabras->s, auxiliar_palabras->n);
    printf("%s\t\t\t%s\t\t\t%d\n", argv[i], auxiliar_palabras->s, auxiliar_palabras->n);
  }
  printf("Se guardó el resultado en el archivo %s\n", argv[argc - 1]);
  fclose(f_output);

  return 0;
}

/* ------ Aquí va la implementación de tus funciones ------ */
void imprime_instrucciones()
{
  printf("Error: El formato de entrada es incorrecto\n");
  printf("Uso: cuenta_mala <archivo> [<archivo> [<archivo> ...]] <archivo>\n");
}


