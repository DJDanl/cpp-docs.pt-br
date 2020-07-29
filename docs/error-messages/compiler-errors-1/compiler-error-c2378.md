---
title: Erro do compilador C2378
ms.date: 11/04/2016
f1_keywords:
- C2378
helpviewer_keywords:
- C2378
ms.assetid: 507a91c6-ca72-48df-b3a4-2cf931c86806
ms.openlocfilehash: c72a46bbc5778bf95ddc49426f97df0320b22a30
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218228"
---
# <a name="compiler-error-c2378"></a>Erro do compilador C2378

' identificador ': redefinição; o símbolo não pode ser sobrecarregado com um typedef

O identificador foi redefinido como um **`typedef`** .

O exemplo a seguir gera C2378:

```cpp
// C2378.cpp
// compile with: /c
int i;
typedef int i;   // C2378
typedef int b;   // OK
```
