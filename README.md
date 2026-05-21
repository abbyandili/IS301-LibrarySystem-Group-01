# IS301-LibrarySystem-Group-01
IS301 Major Project 
## Administrator User Manual

Welcome to the **Library Management System (LMS)** Administrator User Manual. This comprehensive document guides you through operating the system, managing library inventory, updating member profiles, and tracking book transactional data.

---

## 1. System Overview & Architecture

The LMS is a modular, CLI-based corporate tool designed to transition data safely between random access memory (RAM) cache matrices and underlying physical database flat files. 

### Core Components
* **Book Management Module:** Oversees inventory acquisition, dynamic search filters, text formatting, and automated status reports.
* **Member Management Module:** Registers users, profiles identifiers, and performs in-memory atomic string variable modification updates.
* **Borrowing Module:** Coordinates real-time book transactions via counter checks, recording file logs, and modifying active quantity stocks.

---

## 2. Dynamic Input & System Safety Controls

To maximize uptime, the system employs deep-level **Error Handling** protocols:
1.  **Buffer Flush Synchronization:** Uses character clearing routines (`while(getchar() != '\\n')`) to purge garbage input data from input streams, preventing infinite UI loop cascading.
2.  **Structural Data Protection:** Prevents runtime segmentation crashes by blocking structural modifications if physical storage parameters exceed capacity constants (`MAX_MEMBERS`, `MAX_BOOKS`).
3.  **File Validation Wrappers:** Catches missing or restricted asset pointers safely, outputting errors gracefully (`[ERROR] Could not open file`) rather than abruptly shutting down the system thread.

---

## 3. Command Menu Operations Manual

Below is the detailed operational guide for the core user command matrix.

###  BOOK MANAGEMENT

#### Option 1: Display All Books
* **Functional Mechanics:** Reads the temporary tracking data structure and prints a formatted, aligned system output screen showing all current catalog contents.
* **Data Fields Displayed:** `ID`, `Title`, `Author`, and `Qty` (Quantity Available).

#### Option 2: Search for a Book
* **Functional Mechanics:** Instructs the user to input a contextual query term. The system iterates through cache files using substring comparison operators to return records containing the query term within the title or author data attributes.
* **Safety Handling:** If no record satisfies the search query, the system intercepts empty buffer sets and returns a clean error statement.

#### Option 3: Add New Book
* **Functional Mechanics:** Allocates structural memory fields for a new book profile. The system collects data inputs sequentially, applies string truncation modifications, updates the structural array table tracker, and commits the records onto the raw storage layer.
* **Dynamic Actions:** Triggers `saveBooks()` automatically to persist modifications onto disk space.

#### Option 4: Update Book Quantity
* **Functional Mechanics:** Targets a specific volume ledger profile by matching its specific integer ID. If matched, it prompts for stock adjustment inputs, replaces older data records, and rewrites changes back down onto the file layer.

#### Option 5: Generate Inventory Report
* **Functional Mechanics:** Traverses all existing tracking blocks in sequence and translates structural fields into formatted alphanumeric files written cleanly as a flat text asset named `inventory_report.txt`.
* **Output Parameters:** Generates explicit data tracking blocks separating elements by lines with automated calculations checking for stock counts to output descriptive status tokens:
    * `Quantity > 0` $\\rightarrow$ `Availability Status: Available`
    * `Quantity <= 0` $\\rightarrow$ `Availability Status: Out of Stock`

---

###  MEMBER MANAGEMENT 

#### Option 6: Register New Member
* **Functional Mechanics:** Validates that total records do not breach system limits. Captures demographic values, adds records into memory cache sets, and appends the raw text string profile safely into `members.txt`.

#### Option 7: View Member Details
* **Functional Mechanics:** Processes dynamic memory variables and runs formatted console render actions to structure registered personnel rows or output empty cache warnings.

#### Option 8: Update Member Information
* **Functional Mechanics:** Isolates target data structures through ID matching routines. Opens an input sequence updating name strings or contact variables inside runtime structures, then rebuilds the total configuration state back to disk storage safely.

---

###  BORROWING RECORDS 

#### Option 9: Issue a Book
* **Functional Mechanics:** Pairs real-time book targets with valid user identifiers. Evaluates whether item item pools contain sufficient quantities. If verified, it decrements the collection value, rewrites the global configuration tables, and appends transaction lines to `borrowings.txt` marked with state indicator `0` (Borrowed).

#### Option 10: Return a Book
* **Functional Mechanics:** Parses existing log entries row by row within your transaction logs to search for open actions matching the target criteria where state indicates `0`. Upon success, it updates the status byte flag to `1` (Returned), collects timestamp strings, rewrites the structural file matrix safely, and returns 1 item volume count back into the physical inventory allocation space.

---

###   SYSTEM NAVIGATION 

#### Option 11: Exit
* **Functional Mechanics:** Generates termination exit indicators, flushes data stream pathways safely, returns system operational code values back to zero (`return 0`), and cleanly closes the running terminal process block.

---

## 4. Operational Flowchart & Task Lifecycle

Every interaction from selection to operation loop confirmation follows a clear navigation cycle.