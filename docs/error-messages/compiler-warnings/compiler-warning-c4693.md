---
title: C4693 de aviso do compilador | Microsoft Docs
ms.date: 10/25/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4693
dev_langs:
- C++
helpviewer_keywords:
- C4693
ms.assetid: 72d8db01-5e6f-4794-8731-76107e8f064a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f8230e60d65c80b4f839cc8a1c97ccc0c7b18086
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33273875"
---
# <a name="compiler-warning-c4693"></a>C4693 de aviso do compilador

> 'class': uma classe sealed abstract não pode ter quaisquer membros de instância 'Test'

Se um tipo está marcado como [lacrado](../../windows/sealed-cpp-component-extensions.md) e [abstrata](../../windows/abstract-cpp-component-extensions.md), ele só pode ter membros estáticos.

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md).

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