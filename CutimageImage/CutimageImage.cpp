#include "CutimageImage.hpp"
#include <cassert>

namespace sstd {
    namespace qcutimage {

        class ImageSceneNode : public QSGTransformNode {
            using Super = QSGTransformNode ;
        public:
        };

        class ImageNodeDrawNode : public QSGGeometryNode {
            using Super = QSGGeometryNode;
        public:
        };

        class ImageNode : public QSGTransformNode {
            using Super = QSGTransformNode ;
        public:
        };

        /*******************************************************************/
        class ImageItem{
        public:
            std::shared_ptr< const QImage > image;
        };

        /*******************************************************************/
       class CutimageImage::CutimageImagePrivate{
           CutimageImage * const super;
           ImageItem thisImage;
           ImageSceneNode * thisImageSceneNode{nullptr};
       public:
           inline CutimageImagePrivate(CutimageImage * arg) : super{arg} {
           }
           inline void clearImage();
           inline void rebuildImageNotes();
           inline void setImage( const QImage & );
           inline ImageSceneNode * updateNode(ImageSceneNode *);
           inline void createNode();
       };
       /*******************************************************************/

       CutimageImage::CutimageImage() :
           thisp{new CutimageImagePrivate{this}} {
    }

       void CutimageImage::setImage( const QImage & arg){
           thisp->setImage( arg);
           this->update()       ;
       }

       inline void CutimageImage::CutimageImagePrivate::setImage( const QImage & arg ){
           clearImage();
           if( arg.isNull() ){
                return;
           }
           thisImage.image = std::make_shared<QImage >( arg.copy(/*完整的复制一份 ... */) );
           rebuildImageNotes();
           return;
       }

       inline void CutimageImage::CutimageImagePrivate::clearImage(){
       }

       inline void CutimageImage::CutimageImagePrivate::rebuildImageNotes(){
       }

       QSGNode * CutimageImage::updatePaintNode(QSGNode *oldNode,
                                                QQuickItem::UpdatePaintNodeData *){
          return thisp->updateNode( static_cast< ImageSceneNode * >(oldNode) );
       }

       void CutimageImage::componentComplete()  {
           Super::componentComplete();
            thisp->createNode() ;
       }

      inline void  CutimageImage::CutimageImagePrivate::createNode(){
          if(thisImageSceneNode==nullptr){
              thisImageSceneNode = new ImageSceneNode;
          }
      }

       inline ImageSceneNode * CutimageImage::CutimageImagePrivate::updateNode(ImageSceneNode *arg){
           if( arg == nullptr ){
                return thisImageSceneNode;
           }
           assert( thisImageSceneNode == arg );
           return arg;
       }

    }/* namespace qcutimage */
}/* namespace sstd */


