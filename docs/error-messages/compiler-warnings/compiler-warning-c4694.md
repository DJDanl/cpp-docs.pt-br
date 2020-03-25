---
title: Aviso do compilador C4694
ms.date: 10/25/2017
f1_keywords:
- C4694
helpviewer_keywords:
- C4694
ms.assetid: 5ca122bb-34f3-43ee-a21f-95802cd515f7
ms.openlocfilehash: daf5423588d08260239c3cff5a68532a358d07b2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165113"
---
# <a name="compiler-warning-c4694"></a>Aviso do compilador C4694

> '*Class*': uma classe sealed abstract não pode ter uma classe base '*BASE_CLASS*'

Uma classe abstrata e selada não pode herdar de um tipo de referência; uma classe lacrada e abstrata não pode implementar as funções de classe base nem permitir que ela seja usada como uma classe base.

Para obter mais informações, consulte [abstract](../../extensions/abstract-cpp-component-extensions.md), [sealed](../../extensions/sealed-cpp-component-extensions.md), e [classes e structs](../../extensions/classes-and-structs-cpp-component-extensions.md).

Esse aviso é promovido automaticamente para um erro. Se você quiser modificar esse comportamento, use [#pragma Aviso](../../preprocessor/warning.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4694.

```cpp
// C4694.cpp
// compile with: /c /clr
ref struct A {};
ref struct B sealed abstract : A {};   // C4694
```
