---
title: Erro do compilador C3065 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3065
dev_langs:
- C++
helpviewer_keywords:
- C3065
ms.assetid: e7a0bc69-1c68-459e-a7c4-93c65609ff7c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 35867da62dad9e399e4b4672f84478e4ea9688a5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46104922"
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