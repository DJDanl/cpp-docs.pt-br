---
title: Aviso do compilador (nível 1) C4508
ms.date: 11/04/2016
f1_keywords:
- C4508
helpviewer_keywords:
- C4508
ms.assetid: c05f113b-b789-4df0-a4ef-78bce4767021
ms.openlocfilehash: 394a59a472100cc30476b5bb87f30c45d867f94b
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966299"
---
# <a name="compiler-warning-level-1-c4508"></a>Aviso do compilador (nível 1) C4508

' function ': a função deve retornar um valor; tipo de retorno ' void ' assumido

A função não tem nenhum tipo de retorno especificado. Nesse caso, o C4430 também deve ser acionado e o compilador implementa a correção relatada pelo C4430 (o valor padrão é int).

Para resolver esse aviso, declare explicitamente o tipo de retorno das funções.

O exemplo a seguir gera C4508:

```cpp
// C4508.cpp
// compile with: /W1 /c
#pragma warning (disable : 4430)
func() {}   // C4508
void func2() {}   // OK
```