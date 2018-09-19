---
title: Erro do compilador C2040 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2040
dev_langs:
- C++
helpviewer_keywords:
- C2040
ms.assetid: 74ca3592-1469-4965-ab34-a4815e2fbefe
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ccfbacff97550e20c0dd0202e0737585ffd39d6d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46016462"
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