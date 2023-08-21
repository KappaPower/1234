/********************************************************************************
** Form generated from reading UI file 'export.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORT_H
#define UI_EXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Export
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_export;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_path_file;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_Close;

    void setupUi(QWidget *Export)
    {
        if (Export->objectName().isEmpty())
            Export->setObjectName(QString::fromUtf8("Export"));
        Export->resize(521, 112);
        gridLayout = new QGridLayout(Export);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_export = new QLabel(Export);
        label_export->setObjectName(QString::fromUtf8("label_export"));
        label_export->setEnabled(false);
        label_export->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_export);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Export);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_path_file = new QLineEdit(Export);
        lineEdit_path_file->setObjectName(QString::fromUtf8("lineEdit_path_file"));
        lineEdit_path_file->setEnabled(false);

        horizontalLayout->addWidget(lineEdit_path_file);

        toolButton = new QToolButton(Export);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_Ok = new QPushButton(Export);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));

        horizontalLayout_2->addWidget(pushButton_Ok);

        pushButton_Close = new QPushButton(Export);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));

        horizontalLayout_2->addWidget(pushButton_Close);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Export);

        QMetaObject::connectSlotsByName(Export);
    } // setupUi

    void retranslateUi(QWidget *Export)
    {
        Export->setWindowTitle(QCoreApplication::translate("Export", "Form", nullptr));
        label_export->setText(QCoreApplication::translate("Export", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\204\320\260\320\271\320\273 \320\264\320\273\321\217 Export:", nullptr));
        label_2->setText(QCoreApplication::translate("Export", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203:", nullptr));
        toolButton->setText(QCoreApplication::translate("Export", "...", nullptr));
        pushButton_Ok->setText(QCoreApplication::translate("Export", "Ok", nullptr));
        pushButton_Close->setText(QCoreApplication::translate("Export", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Export: public Ui_Export {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORT_H
