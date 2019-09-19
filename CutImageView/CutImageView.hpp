#pragma once

#include "../all_in_one.hpp"

namespace sstd{

    namespace qcutimage {

    class CutImageView: public QQuickItem{
        Q_OBJECT
    public:
        CutImageView();
    public:
        inline QQmlComponent * getSceneCreator()const;
        void setSceneCreator(QQmlComponent *);
        Q_SIGNAL void sceneCreatorChanged();
    private:
        using Super = QQuickItem;
        class Private;
        friend class Private;
        QQmlComponent * thisSceneCreatorComponent{ nullptr };
    protected:
        void componentComplete() override;
    };

    inline QQmlComponent * CutImageView::getSceneCreator()const{
        return thisSceneCreatorComponent ;
    }

    }/*namespace qcutimage*/

}/*namespace sstd*/

