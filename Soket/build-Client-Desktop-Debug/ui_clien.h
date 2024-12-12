/********************************************************************************
** Form generated from reading UI file 'clien.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIEN_H
#define UI_CLIEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clien
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Clien)
    {
        if (Clien->objectName().isEmpty())
            Clien->setObjectName(QString::fromUtf8("Clien"));
        Clien->resize(800, 600);
        centralwidget = new QWidget(Clien);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Clien->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Clien);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Clien->setMenuBar(menubar);
        statusbar = new QStatusBar(Clien);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Clien->setStatusBar(statusbar);

        retranslateUi(Clien);

        QMetaObject::connectSlotsByName(Clien);
    } // setupUi

    void retranslateUi(QMainWindow *Clien)
    {
        Clien->setWindowTitle(QCoreApplication::translate("Clien", "Clien", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Clien: public Ui_Clien {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIEN_H
