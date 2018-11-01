---
title: Erro do compilador C3537
ms.date: 11/04/2016
f1_keywords:
- C3537
helpviewer_keywords:
- C3537
ms.assetid: f537ebd1-4fb0-4e09-a453-4f38db2c6881
ms.openlocfilehash: 22387470019b0118d06b4cacd82a1df5c3e505fb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50576118"
---
# <a name="compiler-error-c3537"></a>Erro do compilador C3537

'type': não pode ser convertido para um tipo que contenha 'auto'

Você não pode converter uma variável para o tipo indicado, porque o tipo contém o `auto` palavra-chave e o padrão [/ZC: auto](../../build/reference/zc-auto-deduce-variable-type.md) opção do compilador está em vigor.

## <a name="example"></a>Exemplo

O código a seguir produz C3537 porque as variáveis são convertidas em um tipo que contém o `auto` palavra-chave.

```
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