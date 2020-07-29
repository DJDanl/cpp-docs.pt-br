---
title: Aviso do compilador (nível 4) C4061
ms.date: 04/05/2019
f1_keywords:
- C4061
helpviewer_keywords:
- C4061
ms.assetid: a99cf88e-7941-4519-8b1b-f6889d914b2f
ms.openlocfilehash: 18c5a51e24af36c5a330e10a66ce3dcc38295fb1
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225274"
---
# <a name="compiler-warning-level-4-c4061"></a>Aviso do compilador (nível 4) C4061

> o enumerador '*Identifier*' em switch de enumeração '*Enumeration*' não é manipulado explicitamente por um rótulo case

O *identificador* do enumerador especificado não tem nenhum manipulador associado em uma **`switch`** instrução que tenha um **`default`** caso. O caso ausente pode ser uma supervisão ou talvez não seja um problema. Pode depender se o enumerador é manipulado pelo caso padrão ou não. Para obter um aviso relacionado sobre enumeradores não utilizados em **`switch`** instruções que não têm nenhum **`default`** caso, consulte [C4062](compiler-warning-level-4-c4062.md).

Esse aviso está desativado por padrão. Para obter mais informações sobre como habilitar os avisos que estão desativados por padrão, consulte os [avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4061; Adicione um caso para que o enumerador que está faltando corrija:

```cpp
// C4061.cpp
// compile with: /W4
#pragma warning(default : 4061)

enum E { a, b, c };
void func ( E e )
{
   switch(e)
   {
      case a:
      case b:
      default:
         break;
   }   // C4061 c' not handled
}

int main()
{
}
```

## <a name="see-also"></a>Confira também

[Aviso do compilador (nível 4) C4062](compiler-warning-level-4-c4062.md)
