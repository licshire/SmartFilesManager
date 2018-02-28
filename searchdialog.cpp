#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("高级搜索"));
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_checkBoxFormat_toggled(bool checked)
{
    ui->lineEditFormaAdd->setEnabled(checked);
}
