/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEsci;
    QAction *actionLoad_dat;
    QAction *actionAbout_Farm;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QPushButton *btn_database;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(855, 665);
        actionEsci = new QAction(MainWindow);
        actionEsci->setObjectName(QStringLiteral("actionEsci"));
        actionLoad_dat = new QAction(MainWindow);
        actionLoad_dat->setObjectName(QStringLiteral("actionLoad_dat"));
        actionAbout_Farm = new QAction(MainWindow);
        actionAbout_Farm->setObjectName(QStringLiteral("actionAbout_Farm"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);

        horizontalLayout_4->addWidget(lineEdit);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);

        horizontalLayout_6->addWidget(lineEdit_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(false);

        horizontalLayout_6->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);

        horizontalLayout_5->addWidget(lineEdit_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);

        horizontalLayout_5->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setEnabled(false);

        horizontalLayout_7->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setEnabled(false);

        horizontalLayout_7->addWidget(pushButton_6);

        btn_database = new QPushButton(centralwidget);
        btn_database->setObjectName(QStringLiteral("btn_database"));

        horizontalLayout_7->addWidget(btn_database);


        verticalLayout->addLayout(horizontalLayout_7);


        horizontalLayout->addLayout(verticalLayout);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_3->addWidget(listWidget);


        horizontalLayout->addWidget(groupBox);


        verticalLayout_2->addLayout(horizontalLayout);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout_2->addWidget(progressBar);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 855, 35));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionLoad_dat);
        menuFile->addAction(actionEsci);
        menuAbout->addAction(actionAbout_Farm);

        retranslateUi(MainWindow);
        QObject::connect(actionEsci, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FARM", 0));
        actionEsci->setText(QApplication::translate("MainWindow", "Esci", 0));
        actionLoad_dat->setText(QApplication::translate("MainWindow", "Load .dat", 0));
        actionAbout_Farm->setText(QApplication::translate("MainWindow", "About Farm", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "rom path", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "build path", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "backup path", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "Check", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "Rebuild Romset", 0));
        btn_database->setText(QApplication::translate("MainWindow", "Build database", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Loaded configuration", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
