#include "fourfingertap.h"
#include <QTouchEvent>

FourFingerTapGesture::FourFingerTapGesture() : QGestureRecognizer()
{

}

QGesture *FourFingerTapGesture::create(QObject *target)
{
    return static_cast<QGesture *>(new FFTGesture());
}

QGestureRecognizer::Result FourFingerTapGesture::recognize(QGesture *state, QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::TouchUpdate) {
        if (static_cast<QTouchEvent *>(event)->touchPoints().size() == 4) {
            state->setProperty("foo", QLatin1String("GESTURES"));
            return FinishGesture;
        }
    }

    return Ignore;
}

FFTGesture::FFTGesture(QObject *parent)
    : QGesture(parent),
      foo("FFT_GESTURE")
{

}

QString FFTGesture::getFoo()
{
    return foo;
}

void FFTGesture::setFoo(QString _foo)
{
    foo = _foo;
}