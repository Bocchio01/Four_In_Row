#include <stdio.h>
#include <time.h>
#include <math.h>
int main() {
 int  x[42],a,z,i=-7,c,k,q;
 char g11[20],g22[20];
 
 for (z=0;z<43;z++)
 	x[z]=46;
 printf ("Ecco un programma per giocare al gioco: 'Forza 4' ");
 printf ("\nQuesta e' la tabella dove vi sfiderete te e il tuo avversaio\n");
 for (a=0;a<6;a++) { 
 	i=i+7;
  	for (z=0;z<7;z++)
		printf (" %c " , x[z+i]);
	printf ("\n"); }
 printf (" -------------------");
 printf ("\n 1  2  3  4  5  6  7");
 

 printf ("\nOra puoi inserire il nome di g1:  ");								
 scanf ("%s" , &g11);
 printf ("Il giocatore %s utilizzera': x",g11);
 printf ("\nOra puoi inserire il nome di g2:  ");															
 scanf ("%s" , &g22);
 printf ("Il giocatore %s utilizzera': o",g22);
 
 printf ("\nEd ora incominciamo a giocare");						
 printf ("\nScegliamo chi inizia: tiriamo un dado...");	
 srand (time(NULL));		
 q=rand()%2;
 if (q==1) printf ("\nInizia %s",g11);
 else printf ("\nInizia %s",g22);
 k=q;

do {
 if (k%2==1) printf ("\nE' il  tuo turno %s X" , g11);
 else printf ("\nE' il tuo turno %s O" , g22);
 do {
  printf ("\nSeleziona una colonna da 1 a 7:");
  scanf ("%d" , &c);
  while ((c<1)||(c>7)) {
   printf ("\nReinserisci la colonna tra 1 e 7:");
   scanf ("%d" , &c); }
 if (x[c-1]!=46) {
  printf ("\nLa tua colonna e' gia piena");
  printf ("\nReinserisci la colonna scegliendo non una gia piena:");
  a=0;}
 else a=1; 
 } while (a==0);
 if (c==1) c=36;
 if (c==2) c=37;
 if (c==3) c=38;
 if (c==4) c=39;
 if (c==5) c=40;
 if (c==6) c=41;
 if (c==7) c=42;

for (c;c>0;c=c-7) {
	if (x[c-1]==46) {
		if (k%2==1)	x[c-1]=("%c" , 120);
  		else		x[c-1]=("%c" , 111);
   		c=0;}}
i=-7;
for (a=0;a<6;a++) { 
 	i=i+7;
  	for (z=0;z<7;z++)
		printf (" %c " , x[z+i]);
	printf ("\n"); }
 printf (" -------------------");
 printf ("\n 1  2  3  4  5  6  7");
k++;

//Controlli vincita
for(i=0;i<21;i++)
  	if((x[i]==x[i+7])&&(x[i]==x[i+14])&&(x[i]==x[i+21])&&(x[i]>46))	z=0;
 	
for(i=0;i<39;i++)
 	if((x[i]==x[i+1])&&(x[i]==x[i+2])&&(x[i]==x[i+3])&&(x[i]>46))	z=0; 

for (c=0;c<15;c+=7)
	for(i=0;i<3;i++)
 	 	if((x[i+c]==x[i+c+8])&&(x[i+c]==x[i+c+16])&&(x[i+c]==x[i+c+24])&&(x[i+c]>46))	z=0; 

for (c=0;c<15;c+=7)
	for(i=3;i>0;i--)
 	 	if((x[i+c]==x[i+c+6])&&(x[i+c]==x[i+c+12])&&(x[i+c]==x[i+c+18])&&(x[i+c]>46))	z=0; 

if (z==0){
	if (k%2==0) printf ("\nComplimenti %s, hai vinto" , g11);
	else printf ("\nComplimenti %s, hai vinto" , g22);}
} while (z!=0);
 
 printf ("\n\n");
 system ("PAUSE");
 return 0;
}
