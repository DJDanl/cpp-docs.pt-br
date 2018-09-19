---
title: Erro do compilador C3539 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3539
dev_langs:
- C++
helpviewer_keywords:
- C3539
ms.assetid: 34a33a0f-d1b6-498f-b312-ffad2d4799b3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4b2f78b69e00290dcc283e3fc340d25a4a071776
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46091875"
---
# <a name="compiler-error-c3539"></a>Erro do compilador C3539

'type': um argumento de modelo não pode ser um tipo que contenha 'auto'

O tipo de argumento de modelo indicado não pode conter um uso do `auto` palavra-chave.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Não especifique o argumento de modelo com o `auto` palavra-chave.

## <a name="example"></a>Exemplo

O exemplo a seguir produz C3539.

```
// C3539.cpp
// Compile with /Zc:auto
template<class T> class C{};
int main()
{
   C<auto> c;   // C3539
   return 0;
}
```

## <a name="see-also"></a>Consulte também

[Palavra-chave auto](../../cpp/auto-keyword.md)