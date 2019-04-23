---
title: Erro do compilador C3481
ms.date: 11/04/2016
f1_keywords:
- C3481
helpviewer_keywords:
- C3481
ms.assetid: 5d09375a-5ed3-4b61-86ed-45e91fd734c7
ms.openlocfilehash: eff7c7a4f39524aa1d894b7b4590aa809714aae6
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59041196"
---
# <a name="compiler-error-c3481"></a>Erro do compilador C3481

'var': variável de captura de lambda não encontrado

O compilador não foi possível encontrar a definição de uma variável que você passou para a lista de captura de uma expressão lambda.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Remova a variável na lista da expressão lambda captura.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3481 porque a variável `n` não está definido:

```
// C3481.cpp

int main()
{
   [n] {}(); // C3481
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)