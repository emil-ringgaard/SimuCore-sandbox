#include <Application.hpp>
#include <SimuCore/SimuCoreBaseConfig.hpp>
#include <memory>
#include <iostream>
Application *application = new Application();

void setup()
{
	application->initApp();
}

void loop()
{
	application->run();
}
