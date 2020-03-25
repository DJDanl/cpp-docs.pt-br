---
title: Aviso do compilador (nível 2) C4150
ms.date: 11/04/2016
f1_keywords:
- C4150
helpviewer_keywords:
- C4150
ms.assetid: ff1760ec-0d9f-4d45-b797-94261624becf
ms.openlocfilehash: c4d84165c7fcda4ceab94b1380a818236f6f5ea5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80162108"
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
