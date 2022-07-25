#include <QtWidgets>
#include "fourfingertap.h"

class GestureLabel : public QLabel
{
    Q_OBJECT
public:
    explicit GestureLabel(QWidget *parent = 0);
    Qt::GestureType getFftType();

signals:

public slots:
protected:
    bool event(QEvent *e);
private:
    FourFingerTapGesture *fftRecognizer;
    Qt::GestureType fftType;
    virtual void gestureEvent(QGestureEvent *event);
};
