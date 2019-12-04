---
title: Erro do compilador C3462
ms.date: 11/04/2016
f1_keywords:
- C3462
helpviewer_keywords:
- C3462
ms.assetid: 56b75f35-9fad-42d9-a969-eeca5d709bec
ms.openlocfilehash: 56227f124d49630d8776f291ada302bd6cd6e983
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74756598"
---
# <a name="compiler-error-c3462"></a>Erro do compilador C3462

' type ': somente um tipo importado pode ser encaminhado

O atributo TypeForwardedTo deve ser aplicado a um tipo em metadados referenciados.

Para obter mais informações, consulte [tipo encaminhamentoC++(/CLI)](../../extensions/type-forwarding-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir cria um componente.

```cpp
// C3462.cpp
// compile with: /clr /LD
public ref class R {};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3462.

```cpp
// C3462b.cpp
// compile with: /clr /c
#using "C3462.dll"
ref class N {};
[assembly:TypeForwardedTo(N::typeid)];   // C3462
[assembly:TypeForwardedTo(R::typeid)];
```
