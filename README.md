<h2>Coding</h2>

Commands to run C++ file
```bash
cd <file-path> && g++ -std=c++11 <file-name>.cpp && ./a.out
```

<h2>GeeksforGeeks</h2>

<h2>LeetCode</h2>

To check problem
https://leetcode.com/problems/{filename}
For example, if your filename is implement-strstr.cpp, the leetcode problem link is https://leetcode.com/problems/implement-strstr

<h3>Arrays</h3>
<h3>Strings</h3>
<h3>SQL</h3>

All data available under *leetcode* schema

```
CREATE SCHEMA IF NOT EXISTS leetcode; 
```

<h4>Commands</h4>

<h5>Postgres</h5>

Server related commands
```bash
<h2>Start</h2> DB
postgres -D /usr/local/var/postgres 

<h2>Connect</h2> to DB
psql -d postgres -U postgres
```

Queries to check tables
```sql
-- List all tables in leetcode schema
\dt leetcode.*

-- List all schemas
\dn 

-- Decribe table
\d+ leetcode.world
```

<h5>MySQL</h5>

Server level commands
```bash
# Start mysql server
brew services start mysql

# Stop server
brew services stop mysql

# To connect to DB
mysql -u root -p
```

DB related queries
```sql
-- View all DBs
show databases;

-- Use particular schema/db
use leetcode;
```

