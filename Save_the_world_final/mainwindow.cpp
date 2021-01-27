#include "mainwindow.h"
#include "ui_mainwindow.h"
#define RUTA_FICHEROS "Ficheros.txt"
#define FICHEROS_RESPALDO "Respaldo.txt"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Coloca el fondo
    setStyleSheet("MainWindow {background-image:url(:/new/Imagenes/Fondo.jpg)}");

    //Se ocultan los elementos que no se necesitan de momento
    ui->Nombre->hide();
    ui->Clave->hide();
    ui->Botoncontinuar->hide();
    ui->Volver->hide();
    ui->Ingresar->hide();
    ui->Botoncontinuar_2->hide();
    ui->Confirmar->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::Find(string Nombre, string Clave)
{
    // Metodo encargado de buscar los datos de un usuario en los registros

    /*QString info;*/                       //String para leer los datos del archivo

    QFile file(RUTA_FICHEROS);           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archivo en modo lectura

    int n=0; //Bandera para el manejo de datos
    while (file.atEnd() == false){
        QString line = file.readLine();
        // Ciclo para guardar cada dato de la linea de texto en su posicion correspondiente en el arreglo datos
        while(n>=0){
            n = line.indexOf(" ");
            if(n!=0){
                datos.append(line.left(n));
            }
            line=line.remove(0,n+1);
        }
        // Conversion de QString a string
        string Name = datos.at(0).toStdString();
        string Password = datos.at(1).toStdString();

        if(Name == Nombre){
            if(Password == Clave){
                file.close();
                return 2;
            }
            else{
                file.close();
                return 1;
            }

        }
        datos.clear();
        n = 0;
    }
    file.close();
    return 0;
}

void MainWindow::on_Botoncontinuar_clicked()
{
    string Nombre = ui->Nombre->text().toStdString();
    string Clave = ui->Clave->text().toStdString();

    // Apertura del nivel y actualizacion de datos
    if(Find(Nombre,Clave)==2){
        datos_partida.setNombre_equipo(datos.at(0).toStdString());
        datos_partida.setClave(datos.at(1).toStdString());
        datos_partida.setModo(datos.at(2).toInt());
        datos_partida.setSemilla(datos.at(3).toInt());
        datos_partida.setPuntaje(datos.at(4).toInt());
        QString Info = "Nombre: "+QString::fromStdString(datos_partida.getNombre_equipo())+"\n"+"Puntaje: "+QString::number(datos_partida.getPuntaje());
        msgBox.setText(Info);
        msgBox.exec();

        if(datos_partida.getSemilla()==1){
            Nivel_1 *nivel_1 = new Nivel_1;
            nivel_1->setDatos_partida_1(this->datos_partida);
            nivel_1->show();
            this->~MainWindow();
        }
        else if(datos_partida.getSemilla()==2){
            Nivel2 *nivel_2 = new Nivel2;
            nivel_2->setDatos_partida(this->datos_partida);
            nivel_2->show();
            this->~MainWindow();
        }
        else{
            Nivel3 *nivel_3 = new Nivel3;
            nivel_3->setDatos_juego(this->datos_partida);
            nivel_3->show();
            this->~MainWindow();
        }
    }

    else{
        msgBox.setText("El usuario no existe. Verifique usuario y contraseña");
        msgBox.exec();
        ui->Nombre->clear();
        ui->Clave->clear();
    }
}

void MainWindow::on_Volver_clicked()
{
    //Volver al menu principal
    ui->Ingresar->hide();
    ui->Nombre->hide();
    ui->Clave->hide();
    ui->Volver->hide();
    ui->Botoncontinuar->hide();
    ui->Solitario->show();
    ui->Multijugador->show();
    ui->CargaPartida->show();
    ui->Seleccionar->show();
    ui->Botoncontinuar_2->hide();
    ui->Confirmar->hide();
    ui->Eliminar->show();
    ui->Nombre->clear();
    ui->Clave->clear();

}

void MainWindow::on_Solitario_clicked()
{
    //Se dirige al menu de registro de un jugador

    ui->Solitario->hide();
    ui->Multijugador->hide();
    ui->CargaPartida->hide();
    ui->Nombre->show();
    ui->Clave->show();
    ui->Botoncontinuar_2->show();
    ui->Eliminar->hide();
    ui->Volver->show();

    datos_partida.setModo(1);
}

void MainWindow::on_Multijugador_clicked()
{
    //Se dirige al menu de registro de un equipo de jugadores
    ui->Solitario->hide();
    ui->Multijugador->hide();
    ui->CargaPartida->hide();
    ui->Nombre->show();
    ui->Clave->show();
    ui->Botoncontinuar_2->show();
    ui->Eliminar->hide();
    ui->Volver->show();

    msgBox.setText("Tener en cuenta\nSe jugará en modo cooperativo por lo que solo se guarda el nombre del equipo y el puntaje es el mismo para ambos.");
    msgBox.exec();

    datos_partida.setModo(2);
}

void MainWindow::on_CargaPartida_clicked()
{
    // Dirige al usuario al menu de cargar partida

    ui->Seleccionar->hide();
    ui->Solitario->hide();
    ui->Multijugador->hide();
    ui->CargaPartida->hide();
    ui->Ingresar->show();
    ui->Volver->show();
    ui->Nombre->show();
    ui->Clave->show();
    ui->Botoncontinuar->show();
    ui->Eliminar->hide();
}

void MainWindow::on_Botoncontinuar_2_clicked()
{
    /* Se capturan los datos de los line edit y se verifica que no existan mas usuarios con el mismo
     * nombre o que se utilicen caracteres no admitidos. Si todo esta en orden, se procede al registro
     */

    QString Nombre = ui->Nombre->text();
    QString Clave = ui->Clave->text();    

    ui->Nombre->clear();
    ui->Clave->clear();

    if(Find(Nombre.toStdString(),Clave.toStdString())==1 || Find(Nombre.toStdString(),Clave.toStdString())==2){
        msgBox.setText("El usuario ya existe, intente con otro nombre"); //Se da el texto para la qMessegeBox
        msgBox.exec(); //Se muestra la qMessegeBox
    }

    else if(Nombre.indexOf(" ")==-1 || Clave.indexOf(" ")==-1){ //Verificacion
        QFile file(RUTA_FICHEROS);
        file.open(QIODevice::WriteOnly | QIODevice::Text |QIODevice::Append);

        QTextStream out(&file);
        out << Nombre<<" "<<Clave<<" "<<datos_partida.getModo()<<" "<<"1"<<" "<<"0"<<"\n"; //Registro
        file.flush();
        file.close();

        datos_partida.setSemilla(1);
        datos_partida.setPuntaje(0);

        Nivel_1 *nivel_1 = new Nivel_1;
        nivel_1->setDatos_partida_1(this->datos_partida);
        nivel_1->show();
        this->~MainWindow();
    }
    else{
        msgBox.setText("Favor no utilizar espacios en el nombre o la contraseña.");
        msgBox.exec();
    }
}

void MainWindow::on_Eliminar_clicked()
{
    //Se dirige al menu para eliminar un usuario
    ui->Seleccionar->hide();
    ui->Solitario->hide();
    ui->Multijugador->hide();
    ui->CargaPartida->hide();
    ui->Ingresar->show();
    ui->Volver->show();
    ui->Nombre->show();
    ui->Clave->show();
    ui->Confirmar->show();
    ui->Eliminar->hide();
}

void MainWindow::on_Confirmar_clicked()
{
    /* Este metodo se utiza para eliminar un usuario
     * Se crean un nuevo archivo (.txt) con el objetivo de que toda
     * la informacion (excepto la del jugador eliminado) se guarde
     */

    QFile file(RUTA_FICHEROS);           //Objeto para manejar la lectura del archivo
    file.open(QIODevice::ReadOnly);     //Abre el archiv en modo lectura
    QList <QString> datos;

    QFile filer(FICHEROS_RESPALDO);
    filer.open(QIODevice::WriteOnly);   //Abre el archiv en modo lectura

    //Captura de datos de los line edit
    QString Nombre = ui->Nombre->text();
    QString Clave = ui->Clave->text();

    int n=0;
    bool Found=false;
    while (file.atEnd() == false){
        QString line = file.readLine();
        //Ciclo para guardar cada dato de la linea de texto en su posicion correspondiente en el arreglo
        while(n>=0){
            n = line.indexOf(" ");
            if(n!=0){
                datos.append(line.left(n));
            }
            line=line.remove(0,n+1);
        }
        QString Name = datos.at(0);
        QString Password = datos.at(1);
        QString modo = datos.at(2);
        QString semilla = datos.at(3);
        QString puntaje = datos.at(4);
        QTextStream out(&filer);
        if(Name != Nombre){
            out << Name<<" "<<Password<<" "<<modo<<" "<<semilla<<" "<<puntaje;
        }
        else{
            if(Clave != Password){
                out << Name<<" "<<Password<<" "<<modo<<" "<<semilla<<" "<<puntaje;
                msgBox.setText("Contraseña incorrecta.");
                msgBox.exec();
                Found = true;
            }
            else{
                msgBox.setText("Usuario elimindado con exito.");
                msgBox.exec();
                Found = true;
            }
        }
        datos.clear();
        n = 0;
    }
    if(!Found){
        msgBox.setText("Usuario no encontrado. Verificar usuario y contraseña");
        msgBox.exec();
    }
    ui->Nombre->clear();
    ui->Clave->clear();
        filer.flush();
        filer.close(); //Se cierra el nuevo archivo
        file.close(); //Se cierra el archivo viejo
        file.remove(); //Se elimina el archivo viejo
        filer.rename(RUTA_FICHEROS); //Se renombra el archivo nuevo

}
