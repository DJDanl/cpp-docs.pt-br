---
title: Erro do compilador C2085 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2085
dev_langs:
- C++
helpviewer_keywords:
- C2085
ms.assetid: 0a86785c-8e6f-481b-8c7b-412220c1950d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d88968e49e38a13782dde2d905a614ad4d177e81
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46082372"
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