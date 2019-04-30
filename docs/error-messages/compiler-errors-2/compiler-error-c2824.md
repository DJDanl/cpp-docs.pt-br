---
title: Erro do compilador C2824
ms.date: 11/04/2016
f1_keywords:
- C2824
helpviewer_keywords:
- C2824
ms.assetid: 5bd865f7-e0af-404e-80fe-e2b798b44a59
ms.openlocfilehash: 226fc078312a214c561e80064474ee237245c0f8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62406932"
---
# <a name="compiler-error-c2824"></a>Erro do compilador C2824

tipo de retorno para 'operator new' deve ser ' void *'

Com não baseados em ponteiros, sobrecargas do operador `new` deve retornar `void *`.

O exemplo a seguir gera C2824:

```
// C2824.cpp
// compile with: /c
class   A {
   A* operator new(size_t i, char *m);   // C2824
   // try the following line instead
   // void* operator new(size_t i, char *m);
};
```