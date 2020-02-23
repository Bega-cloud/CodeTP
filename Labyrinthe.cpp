/**
 * \file Labyrinthe.cpp
 * \brief Le code des méthodes membres et privés de la classe Labyrinthe.
 * \author IFT-2008, Étudiant(e)
 * \version 0.1
 * \date janvier 2020
 * 
 */

//Fichiers à compléter par les autres méthodes de la classe Labyrinthes demandées

#include "Labyrinthe.h"
#include <iostream>
#include <map>

using namespace std;

namespace TP1
{
    Labyrinthe::Labyrinthe() {}

    Labyrinthe::~Labyrinthe() {
        //TODO SupprimerNoeud de la liste
    }
    // -------------------------------------------------------------------------------------------------
    //	Méthodes fournies
    // -------------------------------------------------------------------------------------------------

    /**
    * \fn Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream & entree)
    * \brief Fonction déjà fournie permettant de charger un labyrinthe depuis un fichier
    * \param[in] couleur La couleur du jouer auquel le labyrinthe chargé s'applique
    * \param[in] entree Fichier contenant la définition du labyrinthe
    */
    void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream& entree)
    {

     int nbCols, nbRangs;
     if (!entree.is_open())
         throw logic_error("Labyrinthe::chargeLabyrinthe: Le fichier n'est pas ouvert !");

     entree >> nbCols >> nbRangs;
     entree.ignore();// Pour consommer le \n (le caractère fin de ligne)

     const int MAX_LIGNE = 1000;
     char ligne[MAX_LIGNE];

     entree.getline(ligne, MAX_LIGNE);
     entree.getline(ligne, MAX_LIGNE);
     //! Une chaîne pour écrire dedans, cette chaîne servira pour nommer les pièces du labyrinthe
     std::ostringstream s;


     for (int i = 0; i < nbCols; i++)
     {
         for (int j = 0; j < nbRangs; j++)
         {
             s << i << "," << j;
             Piece p(s.str());
             s.str("");
             ajoutePieceLabyrinthe(p);
         }
     }
        cout << "tchill\n";
     for (int i = 0; i < nbCols; i++)
     {

         if (ligne[i * 4 + 1] == 'D' || ligne[i * 4 + 1] == 'd')
         {
             std::string nom;
             s << i << ",0";
             nom = s.str();
             s.str("");
             placeDepart(nom);
         }
         if (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4
             + 1] == 'A' || ligne[i * 4 + 1] == 'a')
         {
             std::string nom;
             s << i << ",0";
             nom = s.str();
             s.str("");
             placeArrivee(nom);
         }

         //printPieces();
     }


     for (int j = 0; j < nbRangs; j++)
     {
         entree.getline(ligne, MAX_LIGNE);

         for (int i = (j == nbRangs - 1 && (j & 1)) ? 1 : 0; i < nbCols; i++)
         {
             if (j & 1)
             {
                 if (j < nbRangs - 2 && ligne[i * 4 + 3] == ' ')
                 {
                     ajoutePassage(couleur, i, j, i, j + 2);
                 }
                 if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
                 {
                     ajoutePassage(couleur, i, j, i, j + 1);
                 }
                 if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
                 {
                     ajoutePassage(couleur, i - 1, j, i, j + 1);
                 }
                 if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'D' || ligne[i * 4
                     + 1] == 'd'))
                 {
                     std::string nom;
                     s << i << "," << j + 1;
                     nom = s.str();
                     s.str("");
                     placeDepart(nom);
                 }
                 if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'F' || ligne[i * 4
                     + 1] == 'f' || ligne[i * 4 + 1] == 'A' || ligne[i * 4
                     + 1] == 'a'))
                 {
                     std::string nom;
                     s << i << "," << j + 1;
                     nom = s.str();
                     s.str("");
                     placeArrivee(nom);
                 }
             }
             else
             {
                 if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
                 {
                     ajoutePassage(couleur, i - 1, j + 1, i, j);
                 }
                 if (j < nbRangs - 2 && ligne[i * 4 + 1] == ' ')
                 {
                     ajoutePassage(couleur, i, j, i, j + 2);
                 }
                 if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
                 {
                     ajoutePassage(couleur, i, j, i, j + 1);
                 }
                 if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'D' || ligne[i * 4
                     + 3] == 'd'))
                 {
                     std::string nom;
                     s << i << "," << j + 1;
                     nom = s.str();
                     s.str("");
                     placeDepart(nom);
                 }
                 if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'F' || ligne[i * 4
                     + 3] == 'f' || ligne[i * 4 + 3] == 'A' || ligne[i * 4
                     + 3] == 'a'))
                 {
                     std::string nom;
                     s << i << "," << j + 1;
                     nom = s.str();
                     s.str("");
                     placeArrivee(nom);
                 }
             }
         }
     }
    }


    /**
    * \fn Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
    * \brief Fonction déjà fournie permettant d'ajouter une porte à une pièce
    * \param[in]	Couleur couleur Couleur de la porte à ajouter
    * \param[in]	int i1
    * \param[in]	int j1
    * \param[in]	int i2
    * \param[in]	int j2
    */
    void Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
    {

     NoeudListePieces* piece1, * piece2;
     string nomPiece1, nomPiece2;
     ostringstream s;

     s << i1 << "," << j1;
     nomPiece1 = s.str();

     s.str("");

     s << i2 << "," << j2;
     nomPiece2 = s.str();

     s.str("");

     piece1 = trouvePiece(nomPiece1);
     piece2 = trouvePiece(nomPiece2);

     Porte nouvellePorte(couleur, &(piece2->piece));

     piece1->piece.ajoutePorte(nouvellePorte);
    }


    /**
    * \fn Labyrinthe::ajoutePieceLabyrinthe(Piece & p)
    * \brief Fonction déjà fournie permettant d'ajouter une pièce au labyrinthe (si elle ne s'y trouve pas déjà)
    * \param[in]	p La pièce à ajouter
    * \post	La pièce appartient au labyrinthe;
    */
    void Labyrinthe::ajoutePieceLabyrinthe(const Piece& p)
    {
     Labyrinthe::NoeudListePieces* noeud = new Labyrinthe::NoeudListePieces;
     noeud->piece = p;
     if (dernier == nullptr)
     {
         noeud->suivant = noeud;
         dernier = noeud;
     }
     else if (!appartient(p)) {
         noeud->suivant = dernier->suivant;
         dernier->suivant = noeud;
         delete noeud;
     }
    }

    int Labyrinthe::solutionner(Couleur joueur) {
        //!Reset les pieces
        auto finListe = this->dernier;
        auto noeudListe = this->dernier;
        do
        {
            noeudListe->piece.setParcourue(false);
            noeudListe = noeudListe->suivant;
        }
        while(noeudListe != finListe);

        //!explorer le labyrinthe
        std::queue<Piece *> filePieces;
        auto debutLabyrinthe = trouvePiece(depart->getNom());
        debutLabyrinthe->piece.setParcourue(true);
        debutLabyrinthe->piece.setDistanceDuDebut(0);
        filePieces.push(& debutLabyrinthe->piece);

        while(!filePieces.empty()){
            auto pieceDefile = filePieces.front();
            filePieces.pop();

            if(pieceDefile == this->arrivee){
                return pieceDefile->getDistanceDuDebut();
            }

            for (auto porte : pieceDefile->getPortes()){
                //!ajouter les pieces lier aux porte de cette piece
                if(porte.getCouleur() == joueur && !porte.getDestination()->getParcourue()){
                    porte.getDestination()->setDistanceDuDebut(pieceDefile->getDistanceDuDebut() + 1);
                    porte.getDestination()->setParcourue(true);
                    filePieces.push(porte.getDestination());
                }
            }

            //!ajouter les pieces qui ont des portes menant a la piece defile
            auto finListe = this->dernier;
            auto noeudListe = this->dernier;
            do
            {
                if(!noeudListe->piece.getParcourue()) {
                    auto portes = noeudListe->piece.getPortes();
                    auto possedePorteVersPieceDefile = false;
                    for (auto porte : pieceDefile->getPortes()) {
                        if (porte.getCouleur() == joueur && porte.getDestination() == pieceDefile) {
                            possedePorteVersPieceDefile = true;
                        }
                    }
                    if(possedePorteVersPieceDefile){
                        noeudListe->piece.setDistanceDuDebut(pieceDefile->getDistanceDuDebut() + 1);
                        noeudListe->piece.setParcourue(true);
                        filePieces.push(& noeudListe->piece);
                    }
                }
                noeudListe = noeudListe->suivant;
            }
            while(noeudListe != finListe);
        }

        return -1;
    }


    Couleur Labyrinthe::trouveGagnant(){
        std::map<Couleur, int> resultats;

        resultats.insert(std::pair<Couleur, int>(Couleur::Rouge, solutionner(Couleur::Rouge)));
        resultats.insert(std::pair<Couleur, int>(Couleur::Vert, solutionner(Couleur::Vert)));
        resultats.insert(std::pair<Couleur, int>(Couleur::Jaune, solutionner(Couleur::Jaune)));
        resultats.insert(std::pair<Couleur, int>(Couleur::Bleu, solutionner(Couleur::Bleu)));

        int highestValue = -1;
        for(auto pair: resultats) {
            if(pair.second > highestValue){
                highestValue = pair.second;
            }
        }
        if(highestValue == -1){
            return Couleur::Aucun;
        }

        if(resultats[Couleur::Rouge] == highestValue) {
            return Couleur::Rouge;
        } else if(resultats[Couleur::Vert] == highestValue) {
            return Couleur::Vert;
        } else if(resultats[Couleur::Bleu] == highestValue) {
            return Couleur::Bleu;
        } else if(resultats[Couleur::Jaune] == highestValue) {
            return Couleur::Jaune;
        }

        return Couleur::Aucun;
    }

    void Labyrinthe::placeDepart(const std::string & nom){
        auto noeudPiece = this->trouvePiece(nom);
        this->depart = &noeudPiece->piece;
    }

    void Labyrinthe::placeArrivee(const std::string & nom){
        auto noeudPiece = this->trouvePiece(nom);
        this->arrivee = &noeudPiece->piece;
    }

    bool Labyrinthe::appartient(const Piece & p) const {
        try{
            trouvePiece(p.getNom());
            return true;
        } catch(exception) {
            return false;
        }
    }

    Labyrinthe::NoeudListePieces * Labyrinthe::trouvePiece(const std::string & nom) const {
        if(nom.empty()) {
            throw invalid_argument("Labyrinthe::trouvePiece: Le nom de la pièce est vide.");
        }
        auto finListe = this->dernier;
        auto noeudListe = this->dernier->suivant;

        if(finListe->piece.getNom() == nom){
            return noeudListe;
        }

        while(noeudListe != finListe) {
            if(noeudListe->piece.getNom() == nom){
                return noeudListe;

            }
            noeudListe = noeudListe->suivant;
        }

        throw logic_error("Labyrinthe::trouvePiece: Aucune pièce trouvée pour " + nom);
    }

    void Labyrinthe::printPieces() {
        auto finListe = this->dernier;
        auto noeudListe = this->dernier->suivant;

        while(noeudListe != finListe) {
            cout<< "(" << noeudListe->piece.getNom()<<"), ";
            noeudListe = noeudListe->suivant;
        }
        cout<<"(" << finListe->piece.getNom()<<")"<< endl;
    }


}
