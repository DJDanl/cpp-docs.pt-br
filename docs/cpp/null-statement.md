---
title: Instrução de NULL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- expressions [C++], null
- null statement
- null values, expressions
ms.assetid: 606f5953-55f0-40c8-ae03-3ee3a819b851
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ab391bb75dd6e7a2ef1ccf0951fa93770e6cd316
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39408771"
---
# <a name="null-statement"></a>Instrução nula
A "instrução nula" é uma instrução de expressão com o *expressão* ausente. É útil quando a sintaxe da linguagem pede por uma instrução, mas nenhuma avaliação de expressão. Consiste em um ponto e vírgula.  
  
 Em geral, as instruções nulas são usadas como espaços reservados em instruções de iteração ou como instruções nas quais são colocados rótulos no final de instruções ou funções compostas.  
  
 O seguinte fragmento de código mostra como copiar uma cadeia de caracteres para outra e incorpora a instrução nula:  
  
```cpp 
// null_statement.cpp  
char *myStrCpy( char *Dest, const char *Source )  
{  
    char *DestStart = Dest;  
  
    // Assign value pointed to by Source to  
    // Dest until the end-of-string 0 is  
    // encountered.  
    while( *Dest++ = *Source++ )  
        ;   // Null statement.  
  
    return DestStart;  
}  
  
int main()  
{  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Instrução de expressão](../cpp/expression-statement.md)