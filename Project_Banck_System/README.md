Bank Client Management System

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

## 📁 Project Files

| 📂 File | 📄 Description | |
|---|---|---|
| main.cpp | Entry point — login loop | [View →](Project_Banck_System/ShowMainMinue/main.cpp) |
| `global.h | Global CurrentUser & status enums | [View →](Project_Banck_System/ShowMainMinue/global.h) |
| clsPerson.h | Base class (FirstName, LastName, Email, Phone) | [View →](Project_Banck_System/ShowMainMinue/clsPerson.h) |
| `clsBankClient.h` | Client entity + file I/O | [View →](Project_Banck_System/ShowMainMinue/clsBankClient.h) |
| `clsUsers.h` | User entity + permissions | [View →](Project_Banck_System/ShowMainMinue/clsUsers.h) |
| `clsDate.h` | Date utilities | [View →](Project_Banck_System/ShowMainMinue/clsDate.h) |
| `clsString.h` | String helper utilities | [View →](Project_Banck_System/ShowMainMinue/clsString.h) |
| `clsUtility.h` | Encryption / Decryption | [View →](Project_Banck_System/ShowMainMinue/clsUtility.h) |
| `clsInputValidate.h` | Input validation helpers | [View →](Project_Banck_System/ShowMainMinue/clsInputValidate.h) |
| `clsScreen.h` | Base screen class | [View →](Project_Banck_System/ShowMainMinue/clsScreen.h) |
| `clsLoginScreen.h` | Login screen | [View →](Project_Banck_System/ShowMainMinue/clsLoginScreen.h) |
| `clsSMainScreen.h` | Main menu screen | [View →](Project_Banck_System/ShowMainMinue/clsSMainScreen.h) |
| `clsClientListScreen.h` | Show all clients | [View →](Project_Banck_System/ShowMainMinue/clsClientListScreen.h) |
| `clsAddNewClients.h` | Add client screen | [View →](Project_Banck_System/ShowMainMinue/clsAddNewClients.h) |
| `clsDeleteClientScreen.h` | Delete client screen | [View →](Project_Banck_System/ShowMainMinue/clsDeleteClientScreen.h) |
| `clsUpdateClientScreen.h` | Update client screen | [View →](Project_Banck_System/ShowMainMinue/clsUpdateClientScreen.h) |
| `clsFindClientScreen.h` | Find client screen | [View →](Project_Banck_System/ShowMainMinue/clsFindClientScreen.h) |
| `clsTransActions.h` | Transactions menu | [View →](Project_Banck_System/ShowMainMinue/clsTransActions.h) |
| `clsDepositScreen.h` | Deposit screen | [View →](Project_Banck_System/ShowMainMinue/clsDepositScreen.h) |
| `clsWithdrawScreen.h` | Withdraw screen | [View →](Project_Banck_System/ShowMainMinue/clsWithdrawScreen.h) |
| `clsTransferScreen.h` | Money transfer screen | [View →](Project_Banck_System/ShowMainMinue/clsTransferScreen.h) |
| `clsMoneyTransferScreen.h` | Money transfer logic screen | [View →](Project_Banck_System/ShowMainMinue/clsMoneyTransferScreen.h) |
| `clsTotalBalancesScreen.h` | Total balances screen | [View →](Project_Banck_System/ShowMainMinue/clsTotalBalancesScreen.h) |
| `clsTransferLogScreen.h` | Transfer log screen | [View →](Project_Banck_System/ShowMainMinue/clsTransferLogScreen.h) |
| `clsManageUsers.h` | Manage users menu | [View →](Project_Banck_System/ShowMainMinue/clsManageUsers.h) |
| `clsUserListScreen.h` | List users screen | [View →](Project_Banck_System/ShowMainMinue/clsUserListScreen.h) |
| `clsAddNewUserScreen.h` | Add user screen | [View →](Project_Banck_System/ShowMainMinue/clsAddNewUserScreen.h) |
| `clsDeleteUserScreen.h` | Delete user screen | [View →](Project_Banck_System/ShowMainMinue/clsDeleteUserScreen.h) |
| `clsUpdateUserScreen.h` | Update user screen | [View →](Project_Banck_System/ShowMainMinue/clsUpdateUserScreen.h) |
| `clsFindUserScreen.h` | Find user screen | [View →](Project_Banck_System/ShowMainMinue/clsFindUserScreen.h) |
| `clsLoginRegistorScreen.h` | Login register screen | [View →](Project_Banck_System/ShowMainMinue/clsLoginRegistorScreen.h) |



## 🗄️ Data Files

| 📄 File | Description |
|---|---|
| `Clients.txt` | Persistent client records |
| `Users.txt` | Persistent user records |
| `TransferLog.txt` | Transfer transaction history |
| `LoginRegistor.txt` | Login activity log |

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
```    ├── Users.txt  [view](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/7e6ea4cbd3a0b9e1ca317111536517fbe220906c/Project_Banck_System/ShowMainMinue/Users.txt)              # Persistent user records
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

bash
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
