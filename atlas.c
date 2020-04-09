#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void cuerpocompleto(void);
void cara (void);
void infocara (int eleccion);
void mano(void);
void infomano (int eleccion);
void pierna (void);
void infopierna (int eleccion);
void intestinos(void);
void infopanza (int eleccion);
FILE *ficherocorazon,*ficherohigado,*ficheroestomago;
char infocorazon[2048]={"CORAZON: El corazon es el organo muscular principal del aparato circulatorio en todos los animales que poseen un sistema circulatorio (incluyendo todos los vertebrados)."};
char infohigado[2048]={"HIGADO: El higado es la mas voluminosa de las visceras y una de las mas importantes por su actividad metabolica. Es un organo glandular al que se adjudica funciones muy importantes, tales como la sintesis de proteínas plasmaticas, funcion desintoxicante, almacenaje de vitaminas y glucogeno, ademas de secrecion de bilis, entre otras."};
char infoestomago[2048]={"ESTOMAGO: El estomago es la primera porcion del aparato digestivo en el abdomen, excluyendo la pequeña porcion de esofago abdominal."};

int main (void)
{
	int variablecuerpo=0;
	system("cls");
	cuerpocompleto();
	printf("Eligue una parte del cuerpo: ");
	scanf("%i",&variablecuerpo);
	
   ficherocorazon = fopen( "corazon.dat", "w+" ); 
   fwrite( infocorazon, sizeof(char[2048]), 1, ficherocorazon );
   rewind( ficherocorazon);
   
   ficherohigado = fopen( "corazon.dat", "w+" ); 
   fwrite( infohigado, sizeof(char[2048]), 1, ficherohigado );
   rewind( ficherohigado);
   
   ficheroestomago = fopen( "corazon.dat", "w+" ); 
   fwrite( infoestomago, sizeof(char[2048]), 1, ficheroestomago );
   rewind( ficheroestomago);
   
   
	switch(variablecuerpo)
	{
		case 1:
			cara();
			printf("Eligue una parte de la cara: ");
			scanf("%i",&variablecuerpo);
			infocara (variablecuerpo);
		break;
		case 2:
			intestinos();
			printf("Eligue una parte de los intestinos: ");
			scanf("%i",&variablecuerpo);
			infopanza(variablecuerpo);
		break;
		case 3:
			mano();
			printf("Eligue una parte de la mano: ");
			scanf("%i",&variablecuerpo);
			infomano(variablecuerpo);
		break;
		case 4:
			pierna();
			printf("Eligue una parte de la pierna: ");
			scanf("%i",&variablecuerpo);
			infopierna (variablecuerpo);
		break;
	}
	
	return 0;
}

void cuerpocompleto(void)
{
	printf("                           `.                                       \n");
    printf("                        oo+++oo:                                    \n");
    printf("                      `y`     `oo                                   \n");
    printf("                      :s         h.                                 \n");
    printf("                     .y:    1    oo`                                \n");
    printf("                     +s          `y:                                \n");
    printf("                     `h:         y                                  \n");
    printf("                      `h-       y`                                  \n");
    printf("                       .d      `d`                                  \n");
    printf("                   `.-ooy      .y:.`                                \n");
    printf("               .o+:-`        `.-+ooo`                               \n");
    printf("              s-                    `:y-                            \n");
    printf("             -h`                       .h`                          \n");
    printf("             h-                         +o                          \n");
    printf("            -h                          `d`                         \n");
    printf("             s                            s                         \n");
    printf("           `d`                           .h                         \n");
    printf("           :s    `y`               -s     d.                        \n");
    printf("          `y:    sm:       2       +m     +o`                       \n");
    printf("         .y:    `m+o               y d     +s`                      \n");
    printf("         `d.     oo s               d.h:     :h`                    \n");
    printf("        `h-    `y+ h.                s`so     +s                    \n");
    printf("        s+    -y- -y                 d`  y.    s+                   \n");
    printf("      `s+   `so`  s                  o+  .y     y+                  \n");
    printf("   .ooo-   -y:    m`                 -h    +y.    oo+`              \n");
    printf(" +s `     +s`    :y                   d.    .y:  3  -+s:            \n");
    printf(" .om     .d`     s                    s      .d`    odo.            \n");
    printf(" -hoh:   h-      h.                   :s       s  +:hoy`            \n");
	printf(" moy hoy:h       m        .++o.       -y      `d-y+h hsh            \n");
    printf(" `shhydos`       m        m.`:h       .h       -yodsdyo.            \n");
    printf("   `-.``         m       .h  `m       .d        ```-:`              \n");
    printf("                 m        s   h-      .h                            \n");
    printf("                 y:      o    s       +o                            \n");
    printf("                 -h      y:   ++      d.                            \n");
    printf("                  m      m`   .h     `d                             \n");
    printf("                 .h     -h     d`     d                             \n");
    printf("                  s     h-     +o     h.                            \n");
    printf("                 h-    `m      `m     +o                            \n");
    printf("                .d      d.     :y  4  `d                            \n");
    printf("                :s      h.     :s      h.                           \n");
    printf("                -h     `d      .d      d`                           \n");
    printf("                 m`    +o       h:    .h                            \n");
    printf("                 y-   `d`       -h     o                            \n");
    printf("                 o    .d         m`   s                             \n");
    printf("                 :s   `d         m    h.                            \n");
    printf("                 -h   `d         m    d`                            \n");
    printf("                 :y   -y         d`   d`                            \n");
    printf("                 y:    o         y-   +o                            \n");
    printf("                 y    ++         y:   `h.                           \n");
    printf("                oo    s          s     y                            \n");
    printf("                `so:`os          `y `:os                            \n");
    printf("                   :+:              +:                              \n");
	return;
}

void cara (void)
{
     printf("                              .---::////:---.`                             \n");
     printf("                      .:+sssso+/:--.----:::/+osyys+-                       \n");
     printf("                  `:oo+:.`                        -oy/                     \n");
     printf("                -oo-`                                /h-                   \n");
     printf("              :y/`         ``                        `:m:--`               \n");
     printf("            `oy.        .-:-`                        .od+.-++-             \n");
     printf("          `+h/      `.-//:::.                         ``+/  `:o/`          \n");
     printf("         /o/`      -/:-.`             1                 -y     -o/         \n");
     printf("       `s/       .:.``-//:                               .-      :y.       \n");
     printf("      .y:       ..                               `---.:-          -h       \n");
     printf("     :s-            `..`                     `:/+/-.-..y.          h:      \n");
     printf("    +o`           .o+::://::::.            .++-`       `y-         .h-     \n");
     printf("   :s           `o/``/sso+/:-.`         -/+:`           .h          +h     \n");
     printf("  .d.           s:    ``:shhs+:-.`.-:///-`               y.      .- .N.    \n");
     printf("  oh           -h        `.-::/+oo+:..`                  y:      o/  d:    \n");
     printf("  .m.          .y                                       /+       /-  y/    \n");
     printf("   m:          o:                                       y.       :.  h.    \n");
     printf("   os          y`                                       ++          oo     \n");
     printf("   `d.         h                              3         /o.       +o`     \n");
     printf("   `d.        -s  .:++/-.-..`              .....-.-.      `s-     :s       \n");
     printf("   -yo+/      y. :::-.-//+++o/.         `-o+////++++o:     :+    :h:.      \n");
     printf("   y- `:o    :o       ````.``.. .      `:.```````    `     :o  .o/.-y.     \n");
     printf("   o/-  o/ `/o`    .-:o:+my/:.  +`    .   -:/d//d/:-`      .s://.`  h`     \n");
     printf("   o::. `+/+-      `` :hdms ./  `/    /` `:``hhhd. ``       -.` -: :s      \n");
     printf("   s-`s-               `..       +           `..`             `:/  s:      \n");
     printf("   h. .o+`                       +                          `:+-   h`      \n");
     printf("   s:  o++                       -                          s+::  `h 2     \n");
     printf("   `s: .s:                             `                    .h/` `o/       \n");
     printf("    `y. .o`                  `         ..                   +/  .o-        \n");
     printf("     -y` `o                 `/          -/                -`.  `s`         \n");
     printf("      -s/:d+                +s``        `y`               s``.:o.          \n");
     printf("        ...m.               .+/+:----/o-+-               .d++/-            \n");
     printf("           os                    .--.`   4               s/                \n");
     printf("           `d`                                          -d                 \n");
     printf("            o+          .o////:::::::://:/++/+`         h:                 \n");
     printf("            `d`          `.:oyo/::----:++++-.          +o                  \n");
     printf("             /s               -///++++/:.             /y                   \n");
     printf("              y+                `::::`              .yN-                   \n");
     printf("               ss`              `.````            `/d+h`                   \n");
     printf("               `ds/`               5             -yy. h                    \n");
     printf("               .y -oo:`                       `:ys-  `h                    \n");
     printf("               .s   `:os/.`                ``/yo.    .y                    \n");
     printf("               :o       ./+ooo+/:---:::/+osso:       -s                    \n");
     printf("               +/            `.-:/::::-.`            .y                    \n");
     printf("               s.                  6                 `o                    \n");
     printf("               `                                                           \n");
    return;
}

void mano(void)
{
	                                                                                
                                                                                
    printf("                                .:-:.                                       \n");
    printf("                               :/```/-                                      \n");
    printf("                   .::-.      `o    .+                                      \n");
    printf("                  :/```/-     -:    .+           .--.                       \n");
    printf("                  o`   .+     /.    -:          /:.`::                      \n");
    printf("                 `+    `+     +`    /-         :/   `+                      \n");
    printf("                 .+    `+    `+`    /-        .+`   .+                      \n");
    printf("                 -:    `+    .+     +.       `+.    ::                      \n");
    printf("                 ./     o`   ::     o`       /-    `o`                      \n");
    printf("  .--.`          `+     o`   +.     s       :/     :-                       \n");
    printf(" :/...+.         `o     o   `o`     s      `o     .+`                       \n");
    printf(" /:   `+`        .+     o`  ./     `o      /-     +.                        \n");
    printf(" .+    .+`       -:     /.  /-     -/     ::     -/                         \n");
    printf("  /-    :/       /-     :/  +`     o`    :/     `+`                         \n");
    printf("  `+.    /:      -:     -+ `+`     s    :/`  1  /-                          \n");
    printf("   .+`   `/-     .+     -+ .+      s   -+`     .+                           \n");
    printf("    -/    `/-    `o     `o /-      s `-/`      +.                           \n");
    printf("     /-    `+`   `+      ///`      -/::`      ./                            \n");
    printf("     `o`    .+`  ./       `                   o.                            \n");
    printf("      -/     ./--/.                          `o                             \n");
    printf("       :/      .`                            ::                             \n");
    printf("        +`                                   +.                ``.---:-.`   \n");
    printf("        /-                                   /.            `-:::-.` ```-/:  \n");
    printf("        ::                                   .+          .::.           `o  \n");
    printf("        -/                                    +-      .:/:`         `.:::.  \n");
    printf("        .+                                     :/-.-::-`         `-/:.`     \n");
    printf("        `+`                                      `.`          `-/:.         \n");
    printf("         +`                                                 `:/.            \n");
    printf("         /.                                               ./:`              \n");
    printf("         /-                                            `-/:`                \n");
    printf("         -:                                           ./-`                  \n");
    printf("         `o                                         `::`                    \n");
    printf("          +.                                       -/.                      \n");
    printf("          -/                                     `/:`                       \n");
    printf("           /-                                   -/.                         \n");
    printf("           `+`                                `/:`                          \n");
    printf("            :/                              `-/.                            \n");
    printf("            `o`                           .:/.                              \n");
    printf("             ::                         .::.                                \n");
    printf("             `+                        :/.                                  \n");
    printf("             `o                       `+`                                   \n");
    printf("             `o                       -:                                    \n");
    printf("             `o                       /-                                    \n");
    printf("             `+                       /-                                    \n");
    printf("             .+                       /-                                    \n");
    printf("             ./                       :-                                    \n");
    printf("             -/                       -:                                    \n");
    printf("             -:                       ./                                    \n");
    printf("             :-           2           `+                                    \n");
    printf("             /.                        .                                    \n");
                                                                              
	return;
}

void pierna (void)
{
                                                               
    printf("                                /.                                          \n");
    printf("                                h-                                          \n");
    printf("                                h.                                          \n");
    printf("                               `y`                                `-        \n");
    printf("                               .s`                                ++        \n");
    printf("                               -o`                               .y`        \n");
    printf("                               -o`                               o/         \n");
    printf("                               -+`                              .s.         \n");
    printf("                               :+`                              //          \n");
    printf("                               /+                              `o-          \n");
    printf("                               /+`                             :+`          \n");
    printf("                               /+` ``                         `+:           \n");
    printf("                               /+` ``                         .s.           \n");
    printf("                               /+` ``                         :s            \n");
    printf("                               /+` .`                         +/            \n");
    printf("                               :+``:`                        `y.            \n");
    printf("                               -+`.:`                        /o             \n");
    printf("                               -o``.                         y-             \n");
    printf("                               -o`                          .s              \n");
    printf("                               -o`                          +/              \n");
    printf("                               -s`                         `s.              \n");
    printf("                               `y.                         :/`              \n");
    printf("                                h.                        `+-               \n");
    printf("                                y-                        :o`               \n");
    printf("                                +:                       `+:                \n");
    printf("                                /+                       -s`                \n");
    printf("                                :o                       o:                 \n");
    printf("                                .s`      `:`            `y`                 \n");
    printf("                                `y.       -:            .s                  \n");
    printf("                                 +/        ``           //                  \n");
    printf("                                 :o                     o.                  \n");
    printf("                                 -o   1     `           s-                  \n");
    printf("                                 -y        :/         ``++                  \n");
    printf("                                 .h.      .o`           `y.                 \n");
    printf("                                  /+  . .:-              +o                 \n");
    printf("                                  `+:                    `o:                \n");
    printf("                                   -o.                    :o`               \n");
    printf("                                   `s:                    `o:               \n");
    printf("                                    /+                     /+`              \n");
    printf("                                    .s`                    -o`              \n");
    printf("                                     h.                    .y.              \n");
    printf("                                     o:                    `y.              \n");
    printf("                                     /+                    `y.              \n");
    printf("                                     .s                    `s.              \n");
    printf("                                     .y                    `y-              \n");
    printf("                                      s.                   `y.              \n");
    printf("                                     `s.                   -s`              \n");
    printf("                                     `y`                   :+`              \n");
    printf("                                      s.                  `o:               \n");
    printf("                                      s.                  .s-               \n");
    printf("                                      s.                  /o`               \n");
    printf("                                      o:                 `+/                \n");
    printf("                                      o/                 .s.                \n");
    printf("                                      o:                 /s                 \n");
    printf("                                      o:                `s-                 \n");
    printf("                                      o:                /o                  \n");
    printf("                                      s:               -y`                  \n");
    printf("                                      s-              .o:                   \n");
    printf("                                      s-             `+/                    \n");
    printf("                                      s.             :o`                    \n");
    printf("                                     `y`            `s-                     \n");
    printf("                                     .y`         `` :s                      \n");
    printf("                                     :o         .`  o/                      \n");
    printf("                                     s-        `-   h.                      \n");
    printf("                                    -s`        :`  `d`                      \n");
    printf("                                   .o-             .y                       \n");
    printf("                                  `+:              .y                       \n");
    printf("                                 .o:               .y                       \n");
    printf("                               `:o.       -`       `d`                      \n");
    printf("                             `-+/`        . `.  `.  y-                      \n");
    printf("                            -+/`            ``  :o` /o                      \n");
    printf("                         `-+/`              `.::/-  -s`                     \n");
    printf("                     `.///-`                 ```    /o  <----2              \n");
    printf("                   ./+:`                           :s`                      \n");
    printf("               `.://.                           `-++`                       \n");
    printf("           `:++sy/.`..` ``                   `-+o/.                         \n");
    printf("           /y/://:+/.`-/:-.-` .:.        `-/++/.                            \n");
    printf("           `:o++++y+-+o-.//.`:+.`-:--+++//:.`                               \n");
    printf("                  ```.:-:/+//+/+..-.`                                       \n");
     
		return;
}

void intestinos(void)
{
	printf("	 .---.`       .---.       \n");
	printf("   .::`   `-::  ::-`   `::-   \n");
	printf("  /-         `++.         -/  \n");
	printf("  o           `.           +  \n");
	printf("  o                        o  \n");
	printf("  -:                      ::  \n");
	printf("   -/         1          /-   \n");
	printf("    `/:                -/`    \n");
	printf("      `/-            -/.      \n");
	printf("        `/:        :/.        \n");
	printf("          `:-    :/`          \n");
	printf("            `/..+.            \n");
	printf("              //              \n");
    printf("                              \n");                 
	printf("      ````````````            \n");
	printf("     .`         ..````````    \n");
	printf("    .           ``      ```   \n");
	printf("    .       2   ``   ```      \n");
	printf("    .          `.`````        \n");
	printf("    ``   `````  `             \n");
	printf("     .```                     \n");
	printf("                              \n");
	printf("            `---              \n");
    printf("            +  o              \n");
    printf("            +  +-----.        \n");
    printf(" 	        `/.``    ./`      \n");
    printf(" 	          .::     ./      \n");
    printf(" 	    ```    /-  3  :-      \n");
    printf(" 	  -:..-:-:/:`    ./       \n");
    printf("	 :- ----`.     .:-        \n");
    printf("	 -/ .:::o/-----.`         \n");
    printf("	  `-----/-                \n");
                              
	
	return;
}

void infopanza (int eleccion)
{	
	system("cls");
	switch(eleccion)
	{
		case 1:
			while(!feof(ficherocorazon))
			{
				printf("%c",fgetc(ficherocorazon)); 
			}
		break;
		case 2:
			while(!feof(ficherohigado))
			{
				printf("%c",fgetc(ficherohigado)); 
			}
		break;
		case 3:
			while(!feof(ficheroestomago))
			{
				printf("%c",fgetc(ficheroestomago)); 
			}
		break;
	}
	return;
}

void infopierna (int eleccion)
{	
	system("cls");
	switch(eleccion)
	{
		case 1:
			printf("RODILLA: Se llama articulacion de la rodilla a la articulacion central de los miembros posteriores o inferiores de los vertebrados, en el caso de la especie humana es la articulacion central de los miembros inferiores.");
		break;
		case 2:
			printf("TOBILLO: En anatomia humana, el tobillo es la articulacion donde se unen el pie y la pierna. Está constituida por tres huesos: el perone, la tibia que pertenecen a la pierna y el astragalo que forma parte del pie. La tibia y el perone forman conjuntamente en su parte inferior una mortaja articular o cupula sobre la que se encaja la troclea o polea del astragalo.");
		break;
	}
	return;
}

void infomano (int eleccion)
{	
	system("cls");
	switch(eleccion)
	{
		case 1:
			printf("DEDOS: Los dedos son las extremidades de la mano y del pie del ser humano y de otros animales como los grandes simios. Son tambien las diez puntas de las extremidades que pueden apreciar la forma, tamaño, textura y temperatura de un objeto.");
		break;
		case 2:
			printf("MUNECA: En anatomia, la muneca es la articulacion que une los huesos cubito y radio al carpo, es decir, el antebrazo y la mano.");
		break;
	}
	return;
}

void infocara (int eleccion)
{	
	system("cls");
	switch(eleccion)
	{
		case 1:
			printf("CEREBRO: El cerebro es un termino muy general y se entiende como el proceso de centralizacion y cefalizacion del sistema nervioso de mayor complejidad del reino animal.");
		break;
		case 2:
			printf("OIDO: El oido es un conjunto de organos cuyas funciones principales son dotar de equilibrio y audicion al cuerpo de los humanos o animales. Dentro del estudio de la medicina se le denomina también organo vestibulococlear.");
		break;
		case 3:
			printf("OJO: Los ojos son organos visuales que detectan la luz y la convierten en impulsos electroquimicos que viajan a traves de neuronas. La celula fotoreceptora mas simple de la vision consciente asocia la luz al movimiento.");
		break;
		case 4:
			printf("NARIZ: La nariz es una protuberancia que forma parte del sistema respiratorio en los vertebrados. Es el organo del olfato y la entrada del tracto respiratorio.");
		break;
		case 5:
			printf("BOCA: La boca, tambien conocida como cavidad bucal o cavidad oral, es la abertura corporal por la que se ingieren alimentos. Esta ubicada en la cara y constituye en su mayor parte el aparato estomatognatico, asi como la primera parte del sistema digestivo.");
		break;	
		case 6:
			printf("CUELLO: El cuello es el area de transicion entre el craneo —por arriba—, el tronco y las extremidades superiores —por debajo—.");
		break;
		
	}
}