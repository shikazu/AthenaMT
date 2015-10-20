#ifndef _CONNECTOR_REDISCONNECTOR_H_
#define _CONNECTOR_REDISCONNECTOR_H_

#include <boost/asio.hpp>
#include "../../Common/3rdParty/redisclient/redisasyncclient.h"

namespace Connector
{
	class RedisConnector
	{
	public:
		RedisConnector(boost::asio::io_service &ioService, RedisAsyncClient &redisClient)
			: ioService(ioService), redisClient(redisClient)
		{}

		void onConnect(bool connected, const std::string &errorMessage);
		void onSet(const RedisValue &value);
		void onGet(const RedisValue &value);

	private:
		boost::asio::io_service &ioService;
		RedisAsyncClient &redisClient;
	};
}

#endif