---
title: Erro do compilador C2362
ms.date: 06/03/2019
f1_keywords:
- C2362
helpviewer_keywords:
- C2362
ms.assetid: 7aafecbc-b3cf-45a6-9ec3-a17e3f222511
ms.openlocfilehash: 330932f53627f8ba09e9e089cec7809eeeb6ab1c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80206070"
---
# <a name="compiler-error-c2362"></a>Erro do compilador C2362

> a inicialização de '*Identifier*' é ignorada por ' GoTo *Label*'

Quando compilado usando [/za](../../build/reference/za-ze-disable-language-extensions.md), um salto para o rótulo impede que o identificador seja inicializado.

Você só poderá pular uma declaração com um inicializador se a declaração estiver incluída em um bloco que não é inserido ou se a variável já tiver sido inicializada.

O exemplo a seguir gera C2362:

```cpp
// C2362.cpp
// compile with: /Za
int main() {
   goto label1;
   int i = 1;      // C2362, initialization skipped
label1:;
}
```

Resolução possível:

```cpp
// C2362b.cpp
// compile with: /Za
int main() {
   goto label1;
   {
      int j = 1;   // OK, this block is never entered
   }
label1:;
}
```
