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

No mecanismo de exceção do C++, o controle move-se da instrução throw para a primeira instrução catch que pode manipular o tipo lançado. When the catch statement is reached, all of the automatic variables that are in scope between the throw and catch statements are destroyed in a process that is known as *stack unwinding*. No desenrolamento de pilha, a execução ocorre da seguinte maneiro:

1. Control reaches the **try** statement by normal sequential execution. The guarded section in the **try** block is executed.

1. If no exception is thrown during execution of the guarded section, the **catch** clauses that follow the **try** block are not executed. Execution continues at the statement after the last **catch** clause that follows the associated **try** block.

1. If an exception is thrown during execution of the guarded section or in any routine that the guarded section calls either directly or indirectly, an exception object is created from the object that is created by the **throw** operand. (This implies that a copy constructor may be involved.) At this point, the compiler looks for a **catch** clause in a higher execution context that can handle an exception of the type that is thrown, or for a **catch** handler that can handle any type of exception. The **catch** handlers are examined in order of their appearance after the **try** block. If no appropriate handler is found, the next dynamically enclosing **try** block is examined. This process continues until the outermost enclosing **try** block is examined.

1. Se mesmo assim um manipulador correspondente não for localizado, ou se uma exceção ocorrer durante o processo de desenrolamento antes que o manipulador obtenha o controle, a função de tempo de execução predefinida `terminate` é chamada. Se uma exceção ocorrer depois que a exceção for lançada, mas antes do início do desenrolamento, `terminate` é chamada.

1. If a matching **catch** handler is found, and it catches by value, its formal parameter is initialized by copying the exception object. Se a captura for feita por referência, o parâmetro é inicializado para consultar o objeto de exceção. Depois que o parâmetro formal for inicializado, o processo de desenrolamento de pilha é iniciado. This involves the destruction of all automatic objects that were fully constructed—but not yet destructed—between the beginning of the **try** block that is associated with the **catch** handler and the throw site of the exception. A destruição ocorre na ordem inversa da construção. The **catch** handler is executed and the program resumes execution after the last handler—that is, at the first statement or construct that is not a **catch** handler. Control can only enter a **catch** handler through a thrown exception, never through a **goto** statement or a **case** label in a **switch** statement.

## <a name="stack-unwinding-example"></a>Stack unwinding example

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
