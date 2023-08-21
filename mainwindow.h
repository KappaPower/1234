#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include <QTime>
#include <random>
#include <QDebug>
#include <QMessageBox>
#include <QShortcut>
#include <cmath>
#include <QDateTime>
#include <QtGlobal>
#include <QAxWidget>
#include <QAxObject>

#include "QSharedPointer"
#include "qcustomplot.h"
#include "export.h"

#include "structures.h"
enum calc_params{single,several};
QString copy_from_table(QTableView *table_from, int num_from);
double chkstr(QString str);
double roundTo(double val, int n);//округление до n-го знака после запятой
namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pB_add_probab_clicked();//добавить вероятность
    void gen_mersenn();//Генератор Мерсенна

    void filling_table_probab(QStandardItemModel *model);

    void create_probab_model();//создание модели для таблицы с заданными вероятностями угроз
    void create_probab_m2();
    void create_probab_m3();

    void on_pB_del_probab_clicked();//удаление вероятностей угроз
    void on_pB_clear_probab_clicked();//очищение таблицы вероятностей

    void on_pB_genRnd_clicked();//Генерация СЧ
    void gen_rnd_withoutRange(QStandardItemModel *model);

    void genSM_Rnd();//Генерацияя СЧ в заданном диапазоне (2 модель)
    void genTM_Rnd();//

    void on_pB_ClearRnd_clicked();//очищение таблицы со СЧ и очищение списка СЧ
    void replace_by_point();//Замена запятых на точки

    bool test_by_right();
    void filling_Xreal(StartParams* sp);
    void read_All(StartParams* sp);
    void on_actionStart_triggered();
    void single_bridge();

    bool filling_Xreal_by_type(StartParams* sp, QAction *action);//? убрать?

    QList <double> get_center_PD(double min, double max, double step);//получение списка с серединами карманов
    QList <int> count_real(QList <double> spd, QList <double> freq_list);//получение списка с точками функции распределения F
    QList<double> count_density(QList<int> count_F); //получение списка с точками плотности вероятности f
    QList <double> get_result_density(QList<double> spd, double M, double SKO, double step);//получение плотности для графика fN

    double calc_M(QList<double> spd, QList<double> density);//вычисление математического ожидания
    double calc_D(QList<double> spd, QList<double> density, double M);//вычисление дисперсии

    int calc_Xreal_bridge(QList<QList<int> > X_real);//Количество реализовавшихся угроз из row прогонов для мостовой структуры системы

    void on_actionInformation_triggered();

    void on_action_single_toggled(bool arg1);


    void on_action_bridge_toggled(bool arg1);

    void create_freq_model(QList<double> freq_list, struct_model type);//создание модели с частостями

    void create_gi_model(QStandardItemModel *model, QList<double> spd, double max, QVector<QString> *name);//создание модели со статистикой по запуску
    void filling_gi_model(QStandardItemModel *model, QList<int>F, QList<double>f, QList<double> fN);//заполнение модели со статистикой по запуску


    void filling_stat_char_bridge(double M, double D, double SKO, double min, double max);//заполнение статистических характеристик для мост.модели

   double get_min_inList(QList<double> list);//получение минимального эл-та из списка
   double get_max_inList(QList<double> list); //(получение максимального эл-та из списка

   void on_listView_doubleClicked(const QModelIndex &index);

   void std_fill_probab();

   void checked_all_struct();

   void on_pB_buf_rnd_clicked();

   void on_pushButton_freq_buffer_clicked();

   void on_action_const_toggled(bool arg1);

   void on_action_dipasone_toggled(bool arg1);

   void on_action_triangular_toggled(bool arg1);

   void on_pB_gi_bridge_buf_clicked();

   void on_pushButton_buffer_graph_clicked();

   void on_pushButton_clear_graph_clicked();

   void on_pushButton_reset_graph_zoom_clicked();

   void on_pushButton_save_graph_clicked();

   void on_actionExport_rnd_triggered();

   void export_rnd_list(QString filename);

   void deleteExcel(QAxObject *excel);

   void on_spinBox_run_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    Export *exp_form = new Export() ;
    calc_params type_calc_params;
    QStandardItemModel *probab = new QStandardItemModel();

    QStandardItemModel *probab_m2 = new QStandardItemModel();
    QStandardItemModel *probab_rnd_m2 = new QStandardItemModel();

    QStandardItemModel *probab_m3 = new QStandardItemModel();
    QStandardItemModel *probab_rnd_m3 = new QStandardItemModel();

    QStandardItemModel *rnd = new QStandardItemModel();
    QStandardItemModel *freq = new QStandardItemModel();

    //модели со статистикой
    QStandardItemModel *gi_bridge = new QStandardItemModel();

    QStandardItemModel *gi_consist_com = new QStandardItemModel();

    QShortcut *keyQ, *keyW;
    QList <StartParams*> sp_list;
    QList <ResultParams*> sp_list_res;

    QList< QList<double>> random_numb;//массив случайных чисел
    QList<QList< QList<double>>> random_list;//массив случайных чисел

    //____________________________________ РЕГУЛЯРКИ НА ВВОД ________________________________________________
    //дробное число >= 0, с точностью до 4 знака "^([1-9][0-9]*|0)(\\.)[0-9]{4}"
//    QRegExpValidator *reg_val = new QRegExpValidator(QRegExp("0?(\\.|,)([1-9]\\d*{4}"));
};

#endif // MAINWINDOW_H
