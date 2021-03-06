---
title: Aviso do compilador (nível 1) C4091
ms.date: 11/04/2016
f1_keywords:
- C4091
helpviewer_keywords:
- C4091
ms.assetid: 3a404967-ab42-49b0-b324-fd7ba1859d78
ms.openlocfilehash: 1a9fef0a825f98ab3ce8d935c98eefe1866be6cf
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90684684"
---
# <a name="compiler-warning-level-1-c4091"></a>Aviso do compilador (nível 1) C4091

' keyword ': ignorado à esquerda de ' type ' quando nenhuma variável é declarada

O compilador detectou uma situação em que o usuário provavelmente pretendia que uma variável fosse declarada, mas o compilador não conseguiu declarar a variável.

## <a name="examples"></a>Exemplos

Um **`__declspec`** atributo no início de uma declaração de tipo definido pelo usuário se aplica à variável desse tipo. C4091 indica que nenhuma variável está declarada. O exemplo a seguir gera C4091.

```cpp
// C4091.cpp
// compile with: /W1 /c
__declspec(dllimport) class X {}; // C4091

// __declspec attribute applies to varX
__declspec(dllimport) class X2 {} varX;

// __declspec attribute after the class or struct keyword
// applies to user defined type
class __declspec(dllimport) X3 {};
```

Se um identificador for um typedef, ele também não poderá ser um nome de variável. O exemplo a seguir gera C4091.

```cpp
// C4091_b.cpp
// compile with: /c /W1 /WX
#define LIST 4
typedef struct _LIST {} LIST;   // C4091
```
