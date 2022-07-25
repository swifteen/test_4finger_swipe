#include <QWidget>
#include "gesturelabel.h"

namespace Ui {
class GestureWidget;
}

class GestureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GestureWidget(QWidget *parent = 0);
    ~GestureWidget();

private:
    Ui::GestureWidget *ui;
    GestureLabel *label;
};