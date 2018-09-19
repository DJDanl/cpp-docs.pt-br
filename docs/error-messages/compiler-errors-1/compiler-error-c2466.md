---
title: Erro do compilador C2466 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2466
dev_langs:
- C++
helpviewer_keywords:
- C2466
ms.assetid: 75b251d1-7d0b-4a86-afca-26adedf74486
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8d43ee9d09fba77db022177a06c6ebe95c65ff79
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46037834"
---
# <a name="compiler-error-c2466"></a>Erro do compilador C2466

não é possível alocar uma matriz de tamanho da constante 0

Uma matriz está alocada ou declarada com tamanho zero. A expressão de constante para o tamanho da matriz deve ser um inteiro maior que zero. Uma declaração de matriz com um zero subscrito é válida somente para uma classe, estrutura ou membro de união e somente com extensões Microsoft ([/Ze](../../build/reference/za-ze-disable-language-extensions.md)).

O exemplo a seguir gera C2466:

```
// C2466.cpp
// compile with: /c
int i[0];   // C2466
int j[1];   // OK
char *p;
```