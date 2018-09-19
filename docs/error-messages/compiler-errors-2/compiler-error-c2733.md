---
title: Erro do compilador C2733 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2733
dev_langs:
- C++
helpviewer_keywords:
- C2733
ms.assetid: 67f83561-c633-407c-a2ee-f9fd16e165bf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 42749c26f4a8a474f3dac076b80a1bfe71e89d58
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46110439"
---
# <a name="compiler-error-c2733"></a>Erro do compilador C2733

segundo vínculo a C de função sobrecarregada 'function' não permitido

Mais de uma função sobrecarregada foi declarada com vinculação C. Ao usar a ligação de C, apenas uma forma de uma função especificada pode ser externa. Como funções sobrecarregadas têm o mesmo nome não decorado, não pode ser usados com programas em C.

O exemplo a seguir gera C2733:

```
// C2733.cpp
extern "C" {
   void F1(int);
}

extern "C" {
   void F1();   // C2733
   // try the following line instead
   // void F2();
}
```