
# 🏦 Bank Client Management System

A console-based banking application built in **C++** using **Object-Oriented Programming** principles. The system supports full client and user management, financial transactions, a role-based permission system, and a complete currency exchange module — all backed by file-based persistence.

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

### 💱 Currency Exchange *(New)*
- List all available currencies
- Find a specific currency by code
- Update currency exchange rates
- Currency Calculator — convert any amount between currencies
- Data persisted in `Currencies.txt`

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
| `main.cpp` | Entry point — login loop | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/ShowMainMinue.cpp) |
| `global.h` | Global CurrentUser & status enums | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/global.h) |
| `clsPerson.h` | Base class (FirstName, LastName, Email, Phone) | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsPerson.h) |
| `clsBankClient.h` | Client entity + file I/O | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsBankClient.h) |
| `clsUsers.h` | User entity + permissions | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsUsers.h) |
| `clsCurrency.h` | Currency entity + file I/O | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsCurrency.h) |
| `clsDate.h` | Date utilities | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsDate.h) |
| `clsString.h` | String helper utilities | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsString.h) |
| `clsUtility.h` | Encryption / Decryption | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsUtility.h) |
| `clsInputValidate.h` | Input validation helpers | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsInputValidate.h) |
| `clsScreen.h` | Base screen class | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsScreen.h) |
| `clsLoginScreen.h` | Login screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsLoginScreen.h) |
| `clsSMainScreen.h` | Main menu screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsSMainScreen.h) |
| `clsClientListScreen.h` | Show all clients | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsClientListScreen.h) |
| `clsAddNewClients.h` | Add client screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsAddNewClients.h) |
| `clsDeleteClientScreen.h` | Delete client screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsDeleteClientScreen.h) |
| `clsUpdateClientScreen.h` | Update client screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsUpdateClientScreen.h) |
| `clsFindClientScreen.h` | Find client screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsFindClientScreen.h) |
| `clsTransActions.h` | Transactions menu | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsTransActions.h) |
| `clsDepositScreen.h` | Deposit screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsDepositScreen.h) |
| `clsWithdrawScreen.h` | Withdraw screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsWithdrawScreen.h) |
| `clsMoneyTransferScreen.h` | Money transfer screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsMoneyTransferScreen.h) |
| `clsTotalBalancesScreen.h` | Total balances screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsTotalBalancesScreen.h) |
| `clsTransferLogScreen.h` | Transfer log screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsTransferLogScreen.h) |
| `clsManageUsers.h` | Manage users menu | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsManageUsers.h) |
| `clsUserListScreen.h` | List users screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsUserListScreen.h) |
| `clsAddNewUserScreen.h` | Add user screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsAddNewUserScreen.h) |
| `clsDeleteUserScreen.h` | Delete user screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsDeleteUserScreen.h) |
| `clsUpdateUserScreen.h` | Update user screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsUpdateUserScreen.h) |
| `clsFindUserScreen.h` | Find user screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsFindUserScreen.h) |
| `clsLoginRegistorScreen.h` | Login register screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsLoginRegistorScreen.h) |
| `clsCurrencyMainScreen.h` | Currency exchange main menu | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsCurrencyMainScreen.h) |
| `clsCurrenciesListScreen.h` | List all currencies screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsCurrenciesListScreen.h) |
| `clsFindCurrencyScreen.h` | Find currency screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsFindCurrencyScreen.h) |
| `clsUpdateCurrencyRateScreen.h` | Update currency rate screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsUpdateCurrencyRateScreen.h) |
| `clsCurrencyCalculatorScreen.h` | Currency calculator screen | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/clsCurrencyCalculatorScreen.h) |

---

## 🗄️ Data Files

| 📄 File | Description | |
|---|---|---|
| `Clients.txt` | Persistent client records | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/Clients.txt) |
| `Users.txt` | Persistent user records | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/Users.txt) |
| `Currencies.txt` | Currency codes, names, and exchange rates | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/Currencies.txt) |
| `TransferLog.txt` | Transfer transaction history | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/TransferLog.txt) |
| `LoginRegistor.txt` | Login activity log | [View →](https://github.com/SaiedNasef78/Course11-OOP-as-it-Should-Be/blob/main/Project_Banck_System/ShowMainMinue/LoginRegistor.txt) |

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
