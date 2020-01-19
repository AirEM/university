#include "../managers/transformer_manager.h"

namespace managers {

void TransformerManager::rotateObjectX(std::shared_ptr<Object> obj, double angle) {
    angle = degreesToRadians(angle);
    std::shared_ptr<Matrix> transform_matrix(new RotateOxMatrix(angle));
    obj->transform(transform_matrix);
}

void TransformerManager::rotateObjectY(std::shared_ptr<Object> obj, double angle) {
    angle = degreesToRadians(angle);
    std::shared_ptr<Matrix> transform_matrix(new RotateOyMatrix(angle));
    obj->transform(transform_matrix);
}

void TransformerManager::rotateObjectZ(std::shared_ptr<Object> obj, double angle) {
    angle = degreesToRadians(angle);
    std::shared_ptr<Matrix> transform_matrix(new RotateOzMatrix(angle));
    obj->transform(transform_matrix);
}

void TransformerManager::moveObject(std::shared_ptr<Object> obj, int x, int y, int z) {
    std::shared_ptr<Matrix> transform_matrix(new MoveMatrix(x, y, z));
    obj->transform(transform_matrix);
}

void TransformerManager::scaleObject(std::shared_ptr<Object> obj, double x, double y, double z) {
    std::shared_ptr<Matrix> transform_matrix(new ScaleMatrix(x, y, z));
    obj->transform(transform_matrix);
}

double TransformerManager::degreesToRadians(double angle) {
    return angle / 180. * 3.1415926535;
}

} // namespace transformations
