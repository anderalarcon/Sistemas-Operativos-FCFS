#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void linea();
void es_izq();
void es_der();
void ei_izq();
void ei_der();
void cruz();
void medio();
void medio_bajo();
void medio_alto();
void extri();
void extrd();
void esp_x();
void esp_w();
void esp_blanco();
void esp_num(n);
void esp_blanco1();
void esp_num1(n);
void esp_cl();
void t_prom(n,i);
int validar(char numero[50]);
int teclado(int opcion);
int teclado1();
int teclado2();
struct procesos
{
	int tllegada;
	int tcpu;
	int tespera;
	int tretorno;
	int tactual;
	int torden;
};
int main()
{
    int n,m,mi,i,j,k,opcion,frecuencia,temp1,tecla,error=0;
    float retornoprom=0.0,esperaprom=0.0,servicetime,tnormalizado,retornoprom1,esperaprom1,servicetime1,tnormalizado1;
    char confirmando[50];
    system("COLOR B");
    printf("\n");
    es_izq();
    linea(16);
    es_der();
    printf("\n%c Algoritmo FCFS %c\n",179,179);
    ei_izq();
    linea(16);
    ei_der();
    printf("\n");
    es_izq();
    linea(31);
    es_der();
    printf("\n%cIngrese el numero de procesos  %c%c",179,179,175);
    scanf("%s",confirmando);
    n=validar(confirmando);
        if (n==-1){
            error=1;
        }
    memset(confirmando,0,50);
    if (n==0){
        return 0;
    }
    struct procesos p[n];
    ei_izq();
    linea(31);
    ei_der();
    printf("\n");
    es_izq();
    linea(31);
    es_der();
    for(i=0 ; i<n ; i++){
        printf("\n%cProceso [%d] :\t\t\t%c\n",179,i+1,179);
        extri();
        linea(31);
        extrd();
        printf("\n%cIngrese el tiempo de llegada\t%c%c",179,179,175);
        fflush(stdin);
        scanf("%s",confirmando);
        fflush(stdin);
        p[i].tllegada=validar(confirmando);
        if (p[i].tllegada==-1){
            error=1;
        }
        memset(confirmando,0,50);
        extri();
        linea(31);
        extrd();
        printf("\n%cIngrese el T-cpu:\t\t%c%c",179,179,175);
        fflush(stdin);
        scanf("%s",confirmando);
        p[i].tcpu=validar(confirmando);
        if (p[i].tcpu==-1){
            error=1;
        }
        memset(confirmando,0,50);
        if (i!=n-1){
            extri();
            linea(31);
            extrd();
        }
        else{
            ei_izq();
            linea(31);
            }
        if (error==1){
            return 0;
        }
    }
    ei_der();
    printf("\n\n");
    opcion =teclado1();
    if(opcion==1){
         frecuencia=teclado2();
    }
    for(i=0 ; i<n ; i++){
        p[i].torden=i+1;
    }
    for(i=0 ; i<n-1 ; i++){
        for(j=i+1 ; j<n ; j++){
            if(p[i].tllegada>p[j].tllegada){
                temp1=p[i].tllegada;
                p[i].tllegada=p[j].tllegada;
                p[j].tllegada=temp1;
                temp1=p[i].tcpu;
                p[i].tcpu=p[j].tcpu;
                p[j].tcpu=temp1;
                temp1=p[i].torden;
                p[i].torden=p[j].torden;
                p[j].torden=temp1;
            }
        }
    }
    for(i=0 ; i<n ; i++){
        if(i==0){
            p[i].tactual=p[i].tllegada+p[i].tcpu;
        }
        else{
            if(p[i-1].tactual<p[i].tllegada){
                p[i].tactual=p[i].tllegada+p[i].tcpu;
            }
            else{
                p[i].tactual=p[i-1].tactual+p[i].tcpu;
            }
        }
    }
    for(i=0 ; i<n ; i++){
        p[i].tretorno=p[i].tactual-p[i].tllegada;
        p[i].tespera= p[i].tactual-p[i].tllegada-p[i].tcpu;
        retornoprom=retornoprom+p[i].tretorno;
        esperaprom=esperaprom+p[i].tespera;
    }
    esperaprom/=n;
    retornoprom/=n;
    servicetime=retornoprom-esperaprom;
    tnormalizado=retornoprom/servicetime;
    if (opcion!=0){
        esperaprom1=esperaprom/frecuencia;
        retornoprom1=retornoprom/frecuencia;
        servicetime1=servicetime/frecuencia;
        tnormalizado1=tnormalizado/frecuencia;
    }
    mi=(p[n-1].tactual);
    while(tecla!=5){
        printf("\n\n");
        es_izq();
        linea(16);
        es_der();
        printf("\n%c Algoritmo FCFS %c\n",179,179);
        ei_izq();
        linea(16);
        ei_der();
        printf("\n");
        tecla=teclado(opcion);
        printf("\n");
        if (opcion==0){
            if (tecla==4){
                tecla=5;
            }
        }
        if (tecla==1){
            es_izq();
            linea(21);
            es_der();
            printf("\n");
            printf("%c Diagrama de estados %c\n",179,179);
            ei_izq();
            linea(21);
            ei_der();
            printf("\n");
            printf("\t\t");
            es_izq();
            linea(5);
            for (i=0; i<mi-1;i++){
                medio_alto();
                linea(5);
            }
            es_der();
            printf("\n");
            printf("\t\t");
            for (i=0; i<mi;i++){
                esp_num(i);
            }
            medio();
            printf("\n");
            es_izq();
            linea(15);
            cruz();
            linea(5);
            for (i=0; i<mi-1;i++){
                cruz();
                linea(5);
            }
            extrd();
            printf("\n");
            for (i=0;i<n;i++){
                printf("%c %cProceso[%i]  \t%c",179,250,p[i].torden,179);
                for (j=0;j<mi;j++){
                    if (i==0){
                        if (p[0].tllegada>j || p[0].tactual<=j){
                            esp_blanco();
                        }else{
                            esp_x();
                        }
                    }else{
                        if (p[i].tllegada>j || p[i].tactual<=j){
                            esp_blanco();
                        }else if (p[i].tllegada<=j && p[i-1].tactual>j){
                            esp_w();
                        }else{
                            esp_x();
                        }
                    }
                }
                printf("\n");
                if (i<(n-1)){
                    extri();
                    linea(15);
                    cruz();
                    linea(5);
                    for (j=0; j<mi-1;j++){
                        cruz();
                        linea(5);
                    }
                    extrd();
                }else{
                    ei_izq();
                    linea(15);
                    medio_bajo();
                    linea(5);
                    for (j=0; j<mi-1;j++){
                        medio_bajo();
                        linea(5);
                    }
                    ei_der();
                }
                printf("\n");
            }
            printf("\n\n");
            es_izq();
            linea(16);
            es_der();
            printf("\n%c Cola de listos %c\n",179,179);
            ei_izq();
            linea(16);
            ei_der();
            printf("\n");
            es_izq();
            linea(7);
            for (i=0; i<mi-1;i++){
                medio_alto();
                linea(7);
            }
            es_der();
            printf("\n");
            for (i=0; i<mi;i++){
                esp_num1(i);
            }
            medio();
            printf("\n");
            extri();
            linea(7);
            for (i=0; i<mi-1;i++){
                cruz();
                linea(7);
            }
            extrd();
            printf("\n");
            for (i=0;i<n;i++){
                medio();
                m=p[i].tcpu;
                for (j=0;j<mi;j++){
                    if (i==0){
                        if (p[0].tllegada>j || p[0].tactual<=j ||m==0){
                            esp_blanco1();
                        }else{
                            esp_cl(p[i].torden,m);
                            m--;
                        }
                    }else{
                        if (p[i].tllegada>j || p[i].tactual<=j || m==0){
                            esp_blanco1();
                        }else if (p[i].tllegada<=j && p[i-1].tactual>j){
                            esp_cl(p[i].torden,m);
                        }else{
                            esp_cl(p[i].torden,m);
                            m--;
                        }
                    }
                }
                printf("\n");
                if (i<(n-1)){
                    extri();
                    linea(7);
                    for (j=0; j<mi-1;j++){
                        cruz();
                        linea(7);
                    }
                    extrd();
                }else{
                    ei_izq();
                    linea(7);
                    for (j=0; j<mi-1;j++){
                        medio_bajo();
                        linea(7);
                    }
                    ei_der();
                }
                printf("\n");
            }
            printf("\n");
        }
        if (tecla==2){
        es_izq();
        linea(21);
        es_der();
        printf("\n%c Tabla de resultados %c\n",179,179);
        ei_izq();
        linea(21);
        ei_der();
        printf("\n");
        es_izq();
        linea(15);
        medio_alto();
        linea(15);
        medio_alto();
        linea(19);
        medio_alto();
        linea(20);
        medio_alto();
        linea(22);
        es_der();
        printf("\n");
        printf("%c   Procesos    %c   T_Llegada   %c       T-CPU       %c      T-Espera      %c       T-Retorno      %c\n",179,179,179,179,179,179);
        extri();
        linea(15);
        cruz();
        linea(15);
        cruz();
        linea(19);
        cruz();
        linea(20);
        cruz();
        linea(22);
        extrd();
        printf("\n");
        for(i=0 ; i<n ; i++){
            printf("%c %cProceso[%i] \t%c     [%i] \t%c\t[%i] \t    %c        [%i] \t %c        [%i]    \t%c\n",179,250,p[i].torden,179,p[i].tllegada,179,p[i].tcpu,179,p[i].tespera,179,p[i].tretorno,179);
        }
        ei_izq();
        linea(15);
        medio_bajo();
        linea(15);
        medio_bajo();
        linea(19);
        medio_bajo();
        linea(20);
        medio_bajo();
        linea(22);
        ei_der();
        printf("\n\n");
        }
        if (tecla==3||tecla==4){
            es_izq();
            linea(19);
            es_der();
            printf("\n%c Tiempos promedios %c\n",179,179);
            ei_izq();
            linea(19);
            ei_der();
            printf("\n");
            if (tecla==4){
                es_izq();
                linea(47);
                medio_alto();
                linea(23);
                es_der();
                printf("\n%cTiempo de retorno promedio en (s)\t\t%c%c%.9f   \t%c\n",179,179,175,retornoprom1,179);
                t_prom(47,23);
                printf("\n%cTiempo de espera promedio en (s)\t\t%c%c%.9f   \t%c\n",179,179,175,esperaprom1,179);
                t_prom(47,23);
                printf("\n%cTiempo de servicio promedio en (s)\t\t%c%c%.9f   \t%c\n",179,179,175,servicetime1,179);
                t_prom(47,23);
                printf("\n%cTiempo de retorno normalizado promedio en (s)\t%c%c%.9f   \t%c\n",179,179,175,tnormalizado1,179);
                ei_izq();
                linea(47);
                medio_bajo();
                linea(23);
                ei_der();
                printf("\n\n");
            }else{
                es_izq();
                linea(39);
                medio_alto();
                linea(15);
                es_der();
                printf("\n%cTiempo de retorno promedio\t\t%c%c%.3f  \t%c\n",179,179,175,retornoprom,179);
                t_prom(39,15);
                printf("\n%cTiempo de espera promedio\t\t%c%c%.3f  \t%c\n",179,179,175,esperaprom,179);
                t_prom(39,15);
                printf("\n%cTiempo de servicio promedio\t\t%c%c%.3f  \t%c\n",179,179,175,servicetime,179);
                t_prom(39,15);
                printf("\n%cTiempo de retorno normalizado promedio\t%c%c%.3f  \t%c\n",179,179,175,tnormalizado,179);
                ei_izq();
                linea(39);
                medio_bajo();
                linea(15);
                ei_der();
                printf("\n\n");
            }
        }
    }
    if (tecla==5){
        printf("  ");
        es_izq();
        linea(39);
        es_der();
        printf("\n  %c Gracias por utilizar nuestro programa %c\n",179,179) ;
        printf("  ");
        ei_izq();
        linea(39);
        ei_der();
        printf("\n");
        es_izq();
        linea(34);
        medio_alto();
        linea(10);
        es_der();
        printf("\n%c       Apellidos y nombres        %c  C%cdigo  %c\n",179,179,162,179) ;
        extri();
        linea(34);
        cruz();
        linea(10);
        extrd();
        printf("\n%c %cAchata Alarcon, Anderson Adrian %c 20172991 %c\n",179,175,179) ;
        extri();
        linea(34);
        cruz();
        linea(10);
        extrd();
        printf("\n%c %cCalienes Mercado, Amir Esmaild  %c 20180317 %c\n",179,175,179) ;
        extri();
        linea(34);
        cruz();
        linea(10);
        extrd();
        printf("\n%c %cFlores T%cvara, Sergio Flores    %c 20190750 %c\n",179,175,160,179,179) ;
        extri();
        linea(34);
        cruz();
        linea(10);
        extrd();
        printf("\n%c %cLandauro Alba, Marco Antonio    %c 20191063 %c\n",179,175,179) ;
        ei_izq();
        linea(34);
        medio_bajo();
        linea(10);
        ei_der();
        printf("\n");
    }
}
void linea(n){
    int i;
    for (i=0;i<n;i++){
        printf("%c",196);
    }
}
void es_izq(){
    printf("%c",218);
}
void es_der(){
    printf("%c",191);
}
void ei_izq(){
    printf("%c",192);
}
void ei_der(){
    printf("%c",217);
}
void cruz(){
    printf("%c",197);
}
void medio(){
    printf("%c",179);
}
void medio_bajo(){
    printf("%c",193);
}
void medio_alto(){
    printf("%c",194);
}
void extri(){
    printf("%c",195);
}
void extrd(){
    printf("%c",180);
}
void esp_x(){
    printf("  X  %c",179);
}
void esp_w(){
    printf("  W  %c",179);
}
void esp_num(n){
    if (n<10){
        printf("%c  %i  ",179,n);
    }if (n>9&&n<100){
        printf("%c %c%i ",179,175,n);
    }if (n>=100){
        printf("%c%c%i",179,175,n);
    }
}
void esp_num1(n){
    if (n<10){
        printf("%c   %i   ",179,n);
    }if (n>9&&n<100){
        printf("%c  %c%i  ",179,175,n);
    }if (n>=100){
        printf("%c %c%i  ",179,175,n);
    }
}
void esp_blanco(){
    printf("     %c",179);
}
void esp_blanco1(){
    printf("       %c",179);
}
void esp_cl(n,i){
    if (n<10){
        if (i<10){
            printf("[P%i] %i %c",n,i,179);
        }if (i>9 && i<100){
            printf("[P%i]%i %c",n,i,179);
        }if (i>=100){
            printf("[P%i]%i%c",n,i,179);
        }
    }if (n>9 && n<100){
        printf("[P%i]%i%c",n,i,179);
    }if (n>=100){
        printf("[P%i]%i%c",n,i,179);
    }
}
void t_prom(n,i){
    extri();
    linea(n);
    cruz();
    linea(i);
    extrd();
}
int validar(char numero[50]){
    int i=0,j,retorno;
    j=strlen(numero);
    while (i<j){
        if(isdigit(numero[i])!=0){
                i++;
        }else{
            return -1;
        }
    }
    j=atoi(numero);
    return (j);
}
int teclado(opcion){
    int tecla1;
    if (opcion!=0){
        do
        {
            es_izq();
            linea(19);
            es_der();
            printf("\n%c Lista de opciones %c\n",179,179);
            ei_izq();
            linea(19);
            ei_der();
            printf("\n");
            es_izq();
            linea(42);
            es_der();
            printf("\n%c 1. Diagrama de estados y Cola de listos  %c\n",179,179) ;
            extri();
            linea(42);
            extrd();
            printf("\n%c 2. Tabla de resultados                   %c\n",179,179) ;
            extri();
            linea(42);
            extrd();
            printf("\n%c 3. Tiempos promedio                      %c\n",179,179) ;
            extri();
            linea(42);
            extrd();
            printf("\n%c 4. Tiempos promedio con frecuencia       %c\n",179,179) ;
            extri();
            linea(42);
            extrd();
            printf("\n%c 5. Salir                                 %c\n",179,179) ;
            ei_izq();
            linea(42);
            ei_der();
            printf("\n");
            es_izq();
            linea(8);
            es_der();
            printf("\n%c Opci%cn %c%c",179,162,179,175);
            fflush(stdin);
            scanf("%d",&tecla1);
            fflush(stdin);
            ei_izq();
            linea(8);
            ei_der();
            printf("\n\n");
        }while(tecla1!=1&&tecla1!=2&&tecla1!=3&&tecla1!=4&&tecla1!=5) ;
    }else{
        do
        {
            es_izq();
            linea(19);
            es_der();
            printf("\n%c Lista de opciones %c\n",179,179);
            ei_izq();
            linea(19);
            ei_der();
            printf("\n");
            es_izq();
            linea(42);
            es_der();
            printf("\n%c 1. Diagrama de estados y Cola de listos  %c\n",179,179) ;
            extri();
            linea(42);
            extrd();
            printf("\n%c 2. Tabla de resultados                   %c\n",179,179) ;
            extri();
            linea(42);
            extrd();
            printf("\n%c 3. Tiempos promedio                      %c\n",179,179) ;
            extri();
            linea(42);
            extrd();
            printf("\n%c 4. Salir                                 %c\n",179,179) ;
            ei_izq();
            linea(42);
            ei_der();
            printf("\n");
            es_izq();
            linea(8);
            es_der();
            printf("\n%c Opci%cn %c%c",179,162,179,175);
            fflush(stdin);
            scanf("%i",&tecla1);
            fflush(stdin);
            ei_izq();
            linea(8);
            ei_der();
            printf("\n\n");
        }while(tecla1!=1&&tecla1!=2&&tecla1!=3&&tecla1!=4) ;
    }
    return tecla1;
}
int teclado1(){
    char tecla2[2];
    int opcion1;
    do
    {
        es_izq();
        linea(39);
        es_der();
        printf("\n%c Desea ingresar un valor de frecuencia %c%c",179,179,175);
        scanf("%s",&tecla2);
        ei_izq();
        linea(39);
        ei_der();
        printf("\n");
    }while(strcmp(tecla2,"si")!=0&&strcmp(tecla2,"Si")!=0&&strcmp(tecla2,"SI")!=0&&strcmp(tecla2,"sI")!=0&&strcmp(tecla2,"no")!=0&&strcmp(tecla2,"No")!=0&&strcmp(tecla2,"NO")!=0&&strcmp(tecla2,"nO")!=0);
    if (strcmp(tecla2,"si")==0 || strcmp(tecla2,"Si")==0 || strcmp(tecla2,"SI")==0 || strcmp(tecla2,"sI")==0){
        opcion1=1;
    }else{
        opcion1=0;
    }
    return opcion1;
}
int teclado2(){
    int teclita;
    es_izq();
    linea(43);
    es_der();
    printf("\n%c Ingrese el valor de la frecuencia (en Hz) %c%c",179,179,175);
    scanf("%i",&teclita) ;
    ei_izq();
    linea(43);
    ei_der();
    printf("\n\n");
    return teclita;
}
