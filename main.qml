﻿import QtQuick 2.13
import QtQuick.Controls 2.13

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("快速切图")

    ScrollView {
        anchors.fill: parent

        ListView {
            width: parent.width
            model: 20
            delegate: ItemDelegate {
                text: "Item " + (index + 1)
                width: parent.width
            }
        }
    }
}
