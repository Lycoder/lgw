# lgw
Generic, library-agnostic and lightweight helper classes and objects for high performance graphics

## Installing
### Linux
Clone this repository using `git`
```
git clone https://github.com/Lycoder/lgw
```

Install using `make`:
```
make install
```
This will copy the `lgw/` folder into `/usr/include` for straightforward access

### Windows
Clone this repository, just like in Linux, and put the downloaded folder wherever you like, follow the steps below for actually being able to include headers

## Usage
In Linux platforms, just include the desired library into your source code, and it should work, if not, check your global include directories

In Windows, you will have to add the lgw/ folder into your include directories:

### GCC (MinGW/MinGW-w64)
Add an `-I` flag to your commandline:
```
c++ ... -I"path/to/lgw" ...
```

### Visual Studio
Go to Project -> Properties -> C/C++, and add your path in "Additional Include Directories"
