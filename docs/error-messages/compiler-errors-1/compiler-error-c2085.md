---
title: Erro do compilador C2085
ms.date: 11/04/2016
f1_keywords:
- C2085
helpviewer_keywords:
- C2085
ms.assetid: 0a86785c-8e6f-481b-8c7b-412220c1950d
ms.openlocfilehash: 7dbf7266a6330a1fdb46d7f2df90e7684f026d9a
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301958"
---
# <a name="compiler-error-c2085"></a>Erro do compilador C2085

' identifier ': não está na lista de parâmetros formais

O identificador foi declarado em uma definição de função, mas não na lista de parâmetros formais. (Somente ANSI C)

O exemplo a seguir gera C2085:

```c
// C2085.c
void func1( void )
int main( void ) {}   // C2085
```

Resolução possível:

```c
// C2085b.c
void func1( void );
int main( void ) {}
```

Com o ponto-e-vírgula ausente, `func1()` se parece com uma definição de função, não com um protótipo, portanto, `main` é definido em `func1()`, gerando o erro C2085 para o identificador `main`.
