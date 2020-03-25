---
title: Erro do compilador C3409
ms.date: 11/06/2018
f1_keywords:
- C3409
helpviewer_keywords:
- C3409
ms.assetid: e372d9fa-230c-4b28-b6d3-6ad81ccf9dbb
ms.openlocfilehash: 8ab2e0d152e4c123fa23512bc0111cebd070b3ee
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200852"
---
# <a name="compiler-error-c3409"></a>Erro do compilador C3409

> bloco de atributos vazio não é permitido

## <a name="remarks"></a>Comentários

Os colchetes foram interpretados pelo compilador como um bloco de [atributos](../../windows/attributes-alphabetical-reference.md) , mas nenhum atributo foi encontrado.

O compilador pode gerar esse erro quando você usa colchetes como parte da definição de uma expressão lambda. Esse erro ocorre quando o compilador não pode determinar se os colchetes fazem parte da definição de uma expressão lambda ou de um bloco de atributo. Para obter mais informações sobre expressões lambda, consulte [Expressões lambda](../../cpp/lambda-expressions-in-cpp.md).

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Se os colchetes fizerem parte de um bloco de atributos:

   1. Forneça um ou mais atributos no bloco de atributos.

   1. Remova o bloco de atributo.

1. Se os colchetes fizerem parte de uma expressão lambda, certifique-se de que a expressão lambda segue regras de sintaxe válidas.

   Para obter mais informações sobre a sintaxe de expressão lambda, consulte [sintaxe de expressão lambda](../../cpp/lambda-expression-syntax.md).

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

O exemplo a seguir gera C3409 porque uma expressão lambda usa a especificação `mutable`, mas não fornece uma lista de parâmetros. O compilador não pode determinar se os colchetes fazem parte da definição de uma expressão lambda ou de um bloco de atributo.

```cpp
// C3409b.cpp

int main()
{
   [] mutable {}();
}
```

## <a name="see-also"></a>Confira também

[attribute](../../windows/attributes-alphabetical-reference.md)<br/>
[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)<br/>
[Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md)
