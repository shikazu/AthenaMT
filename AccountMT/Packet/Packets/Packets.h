#ifndef _PACKET_PACKETS_PACKETS_H_
#define _PACKET_PACKETS_PACKETS_H_

#include <stdint.h>
#include "../PacketBuffer.h"
#include "../PacketBuilder.h"

/* Packets from Client to Account Server */

// packet 0x64
struct PACKET_CA_LOGIN {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint32_t Version;
	/* this+0x6 */ std::string ID; // [24]
	/* this+0x1e */ std::string Passwd; // [24]
	/* this+0x36 */ uint8_t clienttype;

	PACKET_CA_LOGIN(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x64;
		this->Version = buffer.getData<uint32_t>();
		this->ID = buffer.getString(24);
		this->Passwd = buffer.getString(24);
		this->clienttype = buffer.getData<uint8_t>();
	}
};

// packet 0x1bf
struct PACKET_CA_REPLY_PNGAMEROOM {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint8_t Permission;

	PACKET_CA_REPLY_PNGAMEROOM(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x1bf;
		this->Permission = buffer.getData<uint8_t>();
	}
};

// packet 0x1db
struct PACKET_CA_REQ_HASH {
	/* this+0x0 */ uint16_t PacketType;

	PACKET_CA_REQ_HASH(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x1db;
	}
};

// packet 0x1dd
struct PACKET_CA_LOGIN2 {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint32_t Version;
	/* this+0x6 */ std::string ID; // [24];
	/* this+0x1e */ std::string PasswdMD5; // [16];
	/* this+0x2e */ uint8_t clienttype;

	PACKET_CA_LOGIN2(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x1dd;
		this->Version = buffer.getData<uint32_t>();
		this->ID = buffer.getString(24);
		this->PasswdMD5 = buffer.getString(16);
		this->clienttype = buffer.getData<uint8_t>();
	}
};

// packet 0x1fa
struct PACKET_CA_LOGIN3 {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint32_t Version;
	/* this+0x6 */ std::string ID; // [24];
	/* this+0x1e */ std::string PasswdMD5; // [16];
	/* this+0x2e */ unsigned char clienttype;
	/* this+0x2f */ unsigned char ClientInfo;

	PACKET_CA_LOGIN3(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x1fa;
		this->Version = buffer.getData<uint32_t>();
		this->ID = buffer.getString(24);
		this->PasswdMD5 = buffer.getString(16);
		this->clienttype = buffer.getData<uint8_t>();
		this->ClientInfo = buffer.getData<uint8_t>();
	}
};

// packet 0x200
struct PACKET_CA_CONNECT_INFO_CHANGED {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ std::string ID; // [24];

	PACKET_CA_CONNECT_INFO_CHANGED(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x200;
		this->ID = buffer.getString(24);
	}
};

// packet 0x204
struct PACKET_CA_EXE_HASHCHECK {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ std::string HashValue; // [16];

	PACKET_CA_EXE_HASHCHECK(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x204;
		this->HashValue = buffer.getString(16);
	}
};

// packet 0x258
struct PACKET_CA_REQ_GAME_GUARD_CHECK {
	/* this+0x0 */ uint16_t PacketType;

	PACKET_CA_REQ_GAME_GUARD_CHECK(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x258;
	}
};

// packet 0x264
struct PACKET_CA_ACK_LOGIN_OLDEKEY {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ std::string m_SeedValue; // [9];
	/* this+0xb */ std::string m_EKey; // [9];

	PACKET_CA_ACK_LOGIN_OLDEKEY(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x264;
		this->m_SeedValue = buffer.getString(9);
		this->m_EKey = buffer.getString(9);
	}
};

// packet 0x265
struct PACKET_CA_ACK_LOGIN_NEWEKEY {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ std::string m_SeedValue; // [9];
	/* this+0xb */ std::string m_EKey; // [9];

	PACKET_CA_ACK_LOGIN_NEWEKEY(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x265;
		this->m_SeedValue = buffer.getString(9);
		this->m_EKey = buffer.getString(9);
	}
};

// packet 0x266
struct PACKET_CA_ACK_LOGIN_CARDPASS {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ std::string m_cardPass; // [28];

	PACKET_CA_ACK_LOGIN_CARDPASS(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x266;
		this->m_cardPass = buffer.getString(28);
	}
};

// packet 0x271
struct PACKET_CA_ACK_LOGIN_ACCOUNT_INFO {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t sex;
	/* this+0x4 */ uint16_t bPoint;
	/* this+0x6 */ std::string E_mail; // [34];

	PACKET_CA_ACK_LOGIN_ACCOUNT_INFO(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x271;
		this->sex = buffer.getData<uint16_t>();
		this->bPoint = buffer.getData<uint16_t>();
		this->E_mail = buffer.getString(34);
	}
};

// packet 0x277
struct PACKET_CA_LOGIN_PCBANG {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint32_t Version;
	/* this+0x6 */ std::string ID; // [24];
	/* this+0x1e */ std::string Passwd; // [24];
	/* this+0x36 */ uint8_t clienttype;
	/* this+0x37 */ std::string IP; // [16];
	/* this+0x47 */ std::string MacAdress; // [13];

	PACKET_CA_LOGIN_PCBANG(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x277;
		this->Version = buffer.getData<uint32_t>();
		this->ID = buffer.getString(24);
		this->Passwd = buffer.getString(24);
		this->clienttype = buffer.getData<uint8_t>();
		this->IP = buffer.getString(16);
		this->MacAdress = buffer.getString(13);
	}
};

// packet 0x27c
struct PACKET_CA_LOGIN4 {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint32_t Version;
	/* this+0x6 */ std::string ID; // [24];
	/* this+0x1e */ std::string PasswdMD5; // [16];
	/* this+0x2e */ uint8_t clienttype;
	/* this+0x2f */ std::string macData; // [13];

	PACKET_CA_LOGIN4(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x27c;
		this->Version = buffer.getData<uint32_t>();
		this->ID = buffer.getString(24);
		this->PasswdMD5 = buffer.getString(16);
		this->clienttype = buffer.getData<uint8_t>();
		this->macData = buffer.getString(13);
	}
};

// packet 0x27f
struct PACKET_CA_CLIENT_TYPE {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t ClientType;
	/* this+0x4 */ int32_t nVer;

	PACKET_CA_CLIENT_TYPE(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x27f;
		this->ClientType = buffer.getData<uint16_t>();
		this->nVer = buffer.getData<int32_t>();
	}
};

// packet 0x2b0
struct PACKET_CA_LOGIN_HAN {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint32_t Version;
	/* this+0x6 */ std::string ID; // [24];
	/* this+0x1e */ std::string Passwd; // [24];
	/* this+0x36 */ uint8_t clienttype;
	/* this+0x37 */ std::string m_szIP; // [16];
	/* this+0x47 */ std::string m_szMacAddr; // [13];
	/* this+0x54 */ uint8_t isHanGameUser;

	PACKET_CA_LOGIN_HAN(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x2b0;
		this->Version = buffer.getData<uint32_t>();
		this->ID = buffer.getString(24);
		this->Passwd = buffer.getString(24);
		this->clienttype = buffer.getData<uint8_t>();
		this->m_szIP = buffer.getString(16);
		this->m_szMacAddr = buffer.getString(13);
		this->isHanGameUser = buffer.getData<uint8_t>();
	}
};

// packet 0x822
struct PACKET_CA_OTP_AUTH_REQ {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ std::string OTPCode; //[7];

	PACKET_CA_OTP_AUTH_REQ(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x822;
		this->OTPCode = buffer.getString(7);
	}
};


// packet 0x825a
struct PACKET_CA_SSO_LOGIN_REQa {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t PacketLength;
	/* this+0x4 */ uint32_t Version;
	/* this+0x8 */ uint8_t clienttype;
	/* this+0x9 */ std::string ID; // [24];
	/* this+0x21 */ std::string MacAddr; // [17];
	/* this+0x32 */ std::string IpAddr; // [15];
	/* this+0x41 */ std::string t1;// [...]

	PACKET_CA_SSO_LOGIN_REQa(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x825a;
		this->PacketLength = buffer.getData<uint16_t>();
		this->Version = buffer.getData<uint32_t>();
		this->clienttype = buffer.getData<uint8_t>();
		this->ID = buffer.getString(24);
		this->MacAddr = buffer.getString(17);
		this->IpAddr = buffer.getString(15);

		if (this->PacketLength < 65)
		{
			for (uint16_t i = 0; i < this->PacketLength - 65; i++)
			{
				this->t1.push_back(buffer.getData<char>());
			}
		}
	}
};

// packet 0x825
struct PACKET_CA_SSO_LOGIN_REQ {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t PacketLength;
	/* this+0x4 */ uint32_t Version;
	/* this+0x8 */ uint8_t clienttype;
	/* this+0x9 */ std::string ID; // [24];
	/* this+0x21 */ std::string Passwd; // [27];
	/* this+0x3c */ std::string MacAdress; // [17];
	/* this+0x4d */ std::string IP; // [15];
	/* this+0x5c */ std::string t1; // [...]

	PACKET_CA_SSO_LOGIN_REQ(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x825;
		this->PacketLength = buffer.getData<uint16_t>();
		this->Version = buffer.getData<uint32_t>();
		this->clienttype = buffer.getData<uint8_t>();
		this->ID = buffer.getString(24);
		this->Passwd = buffer.getString(27);
		this->MacAdress = buffer.getString(17);
		this->IP = buffer.getString(15);

		if (this->PacketLength < 92)
		{
			for (uint16_t i = 0; i < this->PacketLength - 92; i++)
			{
				this->t1.push_back(buffer.getData<char>());
			}
		}
	}
};

// packet 0x8cc
struct PACKET_CA_LOGIN5 {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint32_t Version;
	/* this+0x6 */ std::string ID; // [51];
	/* this+0x39 */ std::string Passwd; // [51];
	/* this+0x6c */ uint8_t clienttype;

	PACKET_CA_LOGIN5(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x8cc;
		this->Version = buffer.getData<uint32_t>();
		this->ID = buffer.getString(51);
		this->Passwd = buffer.getString(51);
		this->clienttype = buffer.getData<uint8_t>();
	}
};

// packet 0x987
struct PACKET_CA_LOGIN6 {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint32_t Version;
	/* this+0x6 */ std::string ID; // [24];
	/* this+0x1e */ std::string PasswdMD5; // [32];
	/* this+0x3e */ uint8_t clienttype;

	PACKET_CA_LOGIN6(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x987;
		this->Version = buffer.getData<uint32_t>();
		this->ID = buffer.getString(24);
		this->PasswdMD5 = buffer.getString(32);
		this->clienttype = buffer.getData<uint8_t>();
	}
};

// packet 0x98c
struct PACKET_CA_ACK_NEW_USER {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t Sex;

	PACKET_CA_ACK_NEW_USER(Packet::PacketBuffer &buffer)
	{
		this->PacketType = 0x98c;
		this->Sex = buffer.getData<uint16_t>();
	}
};

/* Packets from Account to Client */

struct SERVER_ADDR { // Size 32
	/* this+0x0 */ uint32_t ip;
	/* this+0x4 */ uint16_t port;
	/* this+0x6 */ std::string name; // [20];
	/* this+0x1a */ uint16_t usercount;
	/* this+0x1c */ uint16_t state;
	/* this+0x1e */ uint16_t property;

	void getPacket(Packet::PacketBuilder &builder)
	{
		builder.append<uint32_t>(&ip);
		builder.append<uint16_t>(&port);
		builder.appendString(name, 20);
		builder.append<uint16_t>(&usercount);
		builder.append<uint16_t>(&state);
		builder.append<uint16_t>(&property);
	}
};

// packet 0x69
struct PACKET_AC_ACCEPT_LOGIN {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t PacketLength;
	/* this+0x4 */ int AuthCode;
	/* this+0x8 */ unsigned long AID;
	/* this+0xc */ unsigned long userLevel;
	/* this+0x10 */ unsigned long lastLoginIP;
	/* this+0x14 */ char lastLoginTime[26];
	/* this+0x2e */ unsigned char Sex;
	/* this+0x2f */ struct SERVER_ADDR ServerList; // [...]
};

// packet 0x6a
struct PACKET_AC_REFUSE_LOGIN {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ unsigned char ErrorCode;
	/* this+0x3 */ char blockDate[20];
};

// packet 0x1be
struct PACKET_AC_ASK_PNGAMEROOM {
	/* this+0x0 */ uint16_t PacketType;
};

// packet 0x1dc
struct PACKET_AC_ACK_HASH {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t PacketLength;
	/* this+0x4 */ unsigned char secret; // [...]
};

// packet 0x1f1
struct PACKET_AC_NOTIFY_ERROR {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t PacketLength;
	/* this+0x4 */ char msg; // [...]
};

// packet 0x23d
struct PACKET_AC_EVENT_RESULT {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ unsigned long EventItemCount;
};

// packet 0x259
struct PACKET_AC_ACK_GAME_GUARD {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ unsigned char ucAnswer;
};

// packet 0x261
struct PACKET_AC_REQ_LOGIN_OLDEKEY {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ char m_SeedValue[9];
};

// packet 0x262
struct PACKET_AC_REQ_LOGIN_NEWEKEY {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ char m_SeedValue[9];
};

// packet 0x263
struct PACKET_AC_REQ_LOGIN_CARDPASS {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ char m_SeedValue[9];
};

// packet 0x267
struct PACKET_AC_ACK_EKEY_FAIL_NOTEXIST {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t errorCode;
};

// packet 0x268
struct PACKET_AC_ACK_EKEY_FAIL_NOTUSESEKEY {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t errorCode;
};

// packet 0x269
struct PACKET_AC_ACK_EKEY_FAIL_NOTUSEDEKEY {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t errorCode;
};

// packet 0x26a
struct PACKET_AC_ACK_EKEY_FAIL_AUTHREFUSE {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t errorCode;
};

// packet 0x26b
struct PACKET_AC_ACK_EKEY_FAIL_INPUTEKEY {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t errorCode;
};

// packet 0x26c
struct PACKET_AC_ACK_EKEY_FAIL_NOTICE {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t errorCode;
};

// packet 0x26d
struct PACKET_AC_ACK_EKEY_FAIL_NEEDCARDPASS {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t errorCode;
};

// packet 0x26e
struct PACKET_AC_ACK_AUTHEKEY_FAIL_NOTMATCHCARDPASS {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t errorCode;
};

// packet 0x26f
struct PACKET_AC_ACK_FIRST_LOGIN {
	/* this+0x0 */ uint16_t PacketType;
};

// packet 0x270
struct PACKET_AC_REQ_LOGIN_ACCOUNT_INFO {
	/* this+0x0 */ uint16_t PacketType;
};

// packet 0x272
struct PACKET_AC_ACK_PT_ID_INFO {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ char szPTID[21];
	/* this+0x17 */ char szPTNumID[21];
};

// packet 0x276
struct PACKET_AC_ACCEPT_LOGIN2 {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t PacketLength;
	/* this+0x4 */ int AuthCode;
	/* this+0x8 */ unsigned long AID;
	/* this+0xc */ unsigned long userLevel;
	/* this+0x10 */ unsigned long lastLoginIP;
	/* this+0x14 */ char lastLoginTime[26];
	/* this+0x2e */ unsigned char Sex;
	/* this+0x2f */ int iAccountSID;
};

// packet 0x2ad
struct PACKET_AC_REQUEST_SECOND_PASSWORD {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t Result;
	/* this+0x4 */ unsigned long dwSeed;
};

// packet 0x821
struct PACKET_AC_OTP_USER {
	/* this+0x0 */ uint16_t PacketType;
};

// packet 0x823
struct PACKET_AC_OTP_AUTH_ACK {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ uint16_t PacketLength;
	/* this+0x4 */ unsigned short LoginResult;
};

// packet 0x826
struct PACKET_AC_SSO_LOGIN_ACK {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ unsigned short Result;
};

// packet 0x83e
struct PACKET_AC_REFUSE_LOGIN_R2 {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ unsigned int ErrorCode;
	/* this+0x6 */ char blockDate[20];
};

// packet 0x8e4
struct PACKET_AC_SHUTDOWN_INFO {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ long Time;
};

// packet 0x986
struct PACKET_AC_SHUTDOWN_NOTIFY {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ long Time;
	/* this+0x6 */ long ServerTime;
};

// packet 0x98b
struct PACKET_AC_REQ_NEW_USER {
	/* this+0x0 */ uint16_t PacketType;
};

// packet 0x9a2
struct PACKET_AC_REQ_MOBILE_OTP {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ unsigned long AID;
};

// packet 0x9a5
struct PACKET_AC_REFUSE_LOGIN3 {
	/* this+0x0 */ uint16_t PacketType;
	/* this+0x2 */ unsigned char ErrorCode;
	/* this+0x3 */ long BlockedReaminSEC;
};

#endif
