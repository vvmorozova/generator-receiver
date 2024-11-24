#include "receiverui.h"
#include "./ui_receiverui.h"

ReceiverUI::ReceiverUI(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ReceiverUI) {
  ui->setupUi(this);
}

ReceiverUI::~ReceiverUI() { delete ui; }

void ReceiverUI::on_showMatrixesRangeBtn_clicked() {
  int from = ui->spinBoxIDFrom->value();
  int to = ui->spinBoxIDTo->value();

  DBWorker dbWorker;
  std::vector<MatrixData> matrixesRangeData = dbWorker.readByIDRange(from, to);

  for (auto matrixData : matrixesRangeData) {
    for (auto i : matrixData.matrix) {
      QString line;
      for (auto j : i) {
        line += j + " ";
      }
      ui->rangeTextEdit->appendPlainText(line);
    }
  }

  qDebug() << "spinBoxIDFrom:" << from;
}

void ReceiverUI::on_transposeBtn_clicked() {}
