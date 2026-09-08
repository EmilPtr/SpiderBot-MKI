import asyncio
from bleak import BleakClient, BleakScanner
from pynput import keyboard

DEVICE = "SpiderBot"

COMMAND_UUID = "6e400002-b5a3-f393-e0a9-e50e24dcca9e"

loop = asyncio.new_event_loop()
asyncio.set_event_loop(loop)

client = None
current_command = None


async def send_command(command):
    global current_command

    if command == current_command:
        return

    current_command = command

    print(f"> {command}")

    await client.write_gatt_char(
        COMMAND_UUID,
        command.encode(),
        response=True
    )


def key_down(key):
    try:
        if key.char == "w":
            asyncio.run_coroutine_threadsafe(
                send_command("FORWARD"), loop
            )

        elif key.char == "s":
            asyncio.run_coroutine_threadsafe(
                send_command("BACKWARD"), loop
            )

        elif key.char == "a":
            asyncio.run_coroutine_threadsafe(
                send_command("LEFT"), loop
            )

        elif key.char == "d":
            asyncio.run_coroutine_threadsafe(
                send_command("RIGHT"), loop
            )

    except AttributeError:
        pass


def key_up(key):
    try:
        if key.char in ("w", "a", "s", "d"):
            asyncio.run_coroutine_threadsafe(
                send_command("STOP"), loop
            )

    except AttributeError:
        pass


async def main():
    global client

    print("Connecting...")

    device = await BleakScanner.find_device_by_name("SpiderBot")

    if device is None:
        print("SpiderBot not found!")
        return

    print(f"Found SpiderBot: {device.address}")

    client = BleakClient(device)
    await client.connect()

    print("Connected!")

    listener = keyboard.Listener(
        on_press=key_down,
        on_release=key_up
    )

    listener.start()

    print("WASD controls active. Press ESC to quit.")

    while listener.is_alive():
        await asyncio.sleep(0.1)

    await client.write_gatt_char(
        COMMAND_UUID,
        b"STOP",
        response=True
    )

    await client.disconnect()


loop.run_until_complete(main())