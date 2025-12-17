# Get Started!
To clone this repo write:

## HTTPS
```bash
git clone https://github.com/ludvix/c-starter.git

cd c-starter
```
---

# Setup Linux / WSL
```bash
sudo apt update
sudo apt upgrade -y
sudo apt install build-essential

sudo apt install bear
bear -- make
```
## Use make to recompile easily 
```bash
make
make clean # optional
```
## Run program
```bash
./app
```
---

# Setup macOS
```bash
xcode-select --install

brew install bear
bear -- make

make 
make clean # optional
```
## Run program
```bash
./app
```
---

# Setup Windows
Install MSYS2 from https://www.msys2.org/
Open MSYS2 terminal and update
```bash
pacman -Syu
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make mingw-w64-x86_64-gdb

cd /project-folder/

mingw32-make     # or make if installed via MSYS2
```
## Run program
```bash
app.exe
```
