        #include <stdio.h>
        #include <conio.h>

        void vfnMemCpy (unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize);

        int main (void)
        {

          return 0;
        }

        void vfnMemCpy (unsigned char* bpSource, unsigned char* bpDest, unsigned short wSize)
        {
        	 	while  (wSize)
         	{
                  bpDest =  bpSource;
                  bpDest++;
                  bpSource++;
                  wSize--;
                  

         	}

        }

        void vfnMemSet(unsigned char* bpDest, unsigned char bByteToFill, unsigned short wSize)
        {
            while  (wSize)
         	{
                 *bpDest =  bByteToFill;
                  bpDest++;
                  wSize--;
         	}
        }

        unsigned char bfnFindMax(unsigned char* bpDest, unsigned short wSize)
        {
        unsigned char *auxiliar=0;
           while  (wSize)
         	{
                 if(*auxiliar < *bpDest)
                  *auxiliar = *bpDest;
                  bpDest++;
                  wSize--;
         	}
            return *auxiliar;
        }

        unsigned char bfnFindMin(unsigned char* bpDest, unsigned short wSize) 
        {
           unsigned char *auxiliar=0;
           while  (wSize)
         	{
                 if(*auxiliar > *bpDest)
                  *auxiliar = *bpDest;
                  bpDest++;
                  wSize--;
         	}
            return *auxiliar;
        }

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

        unsigned char* bpfnByteAddress(unsigned char* bpString, unsigned char bCharToFind, unsigned short wSize)
        {
        unsigned char *Position = 0;

        		while(wSize)
            {
               if (*bpString ==  bCharToFind)
               	return Position;
               else
               	Position++;
                  bpString++;
                  wSize--;

            }
            
            Position = NULL;
            return   Position;

        }

        unsigned short wfnSprintf (char* string, const char* fmt, char ValueToPut, char String[])
        {
        unsigned short counterString;
		  unsigned	int i;
         	while(*string)
            {
                if(*string == '%')
                	switch(*(string+1))
                  {
                       case 'c':
                             *string=' ';
                             string++;
                             *string=ValueToPut;
                       break;

                       case 'd':
                       		  *string=' ';
                             string++;
                             *string=(unsigned int)ValueToPut;
                       break;

                       case 's':
                  			  *string=' ';
                             string++;
                             		while(String[i])
                             			i++;
                              *string = *string>>i;
                              while(i)
                              {
                                 *string = String[i];
                                 i--;
                              }
                       break;

                       case 'x':
                       		switch((unsigned int) ValueToPut % 16)
                           {
							  case '1':
                                    *string = '1';
                              break;
                              case '2':
                                    *string = '2';
                              break;
                              case '3':
                                    *string = '3';
                              break;
                              case '4':
                                    *string = '4';
                              break;
                              case '5':
                                    *string = '5';
                              break;
                              case '6':
                                    *string = '6';
                              break;
                              case '7':
                                    *string = '7';
                              break;
                              case '8':
                                    *string = '8';
                              break;
                              case '9':
                                    *string = '9';
                              break;
                              case '10':
                                    *string = 'A';
                              break;
                              case '11':
                                    *string = 'B';
                              break;
                              case '12':
                                    *string = 'C';
                              break;
                              case '13':
                                    *string = 'D';
                              break;
                              case '14':
                                    *string = 'E';
                              break;
                              case '15':
                                    *string = 'F';
                              break;
                           }

                       break;

                       case 'b':

                       break;

                       default:
                       		*string = *string;
                       break;
                  }

                  string++;
                  counterString++;

            }

            return  counterString;
        }

