---
title: "Instru&#231;&#245;es goto e identificadas (C) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "goto"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "palavra-chave goto [C]"
  - "Instrução rotulada"
  - "instruções, rotulado"
ms.assetid: 3d0473dc-4b18-4fcc-9616-31a38499d7d7
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es goto e identificadas (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A instrução `goto` transfere o controle para um rótulo.  O rótulo fornecido deve residir na mesma função e pode aparecer antes de apenas uma instrução na mesma função.  
  
## Sintaxe  
 *statement*:  
 *labeled\-statement*  
  
 *jump\-statement*  
  
 *jump\-statement*:  
 **goto**  *identifier*  **;**  
  
 *labeled\-statement*:  
 *identifier*  **:**  *statement*  
  
 O rótulo de uma instrução é significante somente para uma instrução `goto`; em qualquer outro contexto, uma instrução rotulada é executada sem considerar o rótulo.  
  
 Um elemento *jump\-statement* deve residir na mesma função e pode aparecer antes de apenas uma instrução na mesma função.  O conjunto de nomes *identifier* que seguem `goto` tem seu próprio namespace para que os nomes não interfiram com outros identificadores.  Os rótulos não podem ser redeclarados.  Consulte [Namespaces](../c-language/name-spaces.md) para obter mais informações.  
  
 É um bom estilo de programação usar as instruções **break**, **continue** e `return` em vez da instrução `goto` sempre que possível.  Como a instrução **break** sair apenas de um nível do loop, `goto` pode ser necessário para sair de um loop dentro de um loop profundamente aninhado.  
  
 Este exemplo demonstra a instrução `goto`:  
  
```  
// goto.c  
#include <stdio.h>  
  
int main()  
{  
    int i, j;  
  
    for ( i = 0; i < 10; i++ )  
    {  
        printf_s( "Outer loop executing. i = %d\n", i );  
        for ( j = 0; j < 3; j++ )  
        {  
            printf_s( " Inner loop executing. j = %d\n", j );  
            if ( i == 5 )  
                goto stop;  
        }  
    }  
  
    /* This message does not print: */  
    printf_s( "Loop exited. i = %d\n", i );  
  
    stop: printf_s( "Jumped to stop. i = %d\n", i );  
}  
```  
  
 Neste exemplo, uma instrução `goto` transfere o controle para o ponto rotulado `stop` quando o valor de `i` é igual a 5.  
  
## Consulte também  
 [Instruções](../c-language/statements-c.md)