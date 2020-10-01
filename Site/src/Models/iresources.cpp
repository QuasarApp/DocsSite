#include "iresources.h"

IResources::IResources()
{

}

QString IResources::resourcesPath() const {
    return "image://curhost/plugins/images";
}
