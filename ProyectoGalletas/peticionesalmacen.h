#ifndef PETICIONESALMACEN_H
#define PETICIONESALMACEN_H
#include "Estructuras.h"
#include <QWidget>
#include <QTableWidget>

namespace Ui {
class PeticionesAlmacen;
}

class PeticionesAlmacen : public QWidget
{
    Q_OBJECT

public:
    explicit PeticionesAlmacen(QWidget *parent = nullptr);
    QTableWidget * tabla;
    ~PeticionesAlmacen();

private:
    Ui::PeticionesAlmacen *ui;
};

#endif // PETICIONESALMACEN_H
