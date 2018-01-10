---
title: "Instruções goto e identificadas (C) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: goto
dev_langs: C++
helpviewer_keywords:
- labeled statement
- statements, labeled
- goto keyword [C]
ms.assetid: 3d0473dc-4b18-4fcc-9616-31a38499d7d7
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ea0543a13d16850be4259d2d93f763dd0edcbda3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="goto-and-labeled-statements-c"></a>Instruções goto e identificadas (C)
A instrução `goto` transfere o controle para um rótulo. O rótulo fornecido deve residir na mesma função e pode aparecer antes de apenas uma instrução na mesma função.  
  
## <a name="syntax"></a>Sintaxe  
 *statement*:  
 *labeled-statement*  
  
 *jump-statement*  
  
 *jump-statement*:  
 **goto**  *identifier*  **;**  
  
 *labeled-statement*:  
 *identifier*  **:**  *statement*  
  
 O rótulo de uma instrução é significante somente para uma instrução `goto`; em qualquer outro contexto, uma instrução rotulada é executada sem considerar o rótulo.  
  
 Um elemento *jump-statement* deve residir na mesma função e pode aparecer antes de apenas uma instrução na mesma função. O conjunto de nomes *identifier* que segue `goto` tem seu próprio namespace para que os nomes não interfiram com outros identificadores. Os rótulos não podem ser redeclarados. Consulte [Namespaces](../c-language/name-spaces.md) para obter mais informações.  
  
 É um bom estilo de programação para usar as instruções **break**, **continue** e `return` em vez de `goto` sempre que possível. Como a instrução **break** sai apenas de um nível do loop, um `goto` pode ser necessário para sair de um loop dentro de um loop profundamente aninhado.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Instruções](../c-language/statements-c.md)