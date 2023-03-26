//Autore: Io
#include <stdio.h>
#include <time.h>
#include <math.h>
int main()
{
 int  x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14,x15,x16,x17,x18,x19,x20,x21,x22,x23,x24,x25,x26,x27,x28,x29,x30,x31,x32,x33,x34,x35,x36,x37,x38,x39,x40,x41,x42;	//Dichiarazione . x o//
 char g11[20],g22[20]; 	//Dichiarazione nomi//
 int l1,l2,i,c, g1, g2, scelta ,z,z1; //Dichiarazione lunghezza nomi-scelta colonna-attribuizione xo//
 char n;
 z=0;
 x1=46;			//Tabella con . = 46 in ASCII//
 x2=46;
 x3=46;
 x4=46;
 x5=46;
 x6=46;
 x7=46;
 x8=46;
 x9=46;
 x10=46;
 x11=46;
 x12=46;
 x13=46;
 x14=46;
 x15=46;
 x16=46;
 x17=46;
 x18=46;
 x19=46;
 x20=46;
 x21=46;
 x22=46;
 x23=46;
 x24=46;
 x25=46;
 x26=46;
 x27=46;
 x28=46;
 x29=46;
 x30=46;
 x31=46;
 x32=46;
 x33=46;
 x34=46;
 x35=46;
 x36=46;
 x37=46;
 x38=46;
 x39=46;
 x40=46;
 x41=46;
 x42=46;
 
 printf ("\nEcco un programma per giocare al gioco: 'Forza 4' ");				//Presntazione programma + tabella con valori .//
 printf ("\nQuesta e la tebella dove vi sfiderete te e il tuo avversaio\n");
 printf (" %c  %c  %c  %c  %c  %c  %c" , x1,x2,x3,x4,x5,x6,x7  );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x8,x9,x10,x11,x12,x13,x14 );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x15,x16,x17,x18,x19,x20,x21 );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x22,x23,x24,x25,x26,x27,x28 ); 
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x29,x30,x31,x32,x33,x34,x35 );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x36,x37,x38,x39,x40,x41,x42 );
 printf ("\n -------------------");
 printf ("\n 1  2  3  4  5  6  7");
 
 
//Inserimento nome di g1//
 printf ("\nOra puoi inserire il nome di g1:  ");								
 scanf ("%s" , &g11);
 printf ("Il giocatore %s utilizzera: x",g11);
 
//Inserimento nome di g2//
printf ("\nOra puoi inserire il nome di g2:  ");															
 scanf ("%s" , &g22);
 printf ("Il giocatore %s utilizzera: o",g22);
 
 																							
																						//Inizio gioco//
 printf ("\nEd ora incominciamo a giocare");						

//Scelta di inizio g1-g2//
 printf ("\nScegliamo chi inizia: tiriamo un dado...");	
 srand (time(NULL));		
 i=rand()%2;
 if (i==1)
 printf ("\nInizia %s",g11);
 else
 printf ("\nInizia %s",g22);
 g1=("%d", g11);
 g2=("%d" , g22);

//Assegnazione di g1-g2 x-o//
 g1=("%c" , 111);
 g2=("%c" , 120);
 
                           //Inizio mega ciclo di ritorno//
do
{
 if (i==1)
  printf ("\nE io tuo turno %s" , g11);
 else
  printf ("\nE il tuo turno %s" , g22);

//Ciclo per evitare una colonna impossibile o gia piena//
do
 {
  printf ("\nSeleziona una colonna da 1 a 7:");
  scanf ("%d" , &c);
  while ((c<1)||(c>7))
  {
   printf ("\nReinserisci la colonna tra 1 e 7:");
   scanf ("%d" , &c);
  }
 scelta=c;
 switch (scelta)
 {
  case 1:
   if (x1!=46)
   do
	{
 	 printf ("\nLa tua colonna e gia piena");
	 printf ("\nSeleziona una colonna tra quelle non piene");
	 printf ("\nReinserisci la colonna scegliendo non una gia piena:");
     scanf ("%d" , &c);
	}
   while (c==1);
  break;
  case 2:
   if (x2!=46)
   do
	{
 	 printf ("\nLa tua colonna e gia piena");
	 printf ("\nSeleziona una colonna tra quelle non piene");
	 printf ("\nReinserisci la colonna scegliendo non una gia piena:");
     scanf ("%d" , &c);
	}
   while (c==2);
  break;
  case 3:
   if (x3!=46)
   do
	{
 	 printf ("\nLa tua colonna e gia piena");
	 printf ("\nSeleziona una colonna tra quelle non piene");
	 printf ("\nReinserisci la colonna scegliendo non una gia piena:");
     scanf ("%d" , &c);
	}
   while (c==3);
  break;
  case 4:
   if (x4!=46)
   do
	{
 	 printf ("\nLa tua colonna e gia piena");
	 printf ("\nSeleziona una colonna tra quelle non piene");
	 printf ("\nReinserisci la colonna scegliendo non una gia piena:");
     scanf ("%d" , &c);
	}
   while (c==4);
  break;
  case 5:
   if (x5!=46)
   do
	{
 	 printf ("\nLa tua colonna e gia piena");
	 printf ("\nSeleziona una colonna tra quelle non piene");
	 printf ("\nReinserisci la colonna scegliendo non una gia piena:");
     scanf ("%d" , &c);
	}
   while (c==5);
  break;
  case 6:	
   if (x6!=46)
   do
	{
 	 printf ("\nLa tua colonna e gia piena");
	 printf ("\nSeleziona una colonna tra quelle non piene");
	 printf ("\nReinserisci la colonna scegliendo non una gia piena:");
     scanf ("%d" , &c);
	}
   while (c==6);
  break;
  case 7:
   if (x7!=46)
   do
	{
 	 printf ("\nLa tua colonna e gia piena");
	 printf ("\nSeleziona una colonna tra quelle non piene");
	 printf ("\nReinserisci la colonna scegliendo non una gia piena:");
     scanf ("%d" , &c);
	}
   while (c==7);
  break;
 }
}
while ((c<1)||(c>7));

//Analisi scelta colonna//
//Colonna =1//
switch (c)
{
 {
  case 1:
   {
	if (x36==46)
 	{
	 if (i==1)
	  x36=g2;
	  else
	  x36=g1;
	}
	else
    {
 	 if(x29==46)
 	 {
	  if (i==1)
	   x29=g2;
	   else
	   x29=g1;
	 }
	else
	{
 	 if(x22==46)
 	 {
	  if (i==1)
	   x22=g2;
	   else
	   x22=g1;
	 }
     else
	 {
 	 if(x15==46)
 	  {
	   if (i==1)
	    x15=g2;
	    else
	    x15=g1;
	  }
	 else
	  {
 	   if(x8==46)
 	    {
	     if (i==1)
	   	  x8=g2;
		  else
		  x8=g1;
		}
	   else
	    {
 	     if(x1==46)
 	      {
	       if (i==1)
	   	    x1=g2;
		    else
		    x1=g1;
		  }
 	    }   
      }
 	 }
    } 
    }
   }
 }
break;

//Colonna =2//
case 2:
	{
		if (x37==46)
 	 
 	
 	{
			if (i==1)
	   	  x37=g2;
		  else
		  x37=g1;
		    }
		    
			else
 {
 	if(x30==46)
 	{
	 if (i==1)
	   	  x30=g2;
		  else
		  x30=g1;
		    }
		    else
		    {
 	if(x23==46)
 	{
	 if (i==1)
	   	  x23=g2;
		  else
		  x23=g1;
		    }
		    else
		    {
 	if(x16==46)
 	{
	 if (i==1)
	   	  x16=g2;
		  else
		  x16=g1;
		    }
		    else
		    {
 	if(x9==46)
 	{
	 if (i==1)
	   	  x9=g2;
		  else
		  x9=g1;
		    }
		    else
		    {
 	if(x2==46)
 	{
	 if (i==1)
	   	  x2=g2;
		  else
		  x2=g1;
		    }
 	}
 }
 	}
 }
}
}		
break;

//Colonna =3//
case 3:
			{
		if (x38==46)
 	 
 	
 	{
			if (i==1)
	   	  x38=g2;
		  else
		  x38=g1;
		    }
		    
			else
 {
 	if(x31==46)
 	{
	 if (i==1)
	   	  x31=g2;
		  else
		  x31=g1;
		    }
		    else
		    {
 	if(x24==46)
 	{
	 if (i==1)
	   	  x24=g2;
		  else
		  x24=g1;
		    }
		    else
		    {
 	if(x17==46)
 	{
	 if (i==1)
	   	  x17=g2;
		  else
		  x17=g1;
		    }
		    else
		    {
 	if(x10==46)
 	{
	 if (i==1)
	   	  x10=g2;
		  else
		  x10=g1;
		    }
		    else
		    {
 	if(x3==46)
 	{
	 if (i==1)
	   	  x3=g2;
		  else
		  x3=g1;
		    }
 	}
 }
 	}
 }
}
}		
break;

//Colonna =4//
case 4:
		{
		if (x39==46)
 	 
 	
 	{
			if (i==1)
	   	  x39=g2;
		  else
		  x39=g1;
		    }
		    
			else
 {
 	if(x32==46)
 	{
	 if (i==1)
	   	  x32=g2;
		  else
		  x32=g1;
		    }
		    else
		    {
 	if(x25==46)
 	{
	 if (i==1)
	   	  x25=g2;
		  else
		  x25=g1;
		    }
		    else
		    {
 	if(x18==46)
 	{
	 if (i==1)
	   	  x18=g2;
		  else
		  x18=g1;
		    }
		    else
		    {
 	if(x11==46)
 	{
	 if (i==1)
	   	  x11=g2;
		  else
		  x11=g1;
		    }
		    else
		    {
 	if(x4==46)
 	{
	 if (i==1)
	   	  x4=g2;
		  else
		  x4=g1;
		    }
 	}
 }
 	}
 }
}
}	
break;

//Colonna =5//
case 5:
			{
		if (x40==46)
 	 
 	
 	{
			if (i==1)
	   	  x40=g2;
		  else
		  x40=g1;
		    }
		    
			else
 {
 	if(x33==46)
 	{
	 if (i==1)
	   	  x33=g2;
		  else
		  x33=g1;
		    }
		    else
		    {
 	if(x26==46)
 	{
	 if (i==1)
	   	  x26=g2;
		  else
		  x26=g1;
		    }
		    else
		    {
 	if(x19==46)
 	{
	 if (i==1)
	   	  x19=g2;
		  else
		  x19=g1;
		    }
		    else
		    {
 	if(x12==46)
 	{
	 if (i==1)
	   	  x12=g2;
		  else
		  x12=g1;
		    }
		    else
		    {
 	if(x5==46)
 	{
	 if (i==1)
	   	  x5=g2;
		  else
		  x5=g1;
		    }
 	}
 }
 	}
 }
}
}	
break;

//Colonna =6//
case 6:
			{
		if (x41==46)
 	 
 	
 	{
			if (i==1)
	   	  x41=g2;
		  else
		  x41=g1;
		    }
		    
			else
 {
 	if(x34==46)
 	{
	 if (i==1)
	   	  x34=g2;
		  else
		  x34=g1;
		    }
		    else
		    {
 	if(x27==46)
 	{
	 if (i==1)
	   	  x27=g2;
		  else
		  x27=g1;
		    }
		    else
		    {
 	if(x20==46)
 	{
	 if (i==1)
	   	  x20=g2;
		  else
		  x20=g1;
		    }
		    else
		    {
 	if(x13==46)
 	{
	 if (i==1)
	   	  x13=g2;
		  else
		  x13=g1;
		    }
		    else
		    {
 	if(x6==46)
 	{
	 if (i==1)
	   	  x6=g2;
		  else
		  x6=g1;
		    }
 	}
 }
 	}
 }
}
}		
break;

//Colonna =7//
case 7:
		{	
		if (x42==46)
 	 
 	
 	{
			if (i==1)
	   	  x42=g2;
		  else
		  x42=g1;
		    }
		    
			else
 {
 	if(x35==46)
 	{
	 if (i==1)
	   	  x35=g2;
		  else
		  x35=g1;
		    }
		    else
		    {
 	if(x28==46)
 	{
	 if (i==1)
	   	  x28=g2;
		  else
		  x28=g1;
		    }
		    else
		    {
 	if(x21==46)
 	{
	 if (i==1)
	   	  x21=g2;
		  else
		  x21=g1;
		    }
		    else
		    {
 	if(x14==46)
 	{
	 if (i==1)
	   	  x14=g2;
		  else
		  x14=g1;
		    }
		    else
		    {
 	if(x7==46)
 	{
	 if (i==1)
	   	  x7=g2;
		  else
		  x7=g1;
		    }
 	}
 }
 	}
 }
}
}	
break;
}
//Fine ciclo scelta colonna//

 printf     (" %c  %c  %c  %c  %c  %c  %c" , x1, x2, x3 ,x4 ,x5 ,x6 ,x7  );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x8, x9, x10,x11,x12,x13,x14 );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x15,x16,x17,x18,x19,x20,x21 );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x22,x23,x24,x25,x26,x27,x28 ); 
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x29,x30,x31,x32,x33,x34,x35 );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x36,x37,x38,x39,x40,x41,x42 );
 printf ("\n -------------------");
 printf ("\n 1  2  3  4  5  6  7");
 
 


 z=z+1;
 z1=z%2;
 z1=z1+1;
 //Controllo vincitori//
 if (//Verticali// 
 ((x36==x29)&&(x22==x15)&&(x29==x22)&&(x36==x15)&&(x36+x29+x22+x15>46*4))||((x8==x29)&&(x22==x15)&&(x29==x22)&&(x8==x15)&&(x29+x22+x8+x15>46*4))||((x8==x1)&&(x22==x15)&&(x1==x22)&&(x8==x15)&&(x1+x22+x8+x15>46*4))
 ||((x37==x30)&&(x30==x23)&&(x23==x16)&&(x30+x37+x23+x16>46*4))||((x23==x30)&&(x16==x9)&&(x23==x16)&&(x30+x9+x23+x16>46*4))||((x2==x9)&&(x16==x9)&&(x23==x16)&&(x2+x9+x23+x16>46*4))||((x38==x31)&&(x31==x24)&&(x24==x17)&&(x38+x31+x24+x17>46*4))
 ||((x39==x32)&&(x32==x25)&&(x25==x18)&&(x39>46))||((x40==x33)&&(x33==x26)&&(x26==x19)&&(x19>46))||((x41==x34)&&(x34==x27)&&(x27==x20)&&(x27>46))||((x42==x35)&&(x35==x28)&&(x28==x21)&&(x21>46))
 ||((x31==x24)&&(x24==x17)&&(x17==x10)&&(x10>46))||((x32==x25)&&(x25==x18)&&(x18==x11)&&(x11>46))||((x33==x26)&&(x26==x19)&&(x19==x12)&&(x12>46))||((x34==x27)&&(x27==x20)&&(x20==x13)&&(x13>46))
 ||((x35==x28)&&(x28==x21)&&(x21==x14)&&(x14>46))||((x24==x17)&&(x17==x10)&&(x10==x3)&&(x10>46))||((x25==x18)&&(x18==x11)&&(x11==x4)&&(x4>46))||((x26==x19)&&(x19==x12)&&(x12==x5)&&(x5>46))
 ||((x27==x20)&&(x20==x13)&&(x13==x6)&&(x6>46))||((x28==x21)&&(x21==x14)&&(x14==x7)&&(x7>46))
 //Orizzontali//    
 ||((x1==x2)&&(x2==x3)&&(x3==x4)&&(x4>46))||((x5==x2)&&(x2==x3)&&(x3==x4)&&(x4>46))||((x3==x4)&&(x4==x5)&&(x5==x6)&&(x6>46))||((x4==x5)&&(x5==x6)&&(x6==x7)&&(x7>46))
 ||((x8==x9)&&(x10==x11)&&(x9==x10)&&(x10>46))||((x9==x10)&&(x10==x11)&&(x11==x12)&&(x12>46))||((x10==x11)&&(x11==x12)&&(x12==x13)&&(x13>46))||((x11==x12)&&(x12==x13)&&(x13==x14)&&(x14>46))
 ||((x15==x16)&&(x17==x16)&&(x17==x18)&&(x18>46))||((x16==x17)&&(x17==x18)&&(x18==x19)&&(x18>46))||((x17==x18)&&(x18==x19)&&(x19==x20)&&(x20>46))||((x18==x19)&&(x19==x20)&&(x20==x21)&&(x21>46))   
 ||((x22==x23)&&(x23==x24)&&(x24==x25)&&(x25>46))||((x23==x24)&&(x24==x25)&&(x25==x26)&&(x26>46))||((x24==x25)&&(x25==x26)&&(x26==x27)&&(x27>46))||((x25==x26)&&(x26==x27)&&(x27==x28)&&(x28>46))
 ||((x29==x30)&&(x30==x31)&&(x31==x32)&&(x32>46))||((x30==x31)&&(x31==x32)&&(x32==x33)&&(x33>46))||((x31==x32)&&(x32==x33)&&(x33==x34)&&(x34>46))||((x32==x33)&&(x33==x34)&&(x34==x35)&&(x35>46))
 ||((x36==x37)&&(x37==x38)&&(x38==x39)&&(x39>46))||((x37==x38)&&(x38==x39)&&(x39==x40)&&(x40>46))||((x38==x39)&&(x39==x40)&&(x40==x41)&&(x41>46))||((x39==x40)&&(x40==x41)&&(x41==x42)&&(x42>46))
 //Oblique verso destra//
 ||((x4==x10)&&(x10==x16)&&(x16==x22)&&(x22>46))||((x5==x11)&&(x11==x17)&&(x17==x23)&&(x23>46))||((x6==x12)&&(x12==x18)&&(x18==x24)&&(x24>46))||((x7==x13)&&(x13==x19)&&(x19==x25)&&(x25>46))
 ||((x11==x17)&&(x17==x23)&&(x23==x29)&&(x29>46))||((x12==x18)&&(x18==x24)&&(x24==x30)&&(x30>46))||((x13==x19)&&(x19==x25)&&(x25==x31)&&(x31>46))||((x14==x20)&&(x20==x26)&&(x26==x32)&&(x26>46))
 ||((x18==x24)&&(x24==x30)&&(x30==x36)&&(x36>46))||((x19==x25)&&(x25==x31)&&(x31==x37)&&(x37>46))||((x20==x26)&&(x26==x32)&&(x32==x38)&&(x38>46))||((x21==x27)&&(x27==x33)&&(x33==x39)&&(x39>46))
 //Oblique verso sinistra//
 ||((x1==x9)&&(x9==x17)&&(x17==x25)&&(x25>46))||((x2==x10)&&(x10==x18)&&(x18==x26)&&(x26>46))||((x3==x11)&&(x11==x19)&&(x19==x27)&&(x27>46))||((x4==x12)&&(x12==x20)&&(x20==x28)&&(x28>46))
 ||((x8==x16)&&(x16==x24)&&(x24==x32)&&(x32>46))||((x9==x17)&&(x17==x25)&&(x25==x33)&&(x33>46))||((x10==x18)&&(x18==x26)&&(x26==x34)&&(x34>46))||((x11==x19)&&(x19==x27)&&(x27==x35)&&(x35>46))
 ||((x15==x23)&&(x23==x31)&&(x31==x39)&&(x39>46))||((x16==x24)&&(x24==x32)&&(x32==x40)&&(x40>46))||((x17==x25)&&(x25==x33)&&(x33==x41)&&(x41>46))||((x18==x26)&&(x26==x34)&&(x34==x42)&&(x42>46)))

 {
 	if (i=1)
 	{
 		if (z1=1)
 	{
 		printf ("\nMi dispiace %s hai perso", g11);
        printf ("\nComplimenti %s hai vinto!!!",g22);
 	}
 	else
 	{
 		printf ("\nMi dispiace %s hai perso", g22);
        printf ("\nComplimenti %s hai vinto!!!",g11);
 	}
 	}
else
{
 		if (z1=1)
 	{
 		printf ("\nMi dispiace %s hai perso", g22);
        printf ("\nComplimenti %s hai vinto!!!",g11);
 	}
 	else 
 	{
 		printf ("\nMi dispiace %s hai perso", g11);
        printf ("\nComplimenti %s hai vinto!!!",g22);
 	}
 	}


  break;
}
if ((x1!=46)&&(x2!=46)&&(x3!=46)&&(x4!=46)&&(x5!=46)&&(x6!=46)&&(x7!=46))
{
	printf ("\nLa partita e finita in pareggio: non ha vinto nessuno dei due");
break;
}
 
 
//Inizio seconda giocata//
 	if (i!=1)
printf ("\nE io tuo turno %s" , g11);
else
printf ("\nE il tuo turno %s" , g22);
do
{
printf ("\nSeleziona una colonna da 1 a 7:");
scanf ("%d" , &c);
while ((c<1)||(c>7))
{
printf ("\nReinserisci la colonna tra 1 e 7:");
scanf ("%d" , &c);
}
scelta=c;
switch (scelta)
{
	case 1:
	if (x1!=46)
 	do
 		{
		 {
 		
 		
 	printf ("\nLa tua colonna e gia piena");
	printf ("\nSeleziona una colonna tra quelle non piene");
	printf ("\nReinserisci la colonna scegliendo non una gia piena:");
scanf ("%d" , &c);
}	
}
while (c==1);
break;
case 2:
	if (x2!=46)
 	do
	 {
	 {
 	printf ("\nLa tua colonna e gia piena");
	printf ("\nSeleziona una colonna tra quelle non piene");
	printf ("\nReinserisci la colonna scegliendo non una gia piena:");
scanf ("%d" , &c);
}
}
while (c==2);
break;
case 3:
if (x3!=46)
 	do
	 {
	 {
 	printf ("\nLa tua colonna e gia piena");
	printf ("\nSeleziona una colonna tra quelle non piene");
	printf ("\nReinserisci la colonna scegliendo non una gia piena:");
scanf ("%d" , &c);
}
}
while (c==3);
break;
case 4:
if (x4!=46)
 	do
	 {
	 {
 	printf ("\nLa tua colonna e gia piena");
	printf ("\nSeleziona una colonna tra quelle non piene");
	printf ("\nReinserisci la colonna scegliendo non una gia piena:");
scanf ("%d" , &c);
}	
}
while (c==4);
break;
case 5:
if (x5!=46)
 	do
	 {
	 {
 	printf ("\nLa tua colonna e gia piena");
	printf ("\nSeleziona una colonna tra quelle non piene");
	printf ("\nReinserisci la colonna scegliendo non una gia piena:");
scanf ("%d" , &c);
}
}
while (c==5);
break;
case 6:	
if (x6!=46)
 	do
	 {
	 {
 	printf ("\nLa tua colonna e gia piena");
	printf ("\nSeleziona una colonna tra quelle non piene");
	printf ("\nReinserisci la colonna scegliendo non una gia piena:");
scanf ("%d" , &c);
}
}
while (c==6);

break;
case 7:
if (x7!=46)
 	do
	 {
	 {
 	printf ("\nLa tua colonna e gia piena");
	printf ("\nSeleziona una colonna tra quelle non piene");
	printf ("\nReinserisci la colonna scegliendo non una gia piena:");
scanf ("%d" , &c);
}
}
while (c==7);
}
}
while ((c<1)||(c>7));

switch (c)
{
	{
	
	case 1:
		{
		if (x36==46)
 	 
 	
 	{
			if (i!=1)
	   	  x36=g2;
		  else
		  x36=g1;
		    }
		    
			else
 {
 	if(x29==46)
 	{
	 if (i!=1)
	   	  x29=g2;
		  else
		  x29=g1;
		    }
		    else
		    {
 	if(x22==46)
 	{
	 if (i!=1)
	   	  x22=g2;
		  else
		  x22=g1;
		    }
		    else
		    {
 	if(x15==46)
 	{
	 if (i!=1)
	   	  x15=g2;
		  else
		  x15=g1;
		    }
		    else
		    {
 	if(x8==46)
 	{
	 if (i!=1)
	   	  x8=g2;
		  else
		  x8=g1;
		    }
		    else
		    {
 	if(x1==46)
 	{
	 if (i!=1)
	   	  x1=g2;
		  else
		  x1=g1;
		    }
 	}
 }
 	}
 }
}
}	
}
break;


case 2:
	{
		if (x37==46)
 	 
 	
 	{
			if (i!=1)
	   	  x37=g2;
		  else
		  x37=g1;
		    }
		    
			else
 {
 	if(x30==46)
 	{
	 if (i!=1)
	   	  x30=g2;
		  else
		  x30=g1;
		    }
		    else
		    {
 	if(x23==46)
 	{
	 if (i!=1)
	   	  x23=g2;
		  else
		  x23=g1;
		    }
		    else
		    {
 	if(x16==46)
 	{
	 if (i!=1)
	   	  x16=g2;
		  else
		  x16=g1;
		    }
		    else
		    {
 	if(x9==46)
 	{
	 if (i!=1)
	   	  x9=g2;
		  else
		  x9=g1;
		    }
		    else
		    {
 	if(x2==46)
 	{
	 if (i!=1)
	   	  x2=g2;
		  else
		  x2=g1;
		    }
 	}
 }
 	}
 }
}
}		
break;


case 3:
			{
		if (x38==46)
 	 
 	
 	{
			if (i!=1)
	   	  x38=g2;
		  else
		  x38=g1;
		    }
		    
			else
 {
 	if(x31==46)
 	{
	 if (i!=1)
	   	  x31=g2;
		  else
		  x31=g1;
		    }
		    else
		    {
 	if(x24==46)
 	{
	 if (i!=1)
	   	  x24=g2;
		  else
		  x24=g1;
		    }
		    else
		    {
 	if(x17==46)
 	{
	 if (i!=1)
	   	  x17=g2;
		  else
		  x17=g1;
		    }
		    else
		    {
 	if(x10==46)
 	{
	 if (i!=1)
	   	  x10=g2;
		  else
		  x10=g1;
		    }
		    else
		    {
 	if(x3==46)
 	{
	 if (i!=1)
	   	  x3=g2;
		  else
		  x3=g1;
		    }
 	}
 }
 	}
 }
}
}		
break;


case 4:
		{
		if (x39==46)
 	 
 	
 	{
			if (i!=1)
	   	  x39=g2;
		  else
		  x39=g1;
		    }
		    
			else
 {
 	if(x32==46)
 	{
	 if (i!=1)
	   	  x32=g2;
		  else
		  x32=g1;
		    }
		    else
		    {
 	if(x25==46)
 	{
	 if (i!=1)
	   	  x25=g2;
		  else
		  x25=g1;
		    }
		    else
		    {
 	if(x18==46)
 	{
	 if (i!=1)
	   	  x18=g2;
		  else
		  x18=g1;
		    }
		    else
		    {
 	if(x11==46)
 	{
	 if (i!=1)
	   	  x11=g2;
		  else
		  x11=g1;
		    }
		    else
		    {
 	if(x4==46)
 	{
	 if (i!=1)
	   	  x4=g2;
		  else
		  x4=g1;
		    }
 	}
 }
 	}
 }
}
}		
break;


case 5:
			{
		if (x40==46)
 	 
 	
 	{
			if (i!=1)
	   	  x40=g2;
		  else
		  x40=g1;
		    }
		    
			else
 {
 	if(x33==46)
 	{
	 if (i!=1)
	   	  x33=g2;
		  else
		  x33=g1;
		    }
		    else
		    {
 	if(x26==46)
 	{
	 if (i!=1)
	   	  x26=g2;
		  else
		  x26=g1;
		    }
		    else
		    {
 	if(x19==46)
 	{
	 if (i!=1)
	   	  x19=g2;
		  else
		  x19=g1;
		    }
		    else
		    {
 	if(x12==46)
 	{
	 if (i!=1)
	   	  x12=g2;
		  else
		  x12=g1;
		    }
		    else
		    {
 	if(x5==46)
 	{
	 if (i!=1)
	   	  x5=g2;
		  else
		  x5=g1;
		    }
 	}
 }
 	}
 }
}
}		
break;


case 6:
			{
		if (x41==46)
 	 
 	
 	{
			if (i!=1)
	   	  x41=g2;
		  else
		  x41=g1;
		    }
		    
			else
 {
 	if(x34==46)
 	{
	 if (i!=1)
	   	  x34=g2;
		  else
		  x34=g1;
		    }
		    else
		    {
 	if(x27==46)
 	{
	 if (i!=1)
	   	  x27=g2;
		  else
		  x27=g1;
		    }
		    else
		    {
 	if(x20==46)
 	{
	 if (i!=1)
	   	  x20=g2;
		  else
		  x20=g1;
		    }
		    else
		    {
 	if(x13==46)
 	{
	 if (i!=1)
	   	  x13=g2;
		  else
		  x13=g1;
		    }
		    else
		    {
 	if(x6==46)
 	{
	 if (i!=1)
	   	  x6=g2;
		  else
		  x6=g1;
		    }
 	}
 }
 	}
 }
}
}		
break;


case 7:
		{	
		if (x42==46)
 	 
 	
 	{
			if (i!=1)
	   	  x42=g2;
		  else
		  x42=g1;
		    }
		    
			else
 {
 	if(x35==46)
 	{
	 if (i!=1)
	   	  x35=g2;
		  else
		  x35=g1;
		    }
		    else
		    {
 	if(x28==46)
 	{
	 if (i!=1)
	   	  x28=g2;
		  else
		  x28=g1;
		    }
		    else
		    {
 	if(x21==46)
 	{
	 if (i!=1)
	   	  x21=g2;
		  else
		  x21=g1;
		    }
		    else
		    {
 	if(x14==46)
 	{
	 if (i!=1)
	   	  x14=g2;
		  else
		  x14=g1;
		    }
		    else
		    {
 	if(x7==46)
 	{
	 if (i!=1)
	   	  x7=g2;
		  else
		  x7=g1;
		    }
 	}
 }
 	}
 }
}
}
break;
}

 printf     (" %c  %c  %c  %c  %c  %c  %c" , x1, x2, x3 ,x4 ,x5 ,x6 ,x7  );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x8, x9, x10,x11,x12,x13,x14 );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x15,x16,x17,x18,x19,x20,x21 );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x22,x23,x24,x25,x26,x27,x28 ); 
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x29,x30,x31,x32,x33,x34,x35 );
 printf ("\n"" %c  %c  %c  %c  %c  %c  %c" , x36,x37,x38,x39,x40,x41,x42 );
 printf ("\n -------------------");
 printf ("\n 1  2  3  4  5  6  7");
 

z=z+1;
 z1=z%2;
  z1=z1+1;
 if (//Verticali// 
 ((x36==x29)&&(x22==x15)&&(x29==x22)&&(x36==x15)&&(x36+x29+x22+x15>46*4))||((x8==x29)&&(x22==x15)&&(x29==x22)&&(x8==x15)&&(x29+x22+x8+x15>46*4))||((x8==x1)&&(x22==x15)&&(x1==x22)&&(x8==x15)&&(x1+x22+x8+x15>46*4))
 ||((x37==x30)&&(x30==x23)&&(x23==x16)&&(x30+x37+x23+x16>46*4))||((x23==x30)&&(x16==x9)&&(x23==x16)&&(x30+x9+x23+x16>46*4))||((x2==x9)&&(x16==x9)&&(x23==x16)&&(x2+x9+x23+x16>46*4))||((x38==x31)&&(x31==x24)&&(x24==x17)&&(x38+x31+x24+x17>46*4))
 ||((x39==x32)&&(x32==x25)&&(x25==x18)&&(x39>46))||((x40==x33)&&(x33==x26)&&(x26==x19)&&(x19>46))||((x41==x34)&&(x34==x27)&&(x27==x20)&&(x27>46))||((x42==x35)&&(x35==x28)&&(x28==x21)&&(x21>46))
 ||((x31==x24)&&(x24==x17)&&(x17==x10)&&(x10>46))||((x32==x25)&&(x25==x18)&&(x18==x11)&&(x11>46))||((x33==x26)&&(x26==x19)&&(x19==x12)&&(x12>46))||((x34==x27)&&(x27==x20)&&(x20==x13)&&(x13>46))
 ||((x35==x28)&&(x28==x21)&&(x21==x14)&&(x14>46))||((x24==x17)&&(x17==x10)&&(x10==x3)&&(x10>46))||((x25==x18)&&(x18==x11)&&(x11==x4)&&(x4>46))||((x26==x19)&&(x19==x12)&&(x12==x5)&&(x5>46))
 ||((x27==x20)&&(x20==x13)&&(x13==x6)&&(x6>46))||((x28==x21)&&(x21==x14)&&(x14==x7)&&(x7>46))
 //Orizzontali//    
 ||((x1==x2)&&(x2==x3)&&(x3==x4)&&(x4>46))||((x5==x2)&&(x2==x3)&&(x3==x4)&&(x4>46))||((x3==x4)&&(x4==x5)&&(x5==x6)&&(x6>46))||((x4==x5)&&(x5==x6)&&(x6==x7)&&(x7>46))
 ||((x8==x9)&&(x10==x11)&&(x9==x10)&&(x10>46))||((x9==x10)&&(x10==x11)&&(x11==x12)&&(x12>46))||((x10==x11)&&(x11==x12)&&(x12==x13)&&(x13>46))||((x11==x12)&&(x12==x13)&&(x13==x14)&&(x14>46))
 ||((x15==x16)&&(x17==x16)&&(x17==x18)&&(x18>46))||((x16==x17)&&(x17==x18)&&(x18==x19)&&(x18>46))||((x17==x18)&&(x18==x19)&&(x19==x20)&&(x20>46))||((x18==x19)&&(x19==x20)&&(x20==x21)&&(x21>46))   
 ||((x22==x23)&&(x23==x24)&&(x24==x25)&&(x25>46))||((x23==x24)&&(x24==x25)&&(x25==x26)&&(x26>46))||((x24==x25)&&(x25==x26)&&(x26==x27)&&(x27>46))||((x25==x26)&&(x26==x27)&&(x27==x28)&&(x28>46))
 ||((x29==x30)&&(x30==x31)&&(x31==x32)&&(x32>46))||((x30==x31)&&(x31==x32)&&(x32==x33)&&(x33>46))||((x31==x32)&&(x32==x33)&&(x33==x34)&&(x34>46))||((x32==x33)&&(x33==x34)&&(x34==x35)&&(x35>46))
 ||((x36==x37)&&(x37==x38)&&(x38==x39)&&(x39>46))||((x37==x38)&&(x38==x39)&&(x39==x40)&&(x40>46))||((x38==x39)&&(x39==x40)&&(x40==x41)&&(x41>46))||((x39==x40)&&(x40==x41)&&(x41==x42)&&(x42>46))
 //Oblique verso destra//
 ||((x4==x10)&&(x10==x16)&&(x16==x22)&&(x22>46))||((x5==x11)&&(x11==x17)&&(x17==x23)&&(x23>46))||((x6==x12)&&(x12==x18)&&(x18==x24)&&(x24>46))||((x7==x13)&&(x13==x19)&&(x19==x25)&&(x25>46))
 ||((x11==x17)&&(x17==x23)&&(x23==x29)&&(x29>46))||((x12==x18)&&(x18==x24)&&(x24==x30)&&(x30>46))||((x13==x19)&&(x19==x25)&&(x25==x31)&&(x31>46))||((x14==x20)&&(x20==x26)&&(x26==x32)&&(x26>46))
 ||((x18==x24)&&(x24==x30)&&(x30==x36)&&(x36>46))||((x19==x25)&&(x25==x31)&&(x31==x37)&&(x37>46))||((x20==x26)&&(x26==x32)&&(x32==x38)&&(x38>46))||((x21==x27)&&(x27==x33)&&(x33==x39)&&(x39>46))
 //Oblique verso sinistra//
 ||((x1==x9)&&(x9==x17)&&(x17==x25)&&(x25>46))||((x2==x10)&&(x10==x18)&&(x18==x26)&&(x26>46))||((x3==x11)&&(x11==x19)&&(x19==x27)&&(x27>46))||((x4==x12)&&(x12==x20)&&(x20==x28)&&(x28>46))
 ||((x8==x16)&&(x16==x24)&&(x24==x32)&&(x32>46))||((x9==x17)&&(x17==x25)&&(x25==x33)&&(x33>46))||((x10==x18)&&(x18==x26)&&(x26==x34)&&(x34>46))||((x11==x19)&&(x19==x27)&&(x27==x35)&&(x35>46))
 ||((x15==x23)&&(x23==x31)&&(x31==x39)&&(x39>46))||((x16==x24)&&(x24==x32)&&(x32==x40)&&(x40>46))||((x17==x25)&&(x25==x33)&&(x33==x41)&&(x41>46))||((x18==x26)&&(x26==x34)&&(x34==x42)&&(x42>46)))
{
 	if (i=1)
 	{
 		if (z1=1)
 	{
 		printf ("\nMi dispiace %s hai perso", g22);
        printf ("\nComplimenti %s hai vinto!!!",g11);
 	}
 	else
 	{
 		printf ("\nMi dispiace %s hai perso", g11);
        printf ("\nComplimenti %s hai vinto!!!",g22);
 	}
 	}
else
{
 		if (z1=1)
 	{
 		printf ("\nMi dispiace %s hai perso", g11);
        printf ("\nComplimenti %s hai vinto!!!",g22);
 	}
 	else 
 	{
 		printf ("\nMi dispiace %s hai perso", g22);
        printf ("\nComplimenti %s hai vinto!!!",g11);
 	}
 	}

 
 break;
}
 if ((x1!=46)&&(x2!=46)&&(x3!=46)&&(x4!=46)&&(x5!=46)&&(x6!=46)&&(x7!=46))
{
	printf ("\nLa partita e finita in pareggio: non ha vinto nessuno dei due");
break;
}
}

while ((c>0)&&(c<8));
 
 printf ("\n\n");
 system ("PAUSE");
 return 0;
}
