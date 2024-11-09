# PHP Hardware ID Extension (hardware_id)

This project provides a PHP extension for retrieving unique hardware identifiers across Linux and Windows platforms. The extension is designed to help obtain various system-specific IDs, such as the CPU ID, MAC ID, Hard Disk ID, and Board ID, useful for system-level applications requiring hardware identification.

## Features

- **CPU ID**: Retrieves the unique CPU identifier.
- **MAC ID**: Accesses the MAC address of the network interface.
- **Hard Disk ID**: Fetches the identifier for the primary storage device.
- **Board ID**: Gets the unique ID of the motherboard.

The extension supports both **Linux** and **Windows** environments, adapting methods to access hardware information based on the operating system.

## Installation

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/Frank-The-Coder/hardware_id.git
   cd hardware_id
   ```

2. Build the extension:

   - **Linux**:
     ```bash
     phpize
     ./configure
     make
     sudo make install
     ```
   - **Windows**: Follow standard PHP extension compilation steps on Windows, ensuring you have the required build tools.

3. Enable the extension by adding it to your `php.ini`:
   ```ini
   extension=phpext.so  # For Linux
   extension=phpext.dll # For Windows
   ```

## Usage

Once installed, you can use the extension functions within your PHP code to retrieve hardware IDs:

```php
<?php
echo "CPU ID: " . get_cpu_id() . PHP_EOL;
echo "MAC ID: " . get_mac_id() . PHP_EOL;
echo "Hard Disk ID: " . get_harddisk_id() . PHP_EOL;
echo "Board ID: " . get_board_id() . PHP_EOL;
?>
```

## Supported Platforms

- **Linux**: Tested on Debian-based and Red Hat-based distributions.
- **Windows**: Compatible with Windows 10 and later.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
