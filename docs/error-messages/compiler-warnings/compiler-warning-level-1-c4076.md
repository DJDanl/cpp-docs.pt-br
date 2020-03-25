---
title: Aviso do compilador (nível 1) C4076
ms.date: 11/04/2016
f1_keywords:
- C4076
helpviewer_keywords:
- C4076
ms.assetid: 04581066-313a-4a11-bb60-721e6d038d75
ms.openlocfilehash: 77efeae27a67ea844759fd9980801d3daf788e89
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200246"
---
# <a name="compiler-warning-level-1-c4076"></a>Aviso do compilador (nível 1) C4076

> '*tipo modificador*': não pode ser usado com o tipo '*TypeName*'

## <a name="remarks"></a>Comentários

Um modificador de tipo, seja **assinado** ou **não assinado,** não pode ser usado com um tipo não inteiro. o *modificador de tipo* é ignorado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4076; para corrigi-lo, remova o modificador de tipo **não assinado** :

```cpp
// C4076.cpp
// compile with: /W1 /LD
unsigned double x;   // C4076
```
