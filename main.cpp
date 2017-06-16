#include "Fabricas/Fabrica.h"
#include "Fabricas/FabricaComando.h"

int main()
{
  while(true)
  {
  try
   {
      FabricaComando* fabcom = FabricaComando::getInstance();
      system("clear");
      cout << "Ingrese el caso de uso deseado:  \n";
      cout << "----------------------------------\n";

      cout << "IniciarGuasapFING\n";
      cout << "CargarDatos\n";
      cout << "\n";
      cout <<"Ingrese el caso de uso deseado: ";
      string casouso;
      cin >> casouso;

      fabcom -> seleccionarCU(casouso);
      if (casouso == "IniciarSesion")
         fabcom -> seleccionarCU("Desplegar_Menu");
    }
    catch (std::invalid_argument &i)
    {
      system("clear");
      cout << i.what() << "\n\n";
      cout << "Presione TECLA+ENTER:   ";
      string hold;
      cin >> hold;
    }
  }
  return 0;
}
