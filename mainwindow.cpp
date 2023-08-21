#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("#MainWindow {background-image: url(:/icons/back.jpg);}");

    QTime midnight(0,0,0);
    qsrand(uint(midnight.secsTo(QTime::currentTime())));


    ui->progressBar->setVisible(0);
    ui->menu_calc_params->hideTearOffMenu();
    ui->tableView_probab->setModel(probab);
    ui->tableView_rnd->setModel(rnd);
    ui->tableView_frequency->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_frequency->setModel(freq);
    ui->tableView_graph_info_bridge->setModel(gi_bridge);
    ui->tableView_start_p_m2->setModel(probab_m2);
    ui->tableView_start_p_m3->setModel(probab_m3);
    ui->tableView_rnd_p_diap_m2->setModel(probab_rnd_m2);
    ui->tableView_rnd_p_diap_m3->setModel(probab_rnd_m3);
    ui->action_single->setChecked(true);

    create_probab_model();

    connect(exp_form, &Export::file_name_export, this, &MainWindow::export_rnd_list,Qt::UniqueConnection);

    keyQ = new QShortcut(this);
    connect(keyQ, &QShortcut::activated, this, &MainWindow::std_fill_probab);
    keyQ->setKey(Qt::CTRL + Qt::Key_Q);

    keyW = new QShortcut(this);
    connect(keyW, &QShortcut::activated, this, &MainWindow::checked_all_struct);
    keyW->setKey(Qt::CTRL + Qt::Key_W);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//добавить вероятность
void MainWindow::on_pB_add_probab_clicked()
{
    if(ui->action_const->isChecked())
    {
        if(probab->rowCount()==0)
            create_probab_model();
        filling_table_probab(probab);
    }
    else if (ui->action_dipasone->isChecked() )
    {

        if(probab_m2->rowCount() == 0)
            create_probab_m2();
        filling_table_probab(probab_m2);
    }
    else if (ui->action_triangular->isChecked() )
    {
        if(probab_m3->rowCount() == 0)
            create_probab_m3();
        filling_table_probab(probab_m3);
    }
}

void MainWindow::gen_mersenn()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 10.0);
    for (int i=0; i<20; ++i)
        qDebug() << i << " = " << dist(mt) << "\n";
}

void MainWindow::filling_table_probab(QStandardItemModel *model)
{
    int column = model->columnCount();
    model->insertColumn(column);

    for(int k = 0; k < model->rowCount(); k++)
        model->setData(model->index(k,column)," ");

    for(int k = 0; k < model->rowCount(); k++)
        for(int i = 0; i < model->columnCount(); i++)
            model->item(k, i)->setTextAlignment(Qt::AlignCenter);
}

//создание модели для таблицы с заданными вероятностями угроз
void MainWindow::create_probab_model()
{
    probab->insertRow(probab->rowCount());
    probab->setHeaderData(0, Qt::Vertical, "P");
    ui->tableView_probab->resizeRowToContents(0);
}

void MainWindow::create_probab_m2()
{
    probab_m2->setRowCount(2);

    probab_m2->setHeaderData(0, Qt::Vertical, "Pmin");
    probab_m2->setHeaderData(1, Qt::Vertical, "Pmax");
}

void MainWindow::create_probab_m3()
{
    probab_m3->setRowCount(3);

    probab_m3->setHeaderData(0, Qt::Vertical, "Pmin");
    probab_m3->setHeaderData(1, Qt::Vertical, "Pmax");
    probab_m3->setHeaderData(2, Qt::Vertical, "Pmod");
}

//удаление вероятностей угроз
void MainWindow::on_pB_del_probab_clicked()
{
    if(ui->action_const->isChecked())
    {
        int count = ui->tableView_probab->selectionModel()->selectedColumns().count();
        for( int i = count-1; i >= 0; i--)
            ui->tableView_probab->model()->removeColumn(ui->tableView_probab->selectionModel()->selectedColumns().at(i).column(), QModelIndex());
    }

    if(ui->action_dipasone->isChecked())
    {
        int count = ui->tableView_start_p_m2->selectionModel()->selectedColumns().count();
        for( int i = count-1; i >= 0; i--)
            ui->tableView_start_p_m2->model()->removeColumn(ui->tableView_start_p_m2->selectionModel()->selectedColumns().at(i).column(), QModelIndex());
    }

    if(ui->action_triangular->isChecked())
    {
        int count = ui->tableView_start_p_m3->selectionModel()->selectedColumns().count();
        for( int i = count-1; i >= 0; i--)
            ui->tableView_start_p_m3->model()->removeColumn(ui->tableView_start_p_m3->selectionModel()->selectedColumns().at(i).column(), QModelIndex());
    }
}

//очищение таблицы вероятностей
void MainWindow::on_pB_clear_probab_clicked()
{
    if(ui->action_const->isChecked())
        probab->clear();
    if(ui->action_dipasone->isChecked())
        probab_m2->clear();
    if(ui->action_triangular->isChecked())
        probab_m3->clear();
}

//Генерация СЧ
void MainWindow::on_pB_genRnd_clicked()
{
    if(ui->action_const->isChecked())
        gen_rnd_withoutRange(probab);
    if(ui->action_dipasone->isChecked())
    {
        genSM_Rnd();
        gen_rnd_withoutRange(probab_rnd_m2);
    }
    if(ui->action_triangular->isChecked())
    {
        genTM_Rnd();
        gen_rnd_withoutRange(probab_rnd_m3);
    }
}

void MainWindow::gen_rnd_withoutRange(QStandardItemModel *model)
{
    if(model->columnCount() == 0)
    {
        QMessageBox::information(this,"Ошибка","Не введено ни одного значения вероятности",QMessageBox::Ok);
        return;
    }

    int column = model->columnCount();
    int row = ui->spinBox_run->value();
    ui->spinBox_run->setAlignment(Qt::AlignCenter);

    QList <QList <double>> result_rnd;
    rnd->setRowCount(row);
    rnd->setColumnCount(column);

    for(int i = 0; i < column; i++)
        rnd->setHeaderData(i,Qt::Horizontal, "СЧ "+ QString::number(i+1));

    for(int j = 0; j <column; j++)
    {
        QList <double> rand_col;
        for(int i = 0; i < row; i++)
        {
            rand_col.append(roundTo(double(rand())/RAND_MAX,4));
            rnd->setData(rnd->index(i,j),QString::number(rand_col.last()));
        }
        result_rnd.append(rand_col);
    }
    random_numb = result_rnd;
}

void MainWindow::genSM_Rnd()
{
    if(probab_m2->columnCount() == 0)
    {
        QMessageBox::information(this,"Ошибка","Не введено ни одного значения вероятности",QMessageBox::Ok);
        return;
    }
    int column = probab_m2->columnCount();
    int row  = 1;
    QList <QList <double>> result_rnd;
    probab_rnd_m2->setRowCount(row);
    probab_rnd_m2->setColumnCount(column);

    for(int i = 0; i < column; i++)
        probab_rnd_m2->setHeaderData(i,Qt::Horizontal, "P"+ QString::number(i+1));

    QList <double> p_min;
    QList <double> p_max;

    for(int i = 0; i < column; i++)
    {
        p_min.append(probab_m2->index(0,i).data().toDouble());
        p_max.append(probab_m2->index(1,i).data().toDouble());
    }

    for(int j = 0; j <column; j++)
    {
        QList <double> rand_col;
        for(int i = 0; i < row; i++)
        {
            double a = p_min.at(j);
            double b = p_max.at(j);
            double rnd_diap = roundTo(double(rand() * (b-a) / RAND_MAX + a),4);

            rand_col.append(roundTo(a+rnd_diap*(b-a),4));
            probab_rnd_m2->setData(probab_rnd_m2->index(i,j),QString::number(rand_col.last()));
        }
        result_rnd.append(rand_col);
    }
    ui->tableView_rnd_p_diap_m2->resizeColumnsToContents();
}

void MainWindow::genTM_Rnd()
{
    if(probab_m3->columnCount() == 0)
    {
        QMessageBox::information(this,"Ошибка","Не введено ни одного значения вероятности",QMessageBox::Ok);
        return;
    }

    int column = probab_m3->columnCount();
    int row  = 1;
    QList <QList <double>> result_rnd;
    probab_rnd_m3->setRowCount(row);
    probab_rnd_m3->setColumnCount(column);

    for(int i = 0; i < column; i++)
        probab_rnd_m3->setHeaderData(i,Qt::Horizontal, "P"+ QString::number(i+1));

    QList <double> p_min;
    QList <double> p_max;
    QList <double> p_mod;

    for(int i = 0; i < column; i++)
    {
        p_min.append(probab_m3->index(0,i).data().toDouble());
        p_max.append(probab_m3->index(1,i).data().toDouble());
        p_mod.append(probab_m3->index(2,i).data().toDouble());
    }

    for(int j = 0; j <column; j++)
    {
        QList <double> rand_col;
        for(int i = 0; i < row; i++)
        {
            double a = p_min.at(j);
            double b = p_max.at(j);
            double c = p_mod.at(j);

            double rnd_diap = roundTo(double(rand() * (b-a) / RAND_MAX + a),4);
            double lambda = double((c-a)/(b-a));

            if(0 <= rnd_diap and rnd_diap <=lambda)
                rand_col.append(roundTo(a+(b-a)*sqrt(rnd_diap*lambda),4));
            else if (lambda<rnd_diap and rnd_diap<=1)
                rand_col.append(roundTo(b-(b-a)*sqrt(rnd_diap*(1-lambda)),4));

            probab_rnd_m3->setData(probab_rnd_m3->index(i,j),QString::number(rand_col.last()));
        }
        result_rnd.append(rand_col);
    }
    ui->tableView_rnd_p_diap_m3->resizeColumnsToContents();
}

//очищение таблицы со СЧ и очищение списка СЧ
void MainWindow::on_pB_ClearRnd_clicked()
{
    rnd->clear();
}

//Замена запятых на точки
void MainWindow::replace_by_point()
{
    for(int i = probab->columnCount()-1; i >= 0; i--)
        probab->setData(probab->index(0,i),probab->index(0,i).data().toString().replace(",","."));

    for(int i = rnd->rowCount()-1; i >=0; i--)
        for(int j = rnd->columnCount()-1; j >= 0; j--)
            rnd->setData(rnd->index(i,j),rnd->index(i,j).data().toString().replace(",","."));

}

//округление до n-го знака после запятой
double roundTo(double val, int n)
{
    int s = int(pow(10, n));
    double num = floor(val*s);
    double res = num/s;
    double t = pow(10, -(n+1.0))*5;

    if (res+t < val)
        res+=pow(10, -n);

    return res;
}

//Проверка на корректность исходных данных
bool MainWindow::test_by_right()
{
    bool const_m = ui->action_const->isChecked();
    bool diapasone_m = ui->action_dipasone->isChecked();

    if(!ui->action_single->isChecked() and !ui->action_several->isChecked()){
        QMessageBox::information(this,"Ошибка","Не выбраны параметры запуска",QMessageBox::Ok);
        return false;}

    if(!ui->action_consistent->isChecked() and !ui->action_parallel->isChecked() and !ui->action_bridge->isChecked()){
        QMessageBox::information(this,"Ошибка","Не указана структура системы",QMessageBox::Ok);
        return false;}

    if((const_m and ui->action_bridge->isChecked() and probab->columnCount()!=5) or
            (diapasone_m and ui->action_bridge->isChecked() and probab_rnd_m2->columnCount()!=5)){
        QMessageBox::information(this,"Ошибка","Для мостовой схемы нужно указать вероятности для 5 уязвимостей",QMessageBox::Ok);
        return false;}

    if((const_m and probab->columnCount()<2)or (diapasone_m and probab_rnd_m2->columnCount()<2)){
        QMessageBox::information(this,"Ошибка","Для запуска необходимо указать 2 или более вероятности",QMessageBox::Ok);
        return false;}

    if((const_m and rnd->columnCount() != probab->columnCount()) or
            (diapasone_m and rnd->columnCount() != probab_rnd_m2->columnCount()))
    {
        QMessageBox::information(this,"Ошибка","СЧ сгенерированы не для каждого элемента вероятности",QMessageBox::Ok);
        return false;}


    for(int i = probab->columnCount()-1; i >= 0; i--)
    {
        bool ok = false;
        double value = probab->index(0,i).data().toDouble(&ok);

        if(!ok or value < 0 or value > 1){
            QMessageBox::information(this,"Ошибка в таблице вероятностей","Значение вероятности д.б. задано числом от 0 до 1, разделительный символ '.'",QMessageBox::Ok);
            return false;}
    }

    for(int i = rnd->rowCount()-1; i >=0; i--)
        for(int j = rnd->columnCount()-1; j >= 0; j--)
        {
            bool ok = false;
            double value = rnd->index(i,j).data().toDouble(&ok);
            if(!ok or value <0 or value >1){
                QMessageBox::information(this,"Ошибка в таблице СЧ","Значение вероятности д.б. задано числом от 0 до 1, разделительный символ .",QMessageBox::Ok);
                return false;}
        }

    return true;
}

//Если случайное значение меньше вероятности значит угроза реализовалась
void MainWindow::filling_Xreal(StartParams *sp)
{
    int column = sp->random_numbers.size();//количество столбцов
    for(int k = 0; k < column; k++)
    {
        QApplication::processEvents();
        QList <int> X;
        double value_probab = sp->probabilities.at(k);
        int row = sp->random_numbers.at(k).size();//количество строк (генераций СЧ)
        for(int i = 0; i <row; i++)
        {
            double value_rnd = sp->random_numbers.at(k).at(i);

            if(roundTo(value_rnd,4) <= roundTo(value_probab,4))
                X.append(1);
            else
                X.append(0);
        }
        sp->X_real.append(X);
    }
}

//считать исходные данные
void MainWindow::read_All(StartParams *sp)
{
    if(ui->action_const->isChecked())
        for(int j = 0; j < probab->columnCount(); j++)
            sp->probabilities.append(probab->index(0,j).data().toDouble());
    if(ui->action_dipasone->isChecked())
        for(int j = 0; j < probab_rnd_m2->columnCount(); j++)
            sp->probabilities.append(probab_rnd_m2->index(0,j).data().toDouble());
    if(ui->action_triangular->isChecked())
        for(int j = 0; j < probab_rnd_m3->columnCount(); j++)
            sp->probabilities.append(probab_rnd_m3->index(0,j).data().toDouble());

    for(int j = 0; j < rnd->columnCount(); j++){
        QList<double> rnd_row;
        for(int i = 0; i < rnd->rowCount(); i++)
            rnd_row.append(rnd->index(i,j).data().toDouble());

        sp->random_numbers.append(rnd_row);}

}

void MainWindow::on_actionStart_triggered()
{
    ui->widget1->clearPlottables();
    ui->widget1->clearGraphs();
    gi_bridge->clear();
    random_list.clear();
    freq->clear();

    //зачистить списки со структурами
    if(sp_list.count()>0)
    {
        for(int i = sp_list.count()-1; i >=0; i--){
            delete sp_list.at(i);
            sp_list.removeLast();
        }
    }
    if(sp_list_res.count()>0)
    {
        for(int i = sp_list_res.count()-1; i >=0; i--){
            delete sp_list_res.at(i);
            sp_list_res.removeLast();
        }
    }
    qDebug()<<"sp_list.count()"<<sp_list.count();
    //-------------------

    replace_by_point();

    QStringList data;

    data.clear();

    if(ui->action_const->isChecked())
    {
        data.append("Модель полной определённости");
    }
    if(ui->action_dipasone->isChecked())
    {
         data.append("Модель погрешности");
    }

   if(ui->action_triangular->isChecked())
   {
         data.append("Модель треугольного распределения");
    }
    QStringListModel *graphs = new QStringListModel;
    graphs->setStringList(data);
    ui->listView->setModel(graphs);

    if(test_by_right())
    {
        qDebug()<<"Let's start this shit";
        ui->progressBar->setValue(0);
        ui->progressBar->setVisible(1);

        if(type_calc_params == single)
        {
                single_bridge();
        }
        if(type_calc_params == several)
        {
            if (ui->action_bridge->isChecked())
                single_bridge();
        }
    }
    ui->progressBar->setVisible(0);
}

void MainWindow::single_bridge()
{
    ResultParams *res = new ResultParams;
    int test_count = ui->spinBox_test->value();

    for (int i = 0; i < test_count;i++)
    {
        StartParams *sp = new startP();

        if(sp_list_res.count()==0)
        {
            if(i == 0)
                read_All(sp);
            else
            {
                on_pB_genRnd_clicked();
                read_All(sp);
            }
        }
        else
        {
            QList <QList <double>>list_rnd = random_list.at(i);
            for(int k = 0; k < rnd->rowCount(); k++)
                for(int j = 0; j < rnd->columnCount(); j++)
                    rnd->setData(rnd->index(k,j),list_rnd.at(j).at(k));

            read_All(sp);
        }

        filling_Xreal(sp);

        sp->type = bridge;
        res->type = bridge;

        sp->all_Xreal = calc_Xreal_bridge(sp->X_real);

        sp->frequency = double(sp->all_Xreal)/double(ui->spinBox_run->value());//частость для 1 итерации
        res->freq_list.append(sp->frequency);// список частостей для test кол-ва экспериментов

        sp_list.append(sp);
        random_list.append(random_numb);
    }

    create_freq_model(res->freq_list,res->type);

    if(test_count > 1)
    {
        res->min_freq = get_min_inList(res->freq_list);
        res->max_freq = get_max_inList(res->freq_list);
        res-> step = ui->dbSpB_step_bridge->value();


        res->spd = get_center_PD(res->min_freq,res->max_freq,res->step);
        res->F = count_real(res->spd,res->freq_list);
        res->f = count_density(res->F);

        res->M = calc_M(res->spd,res->f);
        res->D = calc_D(res->spd,res->f,res->M);
        res->SKO = sqrt(res->D);

        res->fN = get_result_density(res->spd,res->M,res->SKO,res->step);

        create_gi_model(gi_bridge,res->spd,res->max_freq, &res->name);
        filling_gi_model(gi_bridge,res->F,res->f,res->fN);
        filling_stat_char_bridge(res->M,res->D,res->SKO,res->min_freq,res->max_freq);
    }
    sp_list_res.append(res);
}

bool MainWindow::filling_Xreal_by_type(StartParams* sp, QAction *action)
{
    if ( action ==ui->action_bridge and ui->action_bridge->isChecked()){
        sp->type = bridge;
        sp->all_Xreal = calc_Xreal_bridge(sp->X_real);}
    else {
        QMessageBox::information(this,"Ошибка","Не выбрана структура системы",QMessageBox::Ok);
        return false;}
    return true;
}

//получение списка с серединами карманов
QList<double> MainWindow::get_center_PD(double min, double max, double step)
{
    QList<double> properties_diapasone;
    QList<double> result;

    double value = min;
    properties_diapasone.append(value);

    while(roundTo(value,5) <= roundTo(max,5))
    {
        value+=step;
        properties_diapasone.append(value);
    }

    for(int i = properties_diapasone.count()-1; i >=1; i--)
    {
        double value = (properties_diapasone.at(i-1)+properties_diapasone.at(i))/2;
        if(value<=1)
            result.append((properties_diapasone.at(i-1)+properties_diapasone.at(i))/2);
        else
            result.append(1.0);
    }

    std::sort(result.begin(),result.end());

    return result;
}

//получение списка с точками функции распределения
QList<int> MainWindow::count_real(QList<double> spd, QList<double> freq_list)
{
    QList<int> result;
    for(int i = 0; i < spd.count(); i++)
    {
        int count = 0;
        for(int j = 0; j < freq_list.count(); j++)
        {
            if(roundTo(freq_list.at(j),5) <= roundTo(spd.at(i),5))
                count +=1;
        }
        result.append(count);
    }

    return result;
}

QList<double> MainWindow::count_density(QList<int> count_F)
{
    QList <double> result;
    int test = ui->spinBox_test->value();
    result.append(double(count_F.first())/test);

    qDebug()<<"double(count_F.first())/test"<<double(count_F.first())/test;

    for(int i = 0; i < count_F.count(); i++)
    {
        if(i!=count_F.count()-1)
            result.append(double(count_F.at(i+1)-count_F.at(i))/test);
    }
    return result;
}

QList<double> MainWindow::get_result_density(QList<double> spd, double M, double SKO,double step)
{
    QList<double> fN;

    for(int i = 0; i < spd.count(); i++)
    {
        double first = 1/(SKO*sqrt(2*M_PI));
        double num = pow(spd.at(i)-M,2.0);//числит
        double denom = 2*pow(SKO,2.0);//знаменат
        double second = exp(-num/denom);
        double result = first*second*step;
        qDebug()<<"result"<<double(result);
        fN.append(double(result));
//        fN.append(first*second);
        // \0.0/ ит ат таневат
    }
    return fN;
}

//вычисление математического ожидания
double MainWindow::calc_M(QList<double> spd, QList<double> density)
{
    int count = spd.count();
    double M = 0.0;

    for(int i = 0; i < count; i++)
        M+=spd.at(i)*density.at(i);

//    M = M/ui->spinBox_test->value();
    return M;
}

double MainWindow::calc_D(QList<double> spd, QList<double> density, double M)
{
    int count = spd.count();
    double D = 0.0;

    for(int i = 0; i < count; i++)
        D+=spd.at(i)*spd.at(i)*density.at(i);

    D = D/*/ui->spinBox_test->value()*/-M*M;
    return D;
}

int MainWindow::calc_Xreal_bridge(QList<QList<int> > X_real)
{
    int row = X_real.first().size();//количество строк по всем СЧ одинаковое = кол-во прогонов
    int sum_real = 0;
    for (int i = 0; i < row; i++)
    {
        //(X1+X2)*(X3+X4)*X5+(X1*X3+X2*X4)*(1-X5)
        int X1 = X_real.first().at(i);
        int X2 = X_real.at(1).at(i);
        int X3 = X_real.at(2).at(i);
        int X4 = X_real.at(3).at(i);
        int X5 = X_real.last().at(i);

        int x_by_row = (X1 + X2) * (X3+X4) * X5 +(X1 * X3 + X2 * X4) * (1 - X5);//для i-й строки

        //количество реализовавшихся угроз (количество реализовавшихся в цепочке не учитываем, учитываем факт реаизации хотя бы одной угрозы)
        sum_real+= qMin(x_by_row,1);
    }
    return  sum_real;
}

void MainWindow::on_actionInformation_triggered()
{
    QString workingDir = qApp->applicationDirPath();
    QDesktopServices::openUrl (QUrl::fromLocalFile (workingDir+"/Приложение В. Руководство оператора.pdf"));
}

void MainWindow::on_action_single_toggled(bool arg1)
{
    if(arg1)
    {
        type_calc_params = single;



        ui->action_several->setChecked(false);

        ui->action_consistent->setChecked(false);
        ui->action_parallel->setChecked(false);
        ui->action_bridge->setChecked(true);

    }
}

void MainWindow::on_action_bridge_toggled(bool arg1)
{
    if(arg1 and type_calc_params == single){
        ui->action_parallel->setChecked(false);
        ui->action_consistent->setChecked(false);}
}

void MainWindow::create_freq_model(QList<double> freq_list, struct_model type)
{
    QStringList header;
    int row = ui->spinBox_test->value();
    if(freq->rowCount()==0)
        freq->setRowCount(row);
    else
        for(int i = 0; i < freq->columnCount(); i++)
            header.append(freq->headerData(i,Qt::Horizontal).toString());

    if(ui->action_bridge->isChecked() and type == bridge)
        header.append("Вероятность мост");

    freq->insertColumn(freq->columnCount());

    for(int i = 0; i < freq->columnCount(); i++)
        freq->setHeaderData(i,Qt::Horizontal, header.at(i));

    for(int j = 0; j <freq_list.count(); j++)
        freq->setData(freq->index(j,freq->columnCount()-1),QString::number(freq_list.at(j)).replace(",","."));


}

void MainWindow::create_gi_model(QStandardItemModel *model, QList<double> spd, double max,  QVector <QString>*name )
{
    QVector <QString> header_hor = {"P(X)","F","f","fN"};
    int column = header_hor.size();
    QVector <QString> header_vert = {"(0..." + QString::number(spd.first()) + "]"};

    for(int i = 0; i < spd.count(); i++)
        if(i != spd.count()-1)
            header_vert.append("(" + QString::number(spd.at(i)) + "..."+QString::number(spd.at(i+1))+ "]");

    if(spd.last() > max)
        header_vert.last().replace("]",")");//добавить, если последний элемент подписи больше чем максимальный элемент частости

    *name = header_vert;
    int row = header_vert.count();

    model->setColumnCount(column);
    model->setRowCount(row);

    for(int i = 0; i < column; i++)
        model->setHeaderData(i,Qt::Horizontal, header_hor.at(i));

    for(int i = 0; i < row; i++)
        model->setHeaderData(i,Qt::Vertical, header_vert.at(i));

    for(int i = 0; i < spd.count(); i++)
    {
        model->setData(model->index(i,0),QString::number(spd.at(i)));
        model->item(i, 0)->setTextAlignment(Qt::AlignCenter);
    }

    qDebug()<<"vert"<<header_vert;
}

void MainWindow::filling_gi_model(QStandardItemModel *model, QList<int> F, QList<double> f, QList<double> fN)
{
    for(int i = 0; i < F.count(); i++)
    {
        model->setData(model->index(i,1),QString::number(F.at(i)));
        model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
    }
    for(int i = 0; i < f.count(); i++)
    {
        model->setData(model->index(i,2),QString::number(f.at(i)));
        model->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    }
    for(int i = 0; i < fN.count(); i++)
    {
        model->setData(model->index(i,3),QString::number(roundTo(fN.at(i),3)));
        model->item(i, 3)->setTextAlignment(Qt::AlignCenter);
    }
}

void MainWindow::filling_stat_char_bridge(double M, double D, double SKO, double min, double max)
{
    ui->dbSpB_min_bridge->setValue(min);
    ui->dbSpB_max_bridge->setValue(max);
    ui->dbSpB_M_bridge->setValue(M);
    ui->dbSpB_D_bridge->setValue(D);
    ui->dbSpB_SKO_bridge->setValue(SKO);
}

double MainWindow::get_min_inList(QList<double> list)
{
    double min = 1.0;

    for (int j = list.count()-1; j >=1 ; j--)
    {
        if(roundTo(min,3) > roundTo(qMin(list.at(j-1),list.at(j)),3))
            min = qMin(list.at(j-1),list.at(j));
    }
    return min;
}

double MainWindow::get_max_inList(QList<double> list)
{
    double max = 0.0;
    for (int j = list.count()-1; j >=1 ; j--)
    {
        if(roundTo(max,3) < roundTo(qMax(list.at(j-1),list.at(j)),3))
            max = qMax(list.at(j-1),list.at(j));
    }
    return max;
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    ui->widget1->clearPlottables();
    ui->widget1->clearGraphs();

    QCPBars *bar_chart = new QCPBars(ui->widget1->xAxis,ui->widget1->yAxis);
    ui->widget1->addPlottable(bar_chart);
    bar_chart->setName("Плотность распр-ия эксп-ая");

    // create and configure plottables:
    QCPGraph *graph1 = ui->widget1->addGraph();

    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graph1->setPen(QPen(QColor(120,120,120), 2));

    graph1->setName("Плотность норм. распр-ия");

    QVector <double> x;
    QVector <double> y;
    QVector <double> y_fN;
    QVector <QString> x_label;
    QVector <QString> y_label;

    double max_y = 0.0;
    double step_y = 0.0;

    ui->widget1->xAxis->setAutoTicks(false);
    ui->widget1->xAxis->setAutoTickLabels(false);
    ui->widget1->xAxis->setTickLabels(true);
    ui->widget1->legend->setVisible(true);

    ui->widget1->xAxis->setLabel("Вероятность реализации цепочки угроз");
    ui->widget1->yAxis->setLabel("Частота");
    ui->widget1->xAxis->setTickLabelRotation(-90);

    ui->widget1->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);//стрелки на осях
    ui->widget1->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    ui->widget1->setInteractions(/*QCP::iRangeDrag |*/ QCP::iRangeZoom | QCP::iSelectPlottables);
    ui->label_struct_name->setText("Структура системы: "+ index.data().toString());

    if(index.row() == 0)
    {
        step_y = ui->dbSpB_step_bridge->value();
        bar_chart->setBrush(QColor(50, 50, 250, 70));
        bar_chart->setPen(QColor(50,50,100));

        for(int i = 0; i < gi_bridge->rowCount(); i++)
        {
            y.append(gi_bridge->index(i,2).data().toDouble());
            y_fN.append(gi_bridge->index(i,3).data().toDouble());
            x.append(i+1);
            x_label.append(gi_bridge->headerData(i,Qt::Vertical).toString());
        }
    }

    bar_chart->setData(x,y);
    graph1->setData(x, y_fN);

    ui->widget1->xAxis->setTickVector(x);
    ui->widget1->yAxis->setTickVector(y);
    ui->widget1->xAxis->setTickVectorLabels(x_label);


    double max_f = get_max_inList(y.toList());
    double max_fN = get_max_inList(y_fN.toList());

    if(roundTo(max_f,4)>roundTo(max_fN,4))
        max_y = max_f;
    else
        max_y = max_fN;

    double max = get_max_inList(x.toList())+2;
    ui->widget1->xAxis->setRange(0, max);
    ui->widget1->yAxis->setRange(0, max_y + step_y); //поставить 1
    ui->widget1->yAxis->setAutoTickStep(false);
    ui->widget1->yAxis->setTickStep(0.1);
    ui->widget1->axisRect()->setRangeZoom(Qt::Horizontal);   // Включаем удаление/приближение только по горизонтальной оси
    ui->widget1->axisRect()->setRangeZoom(Qt::Vertical);
    ui->widget1->replot();
}

void MainWindow::std_fill_probab()
{
    if(ui->action_const->isChecked())
    {
        probab->clear();
        for(int i = 0; i < 5; i++)
        {
            on_pB_add_probab_clicked();
            probab->setData(probab->index(0,i),"0.5");
        }
    }
    if(ui->action_dipasone->isChecked())
    {
        probab_m2->clear();
        for(int i = 0; i < 5; i++)
        {
            on_pB_add_probab_clicked();
            probab_m2->setData(probab_m2->index(0,i),"0.5");
            probab_m2->setData(probab_m2->index(1,i),"0.7");
        }
        ui->tableView_start_p_m2->resizeColumnsToContents();
    }

    if(ui->action_triangular->isChecked())
    {
        probab_m3->clear();

        for(int i = 0; i < 5; i++)
        {
            on_pB_add_probab_clicked();
            probab_m3->setData(probab_m3->index(0,i),"0.5");
            probab_m3->setData(probab_m3->index(1,i),"0.7");
            probab_m3->setData(probab_m3->index(2,i),"0.6");
        }
        ui->tableView_start_p_m3->resizeColumnsToContents();
    }
}

void MainWindow::checked_all_struct()
{
    ui->action_several->setChecked(true);
    ui->action_consistent->setChecked(true);
    ui->action_parallel->setChecked(true);
    ui->action_bridge->setChecked(true);
}

double chkstr(QString str)// Проверка на использование точек (и замена запятых на точки)
{
    bool isOk = false;
    double num = str.toDouble(&isOk);
    if (isOk == false)
        if (str.contains(",") == true)
            str.replace(",", ".");
    num = str.toDouble(&isOk);
    return num;
}
QString copy_from_table(QTableView *table_from, int num_from)
{
    QString table = "";
    for(int j = 0; j < table_from->model()->columnCount(); j++)
    {
        table += table_from->model()->headerData(j, Qt::Horizontal).toString();
        if (j != table_from->model()->columnCount() - 1)
            table += "\t";
    }
    table += "\n";

    QString vert_head ="";
    for(int j = 0; j < table_from->model()->rowCount(); j++)
    {
        vert_head += "\n";
        vert_head += table_from->model()->headerData(j, Qt::Vertical).toString();
    }

    for (int i = 0; i < table_from->model()->rowCount(); i++)
    {
        for (int j = 0; j < table_from->model()->columnCount(); j++)
        {
            if(j > 0)
                table += "\t";

            if (j >= num_from)
                table += QString::number(roundTo(chkstr(table_from->model()->data(table_from->model()->index(i, j)).toString()), 3)).replace(".",",");

            else
                table += table_from->model()->data(table_from->model()->index(i, j)).toString().replace(".",",");
        }

        table += "\n";
    }
    return  table;
}

void MainWindow::on_pB_buf_rnd_clicked()
{
    QString rnd_res = copy_from_table(ui->tableView_rnd,0);
    QApplication::clipboard()->setText(rnd_res);
}

void MainWindow::on_pushButton_freq_buffer_clicked()
{
    QString result = copy_from_table(ui->tableView_frequency,0);
    QApplication::clipboard()->setText(result);
}

//Если выбрали модель 1 (жесткая оценка)
void MainWindow::on_action_const_toggled(bool arg1)
{
    if(arg1 ){
        ui->action_dipasone->setChecked(false);
        ui->action_triangular->setChecked(false);}
}

//Если выбрали модель 2 (оценка с погрешностью)
void MainWindow::on_action_dipasone_toggled(bool arg1)
{
    if(arg1 ){
        ui->action_const->setChecked(false);
        ui->action_triangular->setChecked(false);}
}

//Если выбрали модель 3 (оценка с треугольным распределением)
void MainWindow::on_action_triangular_toggled(bool arg1)
{
    if(arg1 ){
        ui->action_dipasone->setChecked(false);
        ui->action_const->setChecked(false);}
}

void MainWindow::on_pB_gi_bridge_buf_clicked()
{
    QString result = copy_from_table(ui->tableView_graph_info_bridge,0);

    QStringList common_name = {"Кол-во итераций ГСЧ(n)","Кол-во экспериментов"};
    QStringList common_value;
    common_value.append(QString::number(ui->spinBox_run->value()) + "\n");
    common_value.append(QString::number(ui->spinBox_test->value()) + "\n");

    QString common;
    for(int i = 0; i < common_name.count(); i++)
        common += common_name.at(i) +"\t"+ QString(common_value.at(i)).replace(".",",");

    QString probablies;
    if(ui->action_const->isChecked())
        probablies = copy_from_table(ui->tableView_probab,0);
    if(ui->action_dipasone->isChecked())
        probablies = copy_from_table(ui->tableView_rnd_p_diap_m2,0);

    common += "\n\n"+ probablies + "\n\n";

    QStringList stat_name = {"MIN","MAX","STEP","Математическое ожидание","Дисперсия","СКО"};
    QStringList stat_res;

    stat_res.append(QString::number(ui->dbSpB_min_bridge->value()) + "\n");
    stat_res.append(QString::number(ui->dbSpB_max_bridge->value())+ "\n");
    stat_res.append(QString::number(ui->dbSpB_step_bridge->value()) + "\n");
    stat_res.append(QString::number(ui->dbSpB_M_bridge->value())+ "\n");
    stat_res.append(QString::number(ui->dbSpB_D_bridge->value()) + "\n");
    stat_res.append(QString::number(ui->dbSpB_SKO_bridge->value()));

    QString values;
    for(int i = 0; i < stat_res.count(); i++)
        values+=stat_name.at(i) +"\t"+ QString(stat_res.at(i)).replace(".",",");

    result = common + values + "\n\n\n" + result;

    QApplication::clipboard()->setText(result);
}

//Копировать в буфер график
void MainWindow::on_pushButton_buffer_graph_clicked()
{
    QClipboard *clip = QApplication::clipboard();
    QPixmap pic;

    pic = ui->widget1->toPixmap(ui->widget1->width(), ui->widget1->height());
    clip->setPixmap(pic);
}

//Очистить поле с графиками
void MainWindow::on_pushButton_clear_graph_clicked()
{
    ui->widget1->clearPlottables();
    ui->widget1->clearGraphs();
    ui->label_struct_name->clear();
    ui->widget1->replot();
}

//убрать zoom
void MainWindow::on_pushButton_reset_graph_zoom_clicked()
{
    QString name = ui->label_struct_name->text().remove("Структура системы: ");
    on_pushButton_clear_graph_clicked();

    if(name == "Мостовая"){
        QModelIndex index = ui->listView->model()->index(2, 0, QModelIndex());
        on_listView_doubleClicked(index);}

}

//Сохранение графика в качестве файла
void MainWindow::on_pushButton_save_graph_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Сохранить как..."), QApplication::applicationDirPath(), ui->comboBox_graph_format->currentText());

    switch (ui->comboBox_graph_format->currentIndex())
    {
    case 0:
        ui->widget1->saveJpg(path, ui->widget1->width(), ui->widget1->height(), 1.0, -1);
        break;
    case 1:
        ui->widget1->savePng(path, ui->widget1->width(), ui->widget1->height(), 1.0, -1);
        break;
    case 2:
        ui->widget1->saveBmp(path, ui->widget1->width(), ui->widget1->height(), 1.0);
        break;
    case 3:
        ui->widget1->savePdf(path, false, ui->widget1->width(), ui->widget1->height(), "", "");
        break;
    default:
        ui->widget1->saveJpg(path, ui->widget1->width(), ui->widget1->height(), 1.0, -1);
        break;
    }
}

void MainWindow::on_actionExport_rnd_triggered()
{
    exp_form->show();
}

void MainWindow::export_rnd_list(QString filename)
{
    int start_col = 1, start_row = 1;
    int col_count = 0, row_count = 0;
    QString name;

    if(ui->action_several->isChecked())
    {
        if(ui->action_const->isChecked())
            name = "М-ль_Полная_определенность";
        if(ui->action_dipasone->isChecked())
            name = "Модель_с_погрешностью";
        if(ui->action_triangular->isChecked())
            name = "М-ль_с_треуг-м_распр-ем";
    }
    if(ui->action_single->isChecked())
    {
        if(ui->action_bridge->isChecked())
            name = "Мостовая";
    }

    col_count = rnd->columnCount()*ui->spinBox_test->value();
    row_count = ui->spinBox_run->value();

    QAxObject *excel = new QAxObject( "Excel.Application", this ); //получаем указатьтель на excel
    QAxObject *workbooks = excel->querySubObject("Workbooks"); //получаем указатель на список книг
    QAxObject *workbook = workbooks->querySubObject("Add()"); //добавляем свою книгу в список
    QAxObject *sheets = workbook->querySubObject( "Sheets" ); //получаем указатель список листов
    QAxObject *worksheet = sheets->querySubObject("Item(const QVariant&)",  QVariant("Лист1"));

    // получение указателя на левую верхнюю ячейку [row][col] ((!)нумерация с единицы)
    QAxObject* Cell1 = worksheet->querySubObject("Cells(QVariant&,QVariant&)", start_row, start_col);
    // получение указателя на правую нижнюю ячейку [row + row_count - 1][col + col_count - 1] ((!) row_count>=1,col_count>=1)
    QAxObject* Cell2 = worksheet->querySubObject("Cells(QVariant&,QVariant&)", start_row + row_count , start_col + col_count - 1);
    // получение указателя на целевую область
    QAxObject* range = worksheet->querySubObject("Range(const QVariant&,const QVariant&)", Cell1->asVariant(), Cell2->asVariant() );

    QList <QVariant> cellsList; // список ячеек строки
    QList <QVariant> rowsList; // список строк


    QList <QVariant> header;
    //добавить подпись с № эксперимента

    for (int j = 0; j < rnd->columnCount(); j++) //добавляем в список листов строку с горизонтальным хедером
        header << "СЧ" + QString::number(j+1);

    for (int j = 0; j < ui->spinBox_test->value(); j++) //добавляем в список листов строку с горизонтальным хедером
        cellsList << header;

    rowsList << QVariant(cellsList);

    for (int j = 0; j < ui->spinBox_run->value(); j++) //по столбцам
    {
        cellsList.clear();
        for(int k = 0; k < ui->spinBox_test->value(); k++)
            for (int i = 0; i < rnd->columnCount(); i++)
                cellsList << QString::number(random_list.at(k).at(i).at(j)).replace(".",",");
        rowsList << QVariant(cellsList);
        // в список строк добавляется QVariant каждой строки
    }

    range->dynamicCall("HorizontalAlignment",-4108);//выравнивание по центру
    range->setProperty("Value", QVariant(rowsList) );// собственно вывод

    workbook->dynamicCall("SaveAs(const QString&)", filename);

    // освобождение памяти
    delete range;
    //    delete range_table;
    delete Cell1;
    delete Cell2;

    deleteExcel(sheets);
    deleteExcel(workbook);
    workbooks->dynamicCall("Close");
    deleteExcel(workbooks);
    deleteExcel(excel);

}

//освобождение памяти
void MainWindow::deleteExcel(QAxObject *excel)
{
    excel->clear();
    delete excel;
    excel = NULL;
}

void MainWindow::on_spinBox_run_valueChanged(int arg1)
{
    double value = double(1)/arg1;
    ui->dbSpB_step_bridge->setValue(value);
}
