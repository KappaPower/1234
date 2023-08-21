#include "export.h"
#include "ui_export.h"

Export::Export(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Export)
{
    ui->setupUi(this);
}

Export::~Export()
{
    delete ui;
}

void Export::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save file into"),QDir::currentPath(),tr("Excel Files (*.xlsx *.xls)"));
    if(!fileName.isEmpty())
    {
        fileName = QDir::toNativeSeparators(fileName);
        ui->lineEdit_path_file->setText(fileName);
    }
}

void Export::on_pushButton_Ok_clicked()
{
    emit file_name_export(ui->lineEdit_path_file->text());
    close();
}
