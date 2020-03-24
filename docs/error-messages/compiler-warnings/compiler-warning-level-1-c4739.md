---
title: Aviso do compilador (nível 1) C4739
ms.date: 11/04/2016
f1_keywords:
- C4739
helpviewer_keywords:
- C4739
ms.assetid: 600873b3-7c85-4cd4-944e-cd8e01bfcbb0
ms.openlocfilehash: 9c68a9e0a2873de7e919fafbef68835f0970c03b
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185692"
---
# <a name="compiler-warning-level-1-c4739"></a>Aviso do compilador (nível 1) C4739

referência à variável ' var ' excede seu espaço de armazenamento

Um valor foi atribuído a uma variável, mas o valor é maior que o tamanho da variável. A memória será gravada além do local da memória da variável e a perda de dados será possível.

Para resolver esse aviso, atribua apenas um valor a uma variável cujo tamanho possa acomodar o valor.

O exemplo a seguir gera C4739:

```cpp
// C4739.cpp
// compile with: /RTCs /Zi /W1 /c
char *pc;
int main() {
   char c;
   *(int *)&c = 1;   // C4739

   // OK
   *(char *)&c = 1;
}
```
