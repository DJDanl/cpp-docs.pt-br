---
title: Aviso do compilador (nível 2) C4150
ms.date: 11/04/2016
f1_keywords:
- C4150
helpviewer_keywords:
- C4150
ms.assetid: ff1760ec-0d9f-4d45-b797-94261624becf
ms.openlocfilehash: a3993d2b993205c98de968ca893f24f703b3b635
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218137"
---
# <a name="compiler-warning-level-2-c4150"></a>Aviso do compilador (nível 2) C4150

exclusão de ponteiro para tipo incompleto ' type '; nenhum destruidor chamado

O **`delete`** operador é chamado para excluir um tipo que foi declarado mas não definido, portanto, o compilador não pode localizar um destruidor.

O exemplo a seguir gera C4150:

```cpp
// C4150.cpp
// compile with: /W2
class  IncClass;

void NoDestruct( IncClass* pIncClass )
{
   delete pIncClass;
} // C4150, define class to resolve

int main()
{
}
```
