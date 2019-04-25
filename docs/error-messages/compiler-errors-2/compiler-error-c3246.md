---
title: Erro do compilador C3246
ms.date: 11/04/2016
f1_keywords:
- C3246
helpviewer_keywords:
- C3246
ms.assetid: ad85224a-e540-479b-a5eb-a3bc3964c30b
ms.openlocfilehash: eb5ba268508922daf00adb49cf611c038db76343
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62173191"
---
# <a name="compiler-error-c3246"></a>Erro do compilador C3246

'class': não pode herdar de 'type', pois ele foi declarado como 'sealed'

Uma classe que está marcada como [lacrado](../../extensions/sealed-cpp-component-extensions.md) não pode ser a classe base para todas as outras classes.

O exemplo a seguir gera C3246:

```
// C3246_2.cpp
// compile with: /clr /LD
ref class X sealed {};

ref class Y : public X {}; // C3246
```
