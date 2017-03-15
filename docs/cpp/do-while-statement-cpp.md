---
title: "Instru&#231;&#227;o do-while (C++) | Microsoft Docs"
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
  - "do-while_cpp"
  - "do-while"
  - "do"
  - "while_cpp"
  - "do_cpp"
  - "while"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave do [C++]"
  - "Palavra-chave do [C++], do-while"
  - "Palavra-chave do-while [C++]"
  - "Palavra-chave while [C++], do-while"
ms.assetid: e01e6f7c-7da1-4591-87f9-c26ff848e7b0
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o do-while (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Executa uma *instrução* repetidamente até que a condição de término especificada \(a *expressão*\) seja avaliada como zero.  
  
## Sintaxe  
  
```  
  
      do  
   statement  
   while ( expression ) ;  
```  
  
## Comentários  
 O teste da condição de término é realizado após cada execução do loop; portanto, um loop `do-while` é executado uma ou mais vezes, dependendo do valor da expressão de término.  A instrução `do-while` também pode terminar quando uma instrução [break](../cpp/break-statement-cpp.md), [goto](../cpp/goto-statement-cpp.md) ou [return](../Topic/return%20Statement%20\(C++\).md) for executada no corpo da instrução.  
  
 A *expressão* deve ter o tipo aritmético ou ponteiro.  A execução procede da seguinte maneira:  
  
1.  O corpo da instrução é executado.  
  
2.  Em seguida, a *expressão* é avaliada.  Se a *expressão* for falsa, a instrução `do-while` é finalizada e o controle é passado para a próxima instrução no programa.  Se a *expressão* for verdadeira \(diferente de zero\), o processo é repetido, começando da etapa 1.  
  
## Exemplo  
 O exemplo a seguir demonstra a instrução `do-while`:  
  
```  
// do_while_statement.cpp  
#include <stdio.h>  
int main()  
{  
    int i = 0;  
    do  
    {  
        printf_s("\n%d",i++);  
    } while (i < 3);  
}  
```  
  
## Consulte também  
 [Instruções de iteração](../cpp/iteration-statements-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Instrução while \(C\+\+\)](../cpp/while-statement-cpp.md)   
 [Instrução for \(C\+\+\)](../cpp/for-statement-cpp.md)   
 [Instrução for com base em intervalo \(C\+\+\)](../Topic/Range-based%20for%20Statement%20\(C++\).md)