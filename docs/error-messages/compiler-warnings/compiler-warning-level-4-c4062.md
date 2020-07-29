---
title: Aviso do compilador (nível 4) C4062
ms.date: 04/05/2019
f1_keywords:
- C4062
helpviewer_keywords:
- C4062
ms.assetid: 36d1c6ae-c917-4b08-bf30-2eb49ee94169
ms.openlocfilehash: efe021c9994e20f2630e31537bcc6099783b4308
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219996"
---
# <a name="compiler-warning-level-4-c4062"></a>Aviso do compilador (nível 4) C4062

> o enumerador '*Identifier*' na opção de enumeração '*Enumeration*' não é tratado

O *identificador* do enumerador não tem nenhum `case` manipulador associado em uma **`switch`** instrução, e não há nenhum **`default`** rótulo que possa capturá-lo. O caso ausente pode ser uma supervisão e é um erro potencial em seu código. Para obter um aviso relacionado sobre enumeradores não utilizados em **`switch`** instruções que têm um **`default`** caso, consulte [C4061](compiler-warning-level-4-c4061.md).

Esse aviso está desativado por padrão. Para obter mais informações sobre como habilitar os avisos que estão desativados por padrão, consulte os [avisos do compilador que estão desativados por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4062 e mostra como corrigi-lo:

```cpp
// C4062.cpp
// compile with: /EHsc /W4
#pragma warning(default : 4062)
enum E { a, b, c };
void func ( E e ) {
   switch(e) {
      case a:
      case b:
   // case c:  // to fix, uncomment this line
      break;   // no default label
   }   // C4062, enumerator 'c' not handled
}

int main() {
}
```

## <a name="see-also"></a>Confira também

[Aviso do compilador (nível 4) C4061](compiler-warning-level-4-c4061.md)
