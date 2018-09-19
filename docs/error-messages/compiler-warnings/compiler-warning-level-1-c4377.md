---
title: Compilador aviso (nível 1) C4377 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4377
dev_langs:
- C++
helpviewer_keywords:
- C4377
ms.assetid: a1c797b8-cd5e-4a56-b430-d07932e811cf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 613ebe183b61c6b9894ed3b726f90061e2b24ef6
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46047168"
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