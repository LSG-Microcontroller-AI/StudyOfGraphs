#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TEMPERATURE 100.0  // Massima temperatura
#define TIME_STEP 0.1  // Step di tempo (secondi)
#define MAX_TIME 1 // Tempo massimo (secondi)
#define TARGET_TEMPERATURE 20.0  // Temperatura target per evidenziare i punti

FILE *gnuplotPipe;

double time_X = 0.00;
double temperature_Y = 0.00;
double asc_x1,asc_x2 = 0.00;
double m = 0.00;
double q = 0.00;
double ord_y1,ord_y2 = 0.00;

int main()
{
    initilize_gnuplot();

    while (time_X <= MAX_TIME)
    {
        if(time_X > 0.00f)
        {
            asc_x1 = asc_x2;
            ord_y1 = ord_y2;
            printf("asc_x1 is :: %f \n\r",asc_x1);
            printf("ord_y1 is :: %f \n\r",ord_y1);
        }
        else
        {
            get_temperature();
            plot_point();
            asc_x1 = time_X;
            ord_y1 = temperature_Y;
            printf("asc_x1 is :: %f \n\r",asc_x1);
            printf("ord_y1 is :: %f \n\r",ord_y1);
        }
        increase_time();

        get_temperature();

        plot_point();

        asc_x2 = time_X;
        ord_y2 = temperature_Y;

        printf("asc_x2 is :: %f \n\r",asc_x2);
        printf("ord_y2 is :: %f \n\r",ord_y2);

        calculate_slope();

    }
    pclose(gnuplotPipe);
    return 0;
}

void initilize_gnuplot(){
    srand(time(NULL));

    gnuplotPipe = popen("gnuplot -persistent", "w");

    if (gnuplotPipe == NULL)
    {
        printf("Errore nell'apertura di Gnuplot.\n");
        return -1;
    }

    fprintf(gnuplotPipe, "plot '-' with lines, '-' with points pointtype 7\n");
}

void get_temperature(){

    temperature_Y = (rand() / (double)RAND_MAX) * MAX_TEMPERATURE ;
}

void plot_point(){
    fprintf(gnuplotPipe, "%lf %lf\n", time_X, temperature_Y);
}

void increase_time(){
    time_X += TIME_STEP;
}
void calculate_slope(){

    m = (ord_y2-ord_y1)/(asc_x2-asc_x1);

    q = ord_y1 - (m * asc_x1);

    printf("coefficente angolare = %f \n\r",m);

    printf("Q intersezione ordinata = %f \n\r",q);

    printf("\n\r\n\r");
}
