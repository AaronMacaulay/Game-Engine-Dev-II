#include "PolarEngine.h"
#include <direct.h>
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <SplashScreen.h>

PolarEngine::GameState PolarEngine::_gameState;
GameObjectManager PolarEngine::_gameObjectManager;
bool PolarEngine::Uninitialized = false;
sf::RenderWindow PolarEngine::_renderWindow;

// Free disk space required in MB
const int REQUIRED_DISK_SPACE = 150;
// Min total RAM in GB
const long REQUIRED_MEMORY = 2;
// Min CPU speed in Ghz
const long REQUIRED_CLOCK_SPEED = 2.5;

void PolarEngine::Initialize() {
	//Splash goes here

	//Check sys requirements

	//Disk space check

	_int64 lpFreeBytesAvailable, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes;
	GetDiskFreeSpaceEx(NULL, (PULARGE_INTEGER)&lpFreeBytesAvailable, (PULARGE_INTEGER)&lpTotalNumberOfBytes, (PULARGE_INTEGER)&lpTotalNumberOfFreeBytes);
	int diskAvailable = lpFreeBytesAvailable / (1024 * 1024);
	std::cout << "Free Disk Space Available: " << diskAvailable << "MB" << std::endl;
	if (diskAvailable < REQUIRED_DISK_SPACE)
	{
		std::cout << "Not enough free space available.";
		return;
	}

	//Check Memory
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	unsigned long memoryAvailable = (unsigned long)status.ullTotalPhys / (1024 * 1024);
	std::cout << "Total Memory Available: " << memoryAvailable << "MB" << std::endl;
	if (memoryAvailable < REQUIRED_MEMORY * 1024)
	{
		std::cout << "Not enough memory available.";
		return;
	}

	//Check CPU clock speed
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	//Open the key where the processor speed is hidden
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0.KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS)
	{
		RegQueryValueEx(hKey, "~Mhz", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
	}
	std::cout << "CPU speed at " << dwMHz << "MHz." << std::endl;
	if ((unsigned long)dwMHz < REQUIRED_CLOCK_SPEED * 1024)
	{
		std::cout << "CPU speed is too slow.";
		return;
	}
	isInitialized = true;
}

void PolarEngine::GameLoop()
{
	//update all systems
	_gameObjectManager.Update(0);

	//late update all systems
	_gameObject < anager.LateUpdate(0);
}

void PolarEngine::LevelLoaded()
{
	_gameObjectManager.Awake();
	//awake other systems

	_gameObjectManager.Start();
	// start other systems
}

void PolarEngine::Start(void)
{
	if (!isInitialized)
		return;

	std::cout << "Initialized";

	//Graphics initialization
	_renderWindow.create(sf::VideoMode(800, 600), "Lions Arc");
	//Audio initialization
	//Physics initialization

	//Create Splash Screen
	PushStateToStack(std::make_unique<SplashScreen>());

	while (_renderWindow.isOpen())
	{
		sf::Event event;
		while (_renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_renderWindow.close();
		}
		_renderWindow.clear();
		if (!StateStack.empty())
		{
			StateStack.top()->Render();
		}
		_renderWindow.display();
	}

	_gameState = PolarEngine::Playing;

	while (!IsExiting())
	{
		GameLoop;
	}

	//_mainWindow.Close();
}

void PolarEngine::PushStateToStack(State::Ptr state)
{
	StateStack.push(state);
}

void PolarEngine::PopStateStack()
{
	StateStack.pop();
}

bool PolarEngine::IsExiting()
{
	return true;
}
