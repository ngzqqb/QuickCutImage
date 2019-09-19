#include "CutImageView.hpp"

namespace sstd{

    namespace qcutimage {

        class CutImageView::Private{
            using TT = CutImageView *;
        public:
            inline static void setSceneCreator(TT thiss,QQmlComponent * arg);
        };

   CutImageView::CutImageView(){
       connect(this,&CutImageView::sceneCreatorChanged,
               this,[this](){
           if(this->thisScene){
               this->thisScene->deleteLater();
               this->thisScene=nullptr;
           }
           auto varContex = qmlContext(this);
           assert(varContex);
           auto varObj = this->getSceneCreator()->beginCreate(varContex);
           auto varItem = qobject_cast<QQuickItem *>(varObj);
           assert(varItem);
           varItem->setParent(this);
           varItem->setParentItem(this);
           this->getSceneCreator()->completeCreate();
           this->thisScene = varItem;
       },Qt::DirectConnection);
   }

void CutImageView::componentComplete() {
    assert( this->thisSceneCreatorComponent );
    Super::componentComplete();
}

void CutImageView::setViewHeight(qreal arg){
    if (std::abs(arg - thisViewHeight ) < std::numeric_limits<float>::epsilon() ){
        return;
    }
    thisViewHeight = arg;
    viewHeightChanged();
}

void CutImageView::setViewWidth(qreal arg){
    if (std::abs(arg - thisViewWidth ) < std::numeric_limits<float>::epsilon() ){
        return;
    }
    thisViewWidth = arg;
    viewWidthChanged();
}

void CutImageView::setSceneCreator(QQmlComponent * arg){
    Private::setSceneCreator(this,arg);
}

inline void CutImageView::Private::setSceneCreator(TT thiss, QQmlComponent *arg){
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

    }/* namespace qcutimage */
}/* namespace sstd */












