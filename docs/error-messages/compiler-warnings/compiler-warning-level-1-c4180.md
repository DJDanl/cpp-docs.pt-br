---
title: Compilador aviso (nível 1) C4180
ms.date: 11/04/2016
f1_keywords:
- C4180
helpviewer_keywords:
- C4180
ms.assetid: 40c91bd4-37f1-4d59-a4f3-d5ddab68239b
ms.openlocfilehash: 8ed09edae5a9577773c573337b6e646a49599862
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391693"
---
# <a name="compiler-warning-level-1-c4180"></a>Compilador aviso (nível 1) C4180

qualificador aplicado a tipo de função não tem nenhum significado; ignorado

Um qualificador, tais como **const**, é aplicado a um tipo de função definido pelo `typedef`.

## <a name="example"></a>Exemplo

```
// C4180.cpp
// compile with: /W1 /c
typedef int FuncType(void);

// the const qualifier cannot be applied to the
// function type FuncType
const FuncType f;   // C4180
```