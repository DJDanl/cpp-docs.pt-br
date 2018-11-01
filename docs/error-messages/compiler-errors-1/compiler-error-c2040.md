---
title: Erro do compilador C2040
ms.date: 11/04/2016
f1_keywords:
- C2040
helpviewer_keywords:
- C2040
ms.assetid: 74ca3592-1469-4965-ab34-a4815e2fbefe
ms.openlocfilehash: b45ec25f1ed516ae73b242fdcc7c66f68c92f724
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50624712"
---
# <a name="compiler-error-c2040"></a>Erro do compilador C2040

'operator': 'identifier1' difere em níveis de indireção de 'identifier2'

Uma expressão que envolva os operandos especificados tem tipos de operando incompatível ou implicitamente convertidos em tipos de operando. Se ambos os operandos forem aritméticos, ou ambos são nonarithmetic (por exemplo, matriz ou ponteiro), eles são usados sem alterações. Se um operando for aritmético, e o outro não é, o operando aritmético é convertido para o tipo do operando nonarithmetic.

Este exemplo gera C2040 e mostra como corrigi-lo.

```
// C2040.cpp
// Compile by using: cl /c /W3 C2040.cpp
bool test() {
   char c = '3';
   return c == "3"; // C2446, C2040
   // return c == '3'; // OK
}
```