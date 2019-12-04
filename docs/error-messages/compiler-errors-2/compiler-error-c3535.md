---
title: Erro do compilador C3535
ms.date: 11/04/2016
f1_keywords:
- C3535
helpviewer_keywords:
- C3535
ms.assetid: 24449c98-f681-484d-a00b-32533dca3a88
ms.openlocfilehash: 6b487c0f94a00ec64e0c2178265c5a8c27544a51
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761550"
---
# <a name="compiler-error-c3535"></a>Erro do compilador C3535

Não é possível deduzir o tipo para ' type1 ' de ' type2 '

O tipo da variável declarada pela palavra-chave `auto` não pode ser deduzido a partir do tipo da expressão de inicialização. Por exemplo, esse erro ocorrerá se a expressão de inicialização for avaliada como `void`, que não é um tipo.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Verifique se o tipo da expressão de inicialização não é `void`.

1. Verifique se a declaração não é um ponteiro para um tipo fundamental. Para obter mais informações, consulte [tipos fundamentais](../../cpp/fundamental-types-cpp.md).

1. Certifique-se de que, se a declaração for um ponteiro para um tipo, a expressão de inicialização será um tipo de ponteiro.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3535 porque a expressão de inicialização é avaliada como `void`.

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

O exemplo a seguir produz C3535 porque a instrução declara a variável `x` como um ponteiro para um tipo deduzido, mas o tipo da expressão de inicializador é duplo. Consequentemente, o compilador não pode deduzir o tipo da variável.

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

O exemplo a seguir produz C3535 porque a variável `p` declara um ponteiro para um tipo deduzido, mas a expressão de inicialização não é um tipo de ponteiro.

```cpp
// C3535c.cpp
// Compile with /Zc:auto
class A { };
A x;
auto *p = x;  // C3535
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-keyword.md)<br/>
[Tipos fundamentais](../../cpp/fundamental-types-cpp.md)
