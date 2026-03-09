
# 🏦 Bank Client Management System

A console-based banking application built in **C++** using **Object-Oriented Programming** principles. The system supports full client and user management, financial transactions, and a role-based permission system — all backed by file-based persistence.

---

## 🚀 Features

### 👤 Client Management
- View all bank clients
- Add new clients
- Delete clients
- Update client information
- Find/search for a specific client

### 💸 Transactions
- Deposit funds to an account
- Withdraw funds from an account
- Transfer money between clients
- View transfer log history
- View total balances across all accounts

### 🔐 User Management (Admin)
- List all system users
- Add new users
- Delete users
- Update user information
- Find a specific user

### 🛡️ Authentication & Security
- Login screen with credential validation
- Encrypted password storage via `clsUtility`
- Role-based access control (permissions per user)
- Session management with a global `CurrentUser`
- Login activity logging to `LoginRegistor.txt`

---

## 🏗️ Project Structure


├── main.cpp                     # Entry point — login loop
│
├── Core / Data Layer
│   ├── clsPerson.h              # Base class (FirstName, LastName, Email, Phone)
│   ├── clsBankClient.h          # Client entity (inherits clsPerson) + file I/O
│   ├── clsUsers.h               # User entity (inherits clsPerson) + permissions
│   ├── clsDate.h                # Date utilities
│   ├── clsString.h              # String helper utilities
│   ├── clsUtility.h             # Encryption / Decryption
│   ├── clsInputValidate.h       # Input validation helpers
│   └── global.h                 # Global CurrentUser & status enums
│
├── Screens / UI Layer
│   ├── clsScreen.h              # Base screen class
│   ├── clsLoginScreen.h         # Login screen
│   ├── clsSMainScreen.h         # Main menu screen
│   ├── clsClientListScreen.h    # Show all clients
│   ├── clsAddNewClients.h       # Add client screen
│   ├── clsDeleteClientScreen.h  # Delete client screen
│   ├── clsUpdateClientScreen.h  # Update client screen
│   ├── clsFindClientScreen.h    # Find client screen
│   ├── clsTransActions.h        # Transactions menu
│   ├── clsDepositScreen.h       # Deposit screen
│   ├── clsWithdrawScreen.h      # Withdraw screen
│   ├── clsTransferScreen.h      # Money transfer screen
│   ├── clsTotalBalancesScreen.h # Total balances screen
│   ├── clsTransferLogScreen.h   # Transfer log screen
│   ├── clsManageUsers.h         # Manage users menu
│   ├── clsUserListScreen.h      # List users screen
│   ├── clsAddNewUserScreen.h    # Add user screen
│   ├── clsDeleteUserScreen.h    # Delete user screen
│   ├── clsUpdateUserScreen.h    # Update user screen
│   ├── clsFindUserScreen.h      # Find user screen
│   └── clsLoginRegistorScreen.h # Login register screen
│
└── Data Files
    ├── Clients.txt[view](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/7e6ea4cbd3a0b9e1ca317111536517fbe220906c/Project_Banck_System/ShowMainMinue/Clients.txt)              # Persistent client records
    ├── Users.txt  [view](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/7e6ea4cbd3a0b9e1ca317111536517fbe220906c/Project_Banck_System/ShowMainMinue/Users.txt)              # Persistent user records
    ├── TransferLog.txt          # Transfer transaction history
    └── LoginRegistor.txt        # Login activity log


## ⚙️ How It Works

- Data is stored in **flat `.txt` files** using a `#//# ` delimiter format.
- Each record is serialized/deserialized between objects and file lines.
- Users have a **bitmask permissions** field that controls access to each menu section.
- The `global.h` file holds the `CurrentUser` session object used across all screens.

---

## 🧱 OOP Design

| Concept | Usage |
|---|---|
| **Inheritance** | `clsBankClient` and `clsUsers` both inherit from `clsPerson` |
| **Encapsulation** | Private fields with public accessors in all entity classes |
| **Static Methods** | All screen and file operations are static |
| **Enums** | Used for menu options, modes (Add/Update/Empty), and permissions |
| **Composition** | Screens include and delegate to entity classes |

---

## 🛠️ Build & Run

> Requires a C++ compiler (MSVC / GCC / Clang) with C++11 or later.

```bash
g++ main.cpp -o BankSystem
./BankSystem
```

Or open the project in **Visual Studio** and build directly.

---

## 📌 Notes

- Console application — no GUI.
- All data persisted locally in `.txt` files in the working directory.
- Uses the **"mark for delete"** pattern before removing records from file.
```
