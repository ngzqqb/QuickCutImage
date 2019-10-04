#pragma once

#include "../all_in_one.hpp"

namespace sstd {
    namespace qcutimage {

        class CutimageImage  : public QQuickItem {
    public:
        class CutimageImagePrivate;
        friend class CutimageImagePrivate;
    public:
        CutimageImage();
    public:
        void setImage( const QImage & );
        protected:
        QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData) override;
        void componentComplete() override;
    private:
        CutimageImagePrivate * const thisp;
        using Super = QQuickItem;
    };

    }/* namespace qcutimage */
}/* namespace sstd */













