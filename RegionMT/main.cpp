#include <thread>
#include <boost/asio.hpp>

boost::asio::io_service io_service;

int main(int argc, char** argv)
{

	while (1)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}