---
title: Erro do compilador C3537
ms.date: 11/04/2016
f1_keywords:
- C3537
helpviewer_keywords:
- C3537
ms.assetid: f537ebd1-4fb0-4e09-a453-4f38db2c6881
ms.openlocfilehash: 663ef761d6c52aeb4c3cc9ce109079c647904e36
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87197547"
---
# <a name="compiler-error-c3537"></a>Erro do compilador C3537

' type ': não é possível converter em um tipo que contenha ' auto '

Você não pode converter uma variável para o tipo indicado porque o tipo contém a **`auto`** palavra-chave e a opção padrão [/Zc: compilador auto](../../build/reference/zc-auto-deduce-variable-type.md) está em vigor.

## <a name="example"></a>Exemplo

O código a seguir produz C3537 porque as variáveis são convertidas em um tipo que contém a **`auto`** palavra-chave.

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

## <a name="see-also"></a>Confira também

[Palavra-chave auto](../../cpp/auto-keyword.md)
