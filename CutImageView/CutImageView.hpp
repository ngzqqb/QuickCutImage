#pragma once

#include "../all_in_one.hpp"

namespace sstd{

    namespace qcutimage {

    class CutImageView: public QQuickItem{
        Q_OBJECT
    public:
        CutImageView();
    private:
        using Super = QQuickItem;
        class Private;
        friend class Private;
        QQmlComponent * thisSceneCreatorComponent{ nullptr };
    protected:
        void componentComplete() override;
    };

    }/*namespace qcutimage*/

}/*namespace sstd*/

