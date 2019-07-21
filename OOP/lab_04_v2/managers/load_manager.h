#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include "memory"
#include "../download/builder/model_builder.h"
#include "../download/abs_model_loader.h"
#include "../download/base_loader_imp.h"

namespace managers {

using objects::Model;
using namespace download;

class LoadManager: public AbsModelLoader {
public:
    explicit LoadManager(BaseLoader *loader);
    std::shared_ptr<Model> loadModel(std::string source_name, std::string model_name) override;
private:
    std::unique_ptr<BaseLoader> _loader;
    std::unique_ptr<ModelBuilder> _builder;
};

} // namespace uploading

#endif // MODEL_LOADER_H
