---
title: Aviso do compilador (nível 1) C4293
description: Descreve as causas de C4293 de aviso do compilador MSVC e mostra como corrigi-lo.
ms.date: 07/15/2020
f1_keywords:
- C4293
helpviewer_keywords:
- C4293
ms.assetid: babecd96-eb51-41a5-9835-462c7a46dbad
ms.openlocfilehash: 3b5a05d4a744b084f1cc34210a5374962064e85d
ms.sourcegitcommit: e15b46ea7888dbdd7e0bb47da76aeed680c3c1f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/17/2020
ms.locfileid: "86446470"
---
# <a name="compiler-warning-level-1-c4293"></a>Aviso do compilador (nível 1) C4293

> '*Operator*': contagem de deslocamento negativa ou muito grande, comportamento indefinido

Se uma contagem de deslocamento for negativa ou muito grande, o comportamento da imagem resultante será indefinido.

## <a name="remarks"></a>Comentários

Para resolver esse problema, você pode usar uma conversão no primeiro operando para expandi-lo para o tamanho do tipo de resultado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4293 e mostra maneiras de corrigi-lo:

```cpp
// C4293.cpp
// compile with: /c /W1
unsigned __int64 combine (unsigned lo, unsigned hi)
{
   return (hi << 32) | lo;   // C4293

   // In C, try the following line instead:
   // return ( (unsigned __int64)hi << 32) | lo;
   // In C++, try this line instead:
   // return (static_cast<unsigned __int64>(hi) << 32) | lo;
}
```
