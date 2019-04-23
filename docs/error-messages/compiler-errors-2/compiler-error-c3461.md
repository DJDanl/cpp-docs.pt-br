---
title: Erro do compilador C3461
ms.date: 11/04/2016
f1_keywords:
- C3461
helpviewer_keywords:
- C3461
ms.assetid: bd66833a-545d-445a-bdfe-dee771a450a4
ms.openlocfilehash: a674ce7819c88dd4e26355c0129a6c181da5c276
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59779015"
---
# <a name="compiler-error-c3461"></a>Erro do compilador C3461

'type': somente um tipo gerenciado pode ser encaminhado.

Encaminhamento de tipo só pode ocorrer em tipos CLR.  Ver [Classes e Structs](../../extensions/classes-and-structs-cpp-component-extensions.md) para obter mais informações.

Para obter mais informações, consulte [encaminhamento de tipo (C++/CLI)](../../extensions/type-forwarding-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir cria um componente.

```
// C3461.cpp
// compile with: /clr /LD
public ref class R {};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3461.

```
// C3461b.cpp
// compile with: /clr /c
#using "C3461.dll"
class N {};
[assembly:TypeForwardedTo(N::typeid)];   // C3461
[assembly:TypeForwardedTo(R::typeid)];   // OK
```