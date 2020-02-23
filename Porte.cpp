/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte
 * \author Étudiant(e)
 * \version 0.1
 * \date janvier 2020
 *
 */

#include "Porte.h"

namespace TP1
{

    //! Constructeur par défaut
    Porte::Porte(){
        this->color = Couleur::Aucun;
    }

    //! Constructeur, en argument la couleur de la porte ainsi que la pièce de destination
    Porte::Porte(Couleur c, Piece * d) {
        this->color = c;
        this->destination = d;
    }

    //! Constructeur de copie
    Porte::Porte(const Porte& source) {
        //TODO: vérifié si on doit faire un DEEP-COPY
        this->destination = source.destination;
        this->color = source.color;
    }

    //! Un destructeur qui ne fera rien
    Porte::~Porte(){}

    //! Surcharge de l'opérateur =
    const Porte & Porte::operator =(const Porte& source){
        //TODO: vérifié si on doit faire un DEEP-COPY
        this->destination = source.destination;
        this->color = source.color;
    }

    //! Surcharge de l'opérateur ==
    bool  Porte::operator ==(const Porte& source) const{
        return this->destination == source.destination && this->color == source.color;
    }

    //! Accesseur de la couleur d'une porte
    Couleur  Porte::getCouleur() const {
        return this->color;
    }

    //! Accesseur de la piece de destination
    Piece *  Porte::getDestination() const {
        return this->destination;
    }

}
