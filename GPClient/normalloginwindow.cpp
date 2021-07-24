#include "normalloginwindow.h"
#include "ui_normalloginwindow.h"
#include "gpshared.h"

#include <QCloseEvent>
#include <plog/Log.h>

NormalLoginWindow::NormalLoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NormalLoginWindow)
{
    ui->setupUi(this);
    setWindowTitle("GlobalProtect Login");
    setFixedSize(width(), height());
    setModal(true);

    PLOGI << "set authentication";

    if (gpUser) {
        PLOGI << "-> user from command line";
        // set user from command line
        ui->username->setText(QVariant(gpUser).toString());
    }

    if (gpPassword) {
        PLOGI << "-> password from command line";
        // set password from command line
        ui->password->setText(QVariant(gpPassword).toString());
    }
}

NormalLoginWindow::~NormalLoginWindow()
{
    delete ui;
}

void NormalLoginWindow::setAuthMessage(QString message)
{
    ui->authMessage->setText(message);
}

void NormalLoginWindow::setUsernameLabel(QString label)
{
    ui->username->setPlaceholderText(label);
}

void NormalLoginWindow::setPasswordLabel(QString label)
{
    ui->password->setPlaceholderText(label);
}

void NormalLoginWindow::setPortalAddress(QString portal)
{
    ui->portalAddress->setText(portal);
}

void NormalLoginWindow::setProcessing(bool isProcessing)
{
    ui->username->setReadOnly(isProcessing);
    ui->password->setReadOnly(isProcessing);
    ui->loginButton->setDisabled(isProcessing);
}

void NormalLoginWindow::autoLogin()
{
    on_loginButton_clicked();
}

void NormalLoginWindow::on_loginButton_clicked()
{
    const QString username = ui->username->text().trimmed();
    const QString password = ui->password->text().trimmed();

    if (username.isEmpty() || password.isEmpty()) {
        return;
    }

    emit performLogin(username, password);
}

void NormalLoginWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    reject();
}
