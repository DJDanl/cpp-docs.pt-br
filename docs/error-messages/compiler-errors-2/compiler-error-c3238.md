---
title: Erro do compilador C3238
ms.date: 11/04/2016
f1_keywords:
- C3238
helpviewer_keywords:
- C3238
ms.assetid: 19942497-b3c5-4df0-9144-142ced92468b
ms.openlocfilehash: 1f238a3be27023c755544438166aae1b2b2967d3
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90741977"
---
# <a name="compiler-error-c3238"></a>Erro do compilador C3238

' type ': um tipo com este nome já foi encaminhado para o assembly ' assembly '

Um tipo foi definido em um aplicativo cliente que também é definido, por meio da sintaxe de encaminhamento de tipo, em um assembly referenciado. Os dois tipos não podem ser definidos no escopo do aplicativo.

Confira [tipo encaminhamento (C++/CLI)](../../extensions/type-forwarding-cpp-cli.md) para obter mais informações.

## <a name="examples"></a>Exemplos

O exemplo a seguir cria um assembly que contém um tipo que foi encaminhado de outro assembly.

```cpp
// C3238.cpp
// compile with: /clr /LD
public ref class R {};
```

O exemplo a seguir cria um assembly que costumava conter a definição de tipo, mas não só contém a sintaxe de encaminhamento de tipo.

```cpp
// C3238_b.cpp
// compile with: /clr /LD
#using "C3238.dll"
[ assembly:TypeForwardedTo(R::typeid) ];
```

O exemplo a seguir gera C3238.

```cpp
// C3238_c.cpp
// compile with: /clr /c
// C3238 expected
// Delete the following line to resolve.
#using "C3238_b.dll"
public ref class R {};
```
