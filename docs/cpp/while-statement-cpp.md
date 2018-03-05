---
title: "Embora a instrução (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- while_cpp
dev_langs:
- C++
helpviewer_keywords:
- while keyword [C++]
- while keyword [C++], syntax
ms.assetid: 358dbe76-5e5e-4af5-b575-c2293c636899
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e93d31457beb3c1546b55d303fd71566176a9367
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="while-statement-c"></a>Instrução while (C++)
Executa *instrução* repetidamente até *expressão* for avaliada como zero.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      while ( expression )  
   statement  
```  
  
## <a name="remarks"></a>Comentários  
 O teste de *expressão* ocorra antes de cada execução do loop; portanto, um `while` zero ou mais vezes o loop é executado. *expressão* deve ser de um tipo integral, um tipo de ponteiro ou um tipo de classe com uma conversão não ambígua para integral ou tipo de ponteiro.  
  
 Um `while` loop também pode encerrar quando um [quebra](../cpp/break-statement-cpp.md), [goto](../cpp/goto-statement-cpp.md), ou [retornar](../cpp/return-statement-cpp.md) na declaração de corpo é executado. Use [continuar](../cpp/continue-statement-cpp.md) para finalizar a iteração atual sem sair do `while` loop. **continuar** passa o controle para a próxima iteração do `while` loop.  
  
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
  
 A condição de término é avaliada na parte superior do loop. Se não houver um sublinhado à direita, o loop nunca será executado.  
  
## <a name="see-also"></a>Consulte também  
 [Instruções de Iteração](../cpp/iteration-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)   
 [Instrução for (C++)](../cpp/for-statement-cpp.md)   
 [Instrução for baseada intervalo (C++)](../cpp/range-based-for-statement-cpp.md)