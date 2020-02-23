/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece
 * \author Étudiant(e)
 * \version 0.1
 * \date janvier 2020
 *
 */

#include <iostream>
#include "Piece.h"
using namespace std;


namespace TP1
{
    Piece::Piece() {
    }

    //! Surcharge du constructeur
    Piece::Piece(const std::string & nom){
        this->nom = nom;
    }

    //! Constructeur de copie
    Piece::Piece(const Piece & source){
        //TODO: vérifié si on doit faire un DEEPCLONE
        this->portes = source.portes;
        this->distanceDuDebut = source.distanceDuDebut;
        this->parcourue = source.parcourue;
        this->nom = source.nom;
    }

    //! Destructeur
    Piece::~Piece(){
        //TODO: vérifié si on doit faire qqch (si on a des new ...)
    }

    //! Surcharge de l'opérateur =
    const Piece & Piece::operator=(const Piece & source){
        //TODO: vérifié si on doit faire un DEEPCLONE

        // on teste si on n'affecte pas l'objet à lui-même.
        if (this != &source) {
            this->portes = source.portes;
            this->distanceDuDebut = source.distanceDuDebut;
            this->parcourue = source.parcourue;
            this->nom = source.nom;
        }
        return (*this); //on retourne l'objet appelant.
    }

    //! Accesseur du nom d'une pièce
    std::string Piece::getNom() const{
        return this->nom;
    }

    //! Pour initialiser l'attribut parcourue à true ou false
    void Piece::setParcourue(bool p){
        this->parcourue = p;
    }

    //! Pour initialiser l'attribut distanceDuDebut
    void Piece::setDistanceDuDebut(int d){
        this->distanceDuDebut = d ;
    }

    //! Accéder au membre parcourue
    bool Piece::getParcourue() const {
        return this->parcourue;
    }

    //! Accéder à la liste des portes qui partent de la pièce
    const std::list<Porte> & Piece::getPortes() const {
        return this->portes;
    }

    //! Accéder au membre distanceDuDebut
    int Piece::getDistanceDuDebut() const {
        return this->distanceDuDebut;
    }

    //! Ajouter une porte à la liste des portes qui partent de la pièce
    void Piece::ajoutePorte(const Porte & p) {
        this->portes.push_back(p);
    }

}
