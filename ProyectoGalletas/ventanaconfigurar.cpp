#include "ventanaconfigurar.h"
#include "ui_ventanaconfigurar.h"


VentanaConfigurar::VentanaConfigurar(QWidget *parent) :QMainWindow(parent),ui(new Ui::VentanaConfigurar){
    ui->setupUi(this);
}

VentanaConfigurar::~VentanaConfigurar(){
    this->punteros=NULL;
    ok=true;
    this->ui->rBtn_bnd1On->setChecked(true);
    this->ui->rBtn_bnd2On->setChecked(true);
    this->ui->rBtn_bnd3Off->setChecked(true);
    this->ui->rBtn_bnd4Off->setChecked(true);
    this->ui->rBtn_bnd5Off->setChecked(true);
    this->ui->rBtn_bnd6Off->setChecked(true);
    delete ui;
}
//Insertar pedido paquetes
void VentanaConfigurar::on_btn_InsIns_clicked(){
    this->punteros->paquetes->insertar(this->ui->txt_InsCntGalletas->text().toInt(&ok),this->ui->txt_InsNom->text(),this->ui->txt_InsCntPaq->text().toInt(&ok),1,1,0);
    this->punteros->paquetes->setProbabilidades();
}
//Modificar receta
void VentanaConfigurar::on_btn_RecIns_clicked(){
    this->punteros->receta->cantidadChocolate=this->ui->txt_RecCntChocoGall->text().toDouble(&ok);
    this->punteros->receta->cantidadMasa=this->ui->txt_RecCntMasaGall->text().toDouble(&ok);
}
//Modificar carrito
void VentanaConfigurar::on_btn_CarIns_clicked(){
    this->punteros->carrito->duracion=this->ui->txt_CarTmpXEnv->text().toInt(&ok);
    this->punteros->carrito->capacidadTransporteChocolate=this->ui->txt_CarTransChoco->text().toDouble(&ok);
    this->punteros->carrito->capacidadTransporteMezcla=this->ui->txt_CarTransMasa->text().toDouble(&ok);
}
void VentanaConfigurar::on_btn_maq1Ins_clicked(){
    this->punteros->maquinaMasa1->tiempoProceso=this->ui->txt_maq1TmpProd->text().toInt(&ok);
    this->punteros->maquinaMasa1->maximaCapacidad=this->ui->txt_maq1CntMax->text().toDouble(&ok);
    this->punteros->maquinaMasa1->minimaCapacidad=this->ui->txt_maq1CntMin->text().toDouble(&ok);
    this->punteros->maquinaMasa1->cantidadEnviadaABanda=this->ui->txt_maq1CntProdTiempo->text().toDouble(&ok);
}
void VentanaConfigurar::on_btn_maq2Ins_clicked(){
    this->punteros->maquinaMasa2->tiempoProceso=this->ui->txt_maq2TmpProd->text().toInt(&ok);
    this->punteros->maquinaMasa2->maximaCapacidad=this->ui->txt_maq2CntMax->text().toDouble(&ok);
    this->punteros->maquinaMasa2->minimaCapacidad=this->ui->txt_maq2CntMin->text().toDouble(&ok);
    this->punteros->maquinaMasa2->cantidadEnviadaABanda=this->ui->txt_maq2CntProdTiempo->text().toDouble(&ok);
}
void VentanaConfigurar::on_btn_maqChIns_clicked(){
    this->punteros->maquinaChocolate->tiempoProceso=this->ui->txt_maqChTmpProd->text().toInt(&ok);
    this->punteros->maquinaChocolate->maximaCapacidad=this->ui->txt_maqChCntMax->text().toDouble(&ok);
    this->punteros->maquinaChocolate->minimaCapacidad=this->ui->txt_maqChCntMin->text().toDouble(&ok);
    this->punteros->maquinaChocolate->cantidadEnviadaABanda=this->ui->txt_maqChCntProdTiempo->text().toDouble(&ok);
}
void VentanaConfigurar::on_btn_BTMIns_clicked(){
    this->punteros->colaMasaEnsambladora->maximaCapacidad=this->ui->txt_BTMMax->text().toDouble(&ok);
}
void VentanaConfigurar::on_btn_BTChIns_clicked(){
    this->punteros->colaChocolateEnsambladora->maximaCapacidad=this->ui->txt_BTChMax->text().toDouble(&ok);
}
void VentanaConfigurar::on_btn_maqEmsIns_clicked(){
    this->punteros->maquinaEnsambladora->duracion=this->ui->txt_maqEmsTmpProd->text().toInt(&ok);
    this->punteros->maquinaEnsambladora->produceNGalletas=this->ui->txt_maqEmsCntProdXTiemp->text().toDouble(&ok);
}
void VentanaConfigurar::on_btn_BTEmsHorIns_clicked(){
    this->punteros->colaEnsambladoraHorno->maximaCapacidad=this->ui->txt_BTEmsHorMax->text().toDouble(&ok);
}
void VentanaConfigurar::on_btn_BTHorSupIns_clicked(){
    this->punteros->colaSupervisores->maximaCapacidad=this->ui->txt_BTMMax->text().toDouble(&ok);
}
void VentanaConfigurar::on_btn_SupIns_clicked(){
    this->punteros->supervisor1->probabilidadDesecho=this->ui->txt_Sup1Prob->text().toDouble(&ok);
    this->punteros->supervisor2->probabilidadDesecho=this->ui->txt_Sup2Prob->text().toDouble(&ok);
}
void VentanaConfigurar::on_btn_HorIns_clicked(){
    this->punteros->horno->duracionHorneado=this->ui->txt_HorTmpHorneado->text().toInt(&ok);
}
void VentanaConfigurar::on_btn_bnd1Ins_clicked(){
    this->punteros->horno->bandejas->primeraBandeja->capacidadGalletas=this->ui->txt_bnd1Cap->text().toInt(&ok);
}
void VentanaConfigurar::on_btn_bnd2Ins_clicked(){
    this->punteros->horno->bandejas->primeraBandeja->siguienteBandeja->capacidadGalletas=this->ui->txt_bnd2Cap->text().toInt(&ok);
}
void VentanaConfigurar::on_btn_bnd3Ins_clicked(){
    if (this->ui->rBtn_bnd3On->isChecked()){
        NodoBandeja * nodo = new NodoBandeja();
        nodo->capacidadGalletas=this->ui->txt_bnd3Cap->text().toInt(&ok);
        this->punteros->horno->bandejas->insertarAlFinal(nodo);
    }
}
void VentanaConfigurar::on_btn_bnd4Ins_clicked(){
    if (this->ui->rBtn_bnd4On->isChecked()){
        NodoBandeja * nodo = new NodoBandeja();
        nodo->capacidadGalletas=this->ui->txt_bnd4Cap->text().toInt(&ok);
        this->punteros->horno->bandejas->insertarAlFinal(nodo);
    }
}
void VentanaConfigurar::on_btn_bnd5Ins_clicked(){
    if (this->ui->rBtn_bnd5On->isChecked()){
        NodoBandeja * nodo = new NodoBandeja();
        nodo->capacidadGalletas=this->ui->txt_bnd5Cap->text().toInt(&ok);
        this->punteros->horno->bandejas->insertarAlFinal(nodo);
    }

}
void VentanaConfigurar::on_btn_bnd6Ins_clicked(){
    if (this->ui->rBtn_bnd6On->isChecked()){
        NodoBandeja * nodo = new NodoBandeja();
        nodo->capacidadGalletas=this->ui->txt_bnd6Cap->text().toInt(&ok);
        this->punteros->horno->bandejas->insertarAlFinal(nodo);
    }
}
void VentanaConfigurar::on_btn_maqEmpIns_clicked(){
    this->punteros->maquinaEmpacadora->tiempoEmpaque=this->ui->txt_maqEmpTmp->text().toInt(&ok);
    this->punteros->maquinaEmpacadora->cantidadDePaquetes=this->ui->txt_maqEmpCap->text().toInt(&ok);
}
void VentanaConfigurar::on_btn_transIns_clicked(){
    Transportador * tmp = this->punteros->trans->pn;
    while(tmp!=NULL){
        tmp->tiempoTransporte=this->ui->txt_transCap_2->text().toInt(&ok);
        tmp->maximo=this->ui->txt_transCap_2->text().toInt(&ok);
    }
}

