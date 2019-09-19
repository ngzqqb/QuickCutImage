#pragma once

#include "../all_in_one.hpp"

namespace sstd{

    namespace qcutimage {

    class CutImageView : public QQuickItem{
        Q_OBJECT
    private:
        Q_PROPERTY(QQmlComponent * sceneCreator READ getSceneCreator WRITE setSceneCreator NOTIFY sceneCreatorChanged)
    private:
        Q_PROPERTY(qreal viewWidth READ getViewWidth WRITE setViewWidth NOTIFY viewWidthChanged)
    private:
        Q_PROPERTY(qreal viewHeight READ getViewHeight WRITE setViewHeight NOTIFY viewHeightChanged)
    public:
        CutImageView();
    public:
        inline QQmlComponent * getSceneCreator()const;
        void setSceneCreator(QQmlComponent *);
        Q_SIGNAL void sceneCreatorChanged();
    public:
        inline qreal getViewWidth() const;
        void setViewWidth(qreal );
        Q_SIGNAL void viewWidthChanged();
    public:
        inline qreal getViewHeight() const;
        void setViewHeight(qreal );
        Q_SIGNAL void viewHeightChanged();
    private:
        using Super = QQuickItem;
        class Private;
        friend class Private;
        QQmlComponent * thisSceneCreatorComponent{ nullptr };
        QQuickItem * thisScene{ nullptr };
        qreal thisViewWidth{ 0 };
        qreal thisViewHeight{ 0 };
    protected:
        void componentComplete() override;
    };

    inline qreal CutImageView::getViewHeight() const{
        return thisViewHeight;
    }

    inline qreal CutImageView::getViewWidth() const{
        return thisViewWidth;
    }

    inline QQmlComponent * CutImageView::getSceneCreator()const{
        return thisSceneCreatorComponent ;
    }

    }/*namespace qcutimage*/

}/*namespace sstd*/

