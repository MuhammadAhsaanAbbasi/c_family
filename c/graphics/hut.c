#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

/* Main program to draw a simple house with an animated text */
int main(void)
{
    int gd = DETECT, gm;
    int i;
    int stangle = 45, endangle = 50;
    int radius = 50;
    /* Path to the BGI driver library. Adjust the path as necessary. */
    char bgiPath[] = "C:\\MinGW\\lib\\libbgi.a";

    /* Initialize the graphics system */
    initgraph(&gd, &gm, bgiPath);
    cleardevice();

    /* Draw the house roof and walls */
    line(200, 150, 350, 150);   // Roof top
    line(140, 200, 200, 150);   // Left roof slope
    line(140, 330, 140, 200);   // Left wall
    line(250, 200, 140, 200);   // Base of left roof
    line(200, 150, 250, 200);   // Right roof slope

    /* Draw a circular feature (perhaps a window or ornament) on the house */
    circle(196, 180, 15);
    setfillstyle(SOLID_FILL, 14); // Fill style and color (yellowish)
    floodfill(196, 180, 15);

    /* Extend the drawing to the right side (creating an attached section) */
    setfillstyle(SOLID_FILL, 2);
    line(350, 150, 400, 200);
    floodfill(210, 180, 15);
    line(400, 200, 400, 330);
    line(140, 330, 400, 330);   // Base of the entire structure
    line(250, 200, 250, 330);
    line(250, 200, 400, 200);   // Top of the extension

    /* Draw additional details on the house */
    setfillstyle(SOLID_FILL, 7);
    floodfill(260, 180, 15);

    /* Draw door or window details */
    line(170, 260, 170, 330);
    line(170, 260, 210, 260);
    setfillstyle(SOLID_FILL, 9);
    floodfill(180, 250, 15);
    line(210, 260, 210, 330);
    floodfill(210, 250, 15);

    /* Draw the chimney */
    line(290, 110, 290, 150);
    line(310, 110, 310, 150);
    ellipse(300, 110, 0, 360, 10, 3);
    setfillstyle(SOLID_FILL, 8);
    floodfill(300, 120, 15);

    /* Draw a window or decorative element */
    line(300, 250, 350, 250);
    line(300, 280, 350, 280);
    line(300, 250, 350, 280);
    line(300, 280, 300, 250);
    line(350, 280, 350, 250);
    setfillstyle(SOLID_FILL, 9);
    floodfill(252, 300, 15);
    setfillstyle(SOLID_FILL, 8);
    floodfill(342, 270, 15);

    /* Draw a small arc (for example, a setting or rising sun) */
    setcolor(3);
    arc(30, 300, stangle, endangle, radius);

    /* Draw a ground line */
    setcolor(7);
    line(5, 330, 600, 330);

    /* Animate the text "Home Sweet Home" moving across the screen */
    for (i = 0; i < 650; i += 10)
    {
        /* Draw text in color 4 at the new location */
        setcolor(4);
        settextstyle(7, HORIZ_DIR, 5);
        outtextxy(i, 390, "Home Sweet Home");

        /* Pause to see the text movement */
        delay(100);

        /* Erase the current text by rewriting it in background (black) color */
        setcolor(BLACK);
        outtextxy(i, 390, "Home Sweet Home");
    }

    /* Wait for a key press before closing */
    getch();
    closegraph(60);
    return 0;
}
