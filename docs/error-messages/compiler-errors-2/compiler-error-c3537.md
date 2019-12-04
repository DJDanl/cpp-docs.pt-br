---
title: Erro do compilador C3537
ms.date: 11/04/2016
f1_keywords:
- C3537
helpviewer_keywords:
- C3537
ms.assetid: f537ebd1-4fb0-4e09-a453-4f38db2c6881
ms.openlocfilehash: ef3e954987b84ea128342b38307769903df4b346
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74740475"
---
# <a name="compiler-error-c3537"></a>Erro do compilador C3537

' type ': não é possível converter em um tipo que contenha ' auto '

Você não pode converter uma variável para o tipo indicado porque o tipo contém a palavra-chave `auto` e a opção de compilador [/Zc: auto](../../build/reference/zc-auto-deduce-variable-type.md) do padrão está em vigor.

## <a name="example"></a>Exemplo

O código a seguir produz C3537 porque as variáveis são convertidas em um tipo que contém a palavra-chave `auto`.

```cpp
// C3537.cpp
// Compile with /Zc:auto
int main()
{
   int value = 123;
   auto(value);                        // C3537
   (auto)value;                        // C3537
   auto x1 = auto(value);              // C3537
   auto x2 = (auto)value;              // C3537
   auto x3 = static_cast<auto>(value); // C3537
   return 0;
}
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-keyword.md)
