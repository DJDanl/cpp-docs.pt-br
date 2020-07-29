---
title: Erro do compilador C3491
ms.date: 11/04/2016
f1_keywords:
- C3491
helpviewer_keywords:
- C3491
ms.assetid: 7f0e71b2-46a0-4d25-bd09-6158a280f509
ms.openlocfilehash: f6f20d9af424fdd4254fc15e0580d62b9dfba144
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87184469"
---
# <a name="compiler-error-c3491"></a>Erro do compilador C3491

' var ': uma captura por valor não pode ser modificada em um lambda não mutável

Uma expressão lambda não mutável não pode modificar o valor de uma variável que é capturada por valor.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Declare sua expressão lambda com a **`mutable`** palavra-chave ou

- Passe a variável por referência à lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3491 porque o corpo de uma expressão lambda não mutável modifica a variável de captura `m` :

```cpp
// C3491a.cpp

int main()
{
   int m = 55;
   [m](int n) { m = n; }(99); // C3491
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3491 declarando a expressão lambda com a **`mutable`** palavra-chave:

```cpp
// C3491b.cpp

int main()
{
   int m = 55;
   [m](int n) mutable { m = n; }(99);
}
```

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
