#include "gesturewidget.h"
#include "ui_gesturewidget.h"

GestureWidget::GestureWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GestureWidget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_AcceptTouchEvents);
    label = new GestureLabel(this);
    label->setText("Hello!");
    label->grabGesture(label->getFftType());
    ui->verticalLayout_2->addWidget(label);
    label->setStyleSheet("QLabel{background-color:red;}");
}

GestureWidget::~GestureWidget()
{
    delete ui;
}
