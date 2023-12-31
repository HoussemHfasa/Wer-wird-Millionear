#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

private slots:
    void on_sliderProgress_sliderMoved(int position);

    void on_sliderVolume_sliderMoved(int position);

private:
    Ui::settings *ui;
};

#endif // SETTINGS_H
