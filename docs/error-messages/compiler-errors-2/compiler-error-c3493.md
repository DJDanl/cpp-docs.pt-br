---
title: Erro do compilador C3493
ms.date: 11/04/2016
f1_keywords:
- C3493
helpviewer_keywords:
- C3493
ms.assetid: 734b4257-12a3-436f-8488-c8c55ec81634
ms.openlocfilehash: 1bbf9b269075717ae397b7d29ee28c278b1e4ec8
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59034933"
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

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)