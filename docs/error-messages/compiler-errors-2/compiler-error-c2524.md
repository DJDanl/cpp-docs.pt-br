---
title: Erro do compilador C2524
ms.date: 11/04/2016
f1_keywords:
- C2524
helpviewer_keywords:
- C2524
ms.assetid: e71d17f5-2fc2-416b-8dbd-e9bed85eb33a
ms.openlocfilehash: 369aa5f21c072472808ffba06c3bc5c5e608ac22
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62282177"
---
# <a name="compiler-error-c2524"></a>Erro do compilador C2524

'destruidor': um destruidor/finalizador deve ter uma lista de parâmetros 'void'

O destruidor ou finalizador tinha uma lista de parâmetros que não seja [void](../../cpp/void-cpp.md). Outros tipos de parâmetros não são permitidos.

## <a name="example"></a>Exemplo

O código a seguir reproduz C2524.

```
// C2524.cpp
// compile with: /c
class A {
   A() {}
   ~A(int i) {}    // C2524
   // try the following line instead
   // ~A() {}
};
```

## <a name="example"></a>Exemplo

O código a seguir reproduz C2524.

```
// C2524_b.cpp
// compile with: /clr /c
ref struct I1 {
protected:
   !I1(int i);   // C2524
   // try the following line instead
   // !I1();
};
```