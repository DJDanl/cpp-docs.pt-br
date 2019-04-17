---
title: Aviso do compilador C4694
ms.date: 10/25/2017
f1_keywords:
- C4694
helpviewer_keywords:
- C4694
ms.assetid: 5ca122bb-34f3-43ee-a21f-95802cd515f7
ms.openlocfilehash: 6164fd2e19e35233ba67feb84d117f1e4e01f20d
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58770350"
---
# <a name="compiler-warning-c4694"></a>Aviso do compilador C4694

> '*classe*': uma classe sealed abstract não pode ter uma classe base*base_class*'

Uma classe abstract e sealed não pode herdar de um tipo de referência; uma classe abstract e sealed não pode implementar as funções de classe base nem permitir a mesmo a ser usado como uma classe base.

Para obter mais informações, consulte [abstrata](../../extensions/abstract-cpp-component-extensions.md), [lacrado](../../extensions/sealed-cpp-component-extensions.md), e [Classes e Structs](../../extensions/classes-and-structs-cpp-component-extensions.md).

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4694.

```cpp
// C4694.cpp
// compile with: /c /clr
ref struct A {};
ref struct B sealed abstract : A {};   // C4694
```