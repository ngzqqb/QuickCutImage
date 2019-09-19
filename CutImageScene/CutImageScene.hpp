#pragma once

#include "../all_in_one.hpp"

namespace sstd{

    namespace qcutimage {

    class CutImageScene : public QQuickItem {
        Q_OBJECT
    private:
        Q_PROPERTY(QQmlComponent * imageCreator READ getImageCreator WRITE setImageCreator NOTIFY imageCreatorChanged)
    public:
        CutImageScene();
    public:
        inline QQmlComponent * getImageCreator() const;
        void setImageCreator(QQmlComponent *);
        Q_SIGNAL void imageCreatorChanged();
    private:
        using Super = QQuickItem;
        class Private;
        friend class Private;
        QQmlComponent * thisImageCreatorComponent{ nullptr };
    protected:
        void componentComplete() override;
    };

    inline QQmlComponent * CutImageScene::getImageCreator() const{
        return thisImageCreatorComponent;
    }

    }/*namespace qcutimage*/

}/*namespace sstd*/

