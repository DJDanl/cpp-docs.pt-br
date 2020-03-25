---
title: Aviso do compilador C4693
ms.date: 10/25/2017
f1_keywords:
- C4693
helpviewer_keywords:
- C4693
ms.assetid: 72d8db01-5e6f-4794-8731-76107e8f064a
ms.openlocfilehash: 71c3db18b400ce94bff3c643d6728a6613061039
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165126"
---
# <a name="compiler-warning-c4693"></a>Aviso do compilador C4693

> ' class ': uma classe sealed abstract não pode possuir nenhum membro de instância ' test '

Se um tipo for marcado como [sealed](../../extensions/sealed-cpp-component-extensions.md) e [abstract](../../extensions/abstract-cpp-component-extensions.md), ele só poderá ter membros estáticos.

Esse aviso é promovido automaticamente para um erro. Se você quiser modificar esse comportamento, use [#pragma Aviso](../../preprocessor/warning.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4693.

```cpp
// C4693.cpp
// compile with: /clr /c
public ref class Public_Ref_Class sealed abstract {
public:
   void Test() {}   // C4693
   static void Test2() {}   // OK
};
```
