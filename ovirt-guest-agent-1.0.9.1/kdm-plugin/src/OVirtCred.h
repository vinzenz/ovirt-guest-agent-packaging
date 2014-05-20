/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp -v -c OVirtCred -p OVirtCred.h:OVirtCred.cpp credentials.xml
 *
 * qdbusxml2cpp is Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef OVIRTCRED_H_1320323908
#define OVIRTCRED_H_1320323908

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.ovirt.vdsm.Credentials
 */
class OVirtCred: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.ovirt.vdsm.Credentials"; }

public:
    OVirtCred(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~OVirtCred();

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
    void UserAuthenticated(const QString &token);
};

namespace org {
  namespace ovirt {
    namespace vdsm {
      typedef ::OVirtCred Credentials;
    }
  }
}
#endif
