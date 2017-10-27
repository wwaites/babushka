#include <WifiUdp.h>
#include <Syslog.h>
#include "project.h"
#include "logging.h"

WiFiUDP udpClient;

// Create a new empty syslog instance
Syslog syslog(udpClient, SYSLOG_PROTO_IETF);

void setup_logging(void) {
  syslog.server(SYSLOG_SERV, SYSLOG_PORT);
  syslog.deviceHostname(HOSTNAME);
  syslog.appName(PROGRAM);
  syslog.defaultPriority(LOG_INFO);
}
