#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,temp1;
    float retornoprom=0.0,esperaprom=0.0,servicetime=0.0,tnormalizado=0.0;
    printf("Ingrese el numero de procesos: ");
    scanf("%d",&n);
    int tllegada[n],tcpu[n],torden[n],tactual[n],tretorno[n],tespera[n];
    for(i=0 ; i<n ; i++){
        printf("\n Proceso [%d] :\n",i+1);
        printf("\n Ingrese el tiempo de llegada:");
        scanf("%d",&tllegada[i]);
        printf("\n Ingrese el T-cpu:");
        scanf("%d",&tcpu[i]);
        torden[i]=i+1;
    }

    for(i=0 ; i<n-1 ; i++){
        for(j=i+1 ; j<n ; j++){
            if(tllegada[i]>tllegada[j]){
                temp1=tllegada[i];
                tllegada[i]=tllegada[j];
                tllegada[j]=temp1;
                temp1=tcpu[i];
                tcpu[i]=tcpu[j];
                tcpu[j]=temp1;
                temp1=torden[i];
                torden[i]=torden[j];
                torden[j]=temp1;
            }
        }
    }
    for(i=0 ; i<n ; i++){
        if(i==0){
            tactual[i]=tllegada[i]+tcpu[i];
        }
        else{
            if(tactual[i-1]<tllegada[i]){
                tactual[i]=tllegada[i]+tcpu[i];
            }
            else{
                tactual[i]=tactual[i-1]+tcpu[i];
            }
        }
    }
    for(i=0 ; i<n ; i++){
        tretorno[i]=tactual[i]-tllegada[i];
        tespera[i]=tactual[i]-tllegada[i]-tcpu[i];
        retornoprom+=tretorno[i];
        esperaprom+=tespera[i];
    }
    printf("    Procesos        T_Llegada           T-CPU              T-Espera              T-Retorno       \n",179,179,179,179,179,179);

    for(i=0 ; i<n ; i++){
        printf("   Proceso[%d] \t      [%d] \t \t[%d] \t             [%d] \t          [%d]    \t%\n",torden[i],tllegada[i],tcpu[i],tespera[i],tretorno[i]);
    }
    printf("\n\nTiempo de espera promedio:%f",esperaprom);
    printf("\nTiempo de retorno promedio:%f\n\n",retornoprom);
    printf("\nTiempo de servicio promedio:%f\n\n",servicetime);
    printf("\nTiempo de retorno normalizado promedio:%f\n\n",tnormalizado);
    return 0;
}
