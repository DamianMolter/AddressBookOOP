# Address Book Application

A console-based address book management system written in C++ that allows multiple users to manage their personal contacts with full CRUD (Create, Read, Update, Delete) functionality.

## Features

### User Management
- **User Registration**: Create new user accounts with unique usernames
- **User Login**: Secure authentication with password verification (3 attempts limit)
- **Password Change**: Logged-in users can update their passwords
- **User Logout**: Safe session termination with proper memory cleanup

### Contact Management
- **Add Recipients**: Store contact information including name, surname, phone number, email, and address
- **Display All Recipients**: View complete list of all contacts for the logged-in user
- **Search by Name**: Find contacts by first name
- **Search by Surname**: Find contacts by last name
- **Edit Recipients**: Update any field of existing contacts (name, surname, phone, email, address)
- **Delete Recipients**: Remove contacts with confirmation prompt

## Technical Architecture

### Object-Oriented Design
The application follows OOP principles with clear separation of concerns:

- **AddressBook**: Main application controller orchestrating user and recipient management
- **UserManager**: Handles all user-related operations and authentication
- **RecipientManager**: Manages contact operations for logged-in users
- **UserFile & RecipientFile**: Handle file I/O operations with inheritance from TextFile base class
- **User & Recipient**: Data model classes representing entities
- **AuxiliaryMethod**: Utility class with static helper methods for data conversion and input validation

### Key Design Patterns
- **Composition**: AddressBook contains UserManager and dynamically allocates RecipientManager
- **Inheritance**: File classes inherit from TextFile base class for common file operations
- **Encapsulation**: Private helper methods and protected file operations
- **Resource Management**: Proper memory management with destructor cleanup

## Data Persistence

### File Structure
- **Users.txt**: Stores user credentials in pipe-delimited format: `userId|userName|password|`
- **Recipients.txt**: Stores contacts in pipe-delimited format: `recipientId|userId|name|surname|telephone|email|address|`

### File Operations
- Automatic file creation if not exists
- Line-by-line reading and parsing
- Temporary file strategy for safe updates and deletions
- User-specific data isolation (each user only sees their own contacts)

## User Interface

### Main Menu (Not Logged In)
```
>>> MAIN MENU <
---------------------------
1. Register
2. Sign In
9. Exit Program
---------------------------
```

### User Menu (Logged In)
```
>>> USER MENU <
---------------------------
1. Add Recipient
2. Search by Name
3. Search by Surname
4. Display All Recipients
5. Delete Recipient
6. Edit Recipient
---------------------------
7. Change Password
8. Logout
---------------------------
```

## Implementation Details

### Input Validation
- Character input validation for menu selections
- Integer input validation for ID selections
- String input with automatic case formatting (first letter uppercase, rest lowercase)

### Data Processing
- String-to-integer and integer-to-string conversions
- Pipe-delimited data parsing
- Automatic ID generation for new records

### Memory Management
- Dynamic allocation of RecipientManager only when user is logged in
- Proper cleanup in destructors and logout operations
- NULL pointer checks before deletion

## Building and Running

### Prerequisites
- C++ compiler with C++11 support or higher
- Windows environment (uses `windows.h` for `system("cls")` and `system("pause")`)

### Compilation
```bash
g++ -std=c++11 main.cpp AddressBook.cpp UserManager.cpp RecipientManager.cpp \
    UserFile.cpp RecipientFile.cpp TextFile.cpp User.cpp Recipient.cpp \
    AuxiliaryMethod.cpp -o addressbook
```

### Execution
```bash
./addressbook
```

## File Structure
```
├── main.cpp                    # Application entry point
├── AddressBook.h/cpp          # Main application controller
├── UserManager.h/cpp          # User management logic
├── RecipientManager.h/cpp     # Contact management logic
├── UserFile.h/cpp             # User file I/O operations
├── RecipientFile.h/cpp        # Contact file I/O operations
├── TextFile.h/cpp             # Base file operations class
├── User.h/cpp                 # User data model
├── Recipient.h/cpp            # Contact data model
├── AuxiliaryMethod.h/cpp      # Utility functions
└── Plan/                      # UML class diagram
```

## Security Considerations
- Passwords are stored in plain text (not recommended for production use)
- User isolation ensures contacts are private to each user
- Login attempt limiting (3 tries) prevents brute force attacks

## Future Enhancements
- Password encryption/hashing
- Export contacts to various formats
- Import contacts from files
- Advanced search with multiple criteria
- Contact grouping and categorization
- Cross-platform compatibility (remove Windows-specific calls)

## License
This is an educational project demonstrating OOP principles in C++.