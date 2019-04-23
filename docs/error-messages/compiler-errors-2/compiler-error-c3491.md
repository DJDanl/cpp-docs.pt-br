---
title: Erro do compilador C3491
ms.date: 11/04/2016
f1_keywords:
- C3491
helpviewer_keywords:
- C3491
ms.assetid: 7f0e71b2-46a0-4d25-bd09-6158a280f509
ms.openlocfilehash: 12f50e48fc18fc23d078b6dbc7d21d05efa06d43
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59032921"
---
# <a name="compiler-error-c3491"></a>Erro do compilador C3491

'var': uma captura por valor não pode ser modificada em um lambda não mutável

Uma expressão lambda não mutável não é possível modificar o valor de uma variável que é capturado por valor.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Declarar sua expressão lambda com o `mutable` palavra-chave, ou

- Passe a variável por referência à lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3491 porque o corpo de uma expressão lambda não mutável modifica a variável de captura `m`:

```
// C3491a.cpp

int main()
{
   int m = 55;
   [m](int n) { m = n; }(99); // C3491
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3491 declarando a expressão lambda com o `mutable` palavra-chave:

```
// C3491b.cpp

int main()
{
   int m = 55;
   [m](int n) mutable { m = n; }(99);
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)