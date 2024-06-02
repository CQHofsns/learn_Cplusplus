#include <iostream>
#include <windows.h>
#include <Xinput.h>

#pragma comment(lib, "Xinput.lib")

// Tạo function Get Controller State để lấy state của Controller
XINPUT_STATE GetControllerState() {
    XINPUT_STATE state;
    ZeroMemory(&state, sizeof(XINPUT_STATE));

    // Lấy state của Controller
    DWORD result = XInputGetState(0, &state);

    if (result != ERROR_SUCCESS) {
        // Handle lỗi Controller không kết nối được (trả về empty state)
        std::cerr << "Controller is not connected" << std::endl;
    }

    return state;
}

int main()
{   
    while (true) {
        XINPUT_STATE state = GetControllerState();

        std::cout << "Button: " << state.Gamepad.wButtons << std::endl;

        std::cout << "Left Thumbstick: (" << state.Gamepad.sThumbLX << "," << state.Gamepad.sThumbLY << ")" << std::endl;
        std::cout << "Right Thumbstick: (" << state.Gamepad.sThumbRX << "," << state.Gamepad.sThumbRY << ")" << std::endl;

        std::cout << "Left Trigger: (" << static_cast<int>(state.Gamepad.bLeftTrigger) << std::endl;
        std::cout << "Right Trigger: (" << static_cast<int>(state.Gamepad.bRightTrigger) << std::endl;

        Sleep(2000);
    }

    return 0;
}
