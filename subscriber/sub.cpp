#include <iostream>

// #include "iceoryx_hoofs/posix_wrapper/signal_watcher.hpp"
#include "iceoryx_posh/popo/subscriber.hpp"
// #include "iceoryx_posh/runtime/posh_runtime.hpp"
#include "myObject.h"

using namespace std;

constexpr char APP_NAME[] = "iox-cpp-subscriber-meril-robot-lh";
iox::popo::Subscriber<myData>* subscriber;

int main() {
  iox::runtime::PoshRuntime::initRuntime(APP_NAME);
  subscriber = new iox::popo::Subscriber<myData>({"Radar", "FrontLeft", "Object"});

  auto takeResult = subscriber->take();
  if (!takeResult.has_error() && takeResult.value()->isSet)
  {
    cout<<takeResult.value()->position[0]<<endl;
    cout<<takeResult.value()->position[1]<<endl;
    cout<<takeResult.value()->position[2]<<endl;
  }
  return 0;
}
     