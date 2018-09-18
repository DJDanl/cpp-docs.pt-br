---
title: Erro do compilador C3247 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3247
dev_langs:
- C++
helpviewer_keywords:
- C3247
ms.assetid: f9a2bbb5-3fce-40bf-9fd3-835a5f164dbb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f706b4f1a1935a5c6246ea285c7e8b2b746f08cb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46047233"
---
# <a name="compiler-error-c3247"></a>Erro do compilador C3247

'class1': uma coclass não pode herdar de outra coclass 'class2'

Uma classe marcada com o [coclass](../../windows/coclass.md) atributo não pode herdar de outra classe marcada com o `coclass` atributo.

O exemplo a seguir gera C3247:

```
// C3247.cpp
[module(name="MyLib")];
[coclass]
class a {
};

[coclass]
class b : public a {   // C3247
};
int main() {
}
```