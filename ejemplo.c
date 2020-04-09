// alea.c: Ejemplo de ficheros de acceso aleatorio.
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
 
struct stRegistro {
   char valido;  // Campo que indica si el registro es válido S->Válido, N->Inválido
   char nombre[34];
   int dato[4];
};

int Menu();
void Leer(struct stRegistro *reg);
void Mostrar(struct stRegistro *reg);
void Listar(long n, struct stRegistro *reg);
long LeeNumero();
void Empaquetar(FILE **fa);
 
int main()
{
   struct stRegistro reg;
   FILE *fa;
   int opcion;
   long numero;
   fa = fopen("alea.dat", "r+b");          // Este modo permite leer y escribir
   if(!fa) fa = fopen("alea.dat", "w+b");  // si el fichero no existe, lo crea.
   do {
      opcion = Menu();
      switch(opcion) {
         case '1': // Añadir registro
            Leer(&amp;reg);
            // Insertar al final:
            fseek(fa, 0, SEEK_END);
            fwrite(&amp;reg, sizeof(struct stRegistro), 1, fa);
            break;
         case '2': // Mostrar registro
            system("cls");
            printf("Mostrar registro: ");
            numero = LeeNumero();
            fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
            fread(&amp;reg, sizeof(struct stRegistro), 1, fa);
            Mostrar(&amp;reg);
            break;
         case '3': // Eliminar registro
            system("cls");
            printf("Eliminar registro: ");
            numero = LeeNumero();
            fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
            fread(&amp;reg, sizeof(struct stRegistro), 1, fa);
            reg.valido = 'N';
            fseek(fa, numero*sizeof(struct stRegistro), SEEK_SET);
            fwrite(&amp;reg, sizeof(struct stRegistro), 1, fa);
            break;
         case '4': // Mostrar todo
            rewind(fa);
            numero = 0;
            system("cls");
            printf("Nombre                             Datos\n");
            while(fread(&amp;reg, sizeof(struct stRegistro), 1, fa))
               Listar(numero++, &amp;reg);
            system("PAUSE");
            break;
         case '5': // Eliminar marcados
            Empaquetar(&amp;fa);
            break;
      }
   } while(opcion != '0');
   fclose(fa);
   return 0;
}
 
// Muestra un menú con las opciones disponibles y captura una opción del usuario
int Menu()
{
   char resp[20];
   do {
      system("cls");
      printf("MENU PRINCIPAL\n");
      printf("--------------\n\n");
      printf("1- Insertar registro\n");
      printf("2- Mostrar registro\n");
      printf("3- Eliminar registro\n");
      printf("4- Mostrar todo\n");
      printf("5- Eliminar registros marcados\n");
      printf("0- Salir\n");
      fgets(resp, 20, stdin);
   } while(resp[0] &lt; '0' &amp;&amp; resp[0] &gt; '5');
   return resp[0];
}
 
// Permite que el usuario introduzca un registro por pantalla
void Leer(struct stRegistro *reg)
{
   int i;
   char numero[6];
   system("cls");
   printf("Leer registro:\n\n");
   reg-&gt;valido = 'S';
   printf("Nombre: ");
   fgets(reg-&gt;nombre, 34, stdin);
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   for(i = strlen(reg-&gt;nombre)-1; i &amp;&amp; reg->nombre[i] &lt; ' '; i--)
      reg-&gt;nombre[i] = 0;
   for(i = 0; i &lt; 4; i++) {
      printf("Dato[%1d]: ", i);
      fgets(numero, 6, stdin);
      reg-&gt;dato[i] = atoi(numero);
   }
}
 
// Muestra un registro en pantalla, si no está marcado como borrado
void Mostrar(struct stRegistro *reg)
{
   int i;
   system("cls");
   if(reg-&gt;valido == 'S') {
      printf("Nombre: %s\n", reg-&gt;nombre);
      for(i = 0; i &lt; 4; i++) printf("Dato[%1d]: %d\n", i, reg-&gt;dato[i]);
   }
   system("PAUSE");
}
 
// Muestra un registro por pantalla en forma de listado,
// si no está marcado como borrado
void Listar(long n, struct stRegistro *reg)
{
   int i;
   if(reg-&gt;valido == 'S') {
      printf("[%6ld] %-34s", n, reg-&gt;nombre);
      for(i = 0; i &lt; 4; i++) printf(", %4d", reg-&gt;dato[i]);
      printf("\n");
   }
}
 
// Lee un número suministrado por el usuario
long LeeNumero()
{
   char numero[6];
   fgets(numero, 6, stdin);
   return atoi(numero);
}
 
// Elimina los registros marcados como borrados
void Empaquetar(FILE **fa)
{
   FILE *ftemp;
   struct stRegistro reg;

   ftemp = fopen("alea.tmp", "wb");
   rewind(*fa);
   while(fread(&amp;reg, sizeof(struct stRegistro), 1, *fa))
      if(reg.valido == 'S')
         fwrite(&amp;reg, sizeof(struct stRegistro), 1, ftemp);
   fclose(ftemp);
   fclose(*fa);
   remove("alea.bak");
   rename("alea.dat", "alea.bak");
   rename("alea.tmp", "alea.dat");
   *fa = fopen("alea.dat", "r+b");
}