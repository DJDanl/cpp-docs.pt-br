---
title: "__func__ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__func__"
  - "__func___cpp"
dev_langs: 
  - "C++"
ms.assetid: a5299b8d-f0ee-4af2-91dd-8fb165e68798
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __func__
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**\(C \+ \+ 11\)** \_\_func\_\_ o identificador predefinido é definida implicitamente como uma cadeia de caracteres que contém o nome não qualificado e acrescido da função.  \_\_func\_\_ é exigido pelo padrão C\+\+ e não é uma extensão da Microsoft.  
  
## Sintaxe  
  
```vb  
__func__  
```  
  
## Valor de Retorno  
 Matriz de char const retorna uma terminação nula de caracteres que contém o nome da função.  
  
## Exemplo  
  
```  
  
#include <string>  
#include <iostream>  
  
namespace Test  
{  
    struct Foo  
    {  
        static void DoSomething(int i, std::string s)  
        {  
           std::cout << __func__ << std::endl; // Output: DoSomething  
        }  
    };  
}  
int main()  
{  
    Test::Foo::DoSomething(42, "Hello");  
  
    return 0;  
}  
  
```  
  
## Requisitos  
 C\+\+11