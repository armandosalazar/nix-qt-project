#include <QtWidgets>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QWidget window;
    window.resize(320, 240);
    window.setWindowTitle(QApplication::translate("childwidget", "Child widget"));

    QLabel *label = new QLabel(QApplication::translate("childwidget", "Hello, world!"));
    label->setAlignment(Qt::AlignCenter);
    label->setMargin(75);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QPushButton *button = new QPushButton("Quit");
    QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));

    QPushButton *button2 = new QPushButton("Hello");
    QObject::connect(button2, SIGNAL(clicked()), label, SLOT(hide()));



    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(button);
    layout->addWidget(button2);

    window.setLayout(layout);

    window.show();


    return app.exec();
}
