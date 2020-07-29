---
title: Erro do compilador C2714
ms.date: 07/22/2020
f1_keywords:
- C2714
helpviewer_keywords:
- C2714
ms.assetid: 401a5a42-660c-4bad-9d63-1a2d092bc489
ms.openlocfilehash: d3f733f065af5b3217dc19d46b46e504d39151f4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225404"
---
# <a name="compiler-error-c2714"></a>Erro do compilador C2714

> `alignof(void)`Não é permitido

Um valor inválido foi passado para um operador.

## <a name="remarks"></a>Comentários

Consulte [ `alignof` operador](../../cpp/alignof-operator.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2714.

```cpp
// C2714.cpp
int main() {
   return alignof(void);   // C2714
   return alignof(char);   // OK
}
```
