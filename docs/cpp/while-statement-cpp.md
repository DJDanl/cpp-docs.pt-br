---
title: Embora a instrução (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- while_cpp
dev_langs:
- C++
helpviewer_keywords:
- while keyword [C++]
- while keyword [C++], syntax
ms.assetid: 358dbe76-5e5e-4af5-b575-c2293c636899
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fc826b588f133abb93c9942e7907dd8b0fce9574
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942152"
---
# <a name="while-statement-c"></a>Instrução while (C++)
Executa *instrução* repetidamente até que *expressão* for avaliada como zero.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
while ( expression )  
   statement  
```  
  
## <a name="remarks"></a>Comentários  
 O teste de *expressão* ocorre antes de cada execução do loop; portanto, um **enquanto** loop é executado zero ou mais vezes. *expressão* deve ser de um tipo integral, um tipo de ponteiro, ou um tipo de classe com conversão inequívoca em integral ou tipo de ponteiro.  
  
 Um **enquanto** loop também pode terminar quando um [quebra](../cpp/break-statement-cpp.md), [goto](../cpp/goto-statement-cpp.md), ou [retornar](../cpp/return-statement-cpp.md) dentro da instrução corpo é executado. Use [continue](../cpp/continue-statement-cpp.md) para finalizar a iteração atual sem sair do **enquanto** loop. **Continue** passa para a próxima iteração do controle de **enquanto** loop.  
  
 O código a seguir usa uma **enquanto** loop à direita serão cortados sublinhados de uma cadeia de caracteres:  
  
```cpp 
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