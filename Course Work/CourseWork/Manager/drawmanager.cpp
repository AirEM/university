#include "drawmanager.h"

namespace manager {

void DrawManager::setSize(int w, int h)
{
    this->_width = w;
    this->_height = h;
}

void DrawManager::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    this->_drawer = drawer;
}


Vector3d DrawManager::cast_ray(const Vector3d &camera_position, const Vector3d &dir, const std::shared_ptr<Scene>& scene)
{
    Vector3d point, N;
    Material material;


    if (!(scene->intersect(camera_position, dir, point, N, material)))
    {
        return Vector3d(1, 1, 1); // background color
    }

    // Точечное освещение

    float diffuse_light_intensity = 1.0;
    float specular_light_intensity = 0;

    auto lights = scene->getLights();

    if (lights.size())
    {
        diffuse_light_intensity = 0;


        for (size_t i=0; i < lights.size(); i++)
        {
            Vector3d light_dir = (lights[i]->getPosition() - point).normalize();

            // =============================== Тени  ============================
            float light_distance = (lights[i]->getPosition() - point).length();

            Vector3d shadow_orig = light_dir*N < 0 ? point - N * static_cast<float>(1e-3) : point + N * static_cast<float>(1e-3);
            // checking if the point lies in the shadow of the lights[i]

            Vector3d shadow_pt, shadow_N;

            Material tmpmaterial;
            // scene_intersect(shadow_orig, light_dir, spheres, shadow_pt, shadow_N, tmpmaterial)
            if (scene->intersect(shadow_orig, light_dir, shadow_pt, shadow_N, tmpmaterial) && (shadow_pt-shadow_orig).length() < light_distance)
                continue;

            // ==================================================================

            diffuse_light_intensity  += static_cast<float>(lights[i]->getIntensity()) * std::max(0.f, static_cast<float>(light_dir*N));

            specular_light_intensity += powf( std::max(0.f,  static_cast<float>(reflect(light_dir * -1.0, N)*dir) ) * -1.0,
                                              material.getSpecular() )
                    * lights[i]->getIntensity();
        }
    }

    return material.getDiffuse() * diffuse_light_intensity * material.getAmbient().getX() + Vector3d(1., 1., 1.)*specular_light_intensity * material.getAmbient().getY();

}

Vector3d DrawManager::reflect(const Vector3d &I, const Vector3d &N)
{
    return I - N * static_cast<float>(2.f) * (I*N);
}


void DrawManager::render(std::shared_ptr<Scene>& scene)
{
    const int width    = _width;
    const int height   = _height;
    const float fov    = static_cast<float>(M_PI / 3);


    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            // Высчитываем направления текущего луча
            float dir_x =  (i + 0.5f) -  width/2.0f;
            float dir_y = -(j + 0.5f) + height/2.0f;
            float dir_z = -height / (2.0f * tanf( fov / 2.0f) );


            // Нормализованное напрваление текущего луча
            Vector3d dir = Vector3d(dir_x, dir_y, dir_z).normalize();

            // Цвет текущего пткселя
            Vector3d res_color = cast_ray(Vector3d(0, 0, 0), dir, scene);

            int r = int(roundf(255 *res_color.getX()));
            int g = int(roundf(255 *res_color.getY()));
            int b = int(roundf(255 *res_color.getZ()));

            _drawer->setColor(r, g, b);
            _drawer->drawPoint(i, j);
        }
    }
}


}
