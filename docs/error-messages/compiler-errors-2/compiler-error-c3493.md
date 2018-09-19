---
title: Erro do compilador C3493 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3493
dev_langs:
- C++
helpviewer_keywords:
- C3493
ms.assetid: 734b4257-12a3-436f-8488-c8c55ec81634
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ad3c46117e77d432af27321165f1e1ab93d2ef3c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46045101"
---
# <a name="compiler-error-c3493"></a>Erro do compilador C3493

'var' não pode ser capturado implicitamente porque nenhum modo de captura padrão foi especificado

A captura de expressão lambda vazio, `[]`, especifica que a expressão lambda faz não explicitamente ou implicitamente capturar todas as variáveis.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Fornecer um modo de captura padrão, ou

- Capture explicitamente uma ou mais variáveis.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3493 porque ele modifica uma variável externa, mas Especifica a cláusula capture vazia:

```
// C3493a.cpp

int main()
{
   int m = 55;
   [](int n) { m = n; }(99); // C3493
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3493 especificando por referência como o modo de captura padrão.

```
// C3493b.cpp

int main()
{
   int m = 55;
   [&](int n) { m = n; }(99);
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)