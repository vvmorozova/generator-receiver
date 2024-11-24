#ifndef RECEIVERUI_H
#define RECEIVERUI_H

#include <QMainWindow>
#include "utils.h"
#include "sql.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ReceiverUI;
}
QT_END_NAMESPACE

class ReceiverUI : public QMainWindow {
  Q_OBJECT

public:
  ReceiverUI(QWidget *parent = nullptr);
  ~ReceiverUI();

private slots:
  void on_showMatrixesRangeBtn_clicked();

  void on_transposeBtn_clicked();

private:
  Ui::ReceiverUI *ui;
};
#endif // RECEIVERUI_H
