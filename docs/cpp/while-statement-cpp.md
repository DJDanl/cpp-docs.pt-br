---
title: "Instru&#231;&#227;o while (C++) | Microsoft Docs"
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
  - "while_cpp"
  - "while"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave while [C++]"
  - "Palavra-chave while [C++], sintaxe"
ms.assetid: 358dbe76-5e5e-4af5-b575-c2293c636899
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o while (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Executa a*instrução* repetidamente até que a *expressão* seja avaliada em zero.  
  
## Sintaxe  
  
```  
  
      while ( expression )  
   statement  
```  
  
## Comentários  
 O teste da *expressão* ocorre antes de cada execução do loop; portanto, um loop `while` executa zero ou mais vezes.  A *expressão* deve ser de um tipo integral, um tipo de ponteiro ou um tipo de classe com conversão inequívoca em um tipo integral ou de ponteiro.  
  
 O loop `while` também pode ser encerrado quando uma instrução [break](../cpp/break-statement-cpp.md), [goto](../cpp/goto-statement-cpp.md) ou [return](../Topic/return%20Statement%20\(C++\).md) é executada no corpo da instrução.  Use [continue](../cpp/continue-statement-cpp.md) para encerrar a iteração atual sem sair do loop `while`.  A instrução **continue** passa o controle para a próxima iteração do loop `while`.  
  
 O código a seguir usa um loop `while` para recortar os sublinhados à direita de uma cadeia de caracteres:  
  
```  
// while_statement.cpp  
  
#include <string.h>  
#include <stdio.h>  
char *trim( char *szSource )  
{  
    char *pszEOS = 0;  
  
    //  Set pointer to character before terminating NULL  
    pszEOS = szSource + strlen( szSource ) - 1;  
  
    //  iterate backwards until non '_' is found   
    while( (pszEOS >= szSource) && (*pszEOS == '_') )  
        *pszEOS-- = '\0';  
  
    return szSource;  
}  
int main()  
{  
    char szbuf[] = "12345_____";  
  
    printf_s("\nBefore trim: %s", szbuf);  
    printf_s("\nAfter trim: %s\n", trim(szbuf));  
}  
```  
  
 A condição de término é avaliada na parte superior do loop.  Se não houver um sublinhado à direita, o loop nunca será executado.  
  
## Consulte também  
 [Instruções de iteração](../cpp/iteration-statements-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Instrução do\-while \(C\+\+\)](../cpp/do-while-statement-cpp.md)   
 [Instrução for \(C\+\+\)](../cpp/for-statement-cpp.md)   
 [Instrução for com base em intervalo \(C\+\+\)](../Topic/Range-based%20for%20Statement%20\(C++\).md)