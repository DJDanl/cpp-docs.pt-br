---
title: Erro do compilador C2422 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2422
dev_langs:
- C++
helpviewer_keywords:
- C2422
ms.assetid: ef0ec302-4028-4778-b134-0b8cea4bcad9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 17421f2d4a7823c0e2fbb34a54a7c562223c798c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46047025"
---
# <a name="compiler-error-c2422"></a>Erro do compilador C2422

substituição de segmento inválido em 'operando'

Código de assembly embutido incorretamente usa um operador de substituição de segmento (dois-pontos) em um operando.  Possíveis causas incluem:

- O registro anterior o operador não é um registro de segmento.

- O registro anterior o operador não é o registro de segmento único no operando.

- O operador de substituição de segmento aparece dentro de um operador de indireção (colchetes).

- A expressão que segue o operador de substituição de segmento não é um operando imediato ou um operando de memória.

O exemplo a seguir gera C2422:

```
// C2422.cpp
// processor: x86
int main() {
   _asm {
      mov AX, [BX:ES]   // C2422
      mov AX, ES   // OK
   }
}
```