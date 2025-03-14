# CipherCrypt - A Simple Caesar Cipher Encryption & Decryption Tool

## 📜 About
CipherCrypt is a simple C-based program that allows users to encrypt and decrypt text using the Caesar cipher technique. It also maintains a history of all operations performed, allowing users to revisit their past encryptions and decryptions.

## 🔧 Features
- Encrypt and decrypt text using a shift-based Caesar cipher.
- Process and encrypt/decrypt content from a file.
- Maintain a history of all encryption and decryption operations.
- Interactive command-line interface for ease of use.

## 🚀 Usage
1. Clone the repository:
   ```sh
   git clone https://github.com/memehdi14/caesar_cipher.git
   ```
2. Navigate to the project directory:
   ```sh
   cd caesar_cipher
   ```
3. Compile the program:
   ```sh
   gcc caesar_cipher.c -o caesar_cipher
   ```
4. Run the program:
   ```sh
   ./caesar_cipher
   ```

## 📜 How It Works
- The program applies a **Caesar Cipher** shift of `9` to encrypt text.
- Both uppercase and lowercase letters are shifted, while non-alphabetic characters remain unchanged.
- The program allows users to:
  - Encrypt and decrypt user-inputted text.
  - Process text from an external file.
  - View encryption history stored in `cipher_history.txt`.

## 📂 File Structure
```
caesar_cipher/
│── caesar_cipher.c          # Main C program
│── caesar_cipher.txt     # Stores encryption/decryption history
│── README.md              # Documentation
```

## 🛠️ Functions Explained
- `encry()` - Encrypts the input string using Caesar Cipher.
- `decry()` - Decrypts the encrypted string back to the original text.
- `write_to_history()` - Stores encryption and decryption operations in a history file.
- `display_history()` - Displays all past encryption/decryption operations.
- `process_file_content()` - Reads and processes text from a file.
- `print_banner()` - Displays the welcome message.
- `print_menu()` - Shows the available menu options.

## 📜 Example
```
=====================================
|         WELCOME TO CIPHERCRYPT     |
|       ENCRYPT & DECRYPT STRINGS    |
|        HISTORY IS SAVED SAFELY     |
=====================================

------------ MAIN MENU ------------
[1] Encrypt a string
[2] Decrypt a string
[3] View history
[4] Process content from file
[5] Exit
-----------------------------------
```

## 📝 To-Do
- [ ] Add support for custom shift values.
- [ ] Implement a GUI version.
- [ ] Extend support for numeric encryption.

## 🏆 Contributing
Feel free to fork this repository and contribute! If you find any bugs or want new features, open an issue or a pull request.

## 🏷️ License
This project is open-source and licensed under the **MIT License**.

---
⭐ Don't forget to star this repository if you found it useful!


