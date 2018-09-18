---
title: Exceções e desenrolamento de pilha em C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: a1a57eae-5fc5-4c49-824f-3ce2eb8129ed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6a413179ca2c44d1a66ae1702c690039383d1045
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46032198"
---
# <a name="exceptions-and-stack-unwinding-in-c"></a>Exceções e desenrolamento da pilha em C++

No mecanismo de exceção do C++, o controle move-se da instrução throw para a primeira instrução catch que pode manipular o tipo lançado. Quando a instrução catch é atingida, todas as variáveis automáticas que estão no escopo entre o throw e instruções catch são destruídas em um processo conhecido como *desenrolamento de pilha*. No desenrolamento de pilha, a execução ocorre da seguinte maneiro:

1. O controle atinge a **tente** instrução em uma execução sequencial normal. A seção protegida na **tente** bloco é executado.

1. Se nenhuma exceção for gerada durante a execução da seção protegida, o **catch** cláusulas que seguem o **tente** bloco não são executadas. A execução continuará na instrução após a última **catch** cláusula que segue associado **tente** bloco.

1. Se uma exceção for gerada durante a execução da seção protegida ou em qualquer rotina que da seção protegida chama direta ou indiretamente, um objeto de exceção é criado do objeto que é criado pela **lançar** operando. (Isso significa que um construtor de cópia pode ser envolvido.) Neste ponto, o compilador procura um **catch** cláusula em um contexto de execução mais alto que pode manipular uma exceção do tipo que é lançado, ou para um **catch** manipulador que pode lidar com qualquer tipo de exceção. O **catch** manipuladores são examinados em ordem de ocorrência após o **tente** bloco. Se nenhum manipulador apropriado for encontrado, em seguida dinamicamente circunscrição **tente** bloco é examinado. Esse processo continua até que o delimitado mais externo **tente** bloco é examinado.

1. Se mesmo assim um manipulador correspondente não for localizado, ou se uma exceção ocorrer durante o processo de desenrolamento antes que o manipulador obtenha o controle, a função de tempo de execução predefinida `terminate` é chamada. Se uma exceção ocorrer depois que a exceção for lançada, mas antes do início do desenrolamento, `terminate` é chamada.

1. Se encontrar uma correspondência **catch** manipulador for encontrado e ele captura por valor, o parâmetro formal é inicializado copiando o objeto de exceção. Se a captura for feita por referência, o parâmetro é inicializado para consultar o objeto de exceção. Depois que o parâmetro formal for inicializado, o processo de desenrolamento de pilha é iniciado. Isso envolve a destruição de todos os objetos automáticos que foram completamente construídos — mas ainda não destruídos — entre o início do **tente** bloco que está associado com o **catch** manipulador e o lança o site da exceção. A destruição ocorre na ordem inversa da construção. O **catch** manipulador é executado e o programa retoma a execução após o último manipulador — ou seja, na primeira instrução ou construção que não seja um **catch** manipulador. Controle só pode inserir uma **catch** manipulador por meio de uma exceção lançada, nunca por meio de uma **goto** instrução ou uma **caso** rotular em um **alternar** instrução.

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