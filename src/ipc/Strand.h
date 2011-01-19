/*
 * $Id$
 *
 * DEBUG: section 54    Interprocess Communication
 *
 */

#ifndef SQUID_IPC_STRAND_H
#define SQUID_IPC_STRAND_H

#include "ipc/Port.h"
#include "mgr/forward.h"
#include "snmpx/forward.h"


namespace Ipc
{

class StrandCoord;

/// Receives coordination messages on behalf of its process or thread
class Strand: public Port
{
public:
    Strand();

    virtual void start(); // Port (AsyncJob) API

protected:
    virtual void timedout(); // Port (UsdOp) API
    virtual void receive(const TypedMsgHdr &message); // Port API

private:
    void registerSelf(); /// let Coordinator know this strand exists
    void handleRegistrationResponse(const StrandCoord &strand);
    void handleCacheMgrRequest(const Mgr::Request& request);
    void handleCacheMgrResponse(const Mgr::Response& response);
    void handleSnmpRequest(const Snmp::Request& request);
    void handleSnmpResponse(const Snmp::Response& response);

private:
    bool isRegistered; ///< whether Coordinator ACKed registration (unused)

private:
    Strand(const Strand&); // not implemented
    Strand& operator =(const Strand&); // not implemented

    CBDATA_CLASS2(Strand);
};


}


#endif /* SQUID_IPC_STRAND_H */
