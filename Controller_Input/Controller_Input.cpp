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

void PrintButtonState(WORD buttons, WORD buttonMask, const char* buttonName) {
    if (buttons & buttonMask) {
        std::cout << buttonName << " pressed" << std::endl;
    }
}

int main()
{   
    while (true) {
        XINPUT_STATE state = GetControllerState();

        // In state của buttons
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_DPAD_UP, "DPAP UP");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_DPAD_DOWN, "DPAD DOWN");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_DPAD_LEFT, "DPAD LEFT");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_DPAD_RIGHT, "DPAD RIGHT");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_START, "START");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_BACK, "BACK");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_LEFT_THUMB, "LEFT THUMB");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_RIGHT_THUMB, "RIGHT THUMB");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_LEFT_SHOULDER, "LEFT SHOULDER");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_LEFT_SHOULDER, "LEFT SHOULDER");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_A, "A");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_B, "B");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_X, "X");
        PrintButtonState(state.Gamepad.wButtons, XINPUT_GAMEPAD_Y, "Y");

        std::cout << "Left Thumbstick: (" << state.Gamepad.sThumbLX << "," << state.Gamepad.sThumbLY << ")" << std::endl;
        std::cout << "Right Thumbstick: (" << state.Gamepad.sThumbRX << "," << state.Gamepad.sThumbRY << ")" << std::endl;

        std::cout << "Left Trigger: (" << static_cast<int>(state.Gamepad.bLeftTrigger) << std::endl;
        std::cout << "Right Trigger: (" << static_cast<int>(state.Gamepad.bRightTrigger) << std::endl;

        Sleep(2000);
    }

    return 0;
}
