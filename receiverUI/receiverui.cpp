#include "receiverui.h"
#include "./ui_receiverui.h"

ReceiverUI::ReceiverUI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ReceiverUI) {
  ui->setupUi(this);
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &ReceiverUI::updatePlainText);
  timer->start(10000);
}

ReceiverUI::~ReceiverUI() { delete ui; }

void ReceiverUI::on_showMatrixesRangeBtn_clicked() {
  int from = ui->spinBoxIDFrom->value();
  int to = ui->spinBoxIDTo->value();
  ui->rangeTextEdit->clear();

  DBWorker dbWorker;
  std::vector<MatrixData> matrixesRangeData = dbWorker.readByIDRange(from, to);
  if (matrixesRangeData.size() == 0) {
    QMessageBox::warning(this, tr("Marixes"),
                         tr("Matrixes in this id range was not found"));
    return;
  }

  QString longLine = "";
  for (auto matrixData : matrixesRangeData) {
    longLine += "[" + QString::number(matrixData.id) + "]\n";
    for (auto i : matrixData.matrix) {

      QString line = "";
      for (auto j : i) {
        line += QString::number(j) + " ";
      }
      longLine += line + "\n";
    }
  }
  
  ui->rangeTextEdit->setPlainText(longLine);
  // qDebug() << "longLine:" << longLine << " len " << matrixesRangeData.size();
  // qDebug() << "spinBoxIDFrom:" << from;
}

void ReceiverUI::on_transposeBtn_clicked() {
  DBWorker dbWorker;
  int id = ui->spinBoxTransposeID->value();

  std::vector<MatrixData> matrixesRangeData = dbWorker.readByIDRange(id, id);
  if (matrixesRangeData.size() == 0) {
    QMessageBox::warning(this, tr("Matrixes"),
                         tr("Matrix with this id was not found"));
    return;
  }
  QString longLine = "";
  MatrixData matrixData = matrixesRangeData[0];
  for (auto i : matrixData.matrix) {
    QString line = "";
    for (auto j : i) {
      line += QString::number(j) + " ";
    }
    longLine += line + "\n";
  }

  ui->beforeTextEdit->setPlainText(longLine);
  // transpose
  std::vector<std::vector<int>> transMarix(matrixData.matrix[0].size(),
                                           std::vector<int>());

  for (int i = 0; i < matrixData.matrix.size(); i++) {
    for (int j = 0; j < matrixData.matrix[i].size(); j++) {
      transMarix[j].push_back(matrixData.matrix[i][j]);
    }
  }

  longLine = "";
  for (auto i : transMarix) {
    QString line = "";
    for (auto j : i) {
      line += QString::number(j) + " ";
    }
    longLine += line + "\n";
  }

  ui->afterTextEdit->setPlainText(longLine);
}

void ReceiverUI::updatePlainText() {
        DBWorker dbWorker;
        std::string logs = dbWorker.getLogs();
        ui->logsTextEdit->appendPlainText(QString::fromStdString(logs));
    }
