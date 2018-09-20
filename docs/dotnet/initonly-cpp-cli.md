---
title: InitOnly (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
f1_keywords:
- initonly_cpp
- initonly
dev_langs:
- C++
helpviewer_keywords:
- initonly attribute [C++]
ms.assetid: f745d7fa-dc08-46f1-9b97-0977be58a008
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 1c98c2ab1391f65d31e64a60bf0bd86485776ad6
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46429949"
---
# <a name="initonly-ccli"></a>initonly (C++/CLI)

**InitOnly** é uma palavra-chave contextual que indica essa atribuição de variável pode ocorrer apenas como parte da declaração ou em um construtor estático na mesma classe.

O exemplo a seguir mostra como usar `initionly`:

```
// mcpp_initonly.cpp
// compile with: /clr /c
ref struct Y1 {
   initonly
   static int staticConst1;

   initonly
   static int staticConst2 = 0;

   static Y1() {
      staticConst1 = 0;
   }
};
```

## <a name="see-also"></a>Consulte também

[Classes e Structs](../windows/classes-and-structs-cpp-component-extensions.md)