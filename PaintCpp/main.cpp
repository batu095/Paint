#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <stdio.h>
#include <math.h>

using namespace std;

struct grafik{

    void grafikcagir(){
        int gd = DETECT, gm, v, w, color, angle = 0;
        struct arccoordstype h, p;
        initwindow(600,500,"Paint");
        delay(2000);
        v = mousex();
        w = mousey();

        int i,j;

        setbkcolor(0);
        setcolor(15);
        outtextxy(5,50,"Araçlar");

        setfillstyle(SOLID_FILL,7);
        bar(9,69,50,361);
        setfillstyle(SOLID_FILL,15);

        bar(10,415,50,440);
        setcolor(4);
        setbkcolor(15);
        outtextxy(12,420,"EXIT");

        bar(10,385,50,410);
        setcolor(2);
        setbkcolor(15);
        outtextxy(12,390,"SAVE");

        bar(10,450,50,475);
        setcolor(3);
        setbkcolor(15);
        outtextxy(12,455,"LOAD");

        //KALEM
        bar(10,70,50,110);
        setbkcolor(15);
        setcolor(0);
        line(15,85,35,85);
        line(15,95,35,95);
        line(20,90,30,90);
        line(35,85,45,90);
        line(35,95,45,90);
        line(35,85,35,95);

        //ÇIZGI
        bar(10,120,50,160);
        setbkcolor(15);
        setcolor(0);
        line(15,130,40,150);

        //DAIRE
        bar(10,170,50,210);
        setbkcolor(15);
        setcolor(0);
        circle(30,190,10);

        //DIKDORTGEN
        bar(10,220,50,260);
        setbkcolor(15);
        setcolor(0);
        rectangle(20,230,40,250);

        //UCGEN
        bar(10,270,50,310);
        setbkcolor(15);
        setcolor(0);
        line(30,280,20,300);
        line(30,280,40,300);
        line(20,300,40,300);

        //SILGI
        bar(10,320,50,360);
        line(35,330,20,338);
        line(20,338,18,344);
        line(20,338,30,342);
        line(18,344,28,348);
        line(30,344,28,348);
        line(30,344,45,336);
        line(35,330,45,336);
        line(28,348,43,340);
        line(43,340,45,336);

        //RENK
        setbkcolor(0);
        setcolor(15);
        outtextxy(523,100,"Renk");

        setfillstyle(SOLID_FILL,7);
        bar(520,120,564,207);

        setfillstyle(SOLID_FILL,15);

        //KIRMIZI
        for(i=121;i<=140;i++){
            for(j=521;j<=540;j++){
                putpixel(j,i,4);}}

        //YESIL
        for(i=121;i<=140;i++){
            for(j=543;j<=562;j++){
                putpixel(j,i,2);}}

        //MAVI
        for(i=143;i<=162;i++){
            for(j=521;j<=540;j++){
                putpixel(j,i,1);}}

        //SARI
        for(i=143;i<=162;i++){
            for(j=543;j<=562;j++){
                putpixel(j,i,14);}}

        //KAHVERENGI
        for(i=165;i<=184;i++){
            for(j=543;j<=562;j++){
                putpixel(j,i,6);}}

        //CYAN
        for(i=165;i<=184;i++){
            for(j=521;j<=540;j++){
                putpixel(j,i,3);}}

        //BEYAZ
        for(i=186;i<=205;i++){
            for(j=521;j<=540;j++){
                putpixel(j,i,15);}}

        //SIYAH
        for(i=186;i<=205;i++){
            for(j=543;j<=562;j++){
                putpixel(j,i,0);}}

        bar(70,50,500,400);
    };
};

int main() {

    grafik grafik1;
    grafik1.grafikcagir();

    void *pict;
    unsigned p_size;
    int renk=0,x=0,y=0,sekil=1,i=0,x1=0,y1=0,r=0;
    int bayrak=0;

    while(1){


        while(!ismouseclick(WM_LBUTTONDOWN)){
            delay(1);}
        getmouseclick(WM_LBUTTONDOWN, x, y);
            if(x>=521 && x<=540){
                if(y>=121 && y<=140)
                    renk=4;
                else if(y>=143 && y<=162)
                    renk=1;
                else if(y>=165 && y<=184)
                    renk=3;
                else if(y>=186 && y<=205)
                    renk=15;
                    }


            else if(x>=542 && x<=562){
                if(y>=121 && y<=140)
                    renk=2;
                else if(y>=143 && y<=162)
                    renk=14;
                else if(y>=165 && y<=184)
                    renk=6;
                else if(y>=186 && y<=205)
                    renk=0;
            }

            else if(x>=10 && x<=50){
                if(y>=70 && y<=110)
                    sekil=1;
                else if(y>=120 && y<=160)
                    sekil=2;
                else if(y>=175 && y<=210)
                    sekil=3;
                else if(y>=220 && y<=260)
                    sekil=4;
                else if(y>=270 && y<=310)
                    sekil=5;
                else if(y<=360 && y>=320)
                    sekil=6;
                else if(y>=415 && y<=440)
                    exit(1);
                else if(y>=385 && y<=410)
                    writeimagefile("resim.bmp",70,50,500,400);
                else if(y>=450 && y<=475)
                    readimagefile("resim.bmp",70,50,500,400);
            }

            else if(x<=500 && x>=70 && y<=400 && y>=50){
                if(sekil==1){
                    while(1){
                        delay(1);
                        x=mousex();
                        y=mousey();
                        if(x<=500 && x>=70 && y<=400 && y>=50){
                            putpixel(x,y,renk);
                            putpixel(x+1,y+1,renk);
                            putpixel(x-1,y-1,renk);
                            putpixel(x-1,y,renk);
                            putpixel(x+1,y+1,renk);
                            putpixel(x+1,y-1,renk);
                            putpixel(x+1,y,renk);
                            putpixel(x,y+1,renk);
                            putpixel(x,y-1,renk);
                        }
                        if(ismouseclick(WM_LBUTTONDOWN)==1){
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }
                    }
                }

                else if(sekil==2){
                    x1=x;
                    y1=y;
                    p_size = imagesize(70,50,500,400);
                    pict = malloc(p_size);
                    getimage(70,50,500,400,pict);
                    while(1){
                        delay(1);
                        setcolor(15);
                        if(x<=500 && x>=70 && y<=400 && y>=50)
                            line(x,y,x1,y1);
                        x=mousex();
                        y=mousey();
                        setcolor(renk);
                        if(x<=500 && x>=70 && y<=400 && y>=50){
                            bar(70,50,500,400);
                            putimage(70,50,pict,0);
                            line(x,y,x1,y1);}
                        if(ismouseclick(WM_LBUTTONDOWN)==1){
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }
                    }
                }

                else if(sekil==3){
                    x1=x;
                    y1=y;
                    p_size = imagesize(70,50,500,400);
                    pict = malloc(p_size);
                    getimage(70,50,500,400,pict);
                    while(1){
                        delay(1);
                        setcolor(15);
                        if(x<=500 && x>=70 && y<=400 && y>=50){
                            r=fabs((1/2)^(((x-x1)^2)+((y-y1)^2)));
                            if(r<500-x && r<x-70 && r<400-y && r<y-50)
                                circle(x,y,r);}
                        x=mousex();
                        y=mousey();
                        setcolor(renk);
                        if(x<=500 && x>=70 && y<=400 && y>=50){
                            r=fabs((1/2)^(((x-x1)^2)+((y-y1)^2)));
                            if(r<500-x && r<x-70 && r<400-y && r<y-50){
                                bar(70,50,500,400);
                                putimage(70,50,pict,0);
                                circle(x,y,r);
                            }
                        }
                        if(ismouseclick(WM_LBUTTONDOWN)==1){
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }
                    }
                }

                else if(sekil==4){
                    x1=x;
                    y1=y;
                    p_size = imagesize(70,50,500,400);
                    pict = malloc(p_size);
                    getimage(70,50,500,400,pict);
                    while(1){
                        delay(1);
                        setcolor(15);
                        if(x<=500 && x>=70 && y<=400 && y>=50){
                            line(x,y,x,y1);
                            line(x1,y,x1,y1);
                            line(x,y,x1,y);
                            line(x,y1,x1,y1);}
                        x=mousex();
                        y=mousey();
                        setcolor(renk);
                        if(x<=500 && x>=70 && y<=400 && y>=50){
                            bar(70,50,500,400);
                            putimage(70,50,pict,0);
                            line(x,y,x,y1);
                            line(x1,y,x1,y1);
                            line(x,y,x1,y);
                            line(x,y1,x1,y1);}
                        if(ismouseclick(WM_LBUTTONDOWN)==1){
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }
                    }
                }

                else if(sekil==5){
                    x1=x;
                    y1=y;
                    p_size = imagesize(70,50,500,400);
                    pict = malloc(p_size);
                    getimage(70,50,500,400,pict);
                    while(1){
                        delay(1);
                        setcolor(15);
                        if(x<=500 && x>=70 && y<=400 && y>=50){
                            line(x1,y,x,y);
                            line(x1,y,(x1+x)/2,y1);
                            line((x1+x)/2,y1,x,y);}
                        x=mousex();
                        y=mousey();
                        setcolor(renk);
                        if(x<=500 && x>=70 && y<=400 && y>=50){
                            bar(70,50,500,400);
                            putimage(70,50,pict,0);
                            line(x1,y,x,y);
                            line(x1,y,(x1+x)/2,y1);
                            line((x1+x)/2,y1,x,y);
                        }
                        if(ismouseclick(WM_LBUTTONDOWN)==1){
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }
                    }
                }
                else if(sekil==6){
                    while(1){
                         delay(1);
                        x=mousex();
                        y=mousey();
                        if(x<=500 && x>=70 && y<=400 && y>=50){
                                setcolor(renk);
                                bar(x-10,y-10,x+10,y+10);}
                        if(ismouseclick(WM_LBUTTONDOWN)==1){
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }
                    }
                }
            }
        }

getch();
closegraph();
return 0;
}
