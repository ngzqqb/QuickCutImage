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
        if( thiss->getImageCreator() == arg ){
            return;
        }
        if( thiss->getImageCreator() ){
            qWarning() << QStringLiteral( "ImageCreator属性是只读的" );
            return;
        }
        thiss->thisImageCreatorComponent = arg;
        thiss->imageCreatorChanged();
        return;
    }

}/* namespace sstd::qcutimage */

