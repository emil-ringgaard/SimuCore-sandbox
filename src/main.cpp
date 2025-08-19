// #include <SimuCore/SimuCoreApplication.hpp>
#include <Application.hpp>
#include <SimuCore/SimuCoreBaseConfig.hpp>
Application* application = new Application();

void setup() {
    application->init();
}

void loop() {
    application->startApp();
    
}
