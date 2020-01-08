---
title: Erro do compilador C2032
ms.date: 11/04/2016
f1_keywords:
- C2032
helpviewer_keywords:
- C2032
ms.assetid: 625d7c83-70b6-42c2-a558-81fbc0026324
ms.openlocfilehash: d20bc61df2d0bab9115768b3bc0589f11a9bcdb9
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75302088"
---
# <a name="compiler-error-c2032"></a>Erro do compilador C2032

' identifier ': a função não pode ser membro de struct/Union ' structorunion '

A estrutura ou a União tem uma função membro, que é permitida C++ em, mas não em C. Para resolver o erro, compile como um C++ programa ou remova a função de membro.

O exemplo a seguir gera C2032:

```c
// C2032.c
struct z {
   int i;
   void func();   // C2032
};
```

Resolução possível:

```c
// C2032b.c
// compile with: /c
struct z {
   int i;
};
```
