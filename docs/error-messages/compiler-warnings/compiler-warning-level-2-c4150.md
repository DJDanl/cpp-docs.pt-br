---
title: Aviso do compilador (nível 2) C4150
ms.date: 11/04/2016
f1_keywords:
- C4150
helpviewer_keywords:
- C4150
ms.assetid: ff1760ec-0d9f-4d45-b797-94261624becf
ms.openlocfilehash: 5f55347dbe7843e67a3c6ef0ab83b91c8fa9d283
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052148"
---
# <a name="compiler-warning-level-2-c4150"></a>Aviso do compilador (nível 2) C4150

exclusão de ponteiro para tipo incompleto ' type '; nenhum destruidor chamado

O operador **delete** é chamado para excluir um tipo que foi declarado, mas não definido, para que o compilador não encontre um destruidor.

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