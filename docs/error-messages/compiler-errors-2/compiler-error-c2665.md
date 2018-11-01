---
title: Erro do compilador C2665
ms.date: 11/04/2016
f1_keywords:
- C2665
helpviewer_keywords:
- C2665
ms.assetid: a7f99b61-2eae-4f2b-ba75-ea68fd1e8312
ms.openlocfilehash: 63817c4181edb942f43f41c24fb10278d14f397e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50474718"
---
# <a name="compiler-error-c2665"></a>Erro do compilador C2665

'function': nenhuma das sobrecargas Número1 pode converter Número2 de parâmetro de tipo 'type'

Um parâmetro da função sobrecarregada não pode ser convertido para o tipo solicitado.  Possíveis resoluções:

- Forneça um operador de conversão.

- Use conversão explícita.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2665.

```
// C2665.cpp
void func(short, char*){}
void func(char*, char*){}

int main() {
   func(0, 1);   // C2665
   func((short)0, (char*)1);   // OK
}
```