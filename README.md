<div align="center">
  <h1>
    📗 Mini Talk
  </h1>
  <p>
    <b><i>A small data exchange program using UNIX signals</i></b>
  </p>
  <p>
    Developed using&nbsp&nbsp
    <a href="https://skillicons.dev">
      <img src="https://skillicons.dev/icons?i=c,vscode,git" />
    </a>
  </p>
</div>

<br />

## Table Of Content
- [Features](#features)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [License](#license)

## Features
- **Data Transmission:** Send data between processes using the signal mechanism.
- **Signal Handling:** Utilize sigaction to set up custom signal handlers.
- **Bitwise Manipulation:** Translate characters into binary representations for transmission.
- **Error Handling:** Handles potential errors during signal transmission.

## How It Works
1. **Server Initialization:** The server process starts and waits for signals from the client.
2. **Data Preparation:** The client process translates the data into a binary representation.
3. **Data Transmission:** Each bit of the binary representation is transmitted as either a SIGUSR1 (for bit 0) or SIGUSR2 (for bit 1).
4. **Data Reception:** The server receives each signal and reconstructs the original data using bitwise manipulation.
5. **Acknowledgment:** Once the server successfully reconstructs a byte, it sends an acknowledgment signal back to the client.

## Installation
#### Prerequisites
- A UNIX-based operating system (Linux, MacOS).
- A C compiler (e.g., gcc/cc).

1. Clone the repository
```shell
git clone https://github.com/RealConrad/42minitalk.git
```
2. Enter the directory and run `make`
> NOTE: This repo has a git submodule of [42c-library](https://github.com/RealConrad/42c-library). Running `make` will clone this repo for you.
```shell
cd 42minitalk
make
```



## License
[MIT](https://choosealicense.com/licenses/mit/)
