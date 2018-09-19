---
title: Erro do compilador C3535 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3535
dev_langs:
- C++
helpviewer_keywords:
- C3535
ms.assetid: 24449c98-f681-484d-a00b-32533dca3a88
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 215fa52f892cb569b32335ca439811eb07b28dc7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46094072"
---
# <a name="compiler-error-c3535"></a>Erro do compilador C3535

não é possível deduzir o tipo de 'type1' de 'type2'

O tipo da variável declarada com o `auto` palavra-chave não pode ser deduzido do tipo da expressão de inicialização. Por exemplo, esse erro ocorre se a expressão de inicialização for avaliada como `void`, que não é um tipo.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Certifique-se de que o tipo da expressão de inicialização não é `void`.

1. Certifique-se de que a declaração não é um ponteiro para um tipo fundamental. Para obter mais informações, consulte [tipos fundamentais](../../cpp/fundamental-types-cpp.md).

1. Certifique-se de que, se a declaração é um ponteiro para um tipo, a expressão de inicialização é um tipo de ponteiro.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3535 porque a expressão de inicialização é avaliada como `void`.

```
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

O exemplo a seguir produz C3535 porque a instrução declara a variável `x` como um ponteiro para um tipo deduzido, mas o tipo do inicializador de expressão é duplo. Consequentemente, o compilador não é possível deduzir o tipo da variável.

```
// C3535b.cpp
// Compile with /Zc:auto
int main()
{
   auto* x = 123.0;   // C3535
   return 0;
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3535 porque variável `p` declara um ponteiro para um tipo deduzido, mas a expressão de inicialização não é um tipo de ponteiro.

```
// C3535c.cpp
// Compile with /Zc:auto
class A { };
A x;
auto *p = x;  // C3535
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-keyword.md)<br/>
[Tipos fundamentais](../../cpp/fundamental-types-cpp.md)