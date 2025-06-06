# 🔐 Secure File Locker

A C-based command-line tool that allows users to securely encrypt and decrypt files using XOR encryption. The program supports user authentication and tracks encrypted files with metadata.

---

## 📂 Features

- User registration and login system
- File encryption using XOR algorithm
- Secure metadata logging for encrypted files
- File decryption with key verification
- List all encrypted files by user

---

## 📁 Project Structure

```
SecureFileLocker/
├── src/               # C source files
├── include/           # Header files
├── data/
│   └── encrypted_files/  # Encrypted file storage
├── metadata/
│   └── meta.dat       # Metadata of encrypted files
├── README.md
└── Makefile (optional)
```

---

## 🔧 How to Build

Make sure you have GCC installed. Then run:

```bash
gcc -Iinclude src/*.c -o SecureFileLocker
```

---

## ▶️ How to Run

```bash
./SecureFileLocker
```

---

## 🔑 Sample Usage

- Register/Login as a user
- Encrypt a file (stored securely in `data/encrypted_files/`)
- View your encrypted files with metadata
- Decrypt files using your key

---

## 📌 Requirements

- GCC compiler
- Unix-like environment or GitHub Codespaces

---

## 📄 License

This project is licensed under the MIT License.

---

## 👨‍💻 Author

Arunagirinathan  
B.Tech Artificial Intelligence and Data Science  
Passionate about Cybersecurity, AI, and C Programming

---

## 🌐 Connect

- GitHub: [ARUNAGIRINATHAN-K](https://github.com/ARUNAGIRINATHAN-K)
- LinkedIn: [arunagirinathan-k](www.linkedin.com/in/arunagirinathan-k)

