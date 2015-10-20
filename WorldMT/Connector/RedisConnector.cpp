#include "RedisConnector.h"

#include <iostream>

using namespace Connector;

static const std::string redisKey = "unique-redis-key-example";
static const std::string redisValue = "unique-redis-value";

void RedisConnector::onConnect(bool connected, const std::string &errorMessage)
{
	if (!connected)
	{
		std::cerr << "Can't connect to redis: " << errorMessage;
	}
	else
	{
		redisClient.command("SET", redisKey, redisValue,
			boost::bind(&RedisConnector::onSet, this, _1));
	}
}

void RedisConnector::onSet(const RedisValue &value)
{
	std::cerr << "SET: " << value.toString() << std::endl;
	if (value.toString() == "OK")
	{
		redisClient.command("GET", redisKey,
			boost::bind(&RedisConnector::onGet, this, _1));
	}
	else
	{
		std::cerr << "Invalid value from redis: " << value.toString() << std::endl;
	}
}

void RedisConnector::onGet(const RedisValue &value)
{
	std::cerr << "GET " << value.toString() << std::endl;
	if (value.toString() != redisValue)
	{
		std::cerr << "Invalid value from redis: " << value.toString() << std::endl;
	}

	redisClient.command("DEL", redisKey,
		boost::bind(&boost::asio::io_service::stop, boost::ref(ioService)));
}
