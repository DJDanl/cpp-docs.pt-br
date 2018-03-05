---
title: "Nomes sem ligação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- functions [C++], parameters
- typedef names, linkage
- enumerators [C++], linkage
- names [C++], with no linkage
- function parameters [C++]
ms.assetid: 7174c500-12d2-4572-8c16-63c27c758fb1
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 13acb94022caf7ad9ddbf2fe94ad2fa95a70dc80
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="names-with-no-linkage"></a>Nomes sem ligação
Os únicos nomes que não têm vinculação são:  
  
-   Parâmetros de função.  
  
-   Nomes com escopo de bloco não declarado como `extern` ou **estático**.  
  
-   Enumeradores.  
  
-   Nomes declarados em uma instrução `typedef`. Uma exceção é quando a instrução `typedef` é usada para fornecer um nome para um tipo de classe não nomeado. Nesse caso, o nome poderá ter vinculação externa se a classe tiver vinculação externa. O exemplo a seguir mostra uma situação em que um nome de `typedef` tem vinculação externa:  
  
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
  
     O nome de `typedef`, `POINT`, se torna o nome de classe da estrutura não nomeada. Em seguida, ele é usado para declarar uma função com vinculação externa.  
  
 Como os nomes de `typedef` não têm nenhuma vinculação, suas definições podem diferir entre unidades de tradução. Como as compilações ocorrem de forma distinta, não há nenhuma maneira de o compilador detectar essas diferenças. Como resultado, os erros desse tipo só são detectados em tempo de vinculação. Considere o caso a seguir:  
  
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
  
## <a name="example"></a>Exemplo  
 As funções do C++ só podem ser definidas no escopo de arquivo ou de classe. O exemplo a seguir ilustra como definir funções e mostra uma definição de função errônea:  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Programa e ligação](../cpp/program-and-linkage-cpp.md)