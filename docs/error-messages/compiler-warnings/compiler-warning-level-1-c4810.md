---
title: Aviso do compilador (nível 1) C4810
ms.date: 11/04/2016
f1_keywords:
- C4810
helpviewer_keywords:
- C4810
ms.assetid: 39e2cae0-9c1c-4ac1-aaa0-5f661d06085b
ms.openlocfilehash: bdeb4dd28587635a391e7b776ccd88b637a7769f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80174928"
---
# <a name="compiler-warning-level-1-c4810"></a>Aviso do compilador (nível 1) C4810

valor de pragma Pack (show) = = n

Esse aviso é emitido quando você usa a opção **Mostrar** do pragma do [pacote](../../preprocessor/pack.md) . *n* é o valor do pacote atual.

Por exemplo, o código a seguir mostra como o aviso de C4810 funciona com a pragma do pacote:

```cpp
// C4810.cpp
// compile with: /W1 /LD
// C4810 expected
#pragma pack(show)
#pragma pack(4)
#pragma pack(show)
```
