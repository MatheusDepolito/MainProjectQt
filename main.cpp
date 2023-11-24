#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setOrganizationName("Dep Corp");
    app.setOrganizationDomain("Dep Corp");
    app.setApplicationName("Dep Corp");

    QQmlApplicationEngine engine;
    engine.load(QUrl(u"qrc:/dep/imports/IdealArc/Main.qml"_qs));
    engine.addImportPath(":/dep/imports");
    return app.exec();
}
