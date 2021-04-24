#include <QCoreApplication>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QDebug>
#include <QSslSocket>
#include <QJsonDocument>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString* html = new QString;
    qDebug() << "Start of GET request";

    QNetworkAccessManager manager;
    QNetworkRequest req(QUrl("https://www.google.com/"));
    QNetworkReply* reply = manager.get(req);

    QObject::connect(reply, &QNetworkReply::downloadProgress, [=](qint64 bytesReceived, qint64 bytesTotal) {
        qDebug() << "Progress: " << bytesReceived << "bytes /" << bytesTotal << "bytes";
    });

    QObject::connect(reply, &QNetworkReply::readyRead, [reply, html]() {
        html->append(QString(reply->readAll()));
    });

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        qDebug() << "Done";
        qDebug() << *html;
    });

    return a.exec();
}
