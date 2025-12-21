# File Transfer Server

A simple tcp file transfer server written in C.
The server listens for client connections, receives a filename request from a client and sends the file back to the client.

--- 

### HTTPS

git clone https://github.com/ludvix/file-transfer-server.git

cd file-transfer-client

---

### Setup Linux / WSL

sudo apt update
sudo apt upgrade -y
sudo apt install build-essential

***Optional***
sudo apt install bear
bear -- make

---

### Use make to recompile easily

make 
make clean # optional

---

### How works?

- Server runs on a TCP socket on port 8080
- File you wanna get on the client from the server, has to live in root directory of server
- Client sends a filename
- Then server checks the following:
    - Check if file actually exists
    - Send file content to client
    - Send error message if fails to deliver

--- 

### To test the server

***Start Server***

./app

***Connect using a client***

1. Using my file-transfer-client at: https://github.com/ludvix/file-transfer-client 

Then type the full name of the file you wanna get.
And it should appear in your own dir.
Server should output (File transfer complete!)

---

### Setup macOS

xcode-select --install

***Optional***

brew install bear 
bear -- make

---

### Use make to recompile easily

make
make clean # optional

--- 

### How works?

- Server runs on a TCP socket on port 8080
- File you wanna get on the client from the server, has to live in root directory of server
- Client sends a filename
- Then server checks the following:
    - Check if file actually exists
    - Send file content to client
    - Send error message if fails to deliver

--- 

### To test the server

***Start Server***

./app

***Connect using a client***

1. Using my file-transfer-client at: https://github.com/ludvix/file-transfer-client 

Then type the full name of the file you wanna get.
And it should appear in your own dir.
Server should output (File transfer complete!)

---