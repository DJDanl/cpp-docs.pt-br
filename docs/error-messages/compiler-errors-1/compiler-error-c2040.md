---
title: Erro do compilador C2040
ms.date: 11/04/2016
f1_keywords:
- C2040
helpviewer_keywords:
- C2040
ms.assetid: 74ca3592-1469-4965-ab34-a4815e2fbefe
ms.openlocfilehash: 8002d7168354b1213d01ca390a03b1baa5e35c88
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74740410"
---
# <a name="compiler-error-c2040"></a>Erro do compilador C2040

' operator ': ' identifier1 ' difere em níveis de indireção de ' identifier2 '

Uma expressão que envolve os operandos especificados tem tipos de operando incompatíveis ou tipos de operando convertidos implicitamente. Se ambos os operandos forem aritméticos ou ambos forem nonaritméticos (como matriz ou ponteiro), eles serão usados sem alteração. Se um operando for aritmético e o outro não for, o operando aritmético será convertido no tipo do operando nonaritmético.

Este exemplo gera C2040 e mostra como corrigi-lo.

```cpp
// C2040.cpp
// Compile by using: cl /c /W3 C2040.cpp
bool test() {
   char c = '3';
   return c == "3"; // C2446, C2040
   // return c == '3'; // OK
}
```
