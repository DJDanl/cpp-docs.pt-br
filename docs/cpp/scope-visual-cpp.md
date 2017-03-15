---
title: "Escopo (Visual C++) | Microsoft Docs"
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
helpviewer_keywords: 
  - "escopo de classe"
  - "classes [C++], escopo"
  - "protótipos de função, escopo"
  - "funções [C++], escopo"
  - "escopo de protótipo"
  - "escopo"
  - "escopo, nomes C++"
ms.assetid: 81fecbb0-338b-4325-8332-49f33e716352
caps.latest.revision: 13
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Escopo (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os nomes de C\+\+ podem ser usados apenas em determinadas regiões de um programa.  Essa área é chamada de "escopo" do nome.  O escopo determina o "tempo de vida" de um nome que não denota um objeto de extensão estática.  O escopo também determina a visibilidade de um nome quando os construtores e os destruidores de classe são chamados e quando as variáveis locais para o escopo são inicializadas.  \(Para obter mais informações, consulte [Construtores](../cpp/constructors-cpp.md) e [Destruidores](../cpp/destructors-cpp.md).\) Há cinco tipos de escopo:  
  
-   **Escopo local** Um nome declarado em um bloco é acessível somente dentro desse bloco e de blocos incluídos nele e apenas após o ponto da declaração.  Os nomes de argumentos formais para uma função no escopo do bloco externo da função têm escopo local, como se tivessem sido declarados no bloco que inclui o corpo da função.  Considere o fragmento de código a seguir:  
  
    ```  
    {  
        int i;  
    }  
    ```  
  
     Como a declaração de `i` está em um bloco entre chaves, `i` tem o escopo local e nunca pode ser acessado, pois nenhum código o acessa antes da chave de fechamento.  
  
-   **Escopo da função** Os rótulos são os únicos nomes que têm o escopo da função.  Eles podem ser usados em qualquer lugar dentro de uma função, mas não podem ser acessados fora dessa função.  Os argumentos formais \(argumentos especificados nas definições de função\) para as funções são considerados dentro do escopo do bloco externo do corpo da função.  
  
-   **Escopo do arquivo** Qualquer nome declarado fora de todos os blocos ou de todas as classes têm o escopo do arquivo.  Ele pode ser acessado em qualquer lugar da unidade de conversão após sua declaração.  Os nomes com escopo de arquivo que não declaram objetos estáticos são chamados frequentemente de nomes globais.  
  
     Em C\+\+, o escopo do arquivo também é conhecido como escopo do namespace.  
  
-   **Escopo da classe** Nomes de membros de classe têm o escopo da classe.  As funções de membro de classe podem ser acessadas somente usando os operadores de seleção de membros \(**.** ou **–\>**\) ou operadores de ponteiro a membro \(**.\*** ou **–\>\***\) em um objeto ou ponteiro para um objeto dessa classe. Os dados de membros de classe não estáticos são considerados locais para o objeto dessa classe.  Considere a seguinte declaração de classe:  
  
    ```  
    class Point  
    {  
        int x;  
        int y;  
    };  
    ```  
  
     Os membros de classe `x` e `y` são considerados como pertencentes ao escopo da classe `Point`.  
  
-   **Escopo do protótipo** Nomes declarados em um protótipo de função são visíveis somente até o final do protótipo.  O protótipo a seguir declara três nomes \(`strDestination`, `numberOfElements` e `strSource`\); esses nomes saem do escopo no final do protótipo:  
  
    ```  
    errno_t strcpy_s( char *strDestination, size_t numberOfElements, const char *strSource );  
    ```  
  
## Ocultando nomes  
 Você pode ocultar um nome declarando\-o em um bloco fechado.  Na figura a seguir, `i` é redeclarado dentro do bloco interno, ocultando assim a variável associada a `i` no escopo do bloco externo.  
  
 ![Escopo de bloco ocultar nomes](../cpp/media/vc38sf1.png "vc38SF1")  
Ocultamento do nome e escopo do bloco  
  
 O resultado do programa mostrado na figura é:  
  
```  
i = 0  
i = 7  
j = 9  
i = 0  
```  
  
> [!NOTE]
>  O argumento `szWhat` é considerado como presente no escopo da função.  Portanto, ele será tratado como se tivesse sido declarado no bloco externo da função.  
  
## Ocultando nomes de classe  
 É possível ocultar nomes de classe declarando uma função, um objeto, uma variável ou um enumerador no mesmo escopo.  No entanto, o nome de classe ainda poderá ser acessado quando precedido pela palavra\-chave **class**.  
  
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
>  Em qualquer lugar em que o nome de classe \(`Account`\) for chamado, a palavra\-chave class deve ser usadas para diferenciá\-lo da variável Account com escopo de arquivo.  Essa regra não se aplica quando o nome de classe ocorre no lado esquerdo do operador de resolução de escopo \(::\).  Os nomes no lado esquerdo do operador de resolução de escopo são sempre considerados nomes de classe.  
  
 O exemplo a seguir demonstra como declarar um ponteiro para um objeto do tipo `Account` usando a palavra\-chave **class**:  
  
```  
class Account *Checking = new class Account( Account );  
```  
  
 O `Account` no inicializador \(entre parênteses\) na instrução anterior tem escopo de arquivo; é do tipo **double**.  
  
> [!NOTE]
>  A reutilização de nomes de identificadores como mostrada neste exemplo é considerada um estilo de programação ruim.  
  
 Para obter mais informações sobre ponteiros, consulte [Tipos derivados](http://msdn.microsoft.com/pt-br/aa14183c-02fe-4d81-95fe-beddb0c01c7c).  Para obter informações sobre declaração e inicialização de objetos de classe, consulte [Classes, estruturas e uniões](../Topic/Classes%20and%20Structs%20\(C++\).md).  Para obter informações sobre como usar os operadores de armazenamento livre **new** e **delete** livre, consulte o tópico sobre [Funções membro especiais](../misc/special-member-functions-cpp.md).  
  
## Ocultando nomes com escopo de arquivo  
 Você pode ocultar nomes com escopo de arquivo declarando explicitamente o mesmo nome no escopo do bloco.  No entanto, os nomes de escopo de arquivo podem ser acessados usando o operador de resolução de escopo \(`::`\).  
  
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
  
  **i com escopo de bloco tem o valor: 5**  
**i com escopo de arquivo tem o valor: 7**   
## Consulte também  
 [Conceitos básicos](../cpp/basic-concepts-cpp.md)