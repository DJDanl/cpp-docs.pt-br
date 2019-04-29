---
title: Erro do compilador C2943
ms.date: 11/04/2016
f1_keywords:
- C2943
helpviewer_keywords:
- C2943
ms.assetid: ede6565e-d892-44c0-8eee-c69545f3be2e
ms.openlocfilehash: 53340611ef92aac7c9bed30f364fed424fdfe140
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366271"
---
# <a name="compiler-error-c2943"></a>Erro do compilador C2943

'class': id de classe de tipo é redefinida como um argumento de tipo de um modelo

Você não pode usar uma classe genérica ou modelo, em vez de um símbolo, como um argumento de tipo genérico ou modelo.

O exemplo a seguir gera C2943:

```
// C2943.cpp
// compile with: /c
template<class T>
class List {};

template<class List<int> > class MyList;   // C2943
template<class T >  class MyList;
```