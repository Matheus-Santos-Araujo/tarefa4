#include<stdio.h>  
#include<math.h>  
  
void  calc(float x1, float y1, float x2, float y2, float x3, float y3,  
          float x, float y, int *flag, float *area);  
int   position(float area, float A, float B, float C);  
float distance(float x1, float y1, float x2, float y2);  
float calc_area(float a, float b, float c);  
  
int main() {  
    float x1, y1, x2, y2, x3, y3, x, y;  
    int flag = 0;  
    float area = 0;  
  
    x1 = 1;
    y1 = 3;
    
    x2 = 3;
    y2 = 2;

    x3 = 4;
    y3 = 5;

    x = 2;
    y = 3;
  
    calc(x1, y1, x2, y2, x3, y3, x, y, &flag, &area);  
  
    printf("\nArea do Triangulo 1 = %f\n", area);  
  
    if(flag) printf("Ponto esta no triangulo logo esta no poligono \n", x, y);  
    else     printf("Ponto não está no triangulo \n", x, y);  

   flag = 0;  
   area = 0;  
  
    x1 = 1;
    y1 = 3;
    
    x2 = 3;
    y2 = 2;

    x3 = 2;
    y3 = 5;

    x = 2;
    y = 3;
  
    calc(x1, y1, x2, y2, x3, y3, x, y, &flag, &area);  
  
    printf("\nArea do Triangulo 2 = %f\n", area);  
  
    if(flag) printf("Ponto esta no triangulo logo esta no poligono \n", x, y);  
    else     printf("Ponto não está no triangulo \n", x, y); 

    flag = 0;  
    area = 0;  
  
    x1 = 3;
    y1 = 2;
    
    x2 = 4;
    y2 = 5;

    x3 = 4;
    y3 = 5;

    x = 5;
    y = 3;
  
    calc(x1, y1, x2, y2, x3, y3, x, y, &flag, &area);  
  
    printf("\nArea do Triangulo 3 = %f\n", area);  
  
    if(flag) printf("Ponto esta no triangulo logo esta no poligono \n", x, y);  
    else     printf("Ponto não esta no triangulo \n", x, y); 
    
    getchar(); 
    return 0;  
}  
  
void calc(float x1, float y1, float x2, float y2, float x3, float y3,  
          float x, float y, int *flag, float *area) {  
    float A, B, C, a, b, c, d, e, f;  
  
    a = distance(x1, y1, x2, y2);  
    b = distance(x2, y2, x3, y3);  
    c = distance(x3, y3, x1, y1);  
*area = calc_area(a, b, c);  
  
    d = distance(x1, y1, x, y);  
    e = distance(x2, y2, x, y);  
    f = distance(x3, y3, x, y);  
  
    A = calc_area(d, a, e);  
    B = calc_area(e, b, f);  
    C = calc_area(f, c, d);  
  
*flag = position(*area, A, B, C);  
}  
  
float distance(float x1, float y1, float x2, float y2) {  
    return( sqrt( pow((x2 - x1), 2) + pow((y2 - y1), 2) ) );  
}  
  
float calc_area(float a, float b, float c) {  
    float S;  

    S = (a + b + c) / 2.0;  
  
    return( sqrt(S * (S - a) * (S - b) * (S - c) ) );  
}  
  
int position(float area, float A, float B, float C) {  
    float res = area - (A + B + C);  
  
    if(res < 0)  {  
        res *= -1;  
    }  
  
    if(res == 0 || res < 0.001 ) {  
        getchar(); 
        return(1); 
    }  
    else {  
        getchar(); 
        return(0);  
    }  
}  