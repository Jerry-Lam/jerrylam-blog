#include <drogon/drogon.h>
int main() {
    //Set HTTP listener address and port
    // drogon::app().addListener("0.0.0.0",80);
    //Load config file
    drogon::app().loadConfigFile("./config.json");
    //Run HTTP framework,the method will block in the internal event loop
    std::cout << " 123" << std::endl;
    
    drogon::app().run();
    return 0;
}
