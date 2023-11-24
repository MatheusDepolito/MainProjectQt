import QtQuick
import QtQuick.Window
import ModuloComponentes 1.0
import QtQuick.Controls

ApplicationWindow {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")
  color: "black"
  //  IRectangle {
  //    width: 100
  //    height: 100
  //    anchors.centerIn: parent
  //  }
  GraficoNotasAlunos {
    anchors.fill: parent
  }
}
