#ifndef _COMMON_CONFIGURATION_CONFIGURATION_H_
#define _COMMON_CONFIGURATION_CONFIGURATION_H_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>

namespace pt = boost::property_tree;

struct RedisConfiguration
{
	std::string hostname;
	uint16_t port;
	std::vector<std::string> channels;

	void load(std::string &filename)
	{
		// Create empty property tree object
		pt::ptree tree;

		// Read JSON to property tree
		pt::read_json(filename, tree);

		// Use the throwing version of get to find the debug filename.
		// If the path cannot be resolved, an exception is thrown.
		hostname = tree.get<std::string>("redis.hostname");
		std::cout << "Hostname: " << hostname << std::endl;

		// Use the default-value version of get to find the debug level.
		// Note that the default value is used to deduce the target type.
		port = tree.get("redis.port", 0);
		std::cout << "Port: " << port << std::endl;

		// Use get_child to find the node containing the modules, and iterate over
		// its children. If the path cannot be resolved, get_child throws.
		// A C++11 for-range loop would also work.
		BOOST_FOREACH(pt::ptree::value_type &v, tree.get_child("redis.channels")) {
			// The data function is used to access the data stored in a node.
			channels.push_back(v.second.data());
			std::cout << "Channel: " << v.second.data() << std::endl;
		}
	}
};

namespace Common
{
	class Configuration
	{
	private:

	public:
		Configuration()
		{
			std::string filePathRedisConfiguration = "config/redis.json";
			RedisConfiguration redisConfig;
			try
			{
				redisConfig.load(filePathRedisConfiguration);
			}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			
		}
	};
}

#endif