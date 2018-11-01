---
title: Erro do compilador C3161
ms.date: 11/04/2016
f1_keywords:
- C3161
helpviewer_keywords:
- C3161
ms.assetid: 1fe2be85-a343-487b-8476-bf9e257eb29d
ms.openlocfilehash: 22ecc176036308699c3ad7bd8c015836be910073
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50501654"
---
# <a name="compiler-error-c3161"></a>Erro do compilador C3161

'interface': aninhamento de classe, struct, union ou interface em uma interface é ilegal; aninhar interface em uma classe, struct ou união é ilegal

Uma [interface](../../cpp/interface.md) só pode aparecer no escopo global ou dentro de um namespace. Uma classe, struct ou union não pode aparecer em uma interface.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3161.

```
// C3161.cpp
// compile with: /c
__interface X {
   __interface Y {};   // C3161 A nested interface
};
```