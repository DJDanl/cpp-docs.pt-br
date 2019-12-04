---
title: Erro do compilador C3216
ms.date: 11/04/2016
f1_keywords:
- C3216
helpviewer_keywords:
- C3216
ms.assetid: bbab1efe-8779-4489-8bb0-b11e45f5cbe5
ms.openlocfilehash: 6b4f51dc0e27381ef64fc6cd1e4e279736a725aa
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74751255"
---
# <a name="compiler-error-c3216"></a>Erro do compilador C3216

a restrição deve ser um parâmetro genérico, não ' type '

Uma restrição estava mal formada.

O exemplo a seguir gera C3216:

```cpp
// C3216.cpp
// compile with: /clr
interface struct A {};

generic <class T>
where F : A   // C3216
// Try the following line instead:
// where T : A    // C3216
ref class C {};
```

O exemplo a seguir demonstra uma possível resolução:

```cpp
// C3216b.cpp
// compile with: /clr /c
interface struct A {};

generic <class T>
where T : A
ref class C {};
```
