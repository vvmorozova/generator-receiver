#include "sql.h"

DBWorker::DBWorker() {
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
}

std::vector<MatrixData> DBWorker::readByIDRange(unsigned long from,
                                                unsigned long to) {}

void DBWorker::writeRecord(MatrixData matrixData) {
  if (db == NULL)
    return;

  const char *insertSQL =
      "INSERT INTO matrixes (id, genTime, m, n, matrix) VALUES (?, ?, ?, ?, ?);";
  sqlite3_stmt *stmt;

  int rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr);
  if (rc != SQLITE_OK) {
    std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db)
              << std::endl;
    sqlite3_close(db);
    return;
  }

  sqlite3_bind_int(stmt, 1, matrixData.id);
  sqlite3_bind_int(stmt, 2, matrixData.genTime);
  sqlite3_bind_int(stmt, 3, matrixData.m);
  sqlite3_bind_int(stmt, 4, matrixData.n);
  sqlite3_bind_text(stmt, 5, matrixToString(matrixData).c_str(), -1, SQLITE_STATIC);
  

  rc = sqlite3_step(stmt);
  if (rc != SQLITE_DONE) {
    std::cerr << "Failed to add record to db: " << sqlite3_errmsg(db)
              << std::endl;
  } else {
    std::cout << "Record added to db!" << std::endl;
  }

  sqlite3_finalize(stmt);

  return;
}