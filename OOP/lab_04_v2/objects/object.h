#ifndef OBJECT_H
#define OBJECT_H

#include <memory>
#include <string>
#include "../math/point.h"
#include "../math/matrix.h"

namespace objects {

using math::Matrix;

class Object {
public:
    Object() = default;
    Object(std::string name): _name(name) {}
    virtual ~Object() = 0;
    virtual void transform(const std::shared_ptr<Matrix>) = 0;
    std::string getNmae() { return _name; }
private:
    std::string _name;
};

} // namespace objects

#endif // OBJECT_H
