---
title: Erro do compilador C3535
ms.date: 11/04/2016
f1_keywords:
- C3535
helpviewer_keywords:
- C3535
ms.assetid: 24449c98-f681-484d-a00b-32533dca3a88
ms.openlocfilehash: 60ffd5d8decd5c9065ca55cfed34383278359f3e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228785"
---
# <a name="compiler-error-c3535"></a>Erro do compilador C3535

Não é possível deduzir o tipo para ' type1 ' de ' type2 '

O tipo da variável declarada pela **`auto`** palavra-chave não pode ser deduzido a partir do tipo da expressão de inicialização. Por exemplo, esse erro ocorrerá se a expressão de inicialização for avaliada como **`void`** , que não é um tipo.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Verifique se o tipo da expressão de inicialização não é **`void`** .

1. Verifique se a declaração não é um ponteiro para um tipo fundamental. Para obter mais informações, consulte [tipos fundamentais](../../cpp/fundamental-types-cpp.md).

1. Certifique-se de que, se a declaração for um ponteiro para um tipo, a expressão de inicialização será um tipo de ponteiro.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3535 porque a expressão de inicialização é avaliada como **`void`** .

```cpp
// C3535a.cpp
// Compile with /Zc:auto
void f(){}
int main()
{
   auto x = f();   //C3535
   return 0;
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3535 porque a instrução declara Variable `x` como um ponteiro para um tipo deduzido, mas o tipo da expressão de inicializador é Double. Consequentemente, o compilador não pode deduzir o tipo da variável.

```cpp
// C3535b.cpp
// Compile with /Zc:auto
int main()
{
   auto* x = 123.0;   // C3535
   return 0;
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3535 porque `p` a variável declara um ponteiro para um tipo deduzido, mas a expressão de inicialização não é um tipo de ponteiro.

```cpp
// C3535c.cpp
// Compile with /Zc:auto
class A { };
A x;
auto *p = x;  // C3535
```

## <a name="see-also"></a>Confira também

[Palavra-chave auto](../../cpp/auto-keyword.md)<br/>
[Tipos fundamentais](../../cpp/fundamental-types-cpp.md)
