#include <graphics.h>


void drawCar(int x, int y) {
   
    rectangle(x, y, x + 100, y + 25);
    rectangle(x + 10, y - 20, x + 90, y);

   
    circle(x + 20, y + 30, 10);
    circle(x + 80, y + 30, 10);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x = 0, y = 300; 

    while (x < getmaxx()) {  
        cleardevice();  
        drawCar(x, y);  
        delay(50); 
        x += 5; 
    }

    getch();
    closegraph();
    return 0;
}
