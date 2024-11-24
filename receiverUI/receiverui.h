#ifndef RECEIVERUI_H
#define RECEIVERUI_H

#include "sql.h"

#include <QMainWindow>
#include <QSpinBox>

#include <vector>

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

protected:
  // QSpinBox *spinBoxIDFrom;
  // QSpinBox *spinBoxIDTo;
  // QSpinBox *spinBoxTransposeID
};
#endif // RECEIVERUI_H
