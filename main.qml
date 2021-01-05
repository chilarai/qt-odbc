import QtQuick 2.15
import QtQuick.Window 2.15
//import QtWebEngine 1.8


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Component.onCompleted: {
//        Odbc.mysqlConn() // Mysql
//        Odbc.mssqlConn() // Microsoft SQL Server
//        Odbc.postgresConn() // postgres sql
        Odbc.excelConn() // For excel
//        Odbc.mongoConn() // For mongo db
    }

    Rectangle{
        id: react1
        height: parent.height
        width: parent.width
        color:"gold"
    }

//    WebEngineView{
//        id: web1
//        url: "https://google.com"
//        anchors.fill:parent
//    }
}
