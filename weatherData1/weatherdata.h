#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QObject>
#include <QJsonObject>
#include<QJsonParseError>
#include<QNetworkAccessManager>
#include<QJsonDocument>
#include<QNetworkReply>
#include<QNetworkRequest>
#include<QTimer>
#include<QDebug>


class weatherdata:public QObject
{
    Q_OBJECT
public:
    QTimer *tmr;
    QJsonDocument doc;
    QJsonObject temp;
    QJsonParseError docEr;
    QNetworkAccessManager *netwMan;
    QNetworkRequest request;
    weatherdata();
    ~weatherdata();
private slots:
    void sendReq();
    void slot_netwMan(QNetworkReply *);



};

#endif // WEATHERDATA_H
