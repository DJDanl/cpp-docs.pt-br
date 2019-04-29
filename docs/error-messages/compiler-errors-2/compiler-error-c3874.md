---
title: Erro do compilador C3874
ms.date: 11/04/2016
f1_keywords:
- C3874
helpviewer_keywords:
- C3874
ms.assetid: fd55fc05-69a7-4237-b3b7-dca1d5400b4f
ms.openlocfilehash: 73476d50b6cfe098ee9d8084837c2090e198a6cd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62242897"
---
# <a name="compiler-error-c3874"></a>Erro do compilador C3874

tipo de retorno de 'function' deve ser 'int', em vez de 'type'

Uma função não tem o tipo de retorno que era esperado pelo compilador.

O exemplo a seguir gera C3874:

```
// C3874b.cpp
double main()
{   // C3874
}
```