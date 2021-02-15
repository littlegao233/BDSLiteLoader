#include "pch.h"
#include "mc/mass.h"
using namespace std;
#pragma warning(disable:4996)
inline string gettime()
{
	time_t rawtime;
	tm* LocTime;
	char timestr[20];
	time(&rawtime);
	LocTime = localtime(&rawtime);
	strftime(timestr, 20, "%Y-%m-%d %H:%M:%S", LocTime);
	return string(timestr);
}
THook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVDisconnectPacket@@@Z",
	ServerNetworkHandler* _this, NetworkIdentifier& a2, unsigned char* pk) {
	ServerPlayer* sp = _this->_getServerPlayer(a2, pk[16]);
	if (sp) {
		return original(_this, a2, pk);
	}
	else {
		std::cout << "[" << gettime() << u8" INFO][BH] " << u8"收到Disconnect漏洞攻击，已过滤" << endl;
		return;
	}
	std::cout << "[" << gettime() << u8" INFO][BH] " << u8"疑似收到Disconnect漏洞攻击，已过滤" << endl;
}