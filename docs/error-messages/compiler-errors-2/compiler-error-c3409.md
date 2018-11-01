---
title: Erro do compilador C3409
ms.date: 11/04/2016
f1_keywords:
- C3409
helpviewer_keywords:
- C3409
ms.assetid: e372d9fa-230c-4b28-b6d3-6ad81ccf9dbb
ms.openlocfilehash: 2a677da40b64a19c4d2a27436344eec7adb80c14
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50600883"
---
# <a name="compiler-error-c3409"></a>Erro do compilador C3409

bloco de atributos vazio não é permitido

Os colchetes foram interpretados pelo compilador como um [atributo](../../windows/cpp-attributes-reference.md) bloco, mas nenhum atributo foi encontrado.

O compilador pode gerar esse erro quando você usa colchetes como parte da definição de uma expressão lambda. Esse erro ocorre quando o compilador não pode determinar se os colchetes são parte da definição de uma expressão lambda ou de um bloco de atributo. Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Se os colchetes são parte de um bloco de atributo:

   1. Forneça um ou mais atributos no bloco de atributo.

   1. Remova o bloco de atributo.

1. Se os colchetes são parte de uma expressão lambda:

   1. Certifique-se de que a expressão lambda segue as regras de sintaxe válida.

         Para obter mais informações sobre a sintaxe da expressão lambda, consulte [sintaxe de expressão Lambda](../../cpp/lambda-expression-syntax.md).

    2.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3409.

```
// C3409.cpp
// compile with: /c
#include <windows.h>
[]   // C3409
class a {};

// OK
[object, uuid("00000000-0000-0000-0000-000000000000")]
__interface x {};

[coclass, uuid("00000000-0000-0000-0000-000000000001")]
class b : public x {};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3409 porque uma expressão lambda usa o `mutable` especificação, mas não fornece uma lista de parâmetros. O compilador não pode determinar se os colchetes são parte da definição de uma expressão lambda ou de um bloco de atributo.

```
// C3409b.cpp

int main()
{
   [] mutable {}();
}
```

## <a name="see-also"></a>Consulte também

[attribute](../../windows/cpp-attributes-reference.md)<br/>
[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)<br/>
[Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md)