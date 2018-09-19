---
title: Compilador aviso (nível 1) C4739 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4739
dev_langs:
- C++
helpviewer_keywords:
- C4739
ms.assetid: 600873b3-7c85-4cd4-944e-cd8e01bfcbb0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7beaaca5d5791079fd8ea1ff8764f0b721f8d57d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46112389"
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