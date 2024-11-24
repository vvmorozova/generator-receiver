#include "generatorSql.h"

generatorDBWorker::generatorDBWorker() {
  char *errMsg = nullptr;

  int rc = sqlite3_open("matrixes.db", &db);
  if (rc) {
    std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    db = NULL;
    return;
  }

  const char *createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS matrixes (
            id INTEGER NOT NULL,
            genTime INTEGER NOT NULL,
            m INTEGER NOT NULL,
            n INTEGER NOT NULL,
            matrix TEXT NOT NULL
        );
    )";

  rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
  if (rc != SQLITE_OK) {
    std::cerr << "SQLite error: " << errMsg << std::endl;
    sqlite3_free(errMsg);
    sqlite3_close(db);
    db = NULL;
    return;
  }

  return;
};

int generatorDBWorker::getLastID() {
  const char *select_max_id_sql = R"(
        SELECT id FROM matrixes ORDER BY id DESC LIMIT 1;
    )";

  sqlite3_stmt *stmt = nullptr;
  if (sqlite3_prepare_v2(db, select_max_id_sql, -1, &stmt, nullptr) !=
      SQLITE_OK) {
    std::cerr << "Error preparing statement: " << sqlite3_errmsg(db)
              << std::endl;
    sqlite3_close(db);
    return 1;
  }

  if (sqlite3_step(stmt) == SQLITE_ROW) {
    return sqlite3_column_int(stmt, 0);
  }
  return 0;
}
