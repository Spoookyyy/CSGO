#include "memory.h"
#include "thread"
#include <iostream>

namespace offsets
{
	constexpr ::std::ptrdiff_t dwLocalPlayer = 0xDEA964;
	constexpr ::std::ptrdiff_t m_fFlags = 0x104;
	constexpr ::std::ptrdiff_t dwForceJump = 0x52BBC7C;
}


int main()
{

	const auto JUMP_KEY = VK_SPACE; // EDIT JUMP KEY

	bool isJumping = false;

	const auto memory = Memory("csgo.exe");

	const auto client = memory.GetModuleAddress("client.dll");



	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(5));

		const auto localPlayer = memory.Read<uintptr_t>(client + offsets::dwLocalPlayer);

		if (!localPlayer) continue;
		
		const auto onGround = memory.Read<bool>(localPlayer + offsets::m_fFlags);

		if (GetAsyncKeyState(JUMP_KEY)) {
			if (isJumping) {
				isJumping = !isJumping;
			}
			else {
				isJumping = !isJumping;
			}
		};

		

		if (isJumping) {
			memory.Write<BYTE>(client + offsets::dwForceJump, 6);
		}
		
	}

}
