#include "qcomport.h"

QComPort::QComPort(QObject *parent) :
    QObject(parent)
{
    comStateflag = 0;
}

 bool QComPort :: openComPort(const QString & name, const PortSettings& settings)
{
    bool flag;
    myCom.setPortName(name);
    myCom.setQueryMode(QextSerialBase::EventDriven);
    flag = myCom.open(QIODevice::ReadWrite);
    myCom.setStopBits(settings.StopBits);
    myCom.setParity(settings.Parity);
    myCom.setFlowControl(settings.FlowControl);
    myCom.setDataBits(settings.DataBits);
    myCom.setBaudRate(settings.BaudRate);

    if(flag == true)
    {
         comStateflag = true;
    }

    return flag;
 }

 void QComPort :: closeComPort(void)
 {
    myCom.close();

    comStateflag = false;
 }

 QString QComPort :: readAll(void)
 {
    QString str=myCom.readAll();
    return str;
 }

 QString QComPort :: readAlltoHex(void)
 {
    QByteArray temp = myCom.readAll();
    QString str;
    QString stt;

    str = temp.toHex();
    str =str.toUpper();
    for(int i = 0 ; i < str.length() ; i += 2)
    {
        stt += str.mid(i,2);
        stt +=" ";
    }

    return stt;
 }
 /*
QString getComValue(int index, QString keyorvalue)
function: Read the name of port in index addr
return : port name
*/
QString QComPort::getComValue(int index, QString keyorvalue)
{
    wchar_t subkey[80];
    wchar_t keyname[256]; //��������
    char keyvalue[256];  //��ֵ����
    int indexnum;
    DWORD keysize,type,valuesize;
    HKEY hKey;

    QString commresult="";
    QString strkey="HARDWARE\\DEVICEMAP\\SERIALCOMM";//�Ӽ�·��
    int a=strkey.toWCharArray(subkey);
    subkey[a]=L'\0';
    if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,subkey,0,KEY_READ|KEY_QUERY_VALUE,&hKey)!=0)
    {
        QString error="Cannot open regedit!";
    }

    QString keymessage="";//����
    QString message="";
    QString valuemessage="";//��ֵ
    indexnum=index;//Ҫ��ȡ��ֵ��������

    keysize=sizeof(keyname);
    valuesize=sizeof(keyvalue);

    if(::RegEnumValue(hKey,indexnum,keyname,&keysize,0,&type,(BYTE*)keyvalue,&valuesize)==0)
    {
        //��ȡ����
        for(uint i=0;i<keysize;i++)
        {
            message=QString::fromStdWString(keyname);
            keymessage.append(message);
        }
        //��ȡ��ֵ
        for(uint j=0;j<valuesize;j++)
        {
            if(keyvalue[j]!=0x00)
            {
                valuemessage.append(keyvalue[j]);
            }
        }

        if(keyorvalue=="key")
        {
            commresult=keymessage;
        }
        if(keyorvalue=="value")
        {
            commresult=valuemessage;
        }
    }
    else
    {
        commresult="nokey";
    }
    ::RegCloseKey(hKey);//�ر�ע���

    return commresult;
}

/*
  QStringList QComPort::readAllComToList(void)
  function:Read all port name
  return :all port name

*/
QStringList QComPort::readAllComToList(void)
{
    QString path="HKEY_LOCAL_MACHINE\\HARDWARE\\DEVICEMAP\\SERIALCOMM";
    QSettings *settings=new QSettings(path,QSettings::NativeFormat);
    QStringList key=settings->allKeys();
    QStringList comlist ;

    int kk = key.size();
    int i;
    comlist.clear();
    for(i=0;i<kk;i++)
    {
         comlist << getComValue(i,"value");
    }

    return comlist;
}


qint64 QComPort::WriteString(QString str)
{
    QByteArray buf=str.toLatin1();

    if(comStateflag == true)
        return myCom.write(buf);
    else
        return -1;
}

qint64 QComPort::WriteHex(QString str)
{
    QByteArray buf=QByteArray::fromHex(str.toLatin1());

    if(comStateflag == true)
        return myCom.write(buf);
    else
        return -1;
}

/*

  function:
  return :

*/
