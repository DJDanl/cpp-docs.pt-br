---
title: Escopo (Visual C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- classes [C++], scope
- scope [C++]
- function prototypes [C++], scope
- class scope
- prototype scope
- functions [C++], scope
- scope, C++ names
ms.assetid: 81fecbb0-338b-4325-8332-49f33e716352
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: dcf85a2feff9aa16434f626804edefa4dbe4610e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="scope-visual-c"></a>Escopo (Visual C++)
Os nomes de C++ podem ser usados apenas em determinadas regiões de um programa. Essa área é chamada de "escopo" do nome. O escopo determina o "tempo de vida" de um nome que não denota um objeto de extensão estática. O escopo também determina a visibilidade de um nome quando os construtores e os destruidores de classe são chamados e quando as variáveis locais para o escopo são inicializadas. (Para obter mais informações, consulte [construtores](../cpp/constructors-cpp.md) e [destruidores](../cpp/destructors-cpp.md).) Há cinco tipos de escopo:  
  
-   **Escopo local** um nome declarado em um bloco é acessível somente dentro desse bloco e blocos incluídos por ele e somente depois do ponto de declaração. Os nomes de argumentos formais para uma função no escopo do bloco externo da função têm escopo local, como se tivessem sido declarados no bloco que inclui o corpo da função. Considere o fragmento de código a seguir:  
  
    ```  
    {  
        int i;  
    }  
    ```  
  
     Como a declaração de `i` está em um bloco entre chaves, `i` tem o escopo local e nunca pode ser acessado, pois nenhum código o acessa antes da chave de fechamento.  
  
-   **Escopo de função** rótulos são os únicos nomes com escopo de função. Eles podem ser usados em qualquer lugar dentro de uma função, mas não podem ser acessados fora dessa função. Os argumentos formais (argumentos especificados nas definições de função) para as funções são considerados dentro do escopo do bloco externo do corpo da função.  
  
-   **Escopo de arquivo** qualquer nome declarado fora de todos os blocos ou classes tem escopo de arquivo. Ele pode ser acessado em qualquer lugar da unidade de conversão após sua declaração. Os nomes com escopo de arquivo que não declaram objetos estáticos são chamados frequentemente de nomes globais.  
  
     Em C++, o escopo do arquivo também é conhecido como escopo do namespace.  
  
-   **Escopo de classe** nomes de membros de classe têm o escopo de classe. Funções de membro de classe podem ser acessadas usando os operadores de seleção de membro (**.** ou  **->** ) ou operadores de ponteiro para membro (**.\***  ou  **-> \*** ) em um objeto ou um ponteiro para um objeto de classe; dados de membro de classe não estático são considerados locais para o objeto de classe. Considere a seguinte declaração de classe:  
  
    ```  
    class Point  
    {  
        int x;  
        int y;  
    };  
    ```  
  
     Os membros de classe `x` e `y` são considerados como pertencentes ao escopo da classe `Point`.  
  
-   **Escopo de protótipo** nomes declarados em um protótipo de função são visíveis somente até o final do protótipo. O protótipo a seguir declara três nomes (`strDestination`, `numberOfElements` e `strSource`); esses nomes saem do escopo no final do protótipo:  
  
    ```  
    errno_t strcpy_s( char *strDestination, size_t numberOfElements, const char *strSource );  
    ```  
  
## <a name="hiding-names"></a>Ocultando nomes  
 Você pode ocultar um nome declarando-o em um bloco fechado. Na figura a seguir, `i` é redeclarado dentro do bloco interno, ocultando assim a variável associada a `i` no escopo do bloco externo.  
  
 ![Bloco &#45; ocultação de nome de escopo](../cpp/media/vc38sf1.png "vc38SF1")  
Ocultamento do nome e escopo do bloco  
  
 O resultado do programa mostrado na figura é:  
  
```  
i = 0  
i = 7  
j = 9  
i = 0  
```  
  
> [!NOTE]
>  O argumento `szWhat` é considerado como presente no escopo da função. Portanto, ele será tratado como se tivesse sido declarado no bloco externo da função.  
  
## <a name="hiding-class-names"></a>Ocultar nomes de classe  
 É possível ocultar nomes de classe declarando uma função, um objeto, uma variável ou um enumerador no mesmo escopo. No entanto, o nome da classe pode ser acessado ainda quando o prefixo a palavra-chave **classe**.  
  
```  
// hiding_class_names.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
// Declare class Account at file scope.  
class Account  
{  
public:  
    Account( double InitialBalance )  
        { balance = InitialBalance; }  
    double GetBalance()  
        { return balance; }  
private:  
    double balance;  
};  
  
double Account = 15.37;            // Hides class name Account  
  
int main()  
{  
    class Account Checking( Account ); // Qualifies Account as   
                                       //  class name  
  
    cout << "Opening account with balance of: "  
         << Checking.GetBalance() << "\n";  
}  
//Output: Opening account with balance of: 15.37  
```  
  
> [!NOTE]
>  Em qualquer lugar em que o nome de classe (`Account`) for chamado, a palavra-chave class deve ser usadas para diferenciá-lo da variável Account com escopo de arquivo. Essa regra não se aplica quando o nome de classe ocorre no lado esquerdo do operador de resolução de escopo (::). Os nomes no lado esquerdo do operador de resolução de escopo são sempre considerados nomes de classe.  
  
 O exemplo a seguir demonstra como declarar um ponteiro para um objeto do tipo `Account` usando o **classe** palavra-chave:  
  
```  
class Account *Checking = new class Account( Account );  
```  
  
 O `Account` no inicializador (entre parênteses) na instrução anterior tem escopo de arquivo; ela é do tipo **duplo**.  
  
> [!NOTE]
>  A reutilização de nomes de identificadores como mostrada neste exemplo é considerada um estilo de programação ruim.  
  
 Para obter mais informações sobre ponteiros, consulte [tipos derivados de](http://msdn.microsoft.com/en-us/aa14183c-02fe-4d81-95fe-beddb0c01c7c). Para obter informações sobre declaração e inicialização de classe de objetos, consulte [Classes, estruturas e uniões](../cpp/classes-and-structs-cpp.md). Para obter informações sobre como usar o **novo** e **excluir** liberar armazenamento de operadores, consulte [novo e excluir operadores](new-and-delete-operators.md).  
  
## <a name="hiding-names-with-file-scope"></a>Ocultar nomes com escopo de arquivo  
 Você pode ocultar nomes com escopo de arquivo declarando explicitamente o mesmo nome no escopo do bloco. No entanto, os nomes de escopo de arquivo podem ser acessados usando o operador de resolução de escopo (`::`).  
  
```  
// file_scopes.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int i = 7;   // i has file scope, outside all blocks  
using namespace std;  
  
int main( int argc, char *argv[] ) {  
   int i = 5;   // i has block scope, hides i at file scope  
   cout << "Block-scoped i has the value: " << i << "\n";  
   cout << "File-scoped i has the value: " << ::i << "\n";  
}  
```  
  
```Output  
Block-scoped i has the value: 5  
File-scoped i has the value: 7  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos básicos](../cpp/basic-concepts-cpp.md)