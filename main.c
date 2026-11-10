#include "raylib.h"

int main(void){
    InitWindow(800,600,"Tekken-C");
    SetTargetFPS(60);
    
    typedef struct player{
        int x,y,speed,size,health;
    }p;
    
    p p1={150,350,4,20,100};
    p p2={650,350,4,20,100};
    while(!WindowShouldClose()){

        if(IsKeyDown(KEY_W)) p1.y-=p1.speed;
        if(IsKeyDown(KEY_S)) p1.y+=p1.speed;
        if(IsKeyDown(KEY_A)) p1.x-=p1.speed;
        if(IsKeyDown(KEY_D)) p1.x+=p1.speed;
        if(IsKeyPressed(KEY_F)){
            if(p1.y==p2.y) p2.health-=30;
            else p2.health-=10;
            if (p2.health < 0) p2.health = 0;
        }
        if(IsKeyPressed(KEY_G)){
            if(p1.y==p2.y) p2.health-=80;
            else p2.health-=20;
            if(p2.health<0) p2.health=0;
        }

        if(IsKeyDown(KEY_UP)) p2.y-=p2.speed;
        if(IsKeyDown(KEY_DOWN)) p2.y+=p2.speed;
        if(IsKeyDown(KEY_LEFT)) p2.x-=p2.speed;
        if(IsKeyDown(KEY_RIGHT)) p2.x+=p2.speed;
        if(IsKeyPressed(KEY_M)){
            if(p1.y==p2.y) p1.health-=30;
            else p1.health-=10;
            if (p1.health < 0) p1.health = 0;
        }
        if(IsKeyPressed(KEY_N)){
            if(p1.y==p2.y) p1.health-=80;
            else p1.health-=20;
            if(p1.health<0) p1.health=0;
        }



        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Player 1: 'W'  'A' 'S' 'D' Punch:'F', Kick:'G'",40,20,20,RAYWHITE);
            DrawText("Player 2: 'UP'  'LEFT' 'DOWN' 'RIGHT' Punch:'M', Kick:'N'",40,60,20,RAYWHITE);
            DrawText(TextFormat("Player 1 - Health:%d",p1.health),50,150,24,BLUE);
            DrawText(TextFormat("Player 2 - Health:%d",p2.health),500,150,24,RED);

            if(p1.health<=0) DrawText("Player 2 Wins!",250,300,50,RED);
            else  if(p2.health<=0) DrawText("Player 1 Wins!",250,300,50,BLUE);
            else{
                DrawRectangle(p1.x,p1.y,p1.size,p1.size,BLUE);
                DrawRectangle(p2.x,p2.y,p2.size,p2.size,RED);
                DrawRectangleLines(50,200,350,350,LIGHTGRAY);
                DrawRectangleLines(400,200,350,350,LIGHTGRAY);
            }
            
        EndDrawing();
    }

    CloseWindow();
}
