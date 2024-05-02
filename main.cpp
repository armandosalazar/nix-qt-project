#include <QtWidgets>
#include <sqlite3.h>
#include <iostream>

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;

    int rc = sqlite3_open("test.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }

    sqlite3_close(db);

    QApplication app(argc, argv);
    QWidget window;
    // window.resize(320, 240);
    window.setWindowTitle(QApplication::translate("childwidget", "Child widget"));


    // QGroupBox
    QGroupBox *groupBox = new QGroupBox("Group Box");
    QPushButton *button3 = new QPushButton("Hello");
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(button3);
    groupBox->setLayout(vbox);


    QLabel *label = new QLabel(QApplication::translate("childwidget", "Hello, world!"));
    label->setAlignment(Qt::AlignCenter);
    // label->setMargin(75);
    // label->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QPushButton *button = new QPushButton("Quit");
    QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));

    QPushButton *button2 = new QPushButton("Hello");
    QObject::connect(button2, SIGNAL(clicked()), label, SLOT(hide()));



    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(groupBox);
    layout->addWidget(label);
    layout->addWidget(button);
    layout->addWidget(button2);

    window.setLayout(layout);

    window.show();


    return app.exec();
}
