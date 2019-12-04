---
title: Erro do compilador C3491
ms.date: 11/04/2016
f1_keywords:
- C3491
helpviewer_keywords:
- C3491
ms.assetid: 7f0e71b2-46a0-4d25-bd09-6158a280f509
ms.openlocfilehash: 78f90ee1c44a0d42e529a027b1e7fc90a0da3cdb
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74738317"
---
# <a name="compiler-error-c3491"></a>Erro do compilador C3491

' var ': uma captura por valor não pode ser modificada em um lambda não mutável

Uma expressão lambda não mutável não pode modificar o valor de uma variável que é capturada por valor.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Declare sua expressão lambda com a palavra-chave `mutable` ou

- Passe a variável por referência à lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3491 porque o corpo de uma expressão lambda não mutável modifica a variável de captura `m`:

```cpp
// C3491a.cpp

int main()
{
   int m = 55;
   [m](int n) { m = n; }(99); // C3491
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3491 declarando a expressão lambda com a palavra-chave `mutable`:

```cpp
// C3491b.cpp

int main()
{
   int m = 55;
   [m](int n) mutable { m = n; }(99);
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)
