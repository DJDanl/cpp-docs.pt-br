---
title: Erro do compilador C3238
ms.date: 11/04/2016
f1_keywords:
- C3238
helpviewer_keywords:
- C3238
ms.assetid: 19942497-b3c5-4df0-9144-142ced92468b
ms.openlocfilehash: d70bb6dac7cb43701b57f3821872e02ab31426dc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62173275"
---
# <a name="compiler-error-c3238"></a>Erro do compilador C3238

'type': um tipo com este nome já foi encaminhado para o assembly 'assembly'

Um tipo foi definido em um aplicativo cliente que também é definido, por meio do encaminhamento de sintaxe, em um assembly referenciado de tipo. Ambos os tipos não podem ser definidos no escopo do aplicativo.

Ver [encaminhamento de tipo (C++/CLI)](../../extensions/type-forwarding-cpp-cli.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir cria um assembly que contém um tipo que foi encaminhado de outro assembly.

```
// C3238.cpp
// compile with: /clr /LD
public ref class R {};
```

## <a name="example"></a>Exemplo

O exemplo a seguir cria um assembly que é usado para conter a definição de tipo, mas contém não apenas a sintaxe de encaminhamento de tipo.

```
// C3238_b.cpp
// compile with: /clr /LD
#using "C3238.dll"
[ assembly:TypeForwardedTo(R::typeid) ];
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3238.

```
// C3238_c.cpp
// compile with: /clr /c
// C3238 expected
// Delete the following line to resolve.
#using "C3238_b.dll"
public ref class R {};
```