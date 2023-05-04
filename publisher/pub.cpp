#include <iostream>

#include "myObject.h"
#include "iceoryx_posh/popo/publisher.hpp"
using namespace std;
iox::popo::Publisher<myData> *publisher;

int main()
{
    constexpr char APP_NAME[] = "iox-cpp-publisher-forcedimension-device";
	iox::runtime::PoshRuntime::initRuntime(APP_NAME);
	iox::popo::PublisherOptions options;
	options.historyCapacity = 1U;
	publisher = new iox::popo::Publisher<myData>({"Radar", "FrontLeft", "Object"}, options);

    auto data = publisher->loan();
	int i=0;
	while(i<1000)
	{
	if (!data.has_error())
	{
		auto &sample = data.value();

		sample->isSet = true;
		sample->position[0] = i;
		sample->position[1] = i+1;
		sample->position[2] = i+2;
		
		cout<<sample->position[0]<<" "<<sample->position[1]<<" "<<sample->position[2]<<endl;
		sample.publish();
	}
	else
	{
		auto error = data.get_error();
		cout << "Unable to loan sample, error code: " << error << endl;
	}

	i++;
	}
    return 0;
}