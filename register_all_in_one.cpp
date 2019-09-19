
#include "all_in_one.hpp"

namespace sstd::qcutimage {

    void detailRegisterAllInOne(){
        qmlRegisterType<CutImageScene>("qcutimage",1,0,"CutImageScene");
        qmlRegisterType<CutImageScene>("qcutimage",1,0,"CutImageView");
        qmlProtectModule(              "qcutimage",1);
    }

    extern void registerAllInOne(){
        detailRegisterAllInOne();
    }

}/* namespace sstd::qcutimage */


