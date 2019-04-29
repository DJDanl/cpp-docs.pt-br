---
title: Compilador aviso (nível 1) C4739
ms.date: 11/04/2016
f1_keywords:
- C4739
helpviewer_keywords:
- C4739
ms.assetid: 600873b3-7c85-4cd4-944e-cd8e01bfcbb0
ms.openlocfilehash: 4c48ad9349361324c18ec790c51d1095cce104e2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62280432"
---
# <a name="compiler-warning-level-1-c4739"></a>Compilador aviso (nível 1) C4739

referência à variável 'var' excede seu espaço de armazenamento

Um valor foi atribuído a uma variável, mas o valor é maior que o tamanho da variável. Memória será gravada além do local da memória da variável e perda de dados.

Para resolver este aviso, atribua apenas um valor a uma variável cujo tamanho pode acomodar o valor.

O exemplo a seguir gera C4739:

```
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