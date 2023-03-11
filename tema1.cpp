#include "lab_m1/tema1/tema1.h"

#include <vector>
#include <iostream>
#include <cmath>
#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"

using namespace std;
using namespace m1;

vector<Mesh*> fireIarba_arr;
vector<bool> available;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


tema1::tema1()
{
}


tema1::~tema1()
{
}


void tema1::Init()
{
     resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(1, 1, 0);//2 
    squareSide = 100;
    angle = 0;

   

    // Initialize tx and ty (the translation steps)
    translateX = rand() % 450 - 1;
    translateY = 0;
    translateX_Scor = translateX_scor2 =  translateX_scor3 = -55;
    translateX_scor4 = translateX_scor5 = -55;
    miscare_aripi = 0;
    //deplasare_dreapta = false;
    aroundPoint = 20;
    impuscat = 0;
    coordonate_cap = glm::vec2(corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0));
    sx = sy = 1;
    rotire_rata = true;
    rata_impuscata = false;
    scor = 0;
    check_scor = false;
    check_inima = false;
    timp  = 0;
    ma_duc_in_sus = false;
    translateX_inima = translateX_inima2 =translateX_inima3 =-130;
    translateX_bullet = translateX_bullet2 = translateX_bullet3 = -140;
    translateX_bullet4 = translateX_bullet5 =  -140;
    bullet_consumat = false;
    speed = 1;
    nr_bullet_consumat = 5;
    reincarcare = false;
    nr_inimi = 3;
    translateX_contur_scor = 0;
    timp_revenire_rata = 13;
    timp_dead_duck = 11;//timpul alocat pt a omora rata
    nr_rate_impuscate = 0;
    speed_initial = 100;
    offset_revenire_rata = 4;
    
    a_random = 450;
    b_random = 1000;

    size_corpX = 35;
    size_corpY = 5;
    size_aripiX = 125;
    size_aripiY = 50;
    size_ciocX = 125;
    size_ciocY = 50;
    offsetX_aripajos = 60;
    offsetY_aripajos = 25;
    offsetX_aripasus = 30;

    // Initialize sx and sy (the scale factors)
    scaleX = 0.5;
    scaleY = 0.5;

   

    Mesh* triangle1 = object2D::CreateTriangle("corp", corner, squareSide/2, glm::vec3(0.58, 0.29, 0.011));
    AddMeshToList(triangle1);

    Mesh* triangle2 = object2D::CreateTriangle("aripa_jos", corner, squareSide/4, glm::vec3(0.011, 0.58, 0.26));
    AddMeshToList(triangle2);

    Mesh* triangle3 = object2D::CreateTriangle("aripa_sus", corner, squareSide/4, glm::vec3(0.011, 0.58, 0.26));
    AddMeshToList(triangle3);

    Mesh* duckHead = object2D::CreateCircle("headDuck", corner + glm::vec3(squareSide * 1.5, squareSide/2 , 0), squareSide/3, glm::vec3(0.58, 0.29, 0.011));
    AddMeshToList(duckHead);

    Mesh* cioc = object2D::CreateTriangle("cioc", corner, squareSide / 4, glm::vec3(1, 1, 0));
    AddMeshToList(cioc);

    Mesh* grass = object2D::CreateSquare("grass", corner, squareSide, glm::vec3(0, 1, 0),true);
    AddMeshToList(grass);

    /*Mesh* tinta = object2D::CreateTinta("tinta", corner, squareSide, glm::vec3(0, 1, 1), false);
    AddMeshToList(tinta);*/

    Mesh* baraScor = object2D::CreateBaraScor("baraScor", corner, squareSide, glm::vec3(0, 1, 1), true);
    AddMeshToList(baraScor);

    Mesh* baraScor2 = object2D::CreateBaraScor("baraScor2", corner, squareSide, glm::vec3(0, 1, 1), true);
    AddMeshToList(baraScor2);

    Mesh* baraScor3 = object2D::CreateBaraScor("baraScor3", corner, squareSide, glm::vec3(0, 1, 1), true);
    AddMeshToList(baraScor3);

    Mesh* baraScor4 = object2D::CreateBaraScor("baraScor4", corner, squareSide, glm::vec3(0, 1, 1), true);
    AddMeshToList(baraScor4);

    Mesh* baraScor5 = object2D::CreateBaraScor("baraScor5", corner, squareSide, glm::vec3(0, 1, 1), true);
    AddMeshToList(baraScor5);

    Mesh* heart = object2D::CreateHeart("heart", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide / 3, glm::vec3(1, 0, 0));
    AddMeshToList(heart);

    Mesh* heart2 = object2D::CreateHeart("heart2", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide / 3, glm::vec3(1, 0, 0));
    AddMeshToList(heart2);

    Mesh* heart3 = object2D::CreateHeart("heart3", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide / 3, glm::vec3(1, 0, 0));
    AddMeshToList(heart3);

    Mesh* bullet = object2D::CreateCircle("bullet", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide / 5, glm::vec3(1, 1, 1));
    AddMeshToList(bullet);

    Mesh* bullet2 = object2D::CreateCircle("bullet2", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide / 5, glm::vec3(1, 1, 1));
    AddMeshToList(bullet2);

    Mesh* bullet3 = object2D::CreateCircle("bullet3", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide / 5, glm::vec3(1, 1, 1));
    AddMeshToList(bullet3);

    Mesh* bullet4 = object2D::CreateCircle("bullet4", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide / 5, glm::vec3(1, 1, 1));
    AddMeshToList(bullet4);

    Mesh* bullet5 = object2D::CreateCircle("bullet5", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide / 5, glm::vec3(1, 1, 1));
    AddMeshToList(bullet5);

    Mesh* soare = object2D::CreateCircle("soare", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 1), squareSide*1.5 , glm::vec3(1, 1, 0));
    AddMeshToList(soare);

    Mesh* hitBox = object2D::CreateCircle("hitBox", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide / 5, glm::vec3(0.58, 0.29, 0.011));
    AddMeshToList(hitBox);
   
    Mesh* contur_bara_scor = object2D::CreateConturBaraScor("contur_bara_scor", corner, squareSide, glm::vec3(1, 0, 0), false);
    AddMeshToList(contur_bara_scor);

    Mesh* sadFace = object2D::CreateCircle("sadFace", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide*2, glm::vec3(1, 1, 0));
    AddMeshToList(sadFace);

    Mesh* sadFace_eyes1 = object2D::CreateCircle("sadFace_eyes1", corner+ glm::vec3(squareSide * 1.5, squareSide / 2, 1), squareSide / 2.5, glm::vec3(0, 0, 0));
    AddMeshToList(sadFace_eyes1);

    Mesh* sadFace_eyes2 = object2D::CreateCircle("sadFace_eyes2", corner+ glm::vec3(squareSide * 1.5, squareSide / 2, 1), squareSide / 2.5, glm::vec3(0, 0, 0));
    AddMeshToList(sadFace_eyes2);

    Mesh* gura_sup = object2D::GuraSup("gura_sup", corner + glm::vec3(0,0,1), squareSide/2.5, glm::vec3(0, 0, 0), true);
    AddMeshToList(gura_sup);

    Mesh* smileyFace = object2D::CreateCircle("smileyFace", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 0), squareSide * 2, glm::vec3(1, 1, 0));
    AddMeshToList(smileyFace);

    Mesh* smileyFace_eyes1 = object2D::CreateCircle("smileyFace_eyes1", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 1), squareSide / 2.5, glm::vec3(1, 1, 1));
    AddMeshToList(smileyFace_eyes1);

    Mesh* smileyFace_eyes2 = object2D::CreateCircle("smileyFace_eyes2", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 1), squareSide / 2.5, glm::vec3(1, 1, 1));
    AddMeshToList(smileyFace_eyes2);

    Mesh* gura_fericita = object2D::CreateSmileyMouth("gura_fericita", corner + glm::vec3(squareSide * 1.5, squareSide / 2, 1), squareSide, glm::vec3(1, 1, 1));
    AddMeshToList(gura_fericita);

    for (int i = 0; i < 38; i++) {
        Mesh* fireDeIarba = object2D::CreateTriangle("fireDeIarba" + to_string(i), corner, squareSide / 4, glm::vec3(0, 1, 0));
        fireIarba_arr.push_back(fireDeIarba);
        available.push_back(true);
        AddMeshToList(fireDeIarba);
    }
}


void tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
    

}

float superAtan(float y, float x)//fc care ma ajutqa sa calculez unghiul de intoarcere al ratei dupa ciocnire
{
    if (x == 0)
        if (y < 0)
            return -M_PI_2;
        else
            return M_PI_2;
    return atan2(y, x);
}


void tema1::Update(float deltaTimeSeconds)
{   
    
    if (nr_inimi <= 0  ) {
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(450, 370);
        RenderMesh2D(meshes["sadFace"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(400, 400);
        RenderMesh2D(meshes["sadFace_eyes1"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(500, 400);
        RenderMesh2D(meshes["sadFace_eyes2"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(540, 370);
        RenderMesh2D(meshes["gura_sup"], shaders["VertexColor"], modelMatrix);
        return;
    }
    else if (scor >= 50) {
        //smiley face
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(450, 370);
        RenderMesh2D(meshes["smileyFace"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(400, 400);
        RenderMesh2D(meshes["smileyFace_eyes1"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(500, 400);
        RenderMesh2D(meshes["smileyFace_eyes2"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(450, 340);
        RenderMesh2D(meshes["gura_fericita"], shaders["VertexColor"], modelMatrix);
        return;
    }
    else {
        if (rata_impuscata == false) {
            timp += deltaTimeSeconds;
        }
       
        cout << "TIMPUL ESTE " << timp << "\n";

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(translateX, translateY);
        modelMatrix *= transform2D::Translate(translateX + size_corpX, translateY + size_corpY);


        glm::vec3 aux_coor(coordonate_cap, 1);
        aux_coor = modelMatrix * aux_coor;
        coordonate_cap_v2 = glm::vec2(aux_coor.x, aux_coor.y);

        if (rotire_rata)
        {
            angle = superAtan(sy, sx);
            cout << "beeeh" << endl;
            rotire_rata = false;
        }

        modelMatrix = transform2D::RotatePoint(angle, coordonate_cap_v2.x, coordonate_cap_v2.y) * modelMatrix;
        
        RenderMesh2D(meshes["corp"], shaders["VertexColor"], modelMatrix);//corpul ratei
        
        
        coordonate_corp = { modelMatrix[2][0],modelMatrix[2][1],0 };
        
        
        modelMatrix = glm::mat3(1);
       
        modelMatrix *= transform2D::Translate(translateX, translateY);
        //modelMatrix *= transform2D::Translate(translateX + size_corpX, translateY + size_corpY);
        modelMatrix *= transform2D::Translate(translateX - 50, translateY -20 );
        //modelMatrix = transform2D::Translate(coordonate_cap_v2.x - 200, coordonate_cap_v2.y - 150);
        modelMatrix = transform2D::RotatePoint(angle, coordonate_cap_v2.x, coordonate_cap_v2.y ) * modelMatrix;
        RenderMesh2D(meshes["hitBox"], shaders["VertexColor"], modelMatrix);

        
        
        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(translateX, translateY);
        modelMatrix *= transform2D::Translate(translateX - 10, translateY - 21);
        //modelMatrix *= transform2D::Scale(scaleX,scaleY);


        modelMatrix = transform2D::RotatePoint(angle, coordonate_cap_v2.x, coordonate_cap_v2.y) * modelMatrix;
        RenderMesh2D(meshes["headDuck"], shaders["VertexColor"], modelMatrix);

        miscare_aripi += deltaTimeSeconds;
        if (miscare_aripi > 0.75)miscare_aripi = 0;

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(translateX + size_aripiX, translateY + size_aripiY);
        modelMatrix *= transform2D::Translate(translateX - offsetX_aripajos, translateY - offsetY_aripajos);
        modelMatrix *= transform2D::Rotate(-M_PI * 0.5);
        modelMatrix *= transform2D::Rotate(miscare_aripi);
        modelMatrix = transform2D::RotatePoint(angle, coordonate_cap_v2.x, coordonate_cap_v2.y) * modelMatrix;
        RenderMesh2D(meshes["aripa_jos"], shaders["VertexColor"], modelMatrix);//aripa de jos

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(translateX + size_aripiX, translateY + size_aripiY);
        modelMatrix *= transform2D::Translate(translateX - offsetX_aripasus, translateY - offsetY_aripajos);//aici am folosit acelasi offset ca la aripa de jos
        modelMatrix *= transform2D::Rotate(M_PI * 0.5);
        modelMatrix *= transform2D::Rotate(-miscare_aripi);

        modelMatrix = transform2D::RotatePoint(angle, coordonate_cap_v2.x, coordonate_cap_v2.y) * modelMatrix;
        RenderMesh2D(meshes["aripa_sus"], shaders["VertexColor"], modelMatrix);//aripa de sus

        modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(translateX + size_ciocX, translateY + size_ciocY);
        modelMatrix *= transform2D::Translate(translateX + 5, translateY - 34);
        modelMatrix = transform2D::RotatePoint(angle, coordonate_cap_v2.x, coordonate_cap_v2.y) * modelMatrix;
        RenderMesh2D(meshes["cioc"], shaders["VertexColor"], modelMatrix);

        modelMatrix = glm::mat3(1);
        RenderMesh2D(meshes["grass"], shaders["VertexColor"], modelMatrix);
       
        
        int count_triangles = 0;
        for (Mesh* triangle : fireIarba_arr)
        { 
            glm:: mat3 triangle_matrix = glm::mat3(1);
            triangle_matrix *= transform2D::Translate(resolution.x - 1280, resolution.y - 630); 
            triangle_matrix *= transform2D:: Translate(count_triangles*35, 0); 
            ++count_triangles;
            RenderMesh2D(meshes[triangle ->GetMeshID()], shaders["VertexColor"], triangle_matrix);
        
        }

       /* modelMatrix = glm::mat3(1);
        modelMatrix *= transform2D::Translate(translateX, translateY);
        modelMatrix *= transform2D::Translate(translateX - 10, translateY - 21);
        modelMatrix = transform2D::RotatePoint(angle, coordonate_cap_v2.x, coordonate_cap_v2.y) * modelMatrix;
        RenderMesh2D(meshes["tinta"], shaders["VertexColor"], modelMatrix);*/
    }
    
    modelMatrix = glm::mat3(1);//primul patrat pt scor 
    modelMatrix *= transform2D::Translate(translateX_Scor, 670);
    RenderMesh2D(meshes["baraScor"], shaders["VertexColor"], modelMatrix);

     modelMatrix = glm::mat3(1);
     modelMatrix *= transform2D::Translate(translateX_scor2 , 670);
     RenderMesh2D(meshes["baraScor2"], shaders["VertexColor"], modelMatrix);


    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_scor3, 670);
    RenderMesh2D(meshes["baraScor3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_scor4, 670);
    RenderMesh2D(meshes["baraScor4"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_scor5, 670);
    RenderMesh2D(meshes["baraScor5"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_inima, 600);
    RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_inima +40, 600);
    RenderMesh2D(meshes["heart2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_inima + 80, 600);
    RenderMesh2D(meshes["heart3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate( translateX_bullet, 550);
    RenderMesh2D(meshes["bullet"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_bullet2 + 20, 550);
    RenderMesh2D(meshes["bullet2"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_bullet3 + 40, 550);
    RenderMesh2D(meshes["bullet3"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_bullet4 + 60, 550);
    RenderMesh2D(meshes["bullet4"], shaders["VertexColor"], modelMatrix);
    
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_bullet5 + 80, 550);
    RenderMesh2D(meshes["bullet5"], shaders["VertexColor"], modelMatrix);

    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(1080, 640);
    RenderMesh2D(meshes["soare"], shaders["VertexColor"], modelMatrix);
    
    modelMatrix = glm::mat3(1);
    modelMatrix *= transform2D::Translate(translateX_contur_scor, 670);
    RenderMesh2D(meshes["contur_bara_scor"], shaders["VertexColor"], modelMatrix);

    
    
   
    
    if (rata_impuscata == true && coordonate_cap_v2.y < 0) {
        translateY = 0;
        translateX = rand() % 450 - 1;
        //rata_impuscata = false;
        rotire_rata = true;
        sx = 1;
        sy =1;
        scor += 10;
        if (nr_rate_impuscate >= 3) {
            speed *= 2;
            cout << "AM OMORAT 3 RATE " << "\n";
        }
       
        check_scor = true;

        //nr_bullet_consumat = 5;
        reincarcare = true;
        
        //bullet_consumat = false;

        rata_impuscata = false;

        //ma_duc_in_sus = false;
        //timp = 0;
        cout << "SCORUL ESTE " << scor << "\n";
    }
    if (scor >= 10 && scor < 20 && check_scor) {
        //translateX_Scor += 50;
        cout << "AM AJUNS" << "\n";
        translateX_Scor = 0;
        //translateX_scor2 = 50;
        check_scor = false;
    }
    //translateX_Scor = 0;
    if (scor >= 20 && scor < 30 && check_scor) {
        //translateX_Scor += 100;
        cout << "AM AJUNS X2" << "\n";
        translateX_scor2 = 50;
        check_scor = false;
    }
    if (scor >= 30 && scor < 40 && check_scor) {
        //translateX_Scor += 100;
        cout << "AM AJUNS X2" << "\n";
        translateX_scor3 = 100;
        check_scor = false;
    }
    if (scor >= 40 && scor < 50 && check_scor) {
        //translateX_Scor += 100;
        cout << "AM AJUNS X2" << "\n";
        translateX_scor4 = 150;
        check_scor = false;
    }
    if (scor >= 50 && scor < 60 && check_scor) {
        //translateX_Scor += 100;
        cout << "AM AJUNS X2" << "\n";
        translateX_scor5 = 200;
        check_scor = false;
    }
    
    if ((coordonate_cap_v2.y > resolution.y || coordonate_cap_v2.y < -5) && ma_duc_in_sus == false)//nu merge fc de getResolution 
    {
        sy = -sy;
        /*if (coordonate_cap_v2.y > 720) {
            coordonate_cap_v2.y = 720;
        }
        if (coordonate_cap_v2.y < -5) {
            coordonate_cap_v2.y = -5;
        }*/
        
        rotire_rata = true;
        //ma_duc_in_sus = true;
        cout << resolution.y<<"\n";
    }
    if (coordonate_cap_v2.x > resolution.x  || coordonate_cap_v2.x < -5)//nu merge fc de getResolution  asa ca am ales sa i dau rez HD
    {
        sx = -sx;
       /* if (coordonate_cap_v2.x > 1280) {
            coordonate_cap_v2.x = 1280;
        }
        if (coordonate_cap_v2.x < -5) {
            coordonate_cap_v2.x = -5;
        }*/
        
        rotire_rata = true;
        cout << resolution.x<<"\n";
    }

    translateX += sx * deltaTimeSeconds * speed_initial *speed;
    translateY += sy * deltaTimeSeconds * speed_initial *speed;

        
    

       if ( rata_impuscata == false && timp > timp_dead_duck) {
                sy = 1;
                sx = 0;
                rotire_rata = true;
                //timp = 0;
                ma_duc_in_sus = true;

                //rata_impuscata = false;//ERA COMEN INAINTE

                //translateX = 0;
                //translateY = 0;
                //coordonate_cap_v2.y = 720;

                //MAGIE
                //timp = 0;

                cout << "MA DUC SUS" << "\n";
                if (timp >= timp_revenire_rata) {
                    translateY = 0;
                    translateX = rand() % 450 - 1;
                    rata_impuscata = false;
                    rotire_rata = true;
                    sx = 1;
                    sy = 1;
                    timp = 0;
                    ma_duc_in_sus = false;

                    check_inima = true;
                    reincarcare = true;

            
                }
        
       }
    
    if (check_inima) {
        translateX_inima3 -= 80;
        translateX_inima2 -= 40;
        translateX_inima -= 40;
        nr_inimi -= 1;
        check_inima = false;
        cout << "NR INIMI ESTE " << nr_inimi << "\n";
    }
    if (bullet_consumat ) {
        translateX_bullet -= 20;
        translateX_bullet2 -= 20;
        translateX_bullet3 -= 20;
        translateX_bullet4 -= 20;
        translateX_bullet5 -= 20;
        nr_bullet_consumat -= 1;
        bullet_consumat = false;
        //rata_impuscata = true;
         cout << " NR BULLET CONSUMAT " << nr_bullet_consumat << "\n";
   
    }

   
    if (nr_bullet_consumat <= 0 && rata_impuscata == false && reincarcare == false) {
        sy = 1;
        sx = 0;
        timp = 9;// ca sa scap de delay

        rotire_rata = true;


        ma_duc_in_sus = true;

       
        cout << "AM CONSUMAT GLOANTELE DECI PLEACA IN SUS" << "\n";
        

        //rata_impuscata = false;

        //if (timp >= timp_revenire_rata - offset_revenire_rata) { // ORICUM NU PREA MAI INTRA PE IF UL ASTA :)))
        //    translateY = 0;
        //    translateX = rand() % 450 - 1;
        //    rata_impuscata = false;
        //    rotire_rata = true;
        //    sx = 1;
        //    sy = 1;
        //    timp = 0;
        //    ma_duc_in_sus = false;

        //    check_inima = true;
        //    reincarcare = true;
        //    cout << "EROARE" << endl;
        //    /* translateX_bullet = translateX_bullet2 = translateX_bullet3 = -140;
        //     translateX_bullet4 = translateX_bullet5 = -140;*/
        //     //nr_bullet_consumat = 5;

        //}

        nr_bullet_consumat = 5;
        //reincarcare = true;//!!!!

        //MAGIE
        //timp = 0;
    }
  
   
    if (reincarcare) {
        translateX_bullet = translateX_bullet2 = translateX_bullet3 = -140;
        translateX_bullet4 = translateX_bullet5 = -140;
        nr_bullet_consumat = 5;
        reincarcare = false;
    }

    //cout << coordonate_cap_v2.x << " " << coordonate_cap_v2.y << endl;
    
    
}


void tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_R) {
        nr_inimi = 3;
        translateX_inima = translateX_inima2 = translateX_inima3 = -130;
        translateX_Scor = translateX_scor2 = translateX_scor3 = -55;
        translateX_scor4 = translateX_scor5 = -55;
        scor = 0;
        timp = 0;
        translateX = 0;
        translateY = 0;
        speed = 1;
        nr_rate_impuscate = 0;
        ma_duc_in_sus = false;
        //cout << "======" << endl;
        //cout << nr_bullet_consumat<<" "<<nr_rate_impuscate<<" "<<speed;
    }
    
}


void tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
    if (ma_duc_in_sus == false && rata_impuscata == false) {
        if (button == 1) {
            //impuscat++;
            bullet_consumat = true;
            //nr_bullet_consumat -= 1;

            
            if ((mouseX - coordonate_corp.x) * (mouseX - coordonate_corp.x) + ((720 - mouseY) - coordonate_corp.y) * ((720 - mouseY) - coordonate_corp.y) < (squareSide/1.5) * (squareSide/1.5)) 
            {
                sy = -1;
                sx = 0;
                rata_impuscata = true;

                nr_rate_impuscate += 1;

                rotire_rata = true;
                timp = 0;

                 //nr_bullet_consumat -= 1;
                 //bullet_consumat = true;
                cout << "MORI" << "\n";
            }

            //cout << coordonate_cap_v2.x << " " << coordonate_cap_v2.y;
           //cout << scor << "\n";


        }
        else {
            cout << "NU MERGE!!" << "\n";
        }

    }
    
    
    
}


void tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void tema1::OnWindowResize(int width, int height)
{
}
