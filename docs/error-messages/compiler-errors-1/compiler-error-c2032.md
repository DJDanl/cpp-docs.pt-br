---
title: Erro do compilador C2032 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2032
dev_langs:
- C++
helpviewer_keywords:
- C2032
ms.assetid: 625d7c83-70b6-42c2-a558-81fbc0026324
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6ab02ca695ec94f25054e3490232b782a46a53a4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46064003"
---
# <a name="compiler-error-c2032"></a>Erro do compilador C2032

'identifier': função não pode ser membro de struct/union 'structorunion'

A estrutura ou união tem uma função de membro, que é permitida em C++, mas não em C. Para resolver o erro, compilar como um programa C++ ou remova a função de membro.

O exemplo a seguir gera C2032:

```
// C2032.c
struct z {
   int i;
   void func();   // C2032
};
```

Solução possível:

```
// C2032b.c
// compile with: /c
struct z {
   int i;
};
```