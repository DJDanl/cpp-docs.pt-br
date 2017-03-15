---
title: "Exce&#231;&#245;es e desenrolamento da pilha em C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
ms.assetid: a1a57eae-5fc5-4c49-824f-3ce2eb8129ed
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es e desenrolamento da pilha em C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

No mecanismo de exceção do C\+\+, o controle move\-se da instrução throw para a primeira instrução catch que pode manipular o tipo lançado.  Quando a instrução catch é atingida, todos as variáveis automáticas que estão no escopo entre o as instruções throw e catch são destruídas em um processo que é conhecido como *desenrolamento de pilha*.  No desenrolamento de pilha, a execução ocorre da seguinte maneiro:  
  
1.  O controle atinge a instrução `try` em uma execução sequencial normal.  A seção protegida no bloco `try` é executada.  
  
2.  Se nenhuma exceção for lançada durante a execução da seção protegida, as cláusulas de `catch` após o bloco `try` não serão executadas.  A execução continua na instrução depois da última cláusula de `catch` após o bloco `try` associado.  
  
3.  Se uma exceção é lançada durante a execução da seção protegida ou em qualquer rotina que a seção protegida chamar direta ou indiretamente, um objeto de exceção é criado a partir do objeto criado pelo operando `throw`. \(Isso significa que um construtor de cópia pode ser envolvido.\) Nesse momento, o compilador procurará uma cláusula de `catch` em um contexto mais alto de execução que possa controlar uma exceção do tipo que foi lançado, ou por um manipulador `catch` que possa controlar qualquer tipo de exceção.  Os manipuladores `catch` são verificados por ordem de ocorrência após o bloco `try`.  Se nenhum manipulador apropriado for localizado, o próximo bloco `try` dinamicamente delimitado será verificado.  Esse processo continua até que o bloco `try` delimitado mais externo seja verificado.  
  
4.  Se mesmo assim um manipulador correspondente não for localizado, ou se uma exceção ocorrer durante o processo de desenrolamento antes que o manipulador obtenha o controle, a função de tempo de execução predefinida `terminate` é chamada.  Se uma exceção ocorrer depois que a exceção for lançada, mas antes do início do desenrolamento, `terminate` é chamada.  
  
5.  Se um manipulador `catch` correspondente for localizado, e fizer a captura por valor, o parâmetro formal é inicializado copiando o objeto de exceção.  Se a captura for feita por referência, o parâmetro é inicializado para consultar o objeto de exceção.  Depois que o parâmetro formal for inicializado, o processo de desenrolamento de pilha é iniciado.  Isso envolve a destruição de todos os objetos automáticos que foram completamente construídos — mas ainda não destruídos — entre o início do bloco `try` associado ao manipulador `catch` e o site de lançamento da exceção.  A destruição ocorre na ordem inversa da construção.  O manipulador `catch` é executado e o programa retoma a execução depois do último manipulador — ou seja, na primeira instrução ou construção que não seja um manipulador `catch`.  O controle só pode inserir um manipulador `catch` com uma exceção lançada, nunca por meio de uma instrução `goto` ou de um rótulo `case` em uma instrução `switch`.  
  
## Exemplo de desenrolamento de pilha  
 O exemplo a seguir demonstra como a pilha é desenrolada depois que uma exceção é lançada.  A execução do thread ignora a instrução throw em `C` e passa à instrução catch em `main`, desenrolando cada função ao longo do caminho.  Observe a ordem na qual os objetos `Dummy` são criados e destruídos à medida que saem do escopo.  Observe também que nenhuma função é concluída, exceto `main`, que contém a instrução catch.  A função `A` nunca retorna da sua chamada a `B()`, e `B` nunca retorna de sua chamada a `C()`.  Se você remover o comentário da definição do ponteiro `Dummy` e a instrução delete correspondente, e executar o programa em seguida, observará que o ponteiro nunca será excluído.  Isso mostra o que pode acontecer quando as funções não fornecem uma garantia de exceção.  Para obter mais informações, consulte Instruções: Design para exceções.  Se você fizer comentários fora da instrução catch, observe o que acontece quando um programa é encerrado devido a uma exceção sem tratamento.  
  
```  
#include <string>  
#include <iostream>  
using namespace std;  
  
class MyException{};  
class Dummy  
{  
    public:  
    Dummy(string s) : MyName(s) { PrintMsg("Created Dummy:"); }  
    Dummy(const Dummy& other) : MyName(other.MyName){ PrintMsg("Copy created Dummy:"); }  
    ~Dummy(){ PrintMsg("Destroyed Dummy:"); }  
    void PrintMsg(string s) { cout << s  << MyName <<  endl; }  
    string MyName;   
    int level;  
};  
  
void C(Dummy d, int i)  
{   
    cout << "Entering FunctionC" << endl;  
    d.MyName = " C";  
    throw MyException();     
  
    cout << "Exiting FunctionC" << endl;  
}  
  
void B(Dummy d, int i)  
{  
    cout << "Entering FunctionB" << endl;  
    d.MyName = "B";  
    C(d, i + 1);     
    cout << "Exiting FunctionB" << endl;   
}  
  
void A(Dummy d, int i)  
{   
    cout << "Entering FunctionA" << endl;  
    d.MyName = " A" ;  
  //  Dummy* pd = new Dummy("new Dummy"); //Not exception safe!!!  
    B(d, i + 1);  
 //   delete pd;   
    cout << "Exiting FunctionA" << endl;     
}  
  
int main()  
{  
    cout << "Entering main" << endl;  
    try  
    {  
        Dummy d(" M");  
        A(d,1);  
    }  
    catch (MyException& e)  
    {  
        cout << "Caught an exception of type: " << typeid(e).name() << endl;  
    }  
  
    cout << "Exiting main." << endl;  
    char c;  
    cin >> c;  
}  
  
/* Output:  
    Entering main  
    Created Dummy: M  
    Copy created Dummy: M  
    Entering FunctionA  
    Copy created Dummy: A  
    Entering FunctionB  
    Copy created Dummy: B  
    Entering FunctionC  
    Destroyed Dummy: C  
    Destroyed Dummy: B  
    Destroyed Dummy: A  
    Destroyed Dummy: M  
    Caught an exception of type: class MyException  
    Exiting main.  
  
*/  
  
```