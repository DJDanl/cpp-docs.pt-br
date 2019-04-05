---
title: Erro do compilador C3409
ms.date: 11/06/2018
f1_keywords:
- C3409
helpviewer_keywords:
- C3409
ms.assetid: e372d9fa-230c-4b28-b6d3-6ad81ccf9dbb
ms.openlocfilehash: 24f107e0c1f74f95afc521c8a4c888a26a35c13a
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59033755"
---
# <a name="compiler-error-c3409"></a>Erro do compilador C3409

> bloco de atributos vazio não é permitido

## <a name="remarks"></a>Comentários

Os colchetes foram interpretados pelo compilador como um [atributo](../../windows/attributes-alphabetical-reference.md) bloco, mas nenhum atributo foi encontrado.

O compilador pode gerar esse erro quando você usa colchetes como parte da definição de uma expressão lambda. Esse erro ocorre quando o compilador não pode determinar se os colchetes são parte da definição de uma expressão lambda ou de um bloco de atributo. Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Se os colchetes são parte de um bloco de atributo:

   1. Forneça um ou mais atributos no bloco de atributo.

   1. Remova o bloco de atributo.

1. Se os colchetes são parte de uma expressão lambda, certifique-se de que a expressão lambda segue as regras de sintaxe válida.

   Para obter mais informações sobre a sintaxe da expressão lambda, consulte [sintaxe de expressão Lambda](../../cpp/lambda-expression-syntax.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3409.

```cpp
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

```cpp
// C3409b.cpp

int main()
{
   [] mutable {}();
}
```

## <a name="see-also"></a>Consulte também

[Atributo](../../windows/attributes-alphabetical-reference.md)<br/>
[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)<br/>
[Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md)