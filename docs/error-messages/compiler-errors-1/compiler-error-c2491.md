---
title: Erro do compilador C2491
ms.date: 11/04/2016
f1_keywords:
- C2491
helpviewer_keywords:
- C2491
ms.assetid: 4e5a8f81-124e-402c-a5ec-d35a89b5469e
ms.openlocfilehash: 3b48bebde6d7baedea73ed181cd4ea33adc44a69
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50563118"
---
# <a name="compiler-error-c2491"></a>Erro do compilador C2491

"identificador": definição da função dllimport não permitida

Dados, membros de dados estáticos e funções podem ser declarados como `dllimport`s, mas não definidos como `dllimport`s.

Para corrigir esse problema, remova o especificador `__declspec(dllimport)` da definição da função.

O seguinte exemplo gera C2491:

```
// C2491.cpp
// compile with: /c
// function definition
void __declspec(dllimport) funcB() {}   // C2491

// function declaration
void __declspec(dllimport) funcB();   // OK
```