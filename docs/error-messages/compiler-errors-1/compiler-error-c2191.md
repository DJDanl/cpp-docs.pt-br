---
title: Erro do compilador C2191 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2191
dev_langs:
- C++
helpviewer_keywords:
- C2191
ms.assetid: 051b8350-e5de-4f51-ab6e-96d32366bcef
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6e739c5c9fc77c4c9658afb2f5f6d9568c6f43bb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088352"
---
# <a name="compiler-error-c2191"></a>Erro do compilador C2191

segunda lista de parâmetros mais do que a primeira

Uma função C foi declarada uma segunda vez com uma lista mais longa do parâmetro. C não oferece suporte a funções sobrecarregadas.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2191:

```
// C2191.c
// compile with: /Za /c
void func( int );
void func( int, float );   // C2191 different parameter list
void func2( int, float );   // OK
```