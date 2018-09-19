---
title: Erro do compilador C3461 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3461
dev_langs:
- C++
helpviewer_keywords:
- C3461
ms.assetid: bd66833a-545d-445a-bdfe-dee771a450a4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8027831810a8f95b8d72ef70e392d9984b5c2f3a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46077926"
---
# <a name="compiler-error-c3461"></a>Erro do compilador C3461

'type': somente um tipo gerenciado pode ser encaminhado.

Encaminhamento de tipo só pode ocorrer em tipos CLR.  Ver [Classes e Structs](../../windows/classes-and-structs-cpp-component-extensions.md) para obter mais informações.

Para obter mais informações, consulte [encaminhamento de tipo (C + + / CLI)](../../windows/type-forwarding-cpp-cli.md).

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