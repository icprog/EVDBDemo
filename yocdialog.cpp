#include "yocdialog.h"
#include <QtGui>

YocDialog::YocDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint  | Qt::Dialog);
    textLabel = new QLabel();
    setAttribute(Qt::WA_TranslucentBackground);
   // setWindowModality(Qt::ApplicationModal);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(textLabel,0,Qt::AlignCenter);
    layout->setSpacing(0);
    layout->setContentsMargins(15,10,15,10);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);
    this->setMinimumHeight(35);
    QFont font = this->font();
    font.setBold(true);
    font.setPointSize(12);
    this->textLabel->setFont(font);
}
void YocDialog::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pen(QColor(Qt::black ),1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    QBrush brush(QColor(Qt::white),Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(this->rect());
    brush.setColor(QColor(Qt::lightGray));
    painter.setBrush(brush);
    QRect textRect;
    textRect.setX(this->rect().x() + SIDEW);
    textRect.setY(this->rect().y() + SIDEW);
    textRect.setWidth(this->rect().width() - 2*SIDEW);
    textRect.setHeight(this->rect().height() - 2*SIDEW);
    painter.drawRect(textRect);
    QDialog::paintEvent(event);

}

QString YocDialog::text() const
{
    return this->textLabel->text();
}


void YocDialog::setText(const QString &text)
{
    if(text.isEmpty())
        textLabel->clear();
    else
        textLabel->setText(text);

    this->repaint();
}



