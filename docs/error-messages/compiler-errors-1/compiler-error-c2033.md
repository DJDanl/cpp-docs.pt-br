---
title: Erro do compilador C2033 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2033
dev_langs:
- C++
helpviewer_keywords:
- C2033
ms.assetid: fd5a1637-9db2-4c98-a7cc-b63b39737cd9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 05ed1274f94c1df8e9654622ec059ea9707cdf87
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46043021"
---
# <a name="compiler-error-c2033"></a>Erro do compilador C2033

'identifier': campo de bits não pode possuir indireção

O campo de bits foi declarado como um ponteiro, que não é permitido.

O exemplo a seguir gera C2033:

```
// C2033.cpp
struct S {
   int *b : 1;  // C2033
};
```

Solução possível:

```
// C2033b.cpp
// compile with: /c
struct S {
   int b : 1;
};
```