---
title: Erro do compilador C2569 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2569
dev_langs:
- C++
helpviewer_keywords:
- C2569
ms.assetid: 092bed1e-f631-436c-9586-7750629f6fac
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9309576439a772427c6adcb6f94826a8f9230058
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46078849"
---
# <a name="compiler-error-c2569"></a>Erro do compilador C2569

'EnumOrUnion': enum/union não pode ser usado como uma classe base

Se você deve derivar um tipo de união especificado ou de enumeração, altere a união ou enumeração para uma classe ou estrutura.

O exemplo a seguir gera C2569:

```
// C2569.cpp
// compile with: /c
union ubase {};
class cHasPubUBase : public ubase {};   // C2569
// OK
struct sbase {};
class cHasPubUBase : public sbase {};
```