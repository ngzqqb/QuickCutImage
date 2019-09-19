#include "CutImageView.hpp"

namespace sstd{

    namespace qcutimage {

        class CutImageView::Private{
            using TT = CutImageView *;
        public:
            inline static void setSceneCreator(TT thiss,QQmlComponent * arg){
                if( arg == thiss->getSceneCreator() ){
                    return;
                }
                if(thiss->getSceneCreator()){
                     qWarning() << QStringLiteral( "SceneCreator属性是只读的" );
                    return;
                }
                thiss->thisSceneCreatorComponent = arg;
                thiss->sceneCreatorChanged();
                return;
            }
        };

   CutImageView::CutImageView(){
   }

void CutImageView::componentComplete() {
    Super::componentComplete();
}

void CutImageView::setSceneCreator(QQmlComponent * arg){
    Private::setSceneCreator(this,arg);
}


    }/* namespace qcutimage */
}/* namespace sstd */












