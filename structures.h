#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <QList>
enum struct_model{consistent,parallel,bridge};

struct StartParams
{
    int test_num; 
//    QList <QPair <struct_model, int>> type_Xreal;
//    QList <QPair <struct_model, double>> frequency;


    QList<QList <double>> random_numbers;
    QList <double> probabilities;
    QList <QList <int>> X_real;
    struct_model type;

    int all_Xreal;//частота
    double frequency;//частость
//     QList <int> frequency;//частость
    double no_fail;

//    int count_real;
//    int count_fail;

};
typedef struct StartParams startP;


struct ResultParams
{
    struct_model type;
    QList <double> fN;
    QVector <QString> name;
    QList <int> F;
    QList <double> f;
    QList <double> spd;
    QList <double> freq_list;
    double max_freq = 0.0;
    double min_freq = 1.0;
    double step = 0.01;
    double M = 0.0;
    double D = 0.0;
    double SKO = 0.0;
};
typedef struct ResultParams resP;
#endif // STRUCTURES_H
