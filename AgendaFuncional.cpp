
#include <iostream>
#include <string.h>

//Clases Contacto y Agenda

const bool isDeleted=false;
class Contacto{

    public:

    char name[50];
    unsigned int numero;
    char mail[50];

    // Constructor y Destructor de Clase

      Contacto (void){
        std::cout<< "Constructor de Contacto"<<std::endl;
      }
      virtual ~Contacto (void){
        std::cout<< "Destructor de Contacto"<<std::endl;
      }

    // Funciones de Contacto
        menu(Contacto* contacto);
        addContacto(Contacto* contacto);
        deleteContacto(Contacto* contacto);


    private:
      Contacto(const Contacto&);
      Contacto& operator = (const Contacto&);

};


class Agenda{

    public:
    // Constructor y Destructor de Clase
      Agenda (void){
        std::cout<< "Constructor de Agenda"<<std::endl;
      }
      virtual ~Agenda (void){
        std::cout<< "Destructor de Agenda"<<std::endl;
      }
    //Funciones Principales

    menu(Contacto* contacto);
    showContacto(Contacto *contacto);
    private:
      Agenda(const Agenda&);
      Agenda& operator = (const Agenda&);

};

Agenda :: menu(Contacto* contacto){

        int opcion;
        std::cout <<"**********************************"<<std::endl;
        std::cout <<"**       Que desea hacer?       **"<<std::endl;
        std::cout <<"**********************************"<<std::endl;
        std::cout <<"\n\n";
        std::cout <<"*********************************"<<std::endl;
        std::cout <<"**  1- Crear Nuevo Contacto    **"<<std::endl;
        std::cout <<"*********************************"<<std::endl;
        std::cout <<"**  2- Mostrar un Contacto      **"<<std::endl;
        std::cout <<"*********************************"<<std::endl;
        std::cout <<"*********************************"<<std::endl;
        std::cout <<"**  3- Eliminar Contacto       **"<<std::endl;
        std::cout <<"*********************************"<<std::endl;
        std::cin  >>opcion;
        std::cout <<"\n\n";
        std::cin.ignore();

        switch (opcion){
            case 1:

                contacto->addContacto(contacto);

            break;

            case 2:

                showContacto(contacto);

            break;

            case 3:

                contacto->deleteContacto(contacto);

            break;

            default:
            std::cout << "La opcion ingresada no es correcta."<< std::endl;
        }
}
Agenda :: showContacto(Contacto* contacto){

        std::cout <<"=========================================="<<std::endl;
        std::cout<< "      Los Datos de su Contacto son:       "<<std::endl;
        std::cout <<"=========================================="<<std::endl;
        std::cout <<"=========================================="<<std::endl;
        std::cout<< "         "<< contacto->name <<"           "<<std::endl;
        std::cout <<"=========================================="<<std::endl;
        std::cout <<"\n\n";
        std::cout <<"=========================================="<<std::endl;
        std::cout<< "         "<< contacto->numero <<"         "<<std::endl;
        std::cout <<"=========================================="<<std::endl;
        std::cout <<"\n\n";
        std::cout <<"=========================================="<<std::endl;
        std::cout<< "         "<< contacto->mail <<"           "<<std::endl;
        std::cout <<"=========================================="<<std::endl;



    }
Contacto :: addContacto(Contacto* contacto){

            std::cout <<"******************************************"<<std::endl;
            std::cout <<"**     Ingrese Nombre del Contacto:     **"<<std::endl;
            std::cout <<"******************************************"<<std::endl;
            std::cin.getline(contacto->name,50);
            std::cin.ignore();
            std::cout <<"******************************************"<<std::endl;
            std::cout <<"**     Ingrese Numero del Contacto:     **"<<std::endl;
            std::cout <<"******************************************"<<std::endl;
            std::cin  >> contacto->numero;
            std::cin.ignore();
            std::cout <<"******************************************"<<std::endl;
            std::cout <<"**     Ingrese Mail del Contacto:       **"<<std::endl;
            std::cout <<"******************************************"<<std::endl;
            std::cin.getline(contacto->mail,50);
            std::cout <<"\n\n\n\n";
    }
Contacto :: deleteContacto(Contacto* contacto){

            int opcion;
            std::cout <<"*****************************************************"<<std::endl;
            std::cout <<"**   Esta seguro que desea eliminar el Contacto?   **"<<std::endl;
            std::cout <<"*****************************************************"<<std::endl;
            std::cout <<"\n\n";
            std::cout <<"*********************************"<<std::endl;
            std::cout <<"**  1- Eliminar Contacto       **"<<std::endl;
            std::cout <<"*********************************"<<std::endl;
            std::cout <<"**  2- Volver al Menu          **"<<std::endl;
            std::cout <<"*********************************"<<std::endl;

            switch (opcion){

            case 1:

                if(isDeleted==false){

                    delete contacto;
            std::cout <<"****************************************"<<std::endl;
            std::cout <<"**   El Contacto ha sido eliminado.   **"<<std::endl;
            std::cout <<"****************************************"<<std::endl;
                    return true;
                }else{

            std::cout <<"********************************"<<std::endl;
            std::cout <<"**   Ese Contacto no existe   **"<<std::endl;
            std::cout <<"********************************"<<std::endl;
                }
            break;

            case 2:
            std::cout <<"*****************************************"<<std::endl;
            std::cout <<"**   No se ha implementado la opcion   **"<<std::endl;
            std::cout <<"*****************************************"<<std::endl;

               //menu(contacto);
            break;

            default:
            std::cout <<"*********************************************"<<std::endl;
            std::cout <<"**   La opcion ingresada no es correcta.   **"<<std::endl;
            std::cout <<"*********************************************"<<std::endl;


            }
   }

void menuLoop(Contacto* contacto, Agenda* agenda){

char Continue = 'y';

    do {
    agenda->menu(contacto);

    std::cout << "Desea Volver al Menu?" <<std::endl;
    std::cout << "Y or N" << std::endl;
    std::cin  >> Continue;
    std::cout <<"\n\n";

    }while (Continue=='y');

    if(isDeleted==false){

       delete contacto;
    }
    delete agenda;


}


int main(){

    Contacto* contacto = new Contacto();
    Agenda* agenda = new Agenda();

    menuLoop(contacto,agenda);

    std::cin.get();
    return 0;
}


