---
title: Erro do compilador C3462
ms.date: 11/04/2016
f1_keywords:
- C3462
helpviewer_keywords:
- C3462
ms.assetid: 56b75f35-9fad-42d9-a969-eeca5d709bec
ms.openlocfilehash: 020556be73f0bad8bea6836c9ec0dd0b92dd7f39
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59778950"
---
# <a name="compiler-error-c3462"></a>Erro do compilador C3462

'type': apenas tipos importados podem ser encaminhados.

O atributo TypeForwardedTo deve ser aplicado a um tipo nos metadados referenciados.

Para obter mais informações, consulte [encaminhamento de tipo (C++/CLI)](../../extensions/type-forwarding-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir cria um componente.

```
// C3462.cpp
// compile with: /clr /LD
public ref class R {};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3462.

```
// C3462b.cpp
// compile with: /clr /c
#using "C3462.dll"
ref class N {};
[assembly:TypeForwardedTo(N::typeid)];   // C3462
[assembly:TypeForwardedTo(R::typeid)];
```