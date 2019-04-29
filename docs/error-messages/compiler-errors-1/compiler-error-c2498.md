---
title: Erro do compilador C2498
ms.date: 11/04/2016
f1_keywords:
- C2498
helpviewer_keywords:
- C2498
ms.assetid: 0839f12c-aaa4-4a02-bb33-7f072715dd14
ms.openlocfilehash: 1087dbb2297058f752e0a15776e4a7185e32a5c5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62360457"
---
# <a name="compiler-error-c2498"></a>Erro do compilador C2498

'function': 'novtable' só pode ser aplicado a declarações de classe ou definições

Esse erro pode ser causado por meio `__declspec(novtable)` com uma função.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2498:

```
// C2498.cpp
// compile with: /c
void __declspec(novtable) f() {}   // C2498
class __declspec(novtable) A {};   // OK
```