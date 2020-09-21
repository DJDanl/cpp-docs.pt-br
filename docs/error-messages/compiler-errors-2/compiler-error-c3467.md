---
title: Erro do compilador C3467
ms.date: 11/04/2016
f1_keywords:
- C3467
helpviewer_keywords:
- C3467
ms.assetid: e2b844d0-4920-412f-99fd-cd8051c4aa41
ms.openlocfilehash: dd7046fcf87a6b8f095092ef0de4b94326151e87
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742821"
---
# <a name="compiler-error-c3467"></a>Erro do compilador C3467

' type ': este tipo já foi encaminhado

O compilador encontrou mais de uma declaração de tipo forward para o mesmo tipo. Somente uma declaração por tipo é permitida.

Para obter mais informações, veja [tipo encaminhamento (C++/CLI)](../../extensions/type-forwarding-cpp-cli.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir cria um componente.

```cpp
// C3467.cpp
// compile with: /LD /clr
public ref class R {};
```

O exemplo a seguir gera C3467.

```cpp
// C3467_b.cpp
// compile with: /clr /c
#using "C3467.dll"
[ assembly:TypeForwardedTo(R::typeid) ];
[ assembly:TypeForwardedTo(R::typeid) ];   // C3467
```
