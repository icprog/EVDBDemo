#ifndef YOCDIALOG_H
#define YOCDIALOG_H

#include <QDialog>
class QLabel;
class QPainterPath;
class QTimer;
class QRect;
#define  SIDEW      4


class YocDialog : public QDialog
{
    Q_OBJECT
public:
    explicit YocDialog(QWidget *parent = 0);
    void setText(const QString &text);
    QString text() const;
    QString text(const bool flag = 0) const;
signals:

protected:
    void paintEvent(QPaintEvent *event);

public slots:

private:
    QLabel *textLabel;


};

#endif // YOCDIALOG_H
