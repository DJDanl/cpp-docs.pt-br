---
title: Erro do compilador C2714
ms.date: 11/04/2016
f1_keywords:
- C2714
helpviewer_keywords:
- C2714
ms.assetid: 401a5a42-660c-4bad-9d63-1a2d092bc489
ms.openlocfilehash: b5bfa56ca95cc93680c7eab227d658134b248976
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74760550"
---
# <a name="compiler-error-c2714"></a>Erro do compilador C2714

__alignof (void) não é permitido

Um valor inválido foi passado para um operador.

Consulte [operador de __alignof](../../cpp/alignof-operator.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2714.

```cpp
// C2714.cpp
int main() {
   return __alignof(void);   // C2714
   return __alignof(char);   // OK
}
```
