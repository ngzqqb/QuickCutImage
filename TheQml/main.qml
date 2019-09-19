import QtQuick 2.13
import QtQuick.Controls 2.13
import qcutimage 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("快速切图")

    CutImageView  {
        anchors.fill : parent ;
        sceneCreator : CutImageScene{
            imageCreator:Image{
            }
        }
    }

}















