---
title: Erro do compilador C3161 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3161
dev_langs:
- C++
helpviewer_keywords:
- C3161
ms.assetid: 1fe2be85-a343-487b-8476-bf9e257eb29d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 11396ccad33489b41d18759ba4d2f00b445e94a3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46136069"
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