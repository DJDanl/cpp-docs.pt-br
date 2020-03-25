---
title: Aviso do compilador (nível 1) C4508
ms.date: 11/04/2016
f1_keywords:
- C4508
helpviewer_keywords:
- C4508
ms.assetid: c05f113b-b789-4df0-a4ef-78bce4767021
ms.openlocfilehash: 54baf35eaeb5ef2c8add024f25c059480d60617b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80186539"
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
