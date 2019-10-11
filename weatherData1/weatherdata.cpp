#include "weatherdata.h"



weatherdata::weatherdata()
{
    netwMan=new QNetworkAccessManager(this);
    connect(netwMan,SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_netwMan(QNetworkReply*)));
    request.setUrl(QUrl("http://api.openweathermap.org/data/2.5/weather?id=2172797&APPID=4461f835879a91d7505ed8e0a94aff65"));
    tmr=new QTimer();
    tmr->setInterval(4000);
    connect(tmr,SIGNAL(timeout()),this,SLOT(sendReq()));
    tmr->start(4000);
    qDebug() << "Timer started";

}

weatherdata::~weatherdata()
{
    tmr->stop();
    tmr->deleteLater();
    delete netwMan;
}

void weatherdata::sendReq()
{
   qDebug() << "Ok";
   netwMan->get(request);
}

void weatherdata::slot_netwMan(QNetworkReply *rep)
{
    rep->waitForReadyRead(1000);
    doc=QJsonDocument::fromJson(rep->readAll(),&docEr);
    if(docEr.errorString().toInt()==QJsonParseError::NoError){
        temp=doc.object().value("main").toObject();

        qDebug() << "Temp:" <<temp.value("temp").toDouble()-273;
        qDebug() << "Data:" << QDateTime::currentDateTime().date();
        qDebug() << "Time:" << QDateTime::currentDateTime().time().toString();
    }
    rep->deleteLater();
}
