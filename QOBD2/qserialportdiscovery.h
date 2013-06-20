/*!
  \class QSerialPortDiscovery
  \brief The QSerialPortDiscovery class lists all serial ports plugged in the system and lists also all OBD devices on the system
  */

#ifndef QSERIALPORTDISCOVERY_H
#define QSERIALPORTDISCOVERY_H

#define READ_TIMEOUT 50

#include "serialportsettings.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QObject>

class QSerialPortDiscovery : public QObject
{
    Q_OBJECT
public:    
    explicit QSerialPortDiscovery(QObject *parent = 0);

    QList<QSerialPortInfo> *getSerialPortList();
    QList<QSerialPortInfo> *getOBDSerialPortList(SerialPortSettings settings);
private:
    bool isOBDDevice(QSerialPort *serialPort);
    void openPort(QSerialPort *serialPort, SerialPortSettings *settings);

signals:
    void error(const QString);
    
};

#endif // QSERIALPORTDISCOVERY_H
