---
title: Erro do compilador C2951 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2951
dev_langs:
- C++
helpviewer_keywords:
- C2951
ms.assetid: c6f95aa2-c894-425b-a51c-d40d70c8daa1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c6757256f08c5c1ed0a35fbf1c2a70776a4f2936
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46074663"
---
# <a name="compiler-error-c2951"></a>Erro do compilador C2951

declarações de tipo são permitidas apenas em um namespace global, ou escopo de classe

Você não pode declarar um genérico ou escopo de namespace ou classe de modelo global externo. Se você tornar suas declarações genérico ou modelo em um arquivo de inclusão, verifique se o arquivo de inclusão está no escopo global.

O exemplo a seguir gera C2951:

```
// C2951.cpp
template <class T>
class A {};

int main() {
   template <class T>   // C2951
   class B {};
}
```

C2951 também podem ocorrer ao usar genéricos:

```
// C2951b.cpp
// compile with: /clr /c

// OK
generic <class T>
ref class GC { };

int main() {
   generic <class T> ref class GC2 {};   // C2951
}
```