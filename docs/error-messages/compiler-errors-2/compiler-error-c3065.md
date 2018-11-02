---
title: Erro do compilador C3065
ms.date: 11/04/2016
f1_keywords:
- C3065
helpviewer_keywords:
- C3065
ms.assetid: e7a0bc69-1c68-459e-a7c4-93c65609ff7c
ms.openlocfilehash: e12f6e318d51ecaccc7c29e1e01d1aedcaac937e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50526549"
---
# <a name="compiler-error-c3065"></a>Erro do compilador C3065

declaração de propriedade em escopo diferente de classe não é permitida

O [propriedade](../../cpp/property-cpp.md) modificador declspec foi usada fora de uma classe.  Uma propriedade só pode ser declarada dentro de uma classe.

O exemplo a seguir gera C3065:

```
// C3065.cpp
// compile with: /c
__declspec(property(get=get_i)) int i;   // C3065

class x {
public:
   __declspec(property(get=get_i)) int i;   // OK
};
```