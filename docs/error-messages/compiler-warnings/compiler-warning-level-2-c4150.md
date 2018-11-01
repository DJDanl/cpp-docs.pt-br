---
title: Compilador aviso (nível 2) C4150
ms.date: 11/04/2016
f1_keywords:
- C4150
helpviewer_keywords:
- C4150
ms.assetid: ff1760ec-0d9f-4d45-b797-94261624becf
ms.openlocfilehash: 4c5c10ee0ea3242e52e6db5391694c9ddf941a78
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50527667"
---
# <a name="compiler-warning-level-2-c4150"></a>Compilador aviso (nível 2) C4150

exclusão de ponteiro para tipo incompleto 'type'; Nenhum destruidor chamado

O **excluir** operador é chamado para excluir um tipo que foi declarado mas não definido, portanto, o compilador não é possível localizar um destruidor.

O exemplo a seguir gera C4150:

```
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