	#include <stdio.h>
    #include <conio.h>

        void vfnMemCpy (unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize);
		unsigned char bfnFindMax(unsigned char* bpDest, unsigned short wSize);
		unsigned char* bpfnByteAddress(unsigned char* bpString, unsigned char bCharToFind, unsigned short wSize);
		unsigned short wfnOccurrence(unsigned char bSymbol, unsigned char* bpSrc, unsigned short wSize);

        int main (void)
        {
			unsigned char datos[10]={0,4,2,3,4,5,6,8,9};
			unsigned char *max=0;
			max = wfnOccurrence(4,datos,10);
			printf("%i",max);
          return 0;
        }
		
		//-Copia los datos del bloque apuntado por bpSource al bloque apuntado por bpDest.
		void vfnMemCpy (unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize)
		{
			while(wSize)
			{
				*bpDest = *bpSource;
				bpSource++;
				bpDest++;
				wSize--;
			}
			return;
		}
		
		//-Rellena el bloque apuntado por bpDest con el dato indicado por bByteToFill.
		void vfnMemSet(unsigned char* bpDest, unsigned char bByteToFill, unsigned short wSize)
        {
            while  (wSize)
         	{
                 *bpDest =  bByteToFill;
                  bpDest++;
                  wSize--;
         	}
        }
		
		//-Devuelve el número sin digno mayor encontrado en el bloque de memoria apuntado por bpDest 
		unsigned char bfnFindMax(unsigned char* bpDest, unsigned short wSize)
        {
        unsigned char auxiliar=0;
           while  (wSize)
         	{
                 if(auxiliar < *bpDest)
                  auxiliar = *bpDest;
                  bpDest++;
                  wSize--;
         	}
            return auxiliar;
        }
		
		//-Devuelve el número sin signo menor encontrado en el bloque de memoria apuntado por bpDest 
		 unsigned char bfnFindMin(unsigned char* bpDest, unsigned short wSize) 
        {
           unsigned char auxiliar=0;
           while  (wSize)
         	{
                 if(auxiliar > *bpDest)
                  auxiliar = *bpDest;
                  bpDest++;
                  wSize--;
         	}
            return auxiliar;
        }
		
		//-Compara las cadenas apuntadas por bpSource y bpDest, devolviendo un 1 si las cadenas son iguales o un 0 si son distintas 
		unsigned char bfnStrCmp(unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize)
        {
        unsigned char value_to_return=0;
            while  (wSize)
            {
				if(*bpSource != *bpDest)
					return 0;
				else
					value_to_return = 1;

               bpSource++;
               bpDest++;
               wSize--;

            }
            return  value_to_return;
        }
		
		//-Entrega la dirección donde se encuentra el valor bCharToFind en la cadena bpString. En caso de no encontrar datos, regresa un apuntador a NULL. 
		unsigned char* bpfnByteAddress(unsigned char* bpString, unsigned char bCharToFind, unsigned short wSize)
        {
        unsigned char *Position;

        	while(wSize)
            {
               if (*bpString ==  bCharToFind)
				{
					Position = bpString;
					return Position;
				}
               else
			   {
					Position++;
					bpString++;
					wSize--;
				}

            }
            Position = NULL;
            return   Position;

        }
		
		//-Devuelve el tamaño de la cadena terminada en 0 apuntada por bpString.
		unsigned short wfnStrLen (unsigned char* bpString)
        {
        	unsigned short StringCounter = 0;
         	while (*bpString != 0)
            {
                  bpString++;
                  StringCounter++;
            }

            return  StringCounter;
        }
		
		//- Devuelve un numero de 16 bits por medio de un generador de números pseudo aleatorio basado en la semilla recibida en wSeed.
		 unsigned short wfnRand(unsigned short wSeed) 
		{
			unsigned short wRandom
			wRandom  = ((wSeed >> 0) ^ (wSeed >> 2) ^ (wSeed >> 3) ^ (wSeed) ) & 1;
			wSeed =  (wSeed >> 1) | (wRandom << 15);
			return wSeed;
		}
		
		//- Devuelve el número de 8 bits que resulta de realizar un xor entre todos los datos contenidos en el espacio de memoria apuntado por bpSrc con tamaño especificado por wSize.
		 unsigned char bfnLRC(unsigned char* bpSrc, unsigned short wSize) 
		 {
				unsigned char LRC = 0x00;
				while (wSize)
				{
					LRC = (LRC + *bpSrc) & 0xFF; 
					wSize--;
					bpSrc++;
				}
				
				return ((LRC ^ 0xFF) + 1) & 0xFF;
		 }
		 
		 //- Devuelve el número de 16 bits que representa la cantidad de veces que se repite el elemento bSymbol en el bloque indicado por bpSrc de tamaño wSize
		  unsigned short wfnOccurrence(unsigned char bSymbol, unsigned char* bpSrc, unsigned short wSize) 
		{
			unsigned short SymbolCounter = 0;
			while(wSize)
			{
				if(*bpSrc == bSymbol)
					SymbolCounter++;
				bpSrc++;
				wSize--;
			}
			return SymbolCounter;
		}
		
		//-Ordena de menor a mayor, en el mismo sitio, los datos contenidos en el buffer apuntado por bpString. 
		void vfnSort (unsigned char* bpString, unsigned short wStringSize)
        {
        unsigned short StringSizeAux = wStringSize;
        unsigned char  StringContentAux;
        unsigned short  StringPositionAux = 0;

         	while(wStringSize)
            {
            	if( *bpString > *(bpString+1))
               {
                     StringContentAux = *bpString;
                     *bpString = *(bpString+1);
                     *(bpString+1) =  StringContentAux;
                     wStringSize = StringSizeAux;
                     bpString =  bpString - StringPositionAux;
                     StringPositionAux = 0;

               }

               else
               {
               	  bpString++;
                    StringPositionAux++;
                    wStringSize--;
               }
            }
        }
		
		void vfnprint (char* string,void* fmt)
		{
			char *cpointer_String;
			int idigit_separationaux=0;
			int idigit_separatated=0;
			int ibinary_convertor = 0;
			int Comparator_bin;
			int Shifter_bin;
			
				while (*string!='\0')
				{
					
				if(*string == '%')
				{
					switch(*(string+1))
					{
						case 'c':
							
							*string=*(char*)fmt;
							string++;
							*string=' ';
						break;
						
						case 'i':
						
							idigit_separationaux=*(int*)fmt;
							string++;
							while (idigit_separationaux > 0) {
								idigit_separatated = (idigit_separationaux % 10);
								idigit_separationaux /= 10;
								*string = idigit_separatated + 48;
								string--;
								}
							*string=' ';
						break;
						
						case 's':
							
							//*cpointer_String = **(char**)fmt;
							while(*cpointer_String)
							{
								*string=*(char*)fmt;
								cpointer_String++;
								string++;
							}
							break;
								
						case 'x':
						if(*(int*)fmt < 10)
						{
							*string = '0'+ *(int*)fmt;
							string++;
							*string=' ';
						}
						else if(*(int*)fmt < 16)
						{
							*string = 'A'+ *(int*)fmt - 10;
							string++;
							*string=' ';
						}
								break;
						
						case 'b':
							ibinary_convertor = *(int*)fmt;
							for (Shifter_bin = 2; Shifter_bin >= 0; Shifter_bin--)
							{
								Comparator_bin = ibinary_convertor >> Shifter_bin;
							
								if (Comparator_bin & 1)
								{
									*string ='1';
									string++;
								}
								else
								{
									*string ='0';
									string++;
								}
							}					
								break;
						}
						fmt = ((void*)(((void**)fmt) + 1));
						string++;
					}
					else
						string++;
				}
				
				
		}