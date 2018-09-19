---
title: Compilador aviso (nível 1) C4091 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4091
dev_langs:
- C++
helpviewer_keywords:
- C4091
ms.assetid: 3a404967-ab42-49b0-b324-fd7ba1859d78
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7b8fd377ed8b1f6425f0a1c13a83531fca1b797f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46114092"
---
# <a name="compiler-warning-level-1-c4091"></a>Compilador aviso (nível 1) C4091

'palavra-chave': ignorado à esquerda de 'type' quando nenhuma variável é declarada

O compilador detectou uma situação em que o usuário provavelmente se destina a uma variável para ser declarada, mas o compilador não foi capaz de declarar a variável.

## <a name="example"></a>Exemplo

Um `__declspec` atributo no início de uma declaração de tipo definido pelo usuário se aplica à variável desse tipo. C4091 indica que nenhuma variável é declarada. O exemplo a seguir gera C4091.

```
// C4091.cpp
// compile with: /W1 /c
__declspec(dllimport) class X {}; // C4091

// __declspec attribute applies to varX
__declspec(dllimport) class X2 {} varX;

// __declspec attribute after the class or struct keyword
// applies to user defined type
class __declspec(dllimport) X3 {};
```

## <a name="example"></a>Exemplo

Se um identificador é um typedef, ele também não pode ser um nome de variável. O exemplo a seguir gera C4091.

```
// C4091_b.cpp
// compile with: /c /W1 /WX
#define LIST 4
typedef struct _LIST {} LIST;   // C4091
```