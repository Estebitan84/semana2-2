#include <stdio.h>
#include <math.h>
float calculodistancia (float x1, float y1, float z1, float x2, float y2, float z2);
void calcularperimetro(float puntos [4][3], float *perimetro1, float *perimetro2, float *perimetro3, float *perimetro4, float *lado1, float *lado2, float *lado3, float *lado4, float *lado5, float *lado6);
float calculararea(float perimetro1, float lado1, float lado2, float lado3);
float calcularareasuperficial(float area1, float area2, float area3, float area4);
float calcularaltura(float puntos [4][3]);
float calcularvolumen(float area1, float altura);

int main (int argc, char *argv[]) {
    float puntos [4][3]= {{0,0,3} , {3,0,0} , {0,0,0}, {1,7,1}};
    float per1, perimetro2, perimetro3, perimetro4, lado1, lado2, lado3, lado4, lado5, lado6;
    calcularperimetro(puntos, &perimetro1, &perimetro2, &perimetro3, &perimertro4, &lado1, &lado2, &lado3, &lado4, &lado5, &lado6);
    float area1= calculararea(perimetro1, lado1, lado2, lado3);
    float area2= calculararea(perimetro2, lado2, lado4, lado6);
    float area3= calculararea(perimetro3, lado3, lado5, lado6);
    float area4= calculararea(perimetro4, lado1, lado5, lado4);
    float AS= calcularareasuperficial(area1, area2, area3, area4);
    float altura= calcularaltura(puntos);
    float volumen= calcularvolumen(area1, altura);
    printf("El perimetro total de la fugura es: \n%.2f\n%.2f\n%.2f\n%.2f\n", perimetro1, perimetro2, perimetro3, perimetro4);
    printf("El area total de su perimetro es: \n%.2f\n%.2f\n%.2f\n%.2f\n", area1, area2, area3, area4);
    printf("Su area superficial de su figura es: %.2f\n", AS);
    printf("el volumen total de su figura es: %.2f\n", volumen);
    return 0;
}

float calculodistancia (float x1, float y1, float z1, float x2, float y2, float z2){
    float dist = sqrt(pow(x1-x2,2)+ pow(y1-y2, 2)+ pow(z1-z2, 2));
    return dist;
}

void calcularperimetro(float puntos [4][3], float *perimetro1, float *perimetro2, float *perimetro3, float *perimetro4, float *lado1, float *lado2, float *lado3, float *lado4, float *lado5, float *lado6){
    *l1= calculodistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l2= calculodistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *l3= calculodistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l4= calculodistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l5= calculodistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l6= calculodistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
   
    *perimetro1= *lado1+*lado2+*lado3;
    *perimetro2= *lado2+*lado4+*lado6;
    *perimetro3= *lado3+*lado5+*lado6;
    *perimetro4= *lado1+*lado5+*lado4;

}

float calculararea(float perimetro1, float lado1, float lado2, float lado3){
    float s = perimetro1/2;
    float area=sqrt(s*(s-l1)*(s-l2)*(s-l3));
    return area;
}

float calcularareasuperficial(float area1, float area2, float area3, float area4){
    float AS=area1+area2+area3+area4;
    return AS;
}
float calcularaltura(float puntos [4][3]){
    float gx=(puntos[0][0]+puntos[1][0]+puntos[2][0])/3;
    float gy=(puntos[0][1]+puntos[1][1]+puntos[2][1])/3;
    float gz=(puntos[0][2]+puntos[1][2]+puntos[2][1])/3;
    float baricentro= gx+gy+gz;
    float altura= sqrt(pow(gx-puntos[3][0], 2)+pow(gy-puntos[3][1], 2)+pow(gz-puntos[3][2], 2));
    return altura;
}

float calcularvolumen(float area1, float altura){
    float volumen= (area1*altura)/3;
    return volumen;
}
