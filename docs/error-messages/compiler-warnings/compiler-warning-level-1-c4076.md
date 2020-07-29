---
title: Aviso do compilador (nível 1) C4076
ms.date: 11/04/2016
f1_keywords:
- C4076
helpviewer_keywords:
- C4076
ms.assetid: 04581066-313a-4a11-bb60-721e6d038d75
ms.openlocfilehash: 1958aec4d6642188af1467ab4cab1ecf55c29165
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223311"
---
# <a name="compiler-warning-level-1-c4076"></a>Aviso do compilador (nível 1) C4076

> '*tipo modificador*': não pode ser usado com o tipo '*TypeName*'

## <a name="remarks"></a>Comentários

Um modificador de tipo, seja **`signed`** ou **`unsigned`** não pode ser usado com um tipo não inteiro. o *modificador de tipo* é ignorado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4076; para corrigi-lo, remova o **`unsigned`** modificador de tipo:

```cpp
// C4076.cpp
// compile with: /W1 /LD
unsigned double x;   // C4076
```
