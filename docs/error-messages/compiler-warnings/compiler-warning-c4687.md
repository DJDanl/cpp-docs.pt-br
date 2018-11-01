---
title: Aviso do compilador C4687
ms.date: 11/04/2016
f1_keywords:
- C4687
helpviewer_keywords:
- C4687
ms.assetid: 2f28e0b1-7358-4c88-bd70-aad8f0aa004c
ms.openlocfilehash: 50551faf817f83d8a4af848a75af67ebe7004fe7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50635468"
---
# <a name="compiler-warning-c4687"></a>Aviso do compilador C4687

'class': uma classe sealed abstract não pode implementar uma interface 'interface'

Normalmente, um tipo abstrato, selado só é útil para manter funções de membro estático.

Para obter mais informações, consulte [abstrata](../../windows/abstract-cpp-component-extensions.md)e [lacrado](../../windows/sealed-cpp-component-extensions.md).

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