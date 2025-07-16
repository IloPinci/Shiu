#include <stdio.h> 
#include <stdlib.h> 
#include <graphics.h> 
#include <time.h> 

 

#define NumriMaksimalShiu 200 
#define NumriMaksimalFlokeve 200 
#define NumriMaksimalSegementeve 10 

 

int main() { 
    int gd, gm; 
    gd = DETECT; 
    initgraph(&gd, &gm, ""); 


    //fullscreen 
    initwindow(getmaxwidth(), getmaxheight(), "", -3, -3); 


    // dimensionet e window 
    int GjeresiaDritares = getmaxx(); 
    int GjatesiaDritares = getmaxy(); 

    setbkcolor(WHITE);  
    setcolor(BLACK); 

    srand(time(NULL)); 


    // vektore ku ruhen pozicionet e pikave te shiut 
    int PozicioniXshi[NumriMaksimalShiu]; 
    int PozicioniYshi[NumriMaksimalShiu]; 

 

    // vektore ku ruhen pozicionet e flokeve te bores 
    int PozicioniXbore[NumriMaksimalFlokeve]; 
    int PozicioniYbore[NumriMaksimalFlokeve]; 

 

    // gjenerimi fillestar random per shiun 
    for (int i = 0; i < NumriMaksimalShiu; i++) { 
        PozicioniXshi[i] = rand() % GjeresiaDritares; 
        PozicioniYshi[i] = rand() % GjatesiaDritares; 
    } 

 
    // e njejta per boren 
    for (int i = 0; i < NumriMaksimalFlokeve; i++) { 
        PozicioniXbore[i] = rand() % GjeresiaDritares; 
        PozicioniYbore[i] = rand() % GjatesiaDritares; 
    } 



    int BieBore = 0; 
    int DrejtimiEres = 0;  
    int ShpejtesiaEres = 1; 
    int Temperatura = 0; 

    int NumriPikaveShiut = 0; 
    int NumriFlokveBores = 0;
 

    int Vetetime = 0; 
    int KohezgjatjaVetetimes = 1; //milisekonda jo sekonda kujdes 
    int KohembajtesiKohezgjatjesVetetimes = 0; 
    int GjatesiaSegmentit = 100; 


    while (1) { 
        cleardevice(); 

        // era 
        for (int i = 0; i < NumriMaksimalShiu; i++) { 
            int ZhvendosjaEresShi = ShpejtesiaEres * 2; // zhvendosje shi 

            if (DrejtimiEres == -1) { 
                PozicioniXshi[i] += ZhvendosjaEresShi;  
            } else if (DrejtimiEres == 1) { 
                PozicioniXshi[i] -= ZhvendosjaEresShi;  
            } 

 

            PozicioniXshi[i] += DrejtimiEres * ShpejtesiaEres;  

            // kur kap kufirin e window ne nje ane del tek ana tjeter 

            if (PozicioniXshi[i] < 0) { 

                PozicioniXshi[i] = GjeresiaDritares;  

            } else if (PozicioniXshi[i] > GjeresiaDritares) { 

                PozicioniXshi[i] = 0;  

            } 

        } 

         

        if (Temperatura <= 0) { 

            BieBore = 1; // bore nese temp me e vogel se 1 

 

            for (int i = 0; i < NumriMaksimalFlokeve; i++) { 

                int ZhvendosjaEresBore = ShpejtesiaEres * 2;  

 

                if (DrejtimiEres == -1) { 

                    PozicioniXbore[i] += ZhvendosjaEresBore;  

                } else if (DrejtimiEres == 1) { 

                    PozicioniXbore[i] -= ZhvendosjaEresBore;  

                } 

 

                PozicioniXbore[i] += DrejtimiEres * ShpejtesiaEres;  

 

                if (PozicioniXbore[i] < 0) { 

                    PozicioniXbore[i] = GjeresiaDritares;  

                } else if (PozicioniXbore[i] > GjeresiaDritares) { 

                    PozicioniXbore[i] = 0;  

                } 

 

                PozicioniYbore[i] += 10 + ShpejtesiaEres;  

 

                if (PozicioniYbore[i] >= GjatesiaDritares) { 

                    PozicioniYbore[i] = 0;  

                    NumriFlokveBores++; 

                } 

 

                circle(PozicioniXbore[i], PozicioniYbore[i], 2);  

            } 

        } else { 

            BieBore = 0; 

 

            for (int i = 0; i < NumriMaksimalShiu; i++) { 

                 

                int OrientimiSipasEresShi = DrejtimiEres * ShpejtesiaEres; 

                PozicioniYshi[i] += 15 + ShpejtesiaEres; 

                 

                int ZhvendosjeXShi = DrejtimiEres * ShpejtesiaEres; 

 

                if (PozicioniYshi[i] >= GjatesiaDritares) { 

                    PozicioniYshi[i] = 0; 

                    NumriPikaveShiut++; 

                } 

 

                // pika shiut ne varesi te drejtimit te eres 

                if (DrejtimiEres == 1) { 

                    line(PozicioniXshi[i], PozicioniYshi[i], PozicioniXshi[i] - ZhvendosjeXShi, PozicioniYshi[i] + OrientimiSipasEresShi);  

                } else if (DrejtimiEres == -1) { 

                    line(PozicioniXshi[i], PozicioniYshi[i], PozicioniXshi[i] + ZhvendosjeXShi, PozicioniYshi[i] + OrientimiSipasEresShi);  

                } else { 

                    line(PozicioniXshi[i], PozicioniYshi[i], PozicioniXshi[i], PozicioniYshi[i] + 10);  

                } 

            } 

        } 

 

        // gjenerimi i vetetimes  

        if (Vetetime) { 

            if (KohembajtesiKohezgjatjesVetetimes == 0) { 

                 

                int PikenisjaXvetetime = rand() % (GjeresiaDritares - GjatesiaSegmentit); 

                int PikenisjaYvetetime = 0; 

 

                // Gjenerimi i segementeve te vetetimes 

                for (int i = 0; i < NumriMaksimalSegementeve; i++) { 

                    int FundiXvetetime = PikenisjaXvetetime + (rand() % (2 * GjatesiaSegmentit) - GjatesiaSegmentit); 

                    int FundiYvetetime = PikenisjaYvetetime + GjatesiaSegmentit; 

 

                    // segmenti brenda window 

                    if (FundiYvetetime > GjatesiaDritares) 

                        FundiYvetetime = GjatesiaDritares; 

 

                    if (FundiXvetetime < 0) 

                        FundiXvetetime = 0; 

                    else if (FundiXvetetime > GjeresiaDritares - 1) 

                        FundiXvetetime = GjeresiaDritares - 1; 

 

                     

                    setcolor(BLUE); 

                    line(PikenisjaXvetetime, PikenisjaYvetetime, FundiXvetetime, FundiYvetetime); 

 

                     

                    PikenisjaXvetetime = FundiXvetetime; 

                    PikenisjaYvetetime = FundiYvetetime; 

                } 

 

                KohembajtesiKohezgjatjesVetetimes = KohezgjatjaVetetimes; 

            } else { 

                KohembajtesiKohezgjatjesVetetimes--; 

            } 

        } 

 

        delay(50); 

 

         

        if (kbhit()) { 

            char key = getch(); 

            switch (key) { 

                case 'C': 

                case 'c': 

                    ShpejtesiaEres = 10; 

                    DrejtimiEres = -1;  

                    break; 

                case 'x': 

                case 'X': 

                    ShpejtesiaEres = 10;  

                    DrejtimiEres = 1;  

                    break; 

                case 'b': 

                case 'B': 

                    ShpejtesiaEres = 0; //ska ere 

                    DrejtimiEres = 0;  

                    break; 

                case 'V': 

                case 'v': 

                    ShpejtesiaEres = 20; //shpejtesia max 

                    break; 

                case 'n': 

                case 'N': 

                    Temperatura--;  

                    break; 

                case 'm': 

                case 'M': 

                    Temperatura++;  

                    break; 

                case ' ': 

                	FILE *fB; 

   					 fB = fopen("Shiu.txt", "w"); 

                    printf("Numri i pikave te shiut eshte: %d\n", NumriPikaveShiut); 

                    printf("Numri i pikave flokeve te bores eshte: %d\n", NumriFlokveBores); 

                    getch();  

                    fprintf(fB, "Numri i pikave te shiut eshte: %d\n", NumriPikaveShiut); 

                    fprintf(fB, "Numri i pikave flokeve te bores eshte: %d", NumriFlokveBores); 

                    fclose(fB); 

                    closegraph(); 

                    return 0; 

                case 'Z': 

                case 'z': 

                    Vetetime = !Vetetime;  

                    break; 

            } 

 

            // Limiti i shpejtesise se eres qe mos te bej crash 

            if (ShpejtesiaEres > 20) 

                ShpejtesiaEres = 20; 

            else if (ShpejtesiaEres < -20) 

                ShpejtesiaEres = -20; 

        } 

    } 

} 