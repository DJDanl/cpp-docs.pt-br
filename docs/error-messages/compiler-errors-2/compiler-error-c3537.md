---
title: Erro do compilador C3537 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3537
dev_langs:
- C++
helpviewer_keywords:
- C3537
ms.assetid: f537ebd1-4fb0-4e09-a453-4f38db2c6881
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9f04500998adf132594b91fc38f82c8bec4b1c5c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46107656"
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