#include <QGesture>
#include <QGestureRecognizer>

class FFTGesture : public QGesture
{
    Q_PROPERTY(QString foo
               READ getFoo
               WRITE setFoo)
public:
    FFTGesture(QObject *parent = 0);
    QString getFoo();
    void setFoo(QString foo);
private:
    QString foo;
};

class FourFingerTapGesture : public QGestureRecognizer
{
public:
    FourFingerTapGesture();
private:
    virtual QGesture *create(QObject *target);
    virtual Result recognize(QGesture *state, QObject *watched, QEvent *event);

};