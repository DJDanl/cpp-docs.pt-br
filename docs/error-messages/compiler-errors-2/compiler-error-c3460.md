---
title: Erro do compilador C3460
ms.date: 11/04/2016
f1_keywords:
- C3460
helpviewer_keywords:
- C3460
ms.assetid: adbf8775-10ca-4654-acdf-58dd765351cd
ms.openlocfilehash: cb1dc84ea7b6666368708e9493349d9c7a9a0571
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743068"
---
# <a name="compiler-error-c3460"></a>Erro do compilador C3460

' type ': somente um tipo definido pelo usuário pode ser encaminhado

Para obter mais informações, veja [tipo encaminhamento (C++/CLI)](../../extensions/type-forwarding-cpp-cli.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir cria um componente.

```cpp
// C3460.cpp
// compile with: /LD /clr
public ref class R {};
```

O exemplo a seguir gera C3460.

```cpp
// C3460_b.cpp
// compile with: /clr /c
#using "C3460.dll"
[assembly:TypeForwardedTo(int::typeid)];   // C3460
[assembly:TypeForwardedTo(R::typeid)];
```
