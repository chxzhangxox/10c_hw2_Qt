#include "grade_calculator.h"
#include "ui_grade_calculator.h"
#include <QMessageBox>
#include <vector>

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(compute_overall()));
}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::compute_overall(){
    std::vector<double> grade(11);
    grade[0] = ui->horizontalSlider->value();
    grade[1] = ui->horizontalSlider_2->value();
    grade[2] = ui->horizontalSlider_3->value();
    grade[3] = ui->horizontalSlider_4->value();
    grade[4] = ui->horizontalSlider_5->value();
    grade[5] = ui->horizontalSlider_6->value();
    grade[6] = ui->horizontalSlider_7->value();
    grade[7] = ui->horizontalSlider_8->value();
    grade[8] = ui->horizontalSlider_9->value();
    grade[9] = ui->horizontalSlider_10->value();
    grade[10] = ui->horizontalSlider_11->value();

    double min = grade[0];
    for (int i = 1; i < grade.size() - 3; i++){
        if (grade[i] < min)
            min = grade[i];
    }

    double hw_sum = 0;
    for (int i = 0; i < grade.size() - 3; i++){
        hw_sum += grade[i];
    }
    hw_sum -= min;

    double score = 0;

    if (ui->comboBox->currentText()== "PIC10B. Intermediate Programming"){

        if (ui->radioButton->isChecked()){
            score = 0.25*hw_sum/7 + 0.2*grade[8] + 0.2*grade[9] + 0.35*grade[10];
        }
        else {
            if (grade[8] < grade[9])
                score = 0.25*hw_sum/7 + 0.3*grade[9] + 0.44*grade[10];
            else
                score = 0.25*hw_sum/7 + 0.3*grade[8] + 0.44*grade[10];
        }
     }

    else{
        if (ui->radioButton->isChecked()){
            score = 0.30*hw_sum/7 + 0.15*grade[8] + 0.15*grade[9] + 0.40*grade[10];
        }
        else {
            if (grade[8] < grade[9])
                score = 0.30*hw_sum/7 + 0.3*grade[9] + 0.40*grade[10];
            else
                score = 0.30*hw_sum/7 + 0.3*grade[8] + 0.40*grade[10];
        }
    }

    ui->label_13->setText(QString::number(score));
}
