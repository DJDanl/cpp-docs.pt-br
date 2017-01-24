---
title: "Nomes sem liga&#231;&#227;o | Microsoft Docs"
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
  - "enumeradores [C++], vinculação"
  - "parâmetros de função [C++]"
  - "funções [C++], parâmetros"
  - "nomes [C++], sem vinculação"
  - "nomes typedef, vinculação"
ms.assetid: 7174c500-12d2-4572-8c16-63c27c758fb1
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Nomes sem liga&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os únicos nomes que não têm vinculação são:  
  
-   Parâmetros de função.  
  
-   Nomes com escopo de bloco não declarados como `extern` ou **static**.  
  
-   Enumeradores.  
  
-   Nomes declarados em uma instrução `typedef`.  Uma exceção é quando a instrução `typedef` é usada para fornecer um nome para um tipo de classe não nomeado.  Nesse caso, o nome poderá ter vinculação externa se a classe tiver vinculação externa.  O exemplo a seguir mostra uma situação em que um nome de `typedef` tem vinculação externa:  
  
    ```  
    // names_with_no_linkage.cpp  
    typedef struct  
    {  
       short x;  
       short y;  
    } POINT;  
  
    extern int MoveTo( POINT pt );  
  
    int main()  
    {  
    }  
    ```  
  
     O nome de `typedef`, `POINT`, se torna o nome de classe da estrutura não nomeada.  Em seguida, ele é usado para declarar uma função com vinculação externa.  
  
 Como os nomes de `typedef` não têm nenhuma vinculação, suas definições podem diferir entre unidades de tradução.  Como as compilações ocorrem de forma distinta, não há nenhuma maneira de o compilador detectar essas diferenças.  Como resultado, os erros desse tipo só são detectados em tempo de vinculação.  Considere o caso a seguir:  
  
```  
// Translation unit 1  
typedef int INT  
  
INT myInt;  
...  
  
// Translation unit 2  
typedef short INT  
  
extern INT myInt;  
...  
```  
  
 O código acima gera um erro "externo não resolvido" em tempo de vinculação.  
  
## Exemplo  
 As funções do C\+\+ só podem ser definidas no escopo de arquivo ou de classe.  O exemplo a seguir ilustra como definir funções e mostra uma definição de função errônea:  
  
```  
// function_definitions.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
void ShowChar( char ch );    // Declare function ShowChar.  
  
void ShowChar( char ch )     // Define function ShowChar.  
{                            // Function has file scope.  
   cout << ch;  
}  
  
struct Char                  // Define class Char.  
{  
    char Show();             // Declare Show function.  
    char Get();              // Declare Get function.  
    char ch;  
};  
  
char Char::Show()            // Define Show function  
{                            //  with class scope.  
    cout << ch;  
    return ch;  
}  
  
void GoodFuncDef( char ch )  // Define GoodFuncDef  
{                            //  with file scope.  
    int BadFuncDef( int i )  // C2601, Erroneous attempt to  
    {                        //  nest functions.  
        return i * 7;  
    }  
    for( int i = 0; i < BadFuncDef( 2 ); ++i )  
        cout << ch;  
    cout << "\n";  
}  
```  
  
## Consulte também  
 [Programa e ligação](../cpp/program-and-linkage-cpp.md)