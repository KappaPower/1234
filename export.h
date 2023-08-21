#ifndef EXPORT_H
#define EXPORT_H

#include <QWidget>
#include <QFileDialog>

namespace Ui {
class Export;
}

class Export : public QWidget
{
    Q_OBJECT

public:
    explicit Export(QWidget *parent = nullptr);
    ~Export();

private slots:
    void on_toolButton_clicked();

    void on_pushButton_Ok_clicked();

private:
    Ui::Export *ui;

signals:
    void file_name_export(QString filename);
};

#endif // EXPORT_H
