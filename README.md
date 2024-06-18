# Samba Configuration Generator

A C program that uses the `ncurses` library to interactively collect user inputs for Samba share configuration and appends the generated configuration to the `/etc/samba/smb.conf` file.

## Features

- Interactive user interface using `ncurses`.
- Prompts for all necessary Samba configuration parameters.
- Appends configuration to the Samba configuration file `/etc/samba/smb.conf`.

## Requirements

- C compiler (e.g., `gcc`)
- `ncurses` library

## Installation

1. **Clone the repository:**

    ```sh
    git clone https://github.com/erwanclx/SambaGUI.git
    cd samba-config-generator
    ```

2. **Compile the program:**

    ```sh
    apt-get install libncurses5-dev
    gcc -o smbconfig smbconfig.c -lncurses
    ```

## Usage

Run the compiled program with superuser privileges to modify the Samba configuration file:

```sh
sudo ./smbconfig
```

Follow the on-screen prompts to enter the Samba share configuration details:

    Share Name: The name of the shared folder.
    Comment: A description of the shared folder.
    Path: The path to the shared folder on the server.

After entering all the details, the program will append the configuration to /etc/samba/smb.conf.

## Troubleshooting

- Permission Denied: Ensure you run the program with sudo to have the necessary permissions to modify /etc/samba/smb.conf.
- ncurses library not found: Install the ncurses library using your package manager (e.g., sudo apt-get install libncurses5-dev on Debian-based systems).

## TO-DO

- [ ] Browsable
- [ ] Create mask
- [ ] Other config for creation of shared folder
- [ ] Config for general Samba
