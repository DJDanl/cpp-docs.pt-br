---
title: Erro do compilador C2703
description: Descreve o erro C2703 do compilador C/C++ do Microsoft.
ms.date: 08/24/2020
f1_keywords:
- C2703
helpviewer_keywords:
- C2703
ms.assetid: 384295c3-643d-47ae-a9a6-865b3036aa84
ms.openlocfilehash: 4d5b5ccad1cd15c1a107c81423e2372e14165776
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898608"
---
# <a name="compiler-error-c2703"></a>Erro do compilador C2703

> instrução inválida `__leave`

## <a name="remarks"></a>Comentários

Uma **`__leave`** instrução deve estar dentro de um **`__try`** bloco.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2703:

```cpp
// C2703.cpp
int main() {
   __leave;   // C2703
   __try {
      // try the following line instead
      __leave;
   }
   __finally {}
}
```

## <a name="see-also"></a>Confira também

[A `__leave` palavra-chave](../../cpp/try-except-statement.md#__leave)\
[`try-except` privacidade](../../cpp/try-except-statement.md)\
[`try-finally` privacidade](../../cpp/try-finally-statement.md)
