---
title: Erro do compilador C3533
ms.date: 11/04/2016
f1_keywords:
- C3533
helpviewer_keywords:
- C3533
ms.assetid: a68b1ba5-466e-4190-a1a4-505ccfe548b7
ms.openlocfilehash: ce95bba417e9be3603f15376a0fd65a48f951a2f
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755636"
---
# <a name="compiler-error-c3533"></a>Erro do compilador C3533

' type ': um parâmetro não pode ter um tipo que contenha ' auto '

Um parâmetro de método ou modelo não pode ser declarado com a palavra-chave `auto` se a opção de compilador [/Zc: auto](../../build/reference/zc-auto-deduce-variable-type.md) padrão estiver em vigor.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Remova a palavra-chave `auto` da declaração de parâmetro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3533 porque ele declara um parâmetro de função com a palavra-chave `auto` e é compilado com **/Zc: auto**.

```cpp
// C3533a.cpp
// Compile with /Zc:auto
void f(auto j) {} // C3533
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3533 no modo C++ 14 porque ele declara um parâmetro de modelo com a palavra-chave `auto` e é compilado com **/Zc: auto**. (No C++ 17, essa é uma definição válida de um modelo de classe com um único parâmetro de modelo sem tipo cujo tipo é deduzido.)

```cpp
// C3533b.cpp
// Compile with /Zc:auto
template<auto T> class C {}; // C3533
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-keyword.md)<br/>
[/Zc:auto (deduzir tipo de variável)](../../build/reference/zc-auto-deduce-variable-type.md)
