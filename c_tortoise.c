#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int  main()
{
    int count=4;
    int energy=20;
    int i,j;
    srand(time(NULL));
	int board[5][5]; //tabloyu yaptım
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
	    board[i][j]='_';  //tabloyu çizgilerle doldurdum
	}
	printf("\n");
	}

int x = rand() % 5;        //kaplumbağa için
int y = rand() % 5; 
while(board[x][y]!='_')
{
    x=rand()%5;
    y=rand()%5;
}
 board[x][y]='@'; 



for (i = 0; i < 4; i++) //dut için
{  
   int x = rand() % 5;
   int y = rand() % 5;
    while (board[x][y] != '_')  // seçilen yerin boş olup         olmadığını kontrol ediyor.
    { 
        x = rand() % 5;
        y = rand() % 5;
    }
    board[x][y] = '*'; // Dutları bu boş hücrelere yerleştiriyoruz
}
for (i = 0; i < 2; i++) //çukur için
{  
   int x = rand() % 5;
   int y = rand() % 5;
    while (board[x][y] != '_') 
    { 
        x = rand() % 5;
        y = rand() % 5;
    }
    board[x][y] = 'O'; 
}
//tahtayı ekrana yazdırma
for(i=0;i<5;i++)
{
	for(j=0;j<5;j++)
	{
	   
	    printf("%c\t",board[i][j]);
	
	}
	printf("\n");
	}
	char K;
	printf(" Yönler:W,E,N,S\n");
	printf("energy level:20\n");
	printf("oynamaya başlayabilirsiniz :)\n");
	while(1)
	{
    printf("\nyön girin:");
	scanf(" %c",&K);
	printf("\n");
	//hareket kısmı
if( K=='N' && x!=0 && board[x-1][y]=='_')      
{
    board[x][y]='_';
    x--;
    board[x][y]='@';
    energy--;
    printf("energy level:%d\n",energy);
} else if(K=='S' && x!=4 && board[x+1][y]=='_')
{
    board[x][y]='_';
    x++;
    board[x][y]='@';
    energy--;
    printf("energy level:%d\n",energy);
}else if(K=='E' && y!=4 && board[x][y+1]=='_' )
{
    board[x][y]='_';
    y++;
    board[x][y]='@';
    energy--;
    printf("energy level:%d\n",energy);
}else if(K=='W' && y!=0 && board[x][y-1]=='_')
{
    
    board[x][y]='_';
    y--;
    board[x][y]='@' ;
    energy--;
    printf("energy level:%d\n",energy);
}
     //çukur kısmı
 if( K=='N' && x!=0 && board[x-1][y]=='O')      
{
    board[x][y]='_';
    x--;
    board[x][y]='@';
    energy--;
    printf("GAME OVER\nçukura düştünüz");
    break;
} else if(K=='S' && x!=4 && board[x+1][y]=='O')
{
    board[x][y]='_';
    x++;
    board[x][y]='@';
    energy--;
    printf("GAME OVER\nçukura düştünüz");
    break;
}else if(K=='E' && y!=4 && board[x][y+1]=='O' )
{
    board[x][y]='_';
    y++;
    board[x][y]='@';
    energy--;
    printf("GAME OVER\nçukura düştünüz");
    break;
}else if(K=='W' && y!=0 && board[x][y-1]=='O')
{
    
    board[x][y]='_';
    y--;
    board[x][y]='@' ;
    energy--;
    printf("GAME OVER\nçukura düştünüz");
    break;
}
        //dut yeme
 if (K == 'Y') {
            char direction;
            printf("Dutun yönünü girin: ");
            scanf(" %c", &direction);

             if (direction == 'W' && y != 0 && board[x][y - 1] == '*') {  // Yukarı ve dut
                board[x][y] = '_';
                y--;
                board[x][y] = '@';
                energy += 10;
                printf("Energy level: %d\n", energy);
                count--;
            } else if (direction == 'S' && x != 4 && board[x + 1][y] == '*') {  // Aşağı ve dut
                board[x][y] = '_';
                x++;
                board[x][y] = '@';
                energy += 10;
                printf("Energy level: %d\n", energy);
                count--;
            } else if (direction == 'E' && y != 4 && board[x][y + 1] == '*') {  // Sağ ve dut
                board[x][y] = '_';
                y++;
                board[x][y] = '@';
                energy += 10;
                printf("Energy level: %d\n", energy);
                count--;
            } else if (direction == 'N' && y != 0 && board[x-1][y] == '*') {  // Sol ve dut
                board[x][y] = '_';
                x--;
                board[x][y] = '@';
                energy += 10;
                printf("Energy level: %d\n", energy);
                count--;
            } 
	}    
	for (i=0;i<5;i++) {           //tabloyu ekrana basmak için 
            for (j=0;j<5;j++) {
                printf(" %c\t", board[i][j]);
            }
            printf("\n");
         }
         //tüm dutlar yenildiğinde
         if(count==0)
      {
        printf("tüm dutları yediniz\n");
        printf("oyunu kazandınız :)");
        break;
      }
      
   if(energy <= 0) {
            printf("Enerjiniz bitti! Oyunu kaybettiniz.\n");
            break;
        }
       }
	 
	return 0;
}





