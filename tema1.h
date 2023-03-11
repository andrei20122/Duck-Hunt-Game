#pragma once

#include "components/simple_scene.h"
#include <cmath>


namespace m1
{
    class tema1 : public gfxc::SimpleScene
    {
    public:
        tema1();
        ~tema1();

        void Init() override;

    private:
        void CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices);
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        float cx, cy;
        glm::mat3 modelMatrix;
        float translateX, translateY,translateX_Scor,translateX_scor2,translateX_scor3;
        float translateX_inima, translateX_inima2, translateX_inima3;
        float translateX_scor4, translateX_scor5;
        float translateX_bullet, translateX_bullet2, translateX_bullet3, translateX_bullet4, translateX_bullet5;
        float scaleX, scaleY;
        float angularStep;
        float miscare_aripi;

        // TODO(student): If you need any other class variables, define them here.
        bool deplasare_dreapta;
        float tr2X, tr2Y;
        GLenum cullFace;
        GLenum polygonMode;
        float aroundPoint;//variabila careia scalam in jurul ei 
        glm::ivec2 resolution;
        float impuscat;
        glm::vec2 coordonate_cap;
        float sx, sy;//variabile de semn 
        bool rotire_rata;
        float angle;
        glm::vec2 coordonate_cap_v2;
        float squareSide;
        bool rata_impuscata;
        float scor;
        bool check_scor;
        float timp;
        bool ma_duc_in_sus;
        bool check_inima;
        bool bullet_consumat;
        float speed;//viteza ratei
        float size_corpX, size_corpY;
        float size_aripiX, size_aripiY;
        float size_ciocX, size_ciocY;
        float nr_bullet_consumat;
        bool reincarcare;
        float nr_inimi;
        float translateX_contur_scor;
        float timp_revenire_rata,timp_dead_duck;
        int nr_rate_impuscate,a_random,b_random;
        glm::vec3 coordonate_corp;
        float offsetX_aripajos, offsetY_aripajos, offsetX_aripasus;
        float speed_initial;
        float offset_revenire_rata;

    };
}   // namespace m1
