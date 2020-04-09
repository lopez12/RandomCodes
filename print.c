

void wfnSprintf (char* string, void* fmt);


 char cadena[]={"hola tengo %i anos que en hexadecimal es %x y mi numero binario favorito es %b  que es %c porque tiene muchos %s \n"};

	 typedef struct
	{
		int integer_Val;
		int hexadecimal_Val;
		int binary_Val;
		char character_Val;
		char string_Val;
		
	}types_data;

	types_data *Pdata,data;



	int main(void)
	{
				
		data.integer_Val= 10; 
		data.hexadecimal_Val = 10;
		data.character_Val= '7'; //en ascii = 2 porque es un caracter y no un entero
		data.binary_Val = 7 ;
		data.string_Val='p';
		
		Pdata=&data;
		
		
		printf("%s",cadena);
		wfnSprintf (cadena, Pdata);
		printf("%s",cadena);
		
		return 0;
	}




void wfnSprintf (char* string,void* fmt)
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
				


