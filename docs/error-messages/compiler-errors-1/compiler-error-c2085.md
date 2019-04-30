---
title: Erro do compilador C2085
ms.date: 11/04/2016
f1_keywords:
- C2085
helpviewer_keywords:
- C2085
ms.assetid: 0a86785c-8e6f-481b-8c7b-412220c1950d
ms.openlocfilehash: a65e3c0ea622950b99b9ba83fc168b4718d13e46
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64345717"
---
# <a name="compiler-error-c2085"></a>Erro do compilador C2085

'identifier': não está na lista de parâmetros formais

O identificador foi declarado em uma definição de função, mas não na lista de parâmetros formais. ANSI C (somente)

O exemplo a seguir gera C2085:

```
// C2085.c
void func1( void )
int main( void ) {}   // C2085
```

Solução possível:

```
// C2085b.c
void func1( void );
int main( void ) {}
```

Com o ponto e vírgula ausente `func1()` se parece com uma definição de função, não é um protótipo, portanto, `main` é definido dentro `func1()`, gerando C2085 de erro para o identificador `main`.