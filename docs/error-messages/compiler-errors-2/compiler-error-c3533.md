---
title: Erro do compilador C3533
ms.date: 11/04/2016
f1_keywords:
- C3533
helpviewer_keywords:
- C3533
ms.assetid: a68b1ba5-466e-4190-a1a4-505ccfe548b7
ms.openlocfilehash: 18ca9f7d61d96dcc81935bd3563f57bc37da8cd7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228798"
---
# <a name="compiler-error-c3533"></a>Erro do compilador C3533

' type ': um parâmetro não pode ter um tipo que contenha ' auto '

Um parâmetro de método ou modelo não pode ser declarado com a **`auto`** palavra-chave se a opção de compilador [/Zc: auto](../../build/reference/zc-auto-deduce-variable-type.md) padrão estiver em vigor.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Remova a **`auto`** palavra-chave da declaração de parâmetro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3533 porque ele declara um parâmetro de função com a **`auto`** palavra-chave e é compilado com **/Zc: auto**.

```cpp
// C3533a.cpp
// Compile with /Zc:auto
void f(auto j) {} // C3533
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3533 no modo C++ 14 porque ele declara um parâmetro de modelo com a **`auto`** palavra-chave e é compilado com **/Zc: auto**. (No C++ 17, essa é uma definição válida de um modelo de classe com um único parâmetro de modelo sem tipo cujo tipo é deduzido.)

```cpp
// C3533b.cpp
// Compile with /Zc:auto
template<auto T> class C {}; // C3533
```

## <a name="see-also"></a>Confira também

[Palavra-chave auto](../../cpp/auto-keyword.md)<br/>
[/Zc: auto (deduzir tipo de variável)](../../build/reference/zc-auto-deduce-variable-type.md)
