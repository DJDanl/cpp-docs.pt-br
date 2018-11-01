---
title: Compilador aviso (nível 3) C4191
ms.date: 11/04/2016
f1_keywords:
- C4191
helpviewer_keywords:
- C4191
ms.assetid: 576d3bc6-95b7-448a-af31-5d798452df09
ms.openlocfilehash: 72a485811647911207b6d048c686acdadd142b65
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50657763"
---
# <a name="compiler-warning-level-3-c4191"></a>Compilador aviso (nível 3) C4191

' operator/operation': conversão não segura de 'type of expression' em 'type required'

Várias operações que envolvem ponteiros de função são consideradas não seguras:

- Tipos de função com as convenções de chamada diferentes.

- Tipos de função com as convenções de retornados diferentes.

- Tipos de argumento ou retorno com tamanhos diferentes, tipo categorias ou classificações.

- Comprimentos de lista de argumento diferentes (em `__cdecl`, somente na conversão da lista mais longa para a lista mais curta, mesmo se for mais curto é varargs).

- Ponteiro para dados (diferente de **void**<strong>\*</strong>) tem um alias em relação a um ponteiro para função.

- Outra diferença de tipo que produziria um erro ou aviso em um `reinterpret_cast`.

Chamar essa função através do ponteiro resultante pode fazer com que seu programa falhe.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4191:

```
// C4191.cpp
// compile with: /W3 /clr
#pragma warning(default: 4191)

void __clrcall f1() { }
void __cdecl   f2() { }

typedef void (__clrcall * fnptr1)();
typedef void (__cdecl   * fnptr2)();

int main() {
   fnptr1 fp1 = static_cast<fnptr1>(&f1);
   fnptr2 fp2 = (fnptr2) &f2;

   fnptr1 fp3 = (fnptr1) &f2;   // C4191
   fnptr2 fp4 = (fnptr2) &f1;   // C4191
};
```