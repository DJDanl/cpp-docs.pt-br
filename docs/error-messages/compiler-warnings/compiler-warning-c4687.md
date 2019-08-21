---
title: Aviso do compilador C4687
ms.date: 11/04/2016
f1_keywords:
- C4687
helpviewer_keywords:
- C4687
ms.assetid: 2f28e0b1-7358-4c88-bd70-aad8f0aa004c
ms.openlocfilehash: 83f5c535f9cf252783110838c181c88c8b0096ee
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69631605"
---
# <a name="compiler-warning-c4687"></a>Aviso do compilador C4687

> '*Class*': uma classe sealed abstract não pode implementar uma interface '*interface*'

## <a name="remarks"></a>Comentários

Um tipo lacrado e abstrato normalmente é útil apenas para manter funções membro estáticas.

Para obter mais informações, consulte [abstract](../../extensions/abstract-cpp-component-extensions.md) e [sealed](../../extensions/sealed-cpp-component-extensions.md).

O C4687 é emitido como um erro por padrão. Você pode suprimir C4687 com o pragma de [aviso](../../preprocessor/warning.md) . Se você tiver certeza de que deseja implementar uma interface em um tipo lacrado e abstrato, poderá suprimir C4687.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4687.

```cpp
// C4687.cpp
// compile with: /clr /c
interface class A {};

ref struct B sealed abstract : A {};   // C4687
ref struct C sealed : A {};   // OK
ref struct D abstract : A {};   // OK
```
