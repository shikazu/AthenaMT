#ifndef _CONNECTOR_REDISACCOUNTSUBSCRIPTION_H_
#define _CONNECTOR_REDISACCOUNTSUBSCRIPTION_H_

#include <string>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio/ip/address.hpp>

#include "../../Common/3rdParty/redisclient/redisasyncclient.h"

class RedisAccountSubscription
{
public:
	RedisAccountSubscription(boost::asio::io_service &ioService)
		: ioService(ioService)
	{
		this->channelName = "Account";
	}

	void onMessage(const std::vector<char> &buf)
	{
		std::string msg(buf.begin(), buf.end());

		std::cerr << "Message: " << msg << std::endl;

		if (msg == "stop")
			ioService.stop();
	}

	void publishHandler(RedisAsyncClient &publisher, const RedisValue &)
	{
		publisher.publish(channelName, "First hello", [&](const RedisValue &) {

		});
	}

private:
	boost::asio::io_service &ioService;
	std::string channelName;
};



#endif