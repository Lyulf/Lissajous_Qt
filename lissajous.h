#ifndef LISSAJOUS_H
#define LISSAJOUS_H

#include <QMainWindow>
#include <QtCharts>

namespace Ui {
class Lissajous;
}

class Lissajous : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lissajous(QWidget *parent = nullptr);
    ~Lissajous();

protected:
    void setupChart();
    void setSeries();
    void generatePoints();
    void selectPoints(int startPos, int endPos);
    double getX(double t);
    double getY(double t);
    void updateChartType();
    bool isDynamicDraw();

protected slots:
    void setDynamicDraw(bool value);
    void updatePoints();

private slots:
    void on_actionExit_triggered();
    void on_actionAbout_Creator_triggered();
    void on_actionDynamic_View_triggered(bool checked);
    void onDynamicDrawChanged();

signals:
    void dynamicDrawChanged();

private:
    Ui::Lissajous *ui;
    QChart chart;
    QValueAxis axisX;
    QValueAxis axisY;
    QSplineSeries splineSeries;
    QScatterSeries scatterSeries;
    QVector<QPointF> points;
    QTimer timer;
    double amplitudeA, frequencyA, phaseA;
    double amplitudeB, frequencyB, phaseB;
    int noPoints, noDynamicPoints, currentPoint;
    bool dynamicDraw;
};

#endif // LISSAJOUS_H
