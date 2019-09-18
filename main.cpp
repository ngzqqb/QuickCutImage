#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    /*开启高分屏支持*/
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication varApp(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &varApp, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl){
            QCoreApplication::exit(-1);
         }
    }, Qt::QueuedConnection);
    engine.load(url);

    return varApp.exec();
}
