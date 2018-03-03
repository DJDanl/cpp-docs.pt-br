---
title: C4694 de aviso do compilador | Microsoft Docs
ms.date: 10/25/2017
ms.technology:
- cpp-tools
ms.topic: article
f1_keywords:
- C4694
dev_langs:
- C++
helpviewer_keywords:
- C4694
ms.assetid: 5ca122bb-34f3-43ee-a21f-95802cd515f7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3f635aad0039812b50bd48a36f307ab5f60cba10
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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