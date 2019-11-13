---
title: Aviso do compilador (nível 3) C4191
ms.date: 11/04/2016
f1_keywords:
- C4191
helpviewer_keywords:
- C4191
ms.assetid: 576d3bc6-95b7-448a-af31-5d798452df09
ms.openlocfilehash: cd0d7dc57c8d3c94a52f72b536657bb3ea1c6b3a
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74051877"
---
# <a name="compiler-warning-level-3-c4191"></a>Aviso do compilador (nível 3) C4191

' operador/operação ': conversão não segura de ' tipo de expressão ' para ' tipo necessário '

Várias operações envolvendo ponteiros de função são consideradas inseguras:

- Tipos de função com diferentes convenções de chamada.

- Tipos de função com diferentes convenções de retorno.

- Argumentos ou tipos de retorno com tamanhos diferentes, categorias de tipo ou classificações.

- Comprimentos de lista de argumentos diferentes (em `__cdecl`, somente na conversão de uma lista mais longa para uma lista mais curta, mesmo se mais curto for varargs).

- Ponteiro para dados (diferente de **void** <strong>\*</strong>) com alias em relação a um ponteiro para funcionar.

- Qualquer outra diferença de tipo que produza um erro ou um aviso em um `reinterpret_cast`.

Chamar essa função por meio do ponteiro de resultado pode fazer com que o programa falhe.

Esse aviso está desativado por padrão. Consulte [os avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.

O exemplo a seguir gera C4191:

```cpp
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