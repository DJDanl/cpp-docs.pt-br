---
title: Aviso do compilador C4687
ms.date: 11/04/2016
f1_keywords:
- C4687
helpviewer_keywords:
- C4687
ms.assetid: 2f28e0b1-7358-4c88-bd70-aad8f0aa004c
ms.openlocfilehash: 1978e1a35ba5b5d59b5961a21378d8af6921d145
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "58778657"
---
# <a name="compiler-warning-c4687"></a>Aviso do compilador C4687

'class': uma classe sealed abstract não pode implementar uma interface 'interface'

Normalmente, um tipo abstrato, selado só é útil para manter funções de membro estático.

Para obter mais informações, consulte [abstrata](../../extensions/abstract-cpp-component-extensions.md)e [lacrado](../../extensions/sealed-cpp-component-extensions.md).

Por padrão, C4687 é emitido como um erro. Você pode suprimir C4687 com o [aviso](../../preprocessor/warning.md) pragma. Se você tiver certeza de que você deseja implementar uma interface em um tipo abstrato, selado, você pode suprimir C4687.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4687.

```
// C4687.cpp
// compile with: /clr /c
interface class A {};

ref struct B sealed abstract : A {};   // C4687
ref struct C sealed : A {};   // OK
ref struct D abstract : A {};   // OK
```