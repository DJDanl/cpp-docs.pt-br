---
title: Aviso do compilador (nível 1) C4606
ms.date: 11/04/2016
f1_keywords:
- C4606
helpviewer_keywords:
- C4606
ms.assetid: c1b45fb6-672b-42eb-9e1c-c67b3e4150d3
ms.openlocfilehash: 9b38e9670157fd15dc7c4b6a96ced7ad40c43e34
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185991"
---
# <a name="compiler-warning-level-1-c4606"></a>Aviso do compilador (nível 1) C4606

aviso de pragma de \#: ' warning_number ' ignorado; Os avisos de análise de código não estão associados aos níveis de aviso

Para avisos de análise de código, somente `error`, `once`e `default` têm suporte com o pragma de [aviso](../../preprocessor/warning.md) .

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4606.

```cpp
// C4606.cpp
// compile with: /c /W1
#pragma warning(1: 6001)   // C4606
#pragma warning(once: 6001)   // OK
```
