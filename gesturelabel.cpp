#include "gesturelabel.h"
#include <iostream>
using std::cout;
using std::endl;
#include <QDebug>
GestureLabel::GestureLabel(QWidget *parent) : QLabel(parent)
{
    setAttribute(Qt::WA_AcceptTouchEvents);
    fftRecognizer = new FourFingerTapGesture();
    fftType = QGestureRecognizer::registerRecognizer(fftRecognizer);
    QVector<Qt::GestureType> gestures;
        gestures << Qt::PanGesture;
        gestures << Qt::PinchGesture;
        gestures << Qt::SwipeGesture<<fftType;
        qDebug()<<__LINE__<<" fftType "<<fftType;
        for (Qt::GestureType gesture : gestures)
            grabGesture(gesture);

}

Qt::GestureType GestureLabel::getFftType()
{
    return fftType;
}

bool GestureLabel::event (QEvent * e)
{
  if (e->type () == QEvent::Gesture)
    {
      QGestureEvent *pGestureEvent = dynamic_cast<QGestureEvent *> (e);
      if (pGestureEvent)
        {
          qDebug()<<__LINE__<<"QEvent::Gesture";
            gestureEvent(pGestureEvent);
        }
    }

  return QLabel::event (e);
}
void GestureLabel::gestureEvent(QGestureEvent *event)
{
    //qDebug()<<__LINE__<<"Gesture event captured"<<event->gestures();
    if(QGesture *g = event->gesture(fftType)) {
        qDebug()<<__LINE__<<"fftType Gesture event captured";
        setText(g->property("foo").toString());
        event->accept(g);
    }
    if(QGesture *g = event->gesture(Qt::SwipeGesture))
    {
        qDebug()<<__LINE__<<"SwipeGesture event captured"<<g;
        event->accept(g);
    }
}
