---
title: Erro do compilador C3753
ms.date: 11/04/2016
f1_keywords:
- C3753
helpviewer_keywords:
- C3753
ms.assetid: a5b99e28-796c-4107-a673-97c2ae3bb2b9
ms.openlocfilehash: 7c9c078e72babc85dc7092b8d6414625e9c0db7b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410467"
---
# <a name="compiler-error-c3753"></a>Erro do compilador C3753

uma propriedade de generic não é permitida

Listas de parâmetro genérico podem aparecer somente em funções, estruturas ou classes gerenciadas.

Para obter mais informações, consulte [genéricos](../../extensions/generics-cpp-component-extensions.md) e [propriedade](../../extensions/property-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3753.

```
// C3753.cpp
// compile with: /clr /c
ref struct A {
   generic <typename T>
   property int i;   // C3753 error
};
```