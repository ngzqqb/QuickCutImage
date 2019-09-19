#include "CutImageScene.hpp"

namespace sstd::qcutimage{

    class CutImageScene::Private{
        using TT = CutImageScene *;
    public:
        inline static void setImageCreator(TT thiss,QQmlComponent *arg);
    };

    CutImageScene::CutImageScene(){
    }

    void CutImageScene::setImageCreator(QQmlComponent * arg){
        Private::setImageCreator(this,arg);
    }

    void CutImageScene::componentComplete(){
        assert( this->thisImageCreatorComponent );
        Super::componentComplete();
    }

    inline void CutImageScene::Private::setImageCreator(TT thiss,QQmlComponent *arg){
        if( thiss->thisImageCreatorComponent == arg ){
            return;
        }
        if( thiss->thisImageCreatorComponent ){
            qWarning() << QStringLiteral( "ImageCreator属性是只读的" );
            return;
        }
        thiss->thisImageCreatorComponent = arg;
        return;
    }

}/* namespace sstd::qcutimage */

