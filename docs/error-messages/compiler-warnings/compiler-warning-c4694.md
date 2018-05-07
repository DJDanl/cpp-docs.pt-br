---
title: C4694 de aviso do compilador | Microsoft Docs
ms.date: 10/25/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4694
dev_langs:
- C++
helpviewer_keywords:
- C4694
ms.assetid: 5ca122bb-34f3-43ee-a21f-95802cd515f7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 33852b76f23e007625f86969119a22ee81305187
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-c4694"></a>C4694 de aviso do compilador

> '*classe*': uma classe sealed abstract não pode ter uma classe base*base_class*'

Uma classe abstract e sealed não pode herdar de um tipo de referência. uma classe abstract e sealed não pode implementar as funções de classe base nem permitir que ela própria a ser usado como uma classe base.

Para obter mais informações, consulte [abstrata](../../windows/abstract-cpp-component-extensions.md), [lacrado](../../windows/sealed-cpp-component-extensions.md), e [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md).

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4694.

```cpp
// C4694.cpp
// compile with: /c /clr
ref struct A {};
ref struct B sealed abstract : A {};   // C4694
```