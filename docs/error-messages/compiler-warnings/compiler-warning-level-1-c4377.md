---
title: Compilador aviso (nível 1) C4377
ms.date: 11/04/2016
f1_keywords:
- C4377
helpviewer_keywords:
- C4377
ms.assetid: a1c797b8-cd5e-4a56-b430-d07932e811cf
ms.openlocfilehash: d8c89967e0dc900e098ca03d22932451f26a6a0a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50531008"
---
# <a name="compiler-warning-level-1-c4377"></a>Compilador aviso (nível 1) C4377

tipos nativos são private por padrão. -d1PrivateNativeTypes é preterido

Em versões anteriores, os tipos nativos em assemblies foram públicos por padrão e uma opção do compilador interno, não documentada, (**/d1PrivateNativeTypes**) foi usado para torná-los em particular.

Todos os tipos nativos e o CLR, agora são private por padrão em um assembly, portanto **/d1PrivateNativeTypes** não for mais necessário.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4377.

```
// C4377.cpp
// compile with: /clr /d1PrivateNativeTypes /W1
// C4377 warning expected
int main() {}
```