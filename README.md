# Hardware ID Retrieval (hardware_id)

This project provides cross-platform C++ modules for retrieving unique hardware identifiers on Linux and Windows. The modules can retrieve system-specific information such as the CPU ID, MAC ID, Hard Disk ID, and Board ID, which are useful for applications requiring hardware identification and low-level system access.

## Features

- **CPU ID**: Uses assembly instructions and system calls to retrieve the unique CPU identifier.
- **MAC ID**: Accesses the MAC address of the primary network interface through direct socket and ioctl system calls.
- **Hard Disk ID**: Obtains the identifier of the primary storage device using ATA and SCSI protocols to interface directly with disk hardware.
- **Board ID**: Retrieves the unique identifier of the motherboard by querying system commands.

The modules are designed to work seamlessly across both **Linux** and **Windows** environments, providing consistent access to hardware information regardless of the operating system.

## Installation

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/Frank-The-Coder/hardware_id.git
   cd hardware_id
   ```

2. Compile the C++ code:

   - **Linux**:
     ```bash
     g++ -o hardware_id *.cpp
     ```
   - **Windows**: Use a compatible C++ compiler (e.g., Visual Studio) to compile the `.cpp` files.

3. Ensure proper permissions are set for system calls, as root or admin privileges may be required for certain hardware queries.

## Usage

After compiling, you can run the modules to retrieve hardware IDs:

```bash
./hardware_id
```

Each function provides direct access to specific hardware identifiers:

- `get_cpu_id()`: Retrieves the CPU identifier.
- `get_mac_address()`: Retrieves the MAC address.
- `get_hard_disk_id()`: Retrieves the hard disk serial number.
- `get_board_id()`: Retrieves the motherboard identifier.

## PHP Integration (Optional)

This project also includes integration as a **PHP extension**, enabling PHP applications to access hardware identifiers directly. When compiled as a PHP extension, the functions are accessible within PHP using custom function names (`ld_get_cpu_id`, `ld_get_mac_addr`, etc.). This integration allows for seamless use of hardware identification within PHP environments.

## Supported Platforms

- **Linux**: Tested on Debian-based and Red Hat-based distributions.
- **Windows**: Compatible with Windows 10 and later.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
