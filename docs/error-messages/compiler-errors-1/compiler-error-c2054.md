---
title: Erro do compilador C2054
ms.date: 11/04/2016
f1_keywords:
- C2054
helpviewer_keywords:
- C2054
ms.assetid: 37f7c612-0d7d-4728-9e67-ac4160555f48
ms.openlocfilehash: 7366995f8930b4733ccff73aef38ebcf65a0c120
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408765"
---
# <a name="compiler-error-c2054"></a>Erro do compilador C2054

esperado ' (' a seguir 'identifier'

O identificador de função é usado em um contexto que requer parênteses à direita.

Esse erro pode ser causado omitindo um sinal de igual (=) em uma inicialização complexo.

O exemplo a seguir gera C2054:

```
// C2054.c
int array1[] { 1, 2, 3 };   // C2054, missing =
```

Solução possível:

```
// C2054b.c
int main() {
   int array2[] = { 1, 2, 3 };
}
```