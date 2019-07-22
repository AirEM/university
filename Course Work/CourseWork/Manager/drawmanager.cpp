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


Vector3d DrawManager::cast_ray(const Vector3d &orig, const Vector3d &dir, const std::shared_ptr<Scene>& scene)
{
    Vector3d point, N;
    Material material;


    if (!(scene->intersect(orig, dir, point, N, material)))
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
    const int fov      = static_cast<int>(M_PI / 2);


    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i < width; i++)
        {
            float x =  (2 * (i + 0.5) /  static_cast<float>(width)  - 1)
                    * tan(fov / 2.0) * width / static_cast<float>(height);

            float y = -(2 * (j + 0.5) / static_cast<float>(height) - 1)
                    * tan(fov / 2.0);

            Vector3d dir = Vector3d(x, y, -1).normalize();

            Vector3d t = cast_ray(Vector3d(0, 0, 0), dir, scene);

            _drawer->setColor(255 * std::max(0.f, std::min(1.f, static_cast<float>(t.getX()))),
                              255 * std::max(0.f, std::min(1.f, static_cast<float>(t.getY()))),
                              255 * std::max(0.f, std::min(1.f, static_cast<float>(t.getZ()))));

            _drawer->drawPoint(static_cast<int>(i), static_cast<int>(j));
        }
    }
}


}
