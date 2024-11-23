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
                                                unsigned long to) {
  const char *sqlQuery = "SELECT id, genTime, m, n, matrix FROM matrixes WHERE "
                         "id BETWEEN ? AND ?;";
  sqlite3_stmt *stmt = nullptr;

  if (sqlite3_prepare_v2(db, sqlQuery, -1, &stmt, nullptr) != SQLITE_OK) {
    std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db)
              << std::endl;
    return {};
  }

  if (sqlite3_bind_int(stmt, 1, from) != SQLITE_OK ||
      sqlite3_bind_int(stmt, 2, to) != SQLITE_OK) {
    std::cerr << "Failed to bind parameters: " << sqlite3_errmsg(db)
              << std::endl;
    sqlite3_finalize(stmt);
    return {};
  }

  MatrixData currMatrixData;
  std::vector<MatrixData> result;

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    currMatrixData.id = sqlite3_column_int(stmt, 0);
    currMatrixData.genTime = sqlite3_column_int(stmt, 1);
    currMatrixData.m = sqlite3_column_int(stmt, 2);
    currMatrixData.n = sqlite3_column_int(stmt, 3);

    std::string matrixChar = std::string(
        reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)));
    stringToMatrix(currMatrixData, matrixChar, currMatrixData.m,
                   currMatrixData.n);

    result.push_back(currMatrixData);
    // std::cout << "ID: " << currMatrixData.id
    //           << ", GenTime: " << currMatrixData.genTime
    //           << ", M: " << currMatrixData.m << ", N: " << currMatrixData.n
    //           << ", Matrix: " << matrixChar << std::endl;
  }

  if (sqlite3_finalize(stmt) != SQLITE_OK) {
    std::cerr << "Failed to finalize statement: " << sqlite3_errmsg(db)
              << std::endl;
  }
  return result;
}

void DBWorker::writeRecord(MatrixData matrixData) {
  if (db == NULL)
    return;

  const char *insertSQL = "INSERT INTO matrixes (id, genTime, m, n, matrix) "
                          "VALUES (?, ?, ?, ?, ?);";
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
  sqlite3_bind_text(stmt, 5, matrixToString(matrixData).c_str(), -1,
                    SQLITE_STATIC);

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