#include "lissajous.h"
#include "ui_lissajous.h"
#include <math.h>

Lissajous::Lissajous(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lissajous),
    chart(),
    axisX(),
    axisY(),
    splineSeries(),
    scatterSeries(),
    points(),
    timer(this),
    amplitudeA(1), frequencyA(1), phaseA(0),
    amplitudeB(1), frequencyB(1), phaseB(45),
    noPoints(500), noDynamicPoints(60), currentPoint(0),
    dynamicDraw(false)
{
    ui->setupUi(this);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHeightForWidth(true);
    ui->chartView->setSizePolicy(sizePolicy);
    setupChart();
    connect(this, &Lissajous::dynamicDrawChanged, this, &Lissajous::onDynamicDrawChanged);
}

Lissajous::~Lissajous()
{
    delete ui;
}

void Lissajous::setupChart()
{
    chart.legend()->hide();
    ui->chartView->setChart(&chart);

    chart.removeAllSeries();
    generatePoints();

    chart.addSeries(&splineSeries);
    chart.addSeries(&scatterSeries);
    scatterSeries.setColor(splineSeries.color());
    scatterSeries.setBorderColor(scatterSeries.color());
    scatterSeries.setMarkerSize(1);

    chart.addAxis(&axisX, Qt::AlignBottom);
    splineSeries.attachAxis(&axisX);
    scatterSeries.attachAxis(&axisX);
    axisX.applyNiceNumbers();

    chart.addAxis(&axisY, Qt::AlignLeft);
    splineSeries.attachAxis(&axisY);
    scatterSeries.attachAxis(&axisY);
    axisY.applyNiceNumbers();

    updateChartType();
    connect(&timer, SIGNAL(timeout()), this, SLOT(updatePoints()));
    timer.start(1);
}

void Lissajous::generatePoints()
{
    points.clear();
    points.reserve(noPoints);
    for(int i = 0; i < noPoints; i++)
    {
        double t = static_cast<double>(i) / noPoints * 2 * M_PI;
        QPointF point(getX(t), getY(t));
        points.push_back(point);
    }
    splineSeries.replace(points);
}

void Lissajous::selectPoints(int startPos, int endPos)
{
    int length = endPos - startPos;

    QVector<QPointF> currentPoints = points.mid(startPos, length);
    int noMissingPoints = endPos - points.size();
    if(noMissingPoints > 0) {
        currentPoints.append(points.mid(0, noMissingPoints));
    }
    scatterSeries.replace(currentPoints);
}

inline double Lissajous::getX(double t)
{
    return amplitudeA * sin(frequencyA * (t + phaseA));
}

inline double Lissajous::getY(double t)
{
    return amplitudeB * sin(frequencyB * (t + phaseB));
}

void Lissajous::updateChartType()
{
    scatterSeries.setVisible(dynamicDraw);
    splineSeries.setVisible(!dynamicDraw);
}

bool Lissajous::isDynamicDraw()
{
    return dynamicDraw;
}

void Lissajous::setDynamicDraw(bool value)
{
    dynamicDraw = value;
    if(ui->actionDynamic_View->isChecked() != value)
    {
        ui->actionDynamic_View->toggle();
    }
    emit dynamicDrawChanged();
}

void Lissajous::updatePoints()
{
    currentPoint = (currentPoint + 1) % points.size();
    selectPoints(currentPoint, currentPoint + noDynamicPoints);
}

void Lissajous::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

void Lissajous::on_actionAbout_Creator_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("This program was created by Patryk Chodorowski");
    msgBox.exec();
}

void Lissajous::on_actionDynamic_View_triggered(bool checked)
{
    setDynamicDraw(checked);
}

void Lissajous::onDynamicDrawChanged()
{
    updateChartType();
}
