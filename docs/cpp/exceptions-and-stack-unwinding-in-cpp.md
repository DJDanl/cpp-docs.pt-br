---
title: Exceções e desenrolamento da pilha em C++
ms.date: 11/19/2019
ms.assetid: a1a57eae-5fc5-4c49-824f-3ce2eb8129ed
ms.openlocfilehash: 11657206e86dbc81eb62c1e11b49fd87777f11d8
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74246561"
---
# <a name="exceptions-and-stack-unwinding-in-c"></a>Exceções e desenrolamento da pilha em C++

No mecanismo de exceção do C++, o controle move-se da instrução throw para a primeira instrução catch que pode manipular o tipo lançado. Quando a instrução Catch é atingida, todas as variáveis automáticas que estão no escopo entre as instruções throw e catch são destruídas em um processo conhecido como *desenrolamento de pilha*. No desenrolamento de pilha, a execução ocorre da seguinte maneiro:

1. O controle alcança a instrução **try** por execução sequencial normal. A seção protegida no bloco **try** é executada.

1. Se nenhuma exceção for gerada durante a execução da seção protegida, as cláusulas **Catch** que seguem o bloco **try** não serão executadas. A execução continua na instrução após a última cláusula **Catch** que segue o bloco **try** associado.

1. Se uma exceção for lançada durante a execução da seção protegida ou em qualquer rotina que a seção protegida chama de forma direta ou indireta, um objeto de exceção é criado a partir do objeto criado pelo operando de **throw** . (Isso implica que um construtor de cópia pode estar envolvido.) Neste ponto, o compilador procura uma cláusula **Catch** em um contexto de execução mais alto que pode manipular uma exceção do tipo que é lançado ou para um manipulador **Catch** que pode manipular qualquer tipo de exceção. Os manipuladores **Catch** são examinados em ordem de sua aparência após o bloco **try** . Se nenhum manipulador apropriado for encontrado, o próximo bloco **try** de fechamento dinâmico será examinado. Esse processo continua até que o bloco **try** de circunscrição mais externo seja examinado.

1. Se mesmo assim um manipulador correspondente não for localizado, ou se uma exceção ocorrer durante o processo de desenrolamento antes que o manipulador obtenha o controle, a função de tempo de execução predefinida `terminate` é chamada. Se uma exceção ocorrer depois que a exceção for lançada, mas antes do início do desenrolamento, `terminate` é chamada.

1. Se um manipulador de **Catch** correspondente for encontrado e ele for detectado por valor, seu parâmetro formal será inicializado copiando o objeto de exceção. Se a captura for feita por referência, o parâmetro é inicializado para consultar o objeto de exceção. Depois que o parâmetro formal for inicializado, o processo de desenrolamento de pilha é iniciado. Isso envolve a destruição de todos os objetos automáticos que foram totalmente construídos, mas que ainda não foram destruídos, entre o início do bloco **try** associado ao manipulador **Catch** e ao site de lançamento da exceção. A destruição ocorre na ordem inversa da construção. O manipulador **Catch** é executado e o programa retoma a execução após o último manipulador — ou seja, na primeira instrução ou construção que não é um manipulador **Catch** . O controle só pode inserir um manipulador **Catch** por meio de uma exceção gerada, nunca por meio de uma instrução **goto** ou um rótulo **Case** em uma instrução **switch** .

## <a name="stack-unwinding-example"></a>Exemplo de desenrolamento de pilha

O exemplo a seguir demonstra como a pilha é desenrolada depois que uma exceção é lançada. A execução do thread ignora a instrução throw em `C` e passa à instrução catch em `main`, desenrolando cada função ao longo do caminho. Observe a ordem na qual os objetos `Dummy` são criados e destruídos à medida que saem do escopo. Observe também que nenhuma função é concluída, exceto `main`, que contém a instrução catch. A função `A` nunca retorna da sua chamada a `B()`, e `B` nunca retorna de sua chamada a `C()`. Se você remover o comentário da definição do ponteiro `Dummy` e a instrução delete correspondente, e executar o programa em seguida, observará que o ponteiro nunca será excluído. Isso mostra o que pode acontecer quando as funções não fornecem uma garantia de exceção. Para obter mais informações, consulte Instruções: Design para exceções. Se você fizer comentários fora da instrução catch, observe o que acontece quando um programa é encerrado devido a uma exceção sem tratamento.

```cpp
#include <string>
#include <iostream>
using namespace std;

class MyException{};
class Dummy
{
    public:
    Dummy(string s) : MyName(s) { PrintMsg("Created Dummy:"); }
    Dummy(const Dummy& other) : MyName(other.MyName){ PrintMsg("Copy created Dummy:"); }
    ~Dummy(){ PrintMsg("Destroyed Dummy:"); }
    void PrintMsg(string s) { cout << s  << MyName <<  endl; }
    string MyName;
    int level;
};

void C(Dummy d, int i)
{
    cout << "Entering FunctionC" << endl;
    d.MyName = " C";
    throw MyException();

    cout << "Exiting FunctionC" << endl;
}

void B(Dummy d, int i)
{
    cout << "Entering FunctionB" << endl;
    d.MyName = "B";
    C(d, i + 1);
    cout << "Exiting FunctionB" << endl;
}

void A(Dummy d, int i)
{
    cout << "Entering FunctionA" << endl;
    d.MyName = " A" ;
  //  Dummy* pd = new Dummy("new Dummy"); //Not exception safe!!!
    B(d, i + 1);
 //   delete pd;
    cout << "Exiting FunctionA" << endl;
}

int main()
{
    cout << "Entering main" << endl;
    try
    {
        Dummy d(" M");
        A(d,1);
    }
    catch (MyException& e)
    {
        cout << "Caught an exception of type: " << typeid(e).name() << endl;
    }

    cout << "Exiting main." << endl;
    char c;
    cin >> c;
}

/* Output:
    Entering main
    Created Dummy: M
    Copy created Dummy: M
    Entering FunctionA
    Copy created Dummy: A
    Entering FunctionB
    Copy created Dummy: B
    Entering FunctionC
    Destroyed Dummy: C
    Destroyed Dummy: B
    Destroyed Dummy: A
    Destroyed Dummy: M
    Caught an exception of type: class MyException
    Exiting main.

*/
```
